#include "CppDb.h"
#include <cstring>
// Конструктор по умолчанию
CppDb::CppDb() : pBase(nullptr), count(0), capacity(0) {}

// Деструктор
CppDb::~CppDb() {
    delete[] pBase; // Освобождаем память, выделенную для массива пар
}

// Конструктор копирования
CppDb::CppDb(const CppDb& other) : count(other.count), capacity(other.capacity) {
    // Создаем новый массив пар такого же размера, как у копируемого объекта
    pBase = new Pair[capacity];
    // Копируем каждую пару из другого объекта в новый массив
    for (size_t i = 0; i < count; ++i) {
        pBase[i] = other.pBase[i];
    }
}

// Оператор присваивания
CppDb& CppDb::operator=(const CppDb& other) {
    if (this != &other) { // Проверяем, не является ли объект самим собой
        delete[] pBase; // Освобождаем текущую память
        count = other.count; // Копируем количество пар
        capacity = other.capacity; // Копируем емкость
        // Выделяем новую память под массив пар такого же размера, как у копируемого объекта
        pBase = new Pair[capacity];
        // Копируем каждую пару из другого объекта в новый массив
        for (size_t i = 0; i < count; ++i) {
            pBase[i] = other.pBase[i];
        }
    }
    return *this; // Возвращаем ссылку на текущий объект
}

// Оператор индексирования для доступа к данным сотрудника по ключу
MyData& CppDb::operator[](const char* key) {
    for (size_t i = 0; i < count; ++i) {
        if (pBase[i].getKey() == key) { // Если найден ключ
            return pBase[i].getData(); // Возвращаем данные по ключу
        }
    }
    // Если ключ не найден, добавляем новую пару в базу
    if (count >= capacity) { // Проверяем, достигнут ли предел емкости базы
        // Увеличиваем емкость базы в два раза (или начинаем с 1, если база пуста)
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Pair* newPBase = new Pair[newCapacity]; // Создаем новый массив пар
        // Копируем существующие пары в новый массив
        for (size_t i = 0; i < count; ++i) {
            newPBase[i] = pBase[i];
        }
        delete[] pBase; // Освобождаем память, выделенную для старого массива
        pBase = newPBase; // Переключаем указатель на новый массив
        capacity = newCapacity; // Обновляем емкость базы
    }
    // Добавляем новую пару в базу и возвращаем данные этой пары
    pBase[count++] = Pair(MyString(key), MyData(MyData::UNDEF, 0, "", 0));
    return pBase[count - 1].getData();
}

// Метод удаления пары сотрудника из базы по ключу
int CppDb::deletePair(const char* key) {
    for (size_t i = 0; i < count; ++i) {
        if (pBase[i].getKey() == key) { // Если найден ключ
            // Найдена пара с указанным ключом, удаляем ее
            for (size_t j = i; j < count - 1; ++j) {
                pBase[j] = pBase[j + 1]; // Сдвигаем следующие пары на одну позицию влево
            }
            --count; // Уменьшаем количество пар
            return 0; // Возвращаем успешный результат удаления
        }
    }
    return -1; // Возвращаем код ошибки, если пара с указанным ключом не найдена
}

// Перегруженный оператор вывода для класса базы
std::ostream& operator<<(std::ostream& os, const CppDb& bd) {
    for (size_t i = 0; i < bd.count; ++i) {
        os << bd.pBase[i] << std::endl; // Выводим каждую пару в поток вывода с переводом строки
    }
    return os; // Возвращаем поток вывода
}

// Конструктор перемещения
CppDb::CppDb(CppDb&& other) : pBase(nullptr), count(0), capacity(0) {
    *this = std::move(other); // Вызываем оператор перемещения
}

// Оператор перемещения
CppDb& CppDb::operator=(CppDb&& other) {
    if (this != &other) { // Проверяем, не является ли объект самим собой
        delete[] pBase; // Освобождаем текущую память
        pBase = other.pBase; // Перемещаем указатель на новый массив пар
        count = other.count; // Перемещаем количество пар
        capacity = other.capacity; // Перемещаем емкость
        other.pBase = nullptr; // Устанавливаем указатель в объекте-источнике в nullptr
        other.count = 0; // Сбрасываем количество пар в объекте-источнике
        other.capacity = 0; // Сбрасываем емкость в объекте-источнике
    }
    return *this; // Возвращаем ссылку на текущий объект
}

// Метод для сортировки базы данных
void CppDb::sort() {
    for (size_t i = 1; i < count; ++i) { // Проходим по всем элементам базы (начиная с индекса 1)
        Pair keyPair = pBase[i]; // Запоминаем текущую пару
        size_t j = i; // Запоминаем текущий индекс
        while (j > 0 && pBase[j - 1].getKey() > keyPair.getKey()) { // Пока предыдущий ключ больше текущего
            pBase[j] = pBase[j - 1]; // Сдвигаем предыдущую пару вправо
            --j; // Уменьшаем индекс
        }
        pBase[j] = keyPair; // Помещаем сохраненную пару на правильную позицию
    }
}