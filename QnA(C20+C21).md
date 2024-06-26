<div class="markdown-heading">
	<h1 class="heading-element" tabindex="-1">QnA_Итоговое тестирование С20 + С21</h1>
	<i>Вопросы от апреля 2024. Некоторые ответы могут быть не точными</i>
</div>
</blockquote>
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
		<li>a) A.h class A{ ... public: virtual void VF()=0; }; A.cpp #include "A.h" void A::VF() {&lt;реализация&gt;}
		</li>
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
<blockquote>Отметьте варианты реализации шаблонной функции, для которых компилятор не будет выдавать ошибок в
	приведенном фрагменте: f(1); double d=5.5; f(d);
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
<blockquote>vector v; //формирование значений list l; //формирование v.size() начений deque d; // требуется:
	d[i]=v[i]+l[i];
	<p>Отметьте корректные варианты задания предиката для трансформации двух последовательностей в третью Выберете один
		или несколько ответов:</p>
	<ul>
		<li>a) class MyPlus { public: int operator() (int x, int y) const {return x+y} }; transform(..., MyPlus);</li>
		<li>b) class MyPlus { returnreturn x+y} void main() { ... transform(..., MyPlus); ... }</li>
		<li>c) std::transform(...,std::plus());</li>
		<li>d) template class MyPlus { public: T operator() (T x,T y) const (return x+y} }; transform(..., MyPlus());
		</li>
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
		<li>b) список можно отсортировать как мутодом класса std::list::sotr(), так и обобщеным алгоритмом std::sotr()
			стандартной библиотеки</li>
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
		<li>a) try{ ... } catch(...) { &lt;обработка всех типов исключительных ситуаций, кроме целочисленного
			исключения&gt; } catch (int n) { &lt;обработка целочисленного исключения&gt; }</li>
		<li>b) try{ ... } catch (int n) { &lt;обработка целочисленного исключения&gt; } catch(...) { &lt;обработка всех
			остальных исключительных ситуаций&gt; } c) try{ ... } catch (int n) { &lt;обработка целочисленного
			исключения&gt; } catch(double)</li>
		<li>с) { &lt;обработка исключения типа double&gt; }</li>
		<li>d) try{ ... } catch(...) { &lt;обработка любой исключительной ситуации&gt; } e) try{ ... } &lt;продолжение
			выполнения кода&gt;</li>
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
<p><strong>Вопрос 28:</strong></p>
<blockquote>
	<p>Отметьте варианты, в которых перегружен оператор приведения типа
		выберете один или несколько ответов:</p>
	<ul>
		<li>a)<code>
 class a {
  int m_a;
 public:
  operator int();
  };</code>
		<li>b)<code>
 class a {
  char* p;
 public:
  operator const char*();
  };</code>
		<li>c)<code>
 class a {
  int m_a;
 public:
  int operator();
  };</code>
	</ul>
</blockquote>
<p><strong>Вопрос 29:</strong></p>
<blockquote>Отметьте варианты реализации шаблонной функции, для которых компилятор не будет выдавать ошибок в
	приведенном фрагменте:
	<code>double d = 5.5; </code><br /><code> f(&amp;d); </code><br /><code> f(d);</code> <br /> &nbsp; <br />Выберите
	один или несколько ответов:
	<ul>
		<li>a. template&lt;typename t&gt; void f(t* t) {...}</li>
		<li>b. template&lt;typename t&gt; void f(t t) {...}</li>
		<li>c. template&lt;typename t&gt; void f(t&amp; t) {...}</li>
		<li>d. template&lt;typename t&gt; void f(const t&amp; t) {...} <br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 30:</strong></p>
<blockquote><br />
	<code>class a {}; </code><br /><code> class b : public a {}; </code><br /><code> viod main() { </code><br /><code> b b;</code><br /><code> }</code>
	<br /> какие конструкторы и в каком порядке вызываются? <br /> выберите один ответ:
	<ul>
		<li>a. b</li>
		<li>b. b a</li>
		<li>c. a b</li>
	</ul>
</blockquote>
<p><strong>Вопрос 31:</strong></p>
<blockquote><br />
	<code>class a {}; </code><br /><code> class b : public a {}; </code><br /><code> viod main() { </code><br /><code> b b;</code><br /><code> }</code>
	<br /> какие конструкторы и в каком порядке вызываются? <br /> выберите один ответ:
	<ul>
		<li>a. b</li>
		<li>b. b a</li>
		<li>c. a b</li>
	</ul>
</blockquote>
<p><strong>Вопрос 32:</strong></p>
<blockquote><br /> деструктор <br /> выберите один или несколько ответов:
	<ul>
		<li>a. программист должен обязательно явно реализовать в каждом классе</li>
		<li>b. может быть виртуальным</li>
		<li>c. имя деструктора должно совпадать с именем класса и предваряться значком &laquo;~&raquo;</li>
		<li>d. тип возвращаемого деструктором значения - void</li>
	</ul>
