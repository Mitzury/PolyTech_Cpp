<h1>QnA_Итоговое тестирование С20 + С21</h1>

<strong>Вопрос 1:</strong>
<blockquote>
Дан 
class A{
public void f();
}

Отметьте корректные варианты вызова метода f()
Выберете один или несколько ответов

a) 
void func(A& a){
	a.f();
}
b) 
void func(A* a){
	a.f();
}
c) 
void func(A a){
	a.f();
}
d) 
void func(const A* a){
	a->f();
}
</blockquote>

<strong>Вопрос 2:</strong>
<blockquote>
class A { ... };
class B : public A { ... };

void F(A* pA) { ... }

int main()
{

   B b;
   F (&b);
   
}   

Посредством pA в функции F можно:
Выберете один или несколько ответов:

a) Обращаться к protected переменным класса А
b) Вызывать не виртуальные public методы класса А
c) Обращаться к переменным класса B
d) Вызывать виртуальные public методы класса B
e) Вызывать не виртуальные public методы класса B
</blockquote>

<strong>Вопрос 3:</strong>
<blockquote>
class A { ...
public:

	virtual void VF() = 0;
};
class B : public A{ ...
public:

	virtual void VF();
};

Отметьте корректные варианты
Выберете один или несколько ответов:

a) B b;
	A& r = b;
	
b) A* p = new A;

c) A a;

d) A* p = new B
</blockquote>

<strong>Вопрос 4:</strong>
<blockquote>
Отметьте корректные утверждения:
Выберете один или несколько ответов:

a) для std::deque реализован оператор []
b) для std::deque не реализованы методы push_front(), 
    pop_front(), т.к. вставка в начало неэффективна
c) std::deque - это контейнер с произвольным доступом
</blockquote>

<strong>Вопрос 5:</strong>
<blockquote>
Отметьте корректные варианты:
Выберете один или несколько ответов:
a) 
  A.h
  class A{ ...
  public:
	virtual void VF()=0;
  };
  A.cpp
  #include "A.h"
  void A::VF() {<реализация>}
b)
 class A{ ...
  public:
	virtual void VF()=0; // релизации нет
  };
c)
 class A{ ...
  public:
	virtual void VF()=0; {<реализация>}
  };  
</blockquote>

<strong>Вопрос 6:</strong>
<blockquote>
class A { 
   ...
public:
	A(int=0);
};

отметьте корректные варианты
Выберете один или несколько ответов:

a) 
  A* ar[]={new A(), new A(1)};
b) 
  A* ar[]={&A(1),&A(2)};
c)
  A a1(1), a2(2);
  A* ar[]={&a1,&a2};
</blockquote>

<strong>Вопрос 7:</strong>
<blockquote>
При создании объекта компилятор выделяет память
Выберете один или несколько ответов:

a) для кода не-inline методов класса
b) для обычных (нестатических) переменных класса
c) может добавлять дополнительные байты для оптимизации по времени
d) для кода inline методов класса
</blockquote>

<strong>Вопрос 8:</strong>
<blockquote>
class A { 
...
public:
	A();
	void f();
};
Отметьте корректные варианты
Выберете один или несколько ответов:

a)
	{
		A a;
		A* pa-&a;
		pa->f();
	}
b) 
	{
		A* pa=new A;
		...
		delete pa;
		pa->f();
	}
c)
	{
		A* pa=&A();
		pa->f();
	}
d)
	A* pa;
	{
		A a;
		pa=&a;
	)
	pa->f();
e) 
	{
		A* pa=new A;
		pa->f();
		...
		delete pa;
	}
</blockquote>

<strong>Вопрос 9:</strong>
<blockquote>
Отметьте варианты, в которых перегружен оператор приведения типа
Выберете один или несколько ответов:
a)
	class A {
		int m_a;
	public:
		operator int();
		};
b)
	class A {
		char* p;
	public:
		operator const char*();
		};
c)
	class A {
		int m_a;
	public:
		int operator();
		};
</blockquote>

