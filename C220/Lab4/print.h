#pragma once

//������� 4 
template <typename T>
void printSequence(const T& sequence)
{
	for (const auto& element : sequence)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}


//������� 6 
template<typename Adapter>
void printadapter(const Adapter& adapter) {
    // ���������, �������� �� ������� ������
    if constexpr (std::is_same_v<Adapter, std::stack<typename Adapter::value_type>>) {
        // �������� �������, ����� �� �������� ���
        std::stack<typename Adapter::value_type> temp(adapter);
        // ������� �������� ��������� ����� �� ��� ������� ������������
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
    // ���������, �������� �� ������� ��������
    else if constexpr (std::is_same_v<Adapter, std::queue<typename Adapter::value_type>>) {
        // �������� �������, ����� �� �������� ���
        std::queue<typename Adapter::value_type> temp(adapter);
        // ������� �������� ��������� ������� �� ��� ������� ������������
        while (!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
    // ���������, �������� �� ������� ������������ ��������
    else if constexpr (std::is_same_v<Adapter, std::priority_queue<typename Adapter::value_type>>) {
        // �������� �������, ����� �� �������� ���
        std::priority_queue<typename Adapter::value_type> temp(adapter);
        // ������� �������� ��������� ������������ ������� �� �� ������� ������������
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
    // ���� � �������� �������� ���������
    else if constexpr (std::is_pointer_v<typename Adapter::value_type>) {
        // �������� �������, ����� �� �������� ���
        Adapter temp = adapter;
        // ������� �������� ��������� ��������, ������������� ���������
        for (const auto& element : temp) {
            std::cout << *element << " ";
        }
        std::cout << std::endl;
    }
}


template<typename T>
const auto& printValue(const T& c) {
    // ���������, �������� �� ��������� ������ ��� �������� � �����������
    if constexpr (std::is_same<std::stack<typename T::value_type, typename T::container_type>, T >::value ||
        std::is_same<std::priority_queue<typename T::value_type>, T >::value)
        // ���� ��� �������� � ���������� �������� ����������, ���������� �������������� �������� ��������
        if constexpr (std::is_pointer<typename T::value_type>::value)
            return *c.top();
        else
            return c.top();
    else
        if constexpr (std::is_pointer<typename T::value_type>::value)
            return *c.front();
        else
            return c.front();
}

template<typename T>
void printAdapter(T adapter)
{
    while (!adapter.empty()) {
        std::cout << printValue(adapter) << " ; ";
        adapter.pop();
    }
    std::cout << std::endl;
}