</blockquote>
<p><strong>Вопрос 33:</strong></p>
<blockquote><br /> <code>class a { int m_a;  public: a(int a); };</code>
	<br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li>a. a::a(int a) { m_a = a; }</li>
		<li>b. a::a(int a) : m_a(a) { }</li>
	</ul>
</blockquote>
<p><strong>Вопрос 34:</strong></p>
<blockquote><br /> default конструктор <br /> выберите один или несколько ответов:
	<ul>
		<li>a. генерируется автоматически компилятором только при отсутствии других конструкторов в классе</li>
		<li>b. должен реализовать программист явно</li>
		<li>c. всегда автоматически генерируется компилятором <br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 35:</strong></p>
<blockquote><br />
	<code>class a { </code><br /><code> int m_a; </code><br /><code> public: </code><br /><code> void f(); </code><br /><code> };</code>
	<br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li><code>a. void func(a* p) { </code><br /><code> &nbsp; &nbsp;p-&gt;f(); </code><br /><code> }</code></li>
		<li><code>b. void a::f() { </code><br /><code> &nbsp; &nbsp;m_a++; </code><br /><code> }</code></li>
		<li><code>c. void func(a* p) { </code><br /><code> &nbsp; &nbsp;p-&gt;m_a++; </code><br /><code> }</code>
			<br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 36:</strong></p>
<blockquote>отметьте корректные варианты: <br /> выберите один или несколько ответов:
	<ul>
		<li>a. для обозначения обобщенного параметра можно использовать ключевое слово class</li>
		<li>b. для обозначения обобщенного параметра можно использовать ключевое слово struct</li>
		<li>c. для обозначения обобщенного параметра можно использовать ключевое слово typename <br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 37:</strong></p>
<blockquote>при объявлении шаблона можно указать в качестве параметров шаблона: <br /> выберите один или несколько
	ответов:
	<ul>
		<li>a. целочисленные типы</li>
		<li>b. строковые типы</li>
		<li>c. шаблоны</li>
		<li>d. обобщенные типы</li>
	</ul>
</blockquote>
<p><strong>Вопрос 38:</strong></p>
<blockquote>
	<code>a.h
	class a { int m_a;  public:  void f();  };
	</code>
	<br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li>a. a.cpp <br /> <code>void a::f() { &nbsp;}</code></li>
		<li>b. a.cpp <br /> <code>#include &ldquo;a.h&rdquo; </code><br /><code> void a::f() { }</code></li>
		<li>c. a.h <br />
			<code>class a { </code><br /><code> int m_a; </code><br /><code> public: </code><br /><code> void f(); </code><br /><code> }; </code><br /><code> void a::f() { }</code>
		</li>
		<li>d. a.cpp <br /> <code>#include &ldquo;a.h&rdquo; </code><br /><code> void f() { &nbsp;}</code></li>
	</ul>
</blockquote>
<p><strong>Вопрос 39:</strong></p>
<blockquote>ключевые слова с++, которые относятся к механизму обработки исключений <br /> выберите один или несколько
	ответов:
	<ul>
		<li>a. throw</li>
		<li>b. catch</li>
		<li>c. try</li>
		<li>d. exception</li>
	</ul>
