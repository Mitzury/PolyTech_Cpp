//������������ ������ �3
//initializer_list, move, default, delete, move ���������


/*�������.������������ �����, ������� ��������� ���������������� ������� � ���������� ������ ����.
������ ��������� ������� � ������������ �������, ��� ���� ������������ ������ ��� ����������� �����.���������: ��� ��� ������� � ��� ������������� ��������� ������, ��� ������� ����� ������ ���������� � �����, �  ������� ������ ��������� �� ������ ������� = > ���� ��������� ������� ������� ������������, �� ������ ������ ����� ��� ������������ = > ��������������� �����, ��������� ��������� � �������� ��������.
�������� �� ��������� ������������� ����� ��������� ������, ����� ��������� ��������, ����� ������������ ������ push(), � ��������� ��������� � ������� �� �������� = > ��� ������������� ������ ������� �����������.
��� ���������� ����� ���������� ����������� ������ � ������������ ������� = >
�	������������� ������� ��������� ���������
�	������ ��� ��������� ������������� �� ����������������
��������!
1.	������� ��������� ��� ������������� ������ ������!� ������������� ��������� �� ���� ������������� move - ���������
2.	������� ������� �� ������ � ������� range - base - for
��������� ������������� ����� �� ����������� ���� ���������.���������: ���� �� �� ������� �� ���������� ������ � �� ������������� ������������ � ������� ����� MyString, ������ �������� ��� �� std::string

��������� �������� ������ �������� �� ������ ���������, �� � ���������� :

MyQueue<MyString>  q1{ MyString(�AAA�), MyString(�qwerty�),<������_��������������> };

//������������� MyQueue � ����������� for:
for (const auto& el : q1) { std::cout << el << ' '; }

MyString s(�abc�);
q1.push(s);
q1.push(MyString(�123�));
MyString s1 = q1.pop();
q1.push(�qqq�);
MyQueue < MyString >  q2 = q1;
MyQueue < MyString >  q22 = std::move(q1);

MyQueue < MyString >  q3{ 10, MyString(�!�) }; //������� ������ ��������� 10 ��������� �� ������� �!� 
q1 = q3;
q2 = MyQueue < MyString >(5, MyString(� ? �));
q1 = { MyString(�bbb�), MyString(�ssss�) };
*/
