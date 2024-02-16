#include "Pair.h"

Pair::Pair() : key(""), data(MyData(MyData::UNDEF, 0, "", 0)) {
    // Конструктор по умолчанию инициализирует ключ пустой строкой и данные значениями по умолчанию
}
Pair::Pair(const MyString& k, const MyData& d) : key(k), data(d) {
    // Конструктор с параметрами инициализирует ключ переданной строкой и данные переданным объектом MyData
}
const MyString& Pair::getKey() const {
    return key; // Возвращает ключ пары
}
MyData& Pair::getData() {
    return data; // Возвращает данные пары
}
std::ostream& operator<<(std::ostream& os, const Pair& pair) {
    os << "Key: " << pair.key << ", Data: " << pair.data; // Выводит ключ и данные пары в поток вывода
    return os; // Возвращаем ссылку на поток вывода
}