</blockquote>
<p><strong>Вопрос 40:</strong></p>
<blockquote>
	<code>class a { virtual void f(); }; </code><br /><code> class b : public a { &nbsp;}; </code><br /><code> &nbsp; </code><br /><code> int main() { </code><br /><code> a* pa = new b; </code><br /><code> bool b = typeid(*pa).before(typeid(a)); //? </code><br /><code> } </code><br /><code> &nbsp;</code>
	<br /> значение переменной "b&rdquo;: <br /> выберите один ответ:
	<ul>
		<li>a. false</li>
		<li>b. true</li>
	</ul>
</blockquote>
<p><strong>Вопрос 41:</strong></p>
<blockquote>Порядок инициализации переменных класса <br /> выберите один ответ:
	<ul>
		<li>a. зависит от порядка объявления переменных в классе</li>
		<li>b. зависит от их следования в списке инициализации</li>
	</ul>
</blockquote>
<p><strong>Вопрос 42:</strong></p>
<blockquote>
	<code>class a { </code><br /><code> ... </code><br /><code> public: void f(); </code><br /><code> ... </code><br /><code> }; </code><br /><code> vector &lt;a*&gt; v; </code><br /><code> //формирование элементов вектора </code><br /><code> vector &lt;a*&gt;::iterator it = v.begin();</code>
	<br /> &nbsp; <br /> отметьте корректные варианты вызова метода a::f() <br /> выберите один или несколько ответов:
	<ul>
		<li>a. (*it)-&gt;f();</li>
		<li>b. (*it).f();</li>
		<li>c. (**it).f();</li>
	</ul>
</blockquote>
<p><strong>Вопрос 43:</strong></p>
<blockquote>
	<code>a.h </code><br /><code> class a { </code><br /><code> ... </code><br /><code> public: </code><br /><code> a(int); </code><br /><code> };</code>
	<br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li>a. a* pa = new a();</li>
		<li>b. a a;</li>
		<li>c. a* pa = new a(2);</li>
		<li>d. a a(1);</li>
	</ul>
</blockquote>
<p><strong>Вопрос 44:</strong></p>
<blockquote>Шаблонная функция может быть перегружена <br /> выберите один ответ:
	<ul>
		<li>a. да</li>
		<li>b. нет</li>
	</ul>
</blockquote>
<p><strong>Вопрос 45:</strong></p>
<blockquote>
	<code>class a {}; </code><br /><code> class b : public a {}; </code><br /><code> &nbsp; </code><br /><code> void f1(const a&amp;, const a&amp;); </code><br /><code> void f2(const b&amp;, const b&amp;);</code>
	<br /> &nbsp; <br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li>a. <code>const a a; </code><br /><code> const b b; </code><br /><code> f1(a, b);</code></li>
		<li>b. <code>a a; </code><br /><code> b b; </code><br /><code> f2(a, b);</code></li>
		<li>c. <code>a a; </code><br /><code> b b; </code><br /><code> f1(a, b);</code></li>
	</ul>
	<p>&nbsp;</p>
</blockquote>
<p><strong>Вопрос 46:</strong></p>
<blockquote><code>int ar[5] = {1, 2, 3, 4, 5}; </code><br /><code> vector&lt;int&gt; v;</code> <br /> &nbsp;
	<br /> отметьте корректные варианты: <br /> выберите один или несколько ответов:
	<ul>
		<li>a. copy(ar, ar + 5, inserter(v, v.begin()));</li>
		<li>b. copy(ar, ar + 5, back_inserter(v));</li>
		<li>c. copy(ar, ar + 5, v.begin());</li>
		<li>d. copy(ar, ar + 5, front_inserter(v));</li>
	</ul>
</blockquote>
<p><strong>Вопрос 47:</strong></p>
<blockquote>Дано <br /> a a1, a2, a3;
	<br /> отметьте примеры, в которых оператор можно перегрузить только глобальной функцией <br /> выберите один или
	несколько ответов:
	<ul>
		<li>a. a3 = -a1;</li>
		<li>b. a3 += a2;</li>
		<li>c. a3 = 1 + a2;</li>
		<li>d. a1++;</li>
		<li>e. std::cout &lt;&lt; a1;</li>
		<li>f. a2 += 1; <br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 48:</strong></p>
<blockquote>Методы класса могут быть <br /> выберите один или несколько ответов:
	<ul>
		<li>a. private</li>
		<li>b. public</li>
		<li>c. protected</li>
		<li>d. const</li>
	</ul>
</blockquote>
<p><strong>Вопрос 49:</strong></p>
<blockquote>Выберите один или несколько ответов:
	<ul>
		<li>a. можно перегрузить оператор \"+\" для типа заданного с помощью enum</li>
		<li>b. перегруженные операторы наследуют приоритеты и ассоциативность от встроенных операторов</li>
		<li>c. можно реализовать оператор \"$\"</li>
		<li>d. можно перегрузить оператор \"+\" для типа double</li>
	</ul>
</blockquote>
<p><strong>Вопрос 50:</strong></p>
<blockquote>
	<code>class a { </code><br /><code> int m_a; </code><br /><code> public: </code><br /><code> a(int); </code><br /><code> virtual void f(); </code><br /><code> }; </code><br /><code> class b : public a { </code><br /><code> int m_b; </code><br /><code> public: </code><br /><code> b(int, int); </code><br /><code> void f(); </code><br /><code> }; </code><br /><code> class c : public b { </code><br /><code> int m_c; </code><br /><code> public: </code><br /><code> c(int, int, int); </code><br /><code> void f(); </code><br /><code> };</code>
	<br /> для каких классов компилятор сформирует таблицу виртуальных функций <br /> выберите один или несколько
	ответов:
	<ul>
		<li>a. a</li>
		<li>b. c</li>
		<li>c. b</li>
	</ul>
</blockquote>
<p><strong>Вопрос 51:</strong></p>
<blockquote><code>class a { void f(); };</code> <br /> &nbsp; <br /> тип указателя this в методе f() выберите
	один или несколько ответов:
	<ul>
		<li>a. const a*</li>
		<li>b. a*</li>
		<li>c. a* const</li>
		<li>d. void*</li>
	</ul>
</blockquote>
<p><strong>Вопрос 52:</strong></p>
<blockquote>Понятия, связанные с rtti: <br /> выберите один или несколько ответов:
	<ul>
		<li>a. класс exception</li>
		<li>b. оператор static_cast</li>
		<li>c. оператор typeid</li>
		<li>d. оператор dynamic_cast</li>
		<li>e. класс type_info</li>
	</ul>
</blockquote>
<p><strong>Вопрос 53:</strong></p>
<blockquote><code>class a {</code><br /><code> void f(); </code><br /><code> };</code> <br /> &nbsp; <br /> тип
	указателя this в методе f() <br /> выберите один или несколько ответов:
	<ul>
		<li>a. const a*</li>
		<li>b. a*</li>
		<li>c. a* const</li>
		<li>d. void*</li>
	</ul>
</blockquote>
<p><strong>Вопрос 54:</strong></p>
<blockquote>Какие из утверждений верны? <br /> выберите один или несколько ответов:
	<ul>
		<li>a. move operator= может автоматически генерируется компилятором</li>
		<li>b. move operator= вызывается компилятором, если справа временный объект</li>
		<li>c. move operator= &nbsp;может повысить эффективность</li>
		<li>d. move operator= всегда автоматически генерируется компилятором</li>
	</ul>
</blockquote>
<p><strong>Вопрос 55:</strong></p>
<blockquote><code>vector&lt;vector&lt;int&gt;&gt; v(10, vector&lt;int&gt;(10,1));</code>
	<br /> отметьте корректные варианты получения значений элементов <br /> выберите один или несколько ответов:
	<ul>
		<li>a. int x = v.at(1).at(1);</li>
		<li>b. vector&lt;vector&lt;int&gt;&gt;::iterator it = v.begin(); int x = *(it + 1);</li>
		<li>c. int x = v[1][1];</li>
		<li>d. int x = v.at(1)[1];</li>
		<li>e. int x = v[1].at(1); <br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 56:</strong></p>
<blockquote>Объекты класса &nbsp; <strong>type_info</strong> &nbsp; можно: <br /> выберите один или несколько
	ответов:
	<ul>
		<li>a. копировать</li>
		<li>b. модифицировать</li>
		<li>c. создавать</li>
		<li>d. сравнивать</li>
	</ul>
</blockquote>
<p><strong>Вопрос 57:</strong></p>
<blockquote><br /> в каких вариантах компилятор не выдаст ошибку? <br /> выберите один или несколько ответов:
	<ul>
		<li>a.
			<code>class a { &nbsp;}; </code><br /><code> class b : private a { &nbsp;}; </code><br /><code> int main() </code><br /><code> { </code><br /><code> a* p = new b; </code><br /><code> }</code>
		</li>
		<li>b.
			<code>class a { }; </code><br /><code> class b : public a { &nbsp;}; </code><br /><code> int main() </code><br /><code> { </code><br /><code> a* p = new b; </code><br /><code> }</code>
		</li>
		<li>c.
			<code>class a { &nbsp;virtual void f(); &nbsp;}; </code><br /><code> class b : public a { &nbsp;}; </code><br /><code> int main() </code><br /><code> { </code><br /><code> &nbsp;a* p1 = new b; </code><br /><code> &nbsp;b* p2 = dynamic_cast&lt;b*&gt;(p1); </code><br /><code> }</code>
		</li>
		<li>d.
			<code>class a { &nbsp;virtual void f(); }; </code><br /><code> class b : public a { }; </code><br /><code> int main() </code><br /><code> { </code><br /><code> &nbsp;a* p1 = new a; </code><br /><code> &nbsp;b* p2 = dynamic_cast&lt;b*&gt;(p1); </code><br /><code> }</code>
		</li>
		<li>e.
			<code>class a { &nbsp;}; </code><br /><code> class b : public a { &nbsp;}; </code><br /><code> int main() </code><br /><code> { </code><br /><code> b* p = new a; </code><br /><code> }</code>
			<br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 58:</strong></p>
<blockquote><code>class a { }; a a; void func() { }</code>
	<br /> когда будет вызван деструктор? <br /> выберите один ответ:
	<ul>
		<li>a. при завершении приложения</li>
		<li>b. никогда</li>
		<li>c. при завершении функции</li>
	</ul>
</blockquote>
<p><strong>Вопрос 59:</strong></p>
<blockquote>Выберите один или несколько ответов:
	<ul>
		<li>a. не существует ограничений на тип возвращаемого перегруженным оператором значения</li>
		<li>b. нельзя менять число операндов оператора</li>
		<li>c. оператор, перегруженный методом класса, может быть чисто виртуальным</li>
	</ul>
</blockquote>
<p><strong>Вопрос 60:</strong></p>
<blockquote>Когда вызывается деструктор для объекта-исключения? <br /> выберите один или несколько ответов:
	<ul>
		<li>a. по закрывающей фигурной скобке блока try</li>
		<li>b. по закрывающей фигурной скобке обработчика catch</li>
		<li>c. по закрывающей фигурной скобке блока, в котором находится оператор throw</li>
		<li>d. при завершении приложения <br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 61:</strong></p>
<blockquote>
	<code>class a { ... }; </code><br /><code> a a; </code><br /><code> void func() </code><br /><code> { </code><br /><code> &hellip; </code><br /><code> }</code>
	<br /> когда будет вызван деструктор? <br /> выберите один ответ:
	<ul>
		<li>a. при завершении приложения</li>
		<li>b. никогда</li>
		<li>c. при завершении функции <br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 62:</strong></p>
<blockquote>В контейнерах stl выберите один ответ:
	<ul>
		<li>a. совмещены операции захвата памяти и инициализации</li>
		<li>b. осуществляется захват &laquo;сырой&raquo; (неинициализированной) памяти, а вызов конструктора происходит
			только при реальном добавлении элемента в контейнер <br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 63:</strong></p>
<blockquote>
	<code>class a { </code><br /><code> int x; </code><br /><code> protected: </code><br /><code> int y; </code><br /><code> public: </code><br /><code> void f(); </code><br /><code> &hellip; </code><br /><code> }; </code><br /><code> class b : public a {&hellip;};</code>
	<br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li>a. void func(b&amp; b) { b.y = 1; }</li>
		<li>b. void func(b&amp; b) { b.f(); }</li>
		<li>c. void func(b&amp; b) { b.x = 1; } <br /><br /></li>
	</ul>
</blockquote>
<p><strong>Вопрос 64:</strong></p>
<blockquote>
	<code>class a { </code><br /><code> int m_a; </code><br /><code> public: </code><br /><code> a operator=(const a&amp;); </code><br /><code> };</code>
	<br /> в каких примерах можно использовать реализованный оператор присваивания <br /> выберите один или несколько
	ответов:
	<ul>
		<li>a. <code>a a1(1), a2(2), a3; </code><br /><code> a3 = a2 = a1;</code></li>
		<li>b. <code>a a1(1), a2(2); </code><br /><code> a2 = a1;</code></li>
	</ul>
</blockquote>
<p><strong>Вопрос 65:</strong></p>
<blockquote>Выберите один или несколько ответов:
	<ul>
		<li>a.
			<code>void func(const a&amp;); </code><br /><code> void anotherfunc() { </code><br /><code> a a; </code><br /><code> func(a); </code><br /><code> }</code>
		</li>
		<li>b.
			<code>void func(a&amp;); </code><br /><code> void anotherfunc() { </code><br /><code> const a a; </code><br /><code> func(a); </code><br /><code> }</code>
		</li>
		<li>c.
			<code>void func(const a&amp;); </code><br /><code> void anotherfunc() {</code><br /><code> func(a()); </code><br /><code> }</code>
		</li>
	</ul>
</blockquote>
<p><strong>Вопрос 66:</strong></p>
<blockquote>Деструктор <br /> выберите один или несколько ответов:
	<ul>
		<li>a. вызывается компилятором неявно при уничтожении объекта</li>
		<li>b. деструкторов может быть несколько</li>
		<li>c. можно вызывать явно</li>
		<li>d. должен иметь предопределенное имя - destructor</li>
	</ul>
</blockquote>
<p><strong>Вопрос 67:</strong></p>
<blockquote>Какой из операторов присваивания &nbsp;более эффективен? <br /> выберите один ответ:
	<ul>
		<li>a.
			<code>class a { </code><br /><code> int m_a;</code><br /><code> public: </code><br /><code> a operator=(const a&amp;); </code><br /><code> };</code>
		</li>
		<li>b.
			<code>class a { </code><br /><code> int m_a;</code><br /><code> public: </code><br /><code> a&amp; operator=(const a&amp;); </code><br /><code> };</code>
		</li>
	</ul>
</blockquote>
<p><strong>Вопрос 68:</strong></p>
<blockquote>
	<code>class a { </code><br /><code> int m_a; </code><br /><code> public: </code><br /><code> a(int &nbsp;= 0); </code><br /><code> }; </code><br /><code> class b { </code><br /><code> int m_b; </code><br /><code> a m_a; </code><br /><code> public: </code><br /><code> b(const a&amp;, int b); </code><br /><code> };</code>
	<br /> отметьте корректные и эффективные варианты инициализации встроенного объекта <br /> выберите один или
	несколько ответов:
	<ul>
		<li>a. <code>b::b(const a&amp; ra, int b): m_a(ra) { </code><br /><code> }</code></li>
		<li>b.<code> b::b(const a&amp; ra, int b): m_a(ra.m_a) { </code><br /><code>}</code></li>
		<li>c.
			<code>b::b(const a&amp; ra, int b) { </code><br /><code> &nbsp; &nbsp;m_a = ra;</code><br /><code> }</code>
		</li>
	</ul>
</blockquote>
<p><strong>Вопрос 69:</strong></p>
<blockquote>В качестве базового контейнера для<strong> std::priority_queue</strong> можно использовать: <br />
	выберите один или несколько ответов:
	<ul>
		<li>a. std::list</li>
		<li>b. std::deque</li>
		<li>c. std::vector</li>
	</ul>
</blockquote>
<p><strong>Вопрос 70:</strong></p>
<blockquote>Выберите один или несколько ответов:
	<ul>
		<li>a. &nbsp;<code>try { </code><br /><code> } </code><br /><code> catch(int n) {}</code></li>
		<li>b.<code> try {</code><br /><code> } </code><br /><code> catch(int) &nbsp;{ &nbsp;}</code></li>
		<li>c.<code> try {</code><br /><code> } </code><br /><code> catch() {}</code></li>
		<li>d.<code> try { </code><br /><code> } </code><br /><code> catch() &nbsp;{ &nbsp;}</code></li>
	</ul>
</blockquote>
<p><strong>Вопрос 71:</strong></p>
<blockquote><br /> отметьте правильные варианты создания объектов <br /> выберите один или несколько ответов:
	<ul>
		<li>a. <code>vector&lt;int&gt; v(10,33); list&lt;int&gt; l(v.begin(), v.end());</code></li>
		<li>b. <code>vector&lt;int&gt; v(10,33); list&lt;int&gt; l(v);</code></li>
		<li>c. <code>list&lt;int&gt; l(10,33);</code></li>
		<li>d. <code>list&lt;int&gt; l();</code></li>
	</ul>
</blockquote>
<p><strong>Вопрос 73:</strong></p>
<blockquote>Выберите один или несколько ответов:
	<ul>
		<li>a.
			&nbsp;<code>try { </code><br /><code> ... </code><br /><code> } </code><br /><code> catch(int n) {...}</code>
		</li>
		<li>b.
			<code>try { </code><br /><code> ... </code><br /><code> } </code><br /><code> catch(int) &nbsp;{ ... }</code>
		</li>
		<li><code>c. try {</code> <br /> ... <br /> } <br /> catch() {...}</li>
		<li>d.
			<code>try { </code><br /><code> ... </code><br /><code> } </code><br /><code> catch(...) &nbsp;{ ... }</code>
		</li>
	</ul>
</blockquote>
<p><strong>Вопрос 74:</strong></p>
<blockquote>Диапазон изменения данных от (-2) до (+1). Какое из битовых полей удовлетворяет условию?
	<br /> выберите один ответ:
	<ul>
		<li>a.<code> class a { </code><br /><code> unsigned char x:2; </code><br /><code> &hellip; </code><br /><code> };</code>
		</li>
		<li>b. <code>class a { </code><br /><code> char x:1; </code><br /><code> &hellip; </code><br /><code> };</code>
		</li>
		<li>c. <code>class a { </code><br /><code> char x:2; </code><br /><code> &hellip; </code><br /><code> };</code>
		</li>
	</ul>
</blockquote>
<p><strong>Вопрос 75:</strong></p>
<blockquote>
	<code>class a { </code><br /><code> &hellip; </code><br /><code> void f() const; </code><br /><code> };</code>
	<br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li>a. void a::f() const <br /> { <br /> &hellip; <br /> }</li>
		<li>b. void a::f() <br /> { <br /> &hellip; <br /> }</li>
	</ul>
</blockquote>
<p><strong>Вопрос 76:</strong></p>
<blockquote>
	<code>vector&lt;int&gt; v(10,1); </code><br /><code> vector&lt;int&gt;::iterator it = v.begin();</code> <br />
	&nbsp; <br /> отметьте корректные варианты получения значений элементов <br /> выберите один или несколько ответов:
	<ul>
		<li>a. int x = *(it + 5);</li>
		<li>b. int x = *it;</li>
		<li>c. int x = *(v.end());</li>
	</ul>
</blockquote>
<p><strong>Вопрос 77:</strong></p>
<blockquote>
	<code>class a { ... &nbsp;virtual void f(); ... }; </code><br /><code> class b : public a { ... }; </code><br /><code> &nbsp; </code><br /><code> int main() { </code><br /><code> a* pa = new b; </code><br /><code> bool b = typeid(*pa).before(typeid(b)); </code><br /><code> } </code><br /><code> &nbsp;</code>
	<br /> значение переменной "b&rdquo;: <br /> выберите один ответ:
	<ul>
		<li>a. true</li>
		<li>b. false</li>
	</ul>
</blockquote>
<p><strong>Вопрос 78:</strong></p>
<blockquote>
	<code>a.h </code><br /><code> class a { ... </code><br /><code> public: </code><br /><code> explicit a(int = 0); </code><br /><code> };</code>
	<br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li>a. int n = 1;a a = n;</li>
		<li>b. a a;</li>
		<li>c. int n = 1; <br /> a a(n);</li>
		<li>d. int n = 1; <br /> a* pa = new a(n);</li>
	</ul>
</blockquote>
<p><strong>Вопрос 79:</strong></p>
<blockquote><br /> выберите один или несколько ответов:
	<ul>
		<li>a.
			<code>class a { &hellip; </code><br /><code> void f(); </code><br /><code> void f(int = 0); </code><br /><code> };</code>
		</li>
		<li>b.
			<code>class a { &hellip; </code><br /><code> void f(); </code><br /><code> void f()const; </code><br /><code> };</code>
		</li>
		<li>c.
			<code>class a { &hellip; </code><br /><code> void f(); </code><br /><code> int f(); </code><br /><code> };</code>
		</li>
		<li>d.
			<code>class a { &hellip; </code><br /><code> void f(); </code><br /><code> void f(int); </code><br /><code> };</code>
		</li>
	</ul>
</blockquote>
<p><strong>Вопрос 80:</strong></p>
<blockquote>Дано:
<br /><code>class a { ... }; a a1, a2;</code></blockquote>
<br /> для выражения a1 + &nbsp;a2 выберите один или несколько ответов:
<ul>
<li>a. программист должен предоставить компилятору функцию с произвольным именем, например, &ldquo;f+&rdquo;</li>
<li>b. компилятор по контексту использования генерирует код сам</li>
<li>c. программист должен предоставить компилятору функцию с предопределенным именем <br /><br /></li>
</ul>
</blockquote>
<p><strong>Вопрос 81:</strong></p>
<blockquote><br /><br />
	<code>class a { &lt;простой&gt; }; </code><br /><code> class b: &nbsp;public a { &lt;сложный&gt; };</code> <br />
	&nbsp; <br /> Отметьте корректные утверждения <br /> выберите один или несколько ответов:
	<ul>
		<li>a. компилятор всегда автоматически вызывает оператор присваивания базового класса</li>
		<li>b. требуется реализовать оператор присваивания в классе b</li>
		<li>c. требуется обеспечить вызов оператора присваивания базового класса a при реализации оператора присваивания
			производного класса b</li>
		<li>d. требуется реализовать оператор присваивания в классе a</li>
	</ul>
</blockquote>
<p><strong>Вопрос 82:</strong></p>
<blockquote>Какие из спецификаторов доступа позволяет вызывать методы базового класса в методах производного класса. Выберите один или несколько ответов:
	<ul>
		<li>a. private</li>
		<li>b. protected</li>
		<li>c. public</li>
	</ul>
</blockquote>
<p><strong>Вопрос 83:</strong></p>
<blockquote><br />
	<code>class out { </code><br /><code> class in { ... </code><br /><code> in(); </code><br /><code> }; </code><br /><code> ... </code><br /><code> out(); </code><br /><code> };</code>
	<br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li>a. out::out() { ... }</li>
		<li>b. in::in() { ... }</li>
		<li>c. out::in() { ... }</li>
		<li>d. out::in::in() { ... }</li>
	</ul>
</blockquote>
<p><strong>Вопрос 84:</strong></p>
<blockquote>Метод <strong>push_front()</strong> реализован для выберите один или несколько ответов:
	<ul>
		<li>a. deque</li>
		<li>b. vector</li>
		<li>c. stack</li>
		<li>d. set</li>
	</ul>
</blockquote>
<p><strong>Вопрос 85:</strong></p>
<blockquote><br />
	<code>vector&lt;int&gt; v; </code><br /><code> v.reserve(10); </code><br /><code> v.push_back(33); </code><br /><code> size_t n = v.size();</code>
	<br /><br /><br /> значение переменной n?
</blockquote>
<p><strong>Вопрос 86:</strong></p>
<blockquote><br />
	<code>class x { </code><br /><code> int m_x; </code><br /><code> void fx(y&amp; y); </code><br /><code> friend void y::fy1(x&amp; x); </code><br /><code> }; </code><br /><code> class y{ </code><br /><code> int m_y; </code><br /><code> void fy1(x&amp; x); </code><br /><code> void fy2(x&amp; x); </code><br /><code> };</code>
	<br /> отметьте корректные варианты <br /> выберите один или несколько ответов:
	<ul>
		<li>a. void x::fx(y&amp; y) { y.m_y++; }</li>
		<li>b. void y::fy1(x&amp; x) { x.m_x++; }</li>
		<li>c. void y::fy2(x&amp; x) { x.m_x++; } <br /><br /></li>
	</ul>
</blockquote>

<p><strong>Вопрос 87:</strong></p>
<blockquote>Отметьте корректные варианты: выберете один или несколько ответов:
<ul>
<li>a) <code>&nbsp;try{ &nbsp;... &nbsp;} &nbsp;
catch(...) { &nbsp;
&lt;обработка всех типов исключительных ситуаций, &nbsp; кроме целочисленного исключения&gt;
}
catch (int n) {
&nbsp; &lt;обработка целочисленного исключения&gt;
&nbsp;}</code></li>
<li>b) <code>&nbsp; &nbsp;try{ &nbsp;... &nbsp;}
&nbsp;catch (int n) { &nbsp;
&lt;обработка целочисленного исключения&gt; &nbsp;
}
&nbsp;catch(...) { &nbsp;
&lt;обработка всех остальных исключительных ситуаций&gt;
&nbsp;}</code></li>
<li>c)<code> &nbsp;try{ &nbsp;... &nbsp;}
&nbsp;catch (int n) { &nbsp;
&lt;обработка целочисленного исключения&gt; &nbsp;
} &nbsp;
catch(double d) { &nbsp;
&lt;обработка исключения типа double&gt;
&nbsp;}</code></li>
<li>d) <code>&nbsp;try{ &nbsp;... &nbsp;}
&nbsp;catch(...) { &nbsp;
&lt;обработка любой исключительной ситуации&gt; &nbsp;
}</code></li>
</ul>
</blockquote>


