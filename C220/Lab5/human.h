#pragma once

using namespace std;
class human {
private:
	string name;
	bool alive;
	shared_ptr<human> father;
	shared_ptr<human> mother;
	vector<weak_ptr<human>> children;

public:
	// Конструктор
	human(const std::string& name, bool alive = true) : name(name), alive(alive) {}

	// Статический метод для создания ребенка и установки связей с родителями
	static std::shared_ptr<human> child(const std::string& name, const std::shared_ptr<human>& father, const std::shared_ptr<human>& mother) {
		std::shared_ptr<human> childPtr(new human(name));
		if (father) {
			childPtr->father = father;
			father->children.push_back(childPtr);
		}
		if (mother) {
			childPtr->mother = mother;
			mother->children.push_back(childPtr);
		}
		return childPtr;
	}

	// Метод для печати генеалогического дерева для данного индивидуума
	void printFamilyTree(int level = 0) const {
		// Выводим имя индивидуума с отступом, зависящим от уровня в дереве
		cout << string(level, ' ') << name;
		// Если индивидуум не жив, выводим пометку о смерти
		if (!alive) {
			cout << " (deceased)";
		}
		if (father) {
			cout << " [Отец: " << father->name << "]";
		}
		if (mother) {
			cout << " [Мать: " << mother->name << "]";
		}
		// Переходим на новую строку
		cout << endl;
		// Рекурсивно вызываем метод для печати генеалогического дерева каждого ребенка
		for (const auto& child : children) {
			// выводим имена обоих родителей, если они есть
			child.lock()->printFamilyTree(level + 2);
		}
	}

	// метод для обратного вывода генеалогического дерева для данного индивидуума
	void printReverseFamilyTree(int level = 0) const {
		// выводим имя индивидуума с отступом, зависящим от уровня в дереве
		cout << string(level, ' ') << name;
		// если индивидуум не жив, выводим пометку о смерти
		if (!alive) {
			cout << " (deceased)";
		}
		// переходим на новую строку
		cout << endl;
		// рекурсивно вызываем метод для обратного вывода генеалогического дерева каждого родителя
		if (father) {
			father->printReverseFamilyTree(level + 2);
		}
		if (mother) {
			mother->printReverseFamilyTree(level + 2);
		}
	}
	
};