<strong>Вопрос 10:</strong>
<blockquote>
int ar[10] ={8,9,7,6,4,1};
vector<int> v(ar,ar+10);
size_t n1 =v.size();
set<int> s(v.begin(),v.end());
size_t n2 =s.size();
for(set<int>::iterator b=s.begin,e=s.end;b!=e;++b){
		cout<<*b<<", ";
		}

Что будут выведено?

a) 1, 8, 8, 7, 6, 4, 1
b) 1, 8, 9, 7, 6, 4, 1, 0
с) 1, 1, 4, 6, 7, 8, 9
d) 0, 1, 4, 6, 7, 8, 9
</blockquote>

<strong>Вопрос 11:</strong>
<blockquote>
Деструктор
Выберете один или несколько ответов:

a) программист должен обязательно явно реализовать в каждом классе
b) имя деструктора должно совпадать с именем класса и предваряться
   значком "~"
с) тип возвращаемого деструктором значения ~void
d) может быть виртуальным
</blockquote>

<strong>Вопрос 12:</strong>
<blockquote>
Отметьте корректные утверждения:
Выберете один или несколько ответов:
a) для std::deque реализованы методы push_back(), pop_back()
b) для std::deque реализованы методы push_front(), pop_front()
с) std::deque -это контейнер с последовательным доступом
</blockquote>

<strong>Вопрос 13:</strong>
<blockquote>
class A {... virtual void f(); ...};
class B : public A { ... };
class C : public B { ... };

int main()
{
	A* pa= new C;
	bool b1= typeid(*pA) == typeid (C) ; //?
	bool b2= typeid(*pA) == typeid (B) ; //?
}

В строках, помеченных "?",
Выберете один или несколько ответов:

a) b2== true
b) b1== true
</blockquote>

<strong>Вопрос 14:</strong>
<blockquote>
class A {
	int m_a;
	...
	void f1();
	void f(2) const;
};

Отметьте корректные варианты:
Выберете один или несколько ответов:

a)
	void A::f1(){
		m_a++;
	}
b)
	void A::f2() const {
		f1();
	}
c) 
	void A::f2() const {
		m_a++;
	}	
d)
	void A::f1() {
		f2();
	}
</blockquote>

<strong>Вопрос 15:</strong>
<blockquote>
template<typename A> void f(const A& a, const A& b) {...}
Отметьте корректные варианты вызова функции:
Выберете один или несколько ответов:
a)
	f(2,3.3);
b)
	f<double>(2.2,1);
c)
	int x=1;
	unsigned int y=2;
	f(x,y);
d)
	int x=1;
	double y=2.2;
	f(x,y);	
</blockquote> 

<strong>Вопрос 16:</strong>
<blockquote>
Отметьте варианты реализации шаблонной функции, для которых компилятор 
не будет выдавать ошибок в приведенном фрагменте:
f(1);
double d=5.5;
f(d);
Выберете один или несколько ответов:
a)
	template<typename T> void f(const T& t) {...}
b)
	template<typename T> void f(T t) {...}	
c)
	template<typename T> void f(T& t) {...}	
		
</blockquote>

 
<strong>Вопрос 17:</strong>
<blockquote>
Отметьте корректные варианты перегрузки префиксного оператора "++"
Выберете один или несколько ответов:

a)
	class A { ...
	public:
		friend A& operator++(A&);
	};	
b)
	class A { ...
	public:
		A& operator++();
	};	
c)
	class A { ...
	public:
		A& operator++(A&);
	};	
</blockquote>

<strong>Вопрос 18:</strong>
<blockquote>
vector<int> v;
//формирование значений
list<int> l;
//формирование v.size() начений
deque<int> d;
// требуется: d[i]=v[i]+l[i];

Отметьте корректные варианты задания предиката для трансформации двух
последовательностей в третью
Выберете один или несколько ответов:

a)
	class MyPlus {
	public:
		int operator() (int x, int y) const {return x+y}
	};
	transform(..., MyPlus);
b)
	class MyPlus { returnreturn x+y}
	void main() {
	...
	transform(..., MyPlus);
	...
	}
c) 
	std::transform(...,std::plus<int>());
d)
	template<typename T> class MyPlus {
	public:
		T operator() (T x,T y) const (return x+y}
	};
	transform(..., MyPlus<int>());
