#include "Node.h"

// ����������� ������������ ������ Node, ����������������� ������ ���� � ��������� �� ��������� � ���������� ���� �����
Node::Node(const Circle& data) : data(data), next(nullptr), prev(nullptr) {}