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
		// ������� ��� ����������� � ��������, ��������� �� ������ � ������
		cout << string(level, ' ') << name;
		// ���� ���������� �� ���, ������� ������� � ������
		if (!alive) {
			cout << " (deceased)";
		}
		if (father) {
			cout << " [����: " << father->name << "]";
		}
		if (mother) {
			cout << " [����: " << mother->name << "]";
		}
		// ��������� �� ����� ������
		cout << endl;
		// ���������� �������� ����� ��� ������ ���������������� ������ ������� �������
		for (const auto& child : children) {
			// ������� ����� ����� ���������, ���� ��� ����
			child.lock()->printFamilyTree(level + 2);
		}
	}

	// ����� ��� ��������� ������ ���������������� ������ ��� ������� �����������
	void printReverseFamilyTree(int level = 0) const {
		// ������� ��� ����������� � ��������, ��������� �� ������ � ������
		cout << string(level, ' ') << name;
		// ���� ���������� �� ���, ������� ������� � ������
		if (!alive) {
			cout << " (deceased)";
		}
		// ��������� �� ����� ������
		cout << endl;
		// ���������� �������� ����� ��� ��������� ������ ���������������� ������ ������� ��������
		if (father) {
			father->printReverseFamilyTree(level + 2);
		}
		if (mother) {
			mother->printReverseFamilyTree(level + 2);
		}
	}
	
};