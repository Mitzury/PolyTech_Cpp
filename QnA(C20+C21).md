<div class="markdown-heading">
<h1 class="heading-element" tabindex="-1">QnA_Итоговое тестирование С20 + С21</h1>
<i>Вопросы от апреля 2024. Некоторые ответы могут быть не точными</i>
</div>
<p><strong>Вопрос 1:</strong></p>
<blockquote>Дан&nbsp;<code>class A { public void f(); }</code>
<p>Отметьте корректные варианты вызова метода f()</p>
<p>Выберете один или несколько ответов</p>
<ul>
<li>a) void func(A a){ a.f(); }</li>
<li>b) void func(A* a){ a.f(); }</li>
<li>c) void func(A a){ a.f(); }</li>
<li>d) void func(const A* a){ a->f(); }</li>
</ul>
</blockquote>
<p><strong>Вопрос 2:</strong></p>
<blockquote><code>class A { ... }; class B : public A { ... };
void F(A* pA) { ... }
int main() {
B b; F (&b); }</code></p>
<p>Посредством pA в функции F можно: Выберете один или несколько ответов:</p>
<ul>
<li>a) Обращаться к protected переменным класса А</li>
<li>b) Вызывать не виртуальные public методы класса А</li>
<li>c) Обращаться к переменным класса B</li>
<li>d) Вызывать виртуальные public методы класса B</li>
<li>e) Вызывать не виртуальные public методы класса B</li>
</ul>
</blockquote>
<p><strong>Вопрос 3:</strong></p>
<blockquote><code>class A { ... public:
	virtual void VF() = 0; }; 
	class B : public A{ ... public:
	virtual void VF(); };
</code></p>
<p>Отметьте корректные варианты Выберете один или несколько ответов:</p>
<ul>
<li>a) B b; A&amp; r = b;</li>
<li>b) A* p = new A;</li>
<li>c) A a;</li>
<li>d) A* p = new B</li>
</ul>
</blockquote>
<p><strong>Вопрос 4:</strong></p>
<blockquote>Отметьте корректные утверждения: Выберете один или несколько ответов:
<ul>
<li>a) для std::deque реализован оператор []</li>
<li>b) для std::deque не реализованы методы push_front(), pop_front(), т.к. вставка в начало неэффективна</li>
<li>c) std::deque - это контейнер с произвольным доступом</li>
</ul>
</blockquote>
<p><strong>Вопрос 5:</strong></p>
<blockquote>Отметьте корректные варианты: Выберете один или несколько ответов:
<ul>
<li>a) A.h class A{ ... public: virtual void VF()=0; }; A.cpp #include "A.h" void A::VF() {&lt;реализация&gt;}</li>
<li>b) class A{ ... public: virtual void VF()=0; // релизации нет };</li>
<li>c) class A{ ... public: virtual void VF()=0; {&lt;реализация&gt;} };</li>
</ul>
</blockquote>
<p><strong>Вопрос 6:</strong></p>
<blockquote><code>class A { ... public: A (int=0); };</code>
<p>отметьте корректные варианты Выберете один или несколько ответов:</p>
<ul>
<li>a) A* ar[]={new A(), new A(1)};</li>
<li>b) A* ar[]={&amp;A(1),&amp;A(2)};</li>
<li>c) A a1(1), a2(2); A* ar[]={&amp;a1,&amp;a2};</li>
</ul>
</blockquote>
<p><strong>Вопрос 7:</strong></p>
<blockquote>При создании объекта компилятор выделяет память Выберете один или несколько ответов:
<ul>
<li>a) для кода не-inline методов класса</li>
<li>b) для обычных (нестатических) переменных класса</li>
<li>c) может добавлять дополнительные байты для оптимизации по времени</li>
<li>d) для кода inline методов класса</li>
</ul>
</blockquote>
<p><strong>Вопрос 8:</strong></p>
<blockquote><code>class A { ... public: A(); void f(); };</code> 
Отметьте корректные варианты Выберете один или несколько ответов:
<ul>
<li>a) { A a; A* pa-&amp;a; pa-&gt;f(); }</li>
<li>b) { A* pa=new A; ... delete pa; pa-&gt;f(); }</li>
<li>c) { A* pa=&amp;A(); pa-&gt;f(); }</li>
<li>d) A* pa; { A a; pa=&amp;a; ) pa-&gt;f();</li>
<li>e) { A* pa=new A; pa-&gt;f(); ... delete pa; }</li>
</ul>
</blockquote>
<p><strong>Вопрос 9:</strong></p>
<blockquote>Отметьте варианты, в которых перегружен оператор приведения типа Выберете один или несколько ответов:
<ul>
<li>a) class A { int m_a; public: operator int(); };</li>
<li>b) class A { char* p; public: operator const char*(); };</li>
<li>c) class A { int m_a; public: int operator(); };</li>
</ul>
</blockquote>
<p><strong>Вопрос 10:</strong></p>
<blockquote>
	<code>int ar[10] ={8,9,7,6,4,1}; 
		vector v(ar,ar+10);
		 size_t n1 =v.size(); 
		 set s(v.begin(),v.end()); 
		 size_t n2 =s.size(); 
		 for(set::iterator b=s.begin,e=s.end;b!=e;++b) { cout&lt;&lt;*b&lt;&lt;", "; }
	</code>