<p><strong>Вопрос 88:</strong></p>
<blockquote><br /> отметьте корректные варианты: выберете один или несколько ответов:
	<ul>
		<li>a)
			<code>&nbsp;try{ &nbsp;... &nbsp;} &nbsp;catch(...) { &nbsp; &lt;обработка всех типов исключительных ситуаций, &nbsp; кроме целочисленного исключения&gt; &nbsp;} &nbsp;catch (int n) { &nbsp; &lt;обработка целочисленного исключения&gt; &nbsp;}</code>
		</li>
		<li>b)
			<code>&nbsp; &nbsp;try{ &nbsp;... &nbsp;} &nbsp;catch (int n) { &nbsp; &lt;обработка целочисленного исключения&gt; &nbsp;} &nbsp;catch(...) { &nbsp; &lt;обработка всех остальных исключительных ситуаций&gt; &nbsp;}</code>
		</li>
		<li>c)
			<code>&nbsp;try{ &nbsp;... &nbsp;} &nbsp;catch (int n) { &nbsp; &lt;обработка целочисленного исключения&gt; &nbsp;} &nbsp;catch(double d) { &nbsp; &lt;обработка исключения типа double&gt; &nbsp;}&nbsp;</code>
		</li>
		<li>d)
			<code>&nbsp;try{ &nbsp;... &nbsp;} &nbsp;catch(...) { &nbsp; &lt;обработка любой исключительной ситуации&gt; &nbsp;}</code>
		</li>
		<li>e) <code>&nbsp; &nbsp;try{ &nbsp;... &nbsp;} &nbsp;&lt;продолжение выполнения кода&gt; </code></li>
	</ul>

