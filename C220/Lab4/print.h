#pragma once

//«адание 4 
template <typename T>
void printSequence(const T& sequence)
{
	for (const auto& element : sequence)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}


//«адание 6 
template<typename Adapter>
void printadapter(const Adapter& adapter) {
    // провер€ем, €вл€етс€ ли адаптер стеком
    if constexpr (std::is_same_v<Adapter, std::stack<typename Adapter::value_type>>) {
        // копируем адаптер, чтобы не измен€ть его
        std::stack<typename Adapter::value_type> temp(adapter);
        // выводим значени€ элементов стека до его полного освобождени€
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
    // провер€ем, €вл€етс€ ли адаптер очередью
    else if constexpr (std::is_same_v<Adapter, std::queue<typename Adapter::value_type>>) {
        // копируем адаптер, чтобы не измен€ть его
        std::queue<typename Adapter::value_type> temp(adapter);
        // выводим значени€ элементов очереди до его полного освобождени€
        while (!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
    // провер€ем, €вл€етс€ ли адаптер приоритетной очередью
    else if constexpr (std::is_same_v<Adapter, std::priority_queue<typename Adapter::value_type>>) {
        // копируем адаптер, чтобы не измен€ть его
        std::priority_queue<typename Adapter::value_type> temp(adapter);
        // выводим значени€ элементов приоритетной очереди до ее полного освобождени€
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
    // если в адаптере хран€тс€ указатели
    else if constexpr (std::is_pointer_v<typename Adapter::value_type>) {
        // копируем адаптер, чтобы не измен€ть его
        Adapter temp = adapter;
        // выводим значени€ элементов адаптера, разыменовыва€ указатели
        for (const auto& element : temp) {
            std::cout << *element << " ";
        }
        std::cout << std::endl;
    }
}


template<typename T>
const auto& printValue(const T& c) {
    // ѕровер€ем, €вл€етс€ ли контейнер стеком или очередью с приоритетом
    if constexpr (std::is_same<std::stack<typename T::value_type, typename T::container_type>, T >::value ||
        std::is_same<std::priority_queue<typename T::value_type>, T >::value)
        // ≈сли тип значени€ в контейнере €вл€етс€ указателем, возвращаем разыменованное значение элемента
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