<p>Что будет выведено?</p>
<ul>
<li>a) 1, 8, 8, 7, 6, 4, 1</li>
<li>b) 1, 8, 9, 7, 6, 4, 1, 0</li>
<li>с) 1, 1, 4, 6, 7, 8, 9</li>
<li>d) 0, 1, 4, 6, 7, 8, 9</li>
</ul>
</blockquote>
<p><strong>Вопрос 11:</strong></p>
<blockquote>Деструктор Выберете один или несколько ответов:
<ul>
<li>a) программист должен обязательно явно реализовать в каждом классе</li>
<li>b) имя деструктора должно совпадать с именем класса и предваряться значком "~"</li>
<li>с) тип возвращаемого деструктором значения ~void</li>
<li>d) может быть виртуальным</li>
</ul>
</blockquote>
<p><strong>Вопрос 12:</strong></p>
<blockquote>Отметьте корректные утверждения: Выберете один или несколько ответов:
<ul>
<li>a) для std::deque реализованы методы push_back(), pop_back()</li>
<li>b) для std::deque реализованы методы push_front(), pop_front()</li>
<li>с) std::deque -это контейнер с последовательным доступом</li>
</ul>
</blockquote>
<p><strong>Вопрос 13:</strong></p>
<blockquote>
<code>class A {... virtual void f(); ...}; class B : public A { ... }; class C : public B { ... };
int main() { A* pa= new C; bool b1= typeid(*pA) == typeid (C) ; //? bool b2= typeid(*pA) == typeid (B) ; //? }
</code>
<p>В строках, помеченных "?", Выберете один или несколько ответов:</p>
<ul>
<li>a) b2== true</li>
<li>b) b1== true</li>
</ul>
</blockquote>
<p><strong>Вопрос 14:</strong></p>
<blockquote>
<code>class A { int m_a; ... void f1(); void f(2) const; };</code>
<p>Отметьте корректные варианты: Выберете один или несколько ответов:</p>
<ul>
<li>a) void A::f1(){ m_a++; }</li>
<li>b) void A::f2() const { f1(); }</li>
<li>c) void A::f2() const { m_a++; }</li>
<li>d) void A::f1() { f2(); }</li>
</ul>
</blockquote>
<p><strong>Вопрос 15:</strong></p>
<blockquote>
<code>template void f(const A&amp; a, const A&amp; b) {...}</code>
Отметьте корректные варианты вызова функции: Выберете один или несколько ответов:
<ul>
<li>a) f(2,3.3);</li>
<li>b) f(2.2,1);</li>
<li>c) int x=1; unsigned int y=2; f(x,y);</li>
<li>d) int x=1; double y=2.2; f(x,y);</li>
</ul>
</blockquote>
<p><strong>Вопрос 16:</strong></p>
<blockquote>Отметьте варианты реализации шаблонной функции, для которых компилятор не будет выдавать ошибок в приведенном фрагменте: f(1); double d=5.5; f(d); 
Выберете один или несколько ответов:
<ul>
<li>a) template void f(const T&amp; t) {...}</li>
<li>b) template void f(T t) {...}</li>
<li>c) template void f(T&amp; t) {...}</li>
</ul>
</blockquote>
<p><strong>Вопрос 17:</strong></p>
<blockquote>Отметьте корректные варианты перегрузки префиксного оператора "++" Выберете один или несколько ответов:
<ul>
<li>a) class A { ... public: friend A&amp; operator++(A&amp;); };</li>
<li>b) class A { ... public: A&amp; operator++(); };</li>
<li>c) class A { ... public: A&amp; operator++(A&amp;); };</li>
</ul>
</blockquote>
<p><strong>Вопрос 18:</strong></p>
<blockquote>vector v; //формирование значений list l; //формирование v.size() начений deque d; // требуется: d[i]=v[i]+l[i];
<p>Отметьте корректные варианты задания предиката для трансформации двух последовательностей в третью Выберете один или несколько ответов:</p>
<ul>
<li>a) class MyPlus { public: int operator() (int x, int y) const {return x+y} }; transform(..., MyPlus);</li>
<li>b) class MyPlus { returnreturn x+y} void main() { ... transform(..., MyPlus); ... }</li>
<li>c) std::transform(...,std::plus());</li>
<li>d) template class MyPlus { public: T operator() (T x,T y) const (return x+y} }; transform(..., MyPlus());</li>
<li>e) class MyPlus { public: int operator() (int x, int y) const {return x+y} }; transform(..., MyPlus());</li>
</ul>
</blockquote>
<p><strong>Вопрос 19:</strong></p>
<blockquote>Отметьте корректные варианты Выберете один или несколько ответов:
<ul>
<li>a) class A { ... private: friend class B; };</li>
<li>b) class A { ... public: friend class B; };</li>
<li>c) class A{ ... protected: friend class B; };</li>
</ul>
</blockquote>
<p><strong>Вопрос 20:</strong></p>
<blockquote>Отметьте корректные утверждения: Выберете один или несколько ответов:
<ul>
<li>a) сортировка списка реализована только методом класса std::list::sotr()</li>
<li>b) список можно отсортировать как мутодом класса std::list::sotr(), так и обобщеным алгоритмом std::sotr() стандартной библиотеки</li>
<li>c) список можно отсортировать обобщеным алгоритмом std::sotr() стандартной библиотеки</li>
</ul>
</blockquote>
<p><strong>Вопрос 21:</strong></p>
<blockquote>Метод std::vector::rend() Выберете один ответ:
<ul>
<li>a) Возвращает итератор на последний элемент контейнера</li>
<li>b) формирует признак выхода за пределы контейнера</li>
<li>c) Возвращает итератор на первый элемент контейнера</li>
</ul>
</blockquote>
<p><strong>Вопрос 22:</strong></p>
<blockquote>
<code>class A { int m_a; public: A(int); void f(); }; 
	class B public A { int m_b; public: B(int,int); virtual void f(); }; 
	class C public B { int m_c; public: C(int,int,int); };