</blockquote>
<p><strong>Вопрос 89:</strong></p>
<blockquote>отличие классов от структур языка си выберете один или несколько ответов:
	<ul>
		<li>a) структура си может содержать как данные, так и методы</li>
		<li>b) класс может содержать как данные, так и методы</li>
		<li>c) класс может содержать только методы</li>
		<li>d) класс может содержать только данные</li>
		<li>e) структура си должна содержать только данные</li>
	</ul>

</blockquote>
<p><strong>Вопрос 90:</strong></p>
<blockquote>отметьте корректные высказывания:
	<ul>
		<li>a) операции вставки/удаления значений в вписок осуществляются &nbsp;эффективнее чем в вектор</li>
		<li>b) данные в списке располагаются последовательно в памяти</li>
	</ul>
</blockquote>
<p><strong>Вопрос 91:</strong></p>
<blockquote>куда происходит передача управления при выполнении оператора throw? выберете один или несколько ответов:
	<ul>
		<li>a) на открывающую фигурную скобку обработчика catch(int)</li>
		<li>b) на закрывающую фигурную скобку блока, в котором находится &nbsp; &nbsp;оператор throw</li>
		<li>c) на закрывающую фигурную скобку функции, в которой находится оператор throw</li>
	</ul>
</blockquote>
<p><strong>Вопрос 92:</strong></p>
<blockquote>куда происходит передача управления при выполнении оператора throw 1? выберете один или несколько ответов:
	<ul>
		<li>a) на открывающую фигурную скобку обработчика catch(int)</li>
		<li>b) на закрывающую фигурную скобку блока, в котором находится &nbsp; &nbsp;оператор throw</li>
		<li>c) на закрывающую фигурную скобку функции, в которой находится оператор throw</li>
	</ul>
</blockquote>
<p><strong>Вопрос 93:</strong></p>
<blockquote>
	<code>class a 
	{ &nbsp;int m_a; public: &nbsp;a(int); &nbsp;void f(); }; class b public a { &nbsp;int m_b; public: &nbsp;b(int,int); &nbsp;virtual void f(); }; class c public b { &nbsp;int m_c; public: &nbsp;c(int,int,int); };</code>
	для каких классов компилятор сформирует таблицу виртуальных функций выберете один или несколько ответов:
	<ul>
		<li>a) c</li>
		<li>b) a</li>
		<li>c) b</li>
	</ul>
