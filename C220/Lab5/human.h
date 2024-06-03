#pragma once


class human {
private:
	std::string name;
	bool alive;
	std::shared_ptr<human> father;
	std::shared_ptr<human> mother;
	std::vector<std::weak_ptr<human>> children;

public:
	// �����������
	human(const std::string& name, bool alive = true) : name(name), alive(alive) {}

	// ����������� ����� ��� �������� ������� � ��������� ������ � ����������
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

	// ����� ��� ������ ���������������� ������ ��� ������� �����������
	void printFamilyTree(int level = 0) const {
		std::cout << std::string(level, ' ') << name;
		if (!alive) {
			std::cout << " (deceased)";
		}
		std::cout << std::endl;
		for (const auto& child : children) {
			child.lock()->printFamilyTree(level + 2);
		}
	}
};