</code>
<p>Для каких классов компилятор сформирует таблицу виртуальных функций Выберете один или несколько ответов:</p>
<ul>
<li>a) C</li>
<li>b) A</li>
<li>c) B</li>
</ul>
</blockquote>
<p><strong>Вопрос 23:</strong></p>
<blockquote>Куда происходит передача управления при выполнении оператора throw 1? Выберете один или несколько ответов:
<ul>
<li>a) на открывающую фигурную скобку обработчика catch(int)</li>
<li>b) на закрывающую фигурную скобку блока, в котором находится оператор throw</li>
<li>c) на закрывающую фигурную скобку функции, в которой находится оператор throw</li>
</ul>
</blockquote>
<p><strong>Вопрос 24:</strong></p>
<blockquote>Отметьте корректные высказывания:
<ul>
<li>a) операции вставки/удаления значений в вписок осуществляются эффективнее чем в вектор</li>
<li>b) данные в списке располагаются последовательно в памяти</li>
</ul>
</blockquote>
<p><strong>Вопрос 25:</strong></p>
<blockquote>Отличие классов от структур языка Си Выберете один или несколько ответов:
<ul>
<li>a) Структура Си может содержать как данные, так и методы</li>
<li>b) Класс может содержать как данные, так и методы</li>
<li>c) Класс может содержать только методы</li>
<li>d) Класс может содержать только данные</li>
<li>e) Структура Си должна содержать только данные</li>
</ul>
</blockquote>
<p><strong>Вопрос 26:</strong></p>
<blockquote>Отметьте корректные варианты: Выберете один или несколько ответов:
<ul>
<li>a) try{ ... } catch(...) { &lt;обработка всех типов исключительных ситуаций, кроме целочисленного исключения&gt; } catch (int n) { &lt;обработка целочисленного исключения&gt; }</li>
<li>b) try{ ... } catch (int n) { &lt;обработка целочисленного исключения&gt; } catch(...) { &lt;обработка всех остальных исключительных ситуаций&gt; } c) try{ ... } catch (int n) { &lt;обработка целочисленного исключения&gt; } catch(double)</li>
<li>с) { &lt;обработка исключения типа double&gt; }</li>
<li>d) try{ ... } catch(...) { &lt;обработка любой исключительной ситуации&gt; } e) try{ ... } &lt;продолжение выполнения кода&gt;</li>
</ul>
</blockquote>
<p><strong>Вопрос 27:</strong></p>
<blockquote>
<code>class A {... virtual void fA(); ...}; 
	class B {... virtual void fB(); ...}; 
	class C : public A, public B {};
</code>
<p>В каких вариантах будет сформирован ненулевой указатель pp?</p>
<ul>
<li>a) A* p= new C; C* pp= dynamic_cast&lt;C*&gt;(p);</li>
<li>b) A* p= new C; C* pp= dynamic_cast&lt;B*&gt;(p);</li>
<li>c) B* p= new C; C* pp= dynamic_cast&lt;C*&gt;(p);</li>
<li>d) B* p= new C; A* pp= dynamic_cast&lt;A*&gt;(p);</li>
</ul>
</blockquote>