e)
	class MyPlus {
	public:
		int operator() (int x, int y) const {return x+y}
	};
	transform(..., MyPlus());
</blockquote>

<strong>Вопрос 19:</strong>
<blockquote>
Отметьте корректные варианты
Выберете один или несколько ответов:

a)
	class A {
	...
	private:
		friend class B;
	};
b)
	class A {
	...
	public:
		friend class B;
	};
c)
	class A{
	...
	protected:
		friend class B;
	};
</blockquote>

<strong>Вопрос 20:</strong>
<blockquote>
Отметьте корректные утверждения:
Выберете один или несколько ответов:

a) сортировка списка реализована только методом класса
	std::list::sotr()
b) список можно отсортировать как мутодом класса 
	std::list::sotr(), так и обобщеным алгоритмом 	std::sotr()
   стандартной библиотеки
c) список можно отсортировать обобщеным алгоритмом 	std::sotr()
   стандартной библиотеки   

</blockquote>

 
<strong>Вопрос 21:</strong>
<blockquote>
Метод std::vector::rend()
Выберете один ответ:

a) Возвращает итератор на последний элемент контейнера
b) формирует признак выхода за пределы контейнера
c) Возвращает итератор на первый элемент контейнера
</blockquote>


<strong>Вопрос 22:</strong>
<blockquote>

class A {
	int m_a;
public:
	A(int);
	void f();
};
class B public A {
	int m_b;
public:
	B(int,int);
	virtual void f();
};
class C public B {
	int m_c;
public:
	C(int,int,int);
};

Для каких классов компилятор сформирует таблицу виртуальных функций
Выберете один или несколько ответов:
a) C
b) A
c) B
</blockquote>

<strong>Вопрос 23:</strong>
<blockquote>
Куда происходит передача управления при выполнении оператора throw 1?
Выберете один или несколько ответов:

a) на открывающую фигурную скобку обработчика catch(int)
b) на закрывающую фигурную скобку блока, в котором находится
   оператор throw
c) на закрывающую фигурную скобку функции, в которой находится оператор throw
</blockquote>

<strong>Вопрос 24:</strong>
<blockquote>
Отметьте корректные высказывания:

a) операции вставки/удаления значений в вписок осуществляются 
	эффективнее чем в вектор
b) данные в списке располагаются последовательно в памяти
</blockquote>

<strong>Вопрос 25:</strong>
<blockquote>
Отличие классов от структур языка Си
Выберете один или несколько ответов:

a) Структура Си может содержать как данные, так и методы
b) Класс может содержать как данные, так и методы
c) Класс может содержать только методы
d) Класс может содержать только данные
e) Структура Си должна содержать только данные
</blockquote>


<strong>Вопрос 26:</strong>
<blockquote>
Отметьте корректные варианты:
Выберете один или несколько ответов:

a) 
	try{
	...
	}
	catch(...) {
		<обработка всех типов исключительных ситуаций,
		кроме целочисленного исключения>
	}
	catch (int n) {
		<обработка целочисленного исключения>
	}
b)  
	try{
	...
	}
	catch (int n) {
		<обработка целочисленного исключения>
	}
	catch(...) {
		<обработка всех остальных исключительных ситуаций>
	}
c)
	try{
	...
	}
	catch (int n) {
		<обработка целочисленного исключения>
	}
	catch(double d) {
		<обработка исключения типа double>
	}
	
d) 
	try{
	...
	}
	catch(...) {
		<обработка любой исключительной ситуации>
	}
e) 	
	try{
	...
	}
	<продолжение выполнения кода>
</blockquote>

<strong>Вопрос 27:</strong>
<blockquote>
	
class A {... virtual void fA(); ...};
class B {... virtual void fB(); ...};
class C : public A, public B {};

В каких вариантах будет сформирован ненулевой указатель pp?

a) 
	A* p= new C;
	C* pp= dynamic_cast<C*>(p);
b) 
	A* p= new C;
	C* pp= dynamic_cast<B*>(p);
c) 
	B* p= new C;
	C* pp= dynamic_cast<C*>(p);
d) 
	B* p= new C;
	A* pp= dynamic_cast<A*>(p);
</blockquote>


