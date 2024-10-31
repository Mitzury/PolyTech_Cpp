//Ïðàêòèêà 1:
// enum class
// initializer_list è óíèâåðñàëüíûå ñïèñêè èíèöèàëèçàöèè
// auto
// decltype
// lambda 
// template variable


#include "T.h"
#include <deque>

using namespace std;

int main() {
setlocale(LC_ALL, "Russian");
#if 1
	//Çàäàíèå 1. 
	{
		std::cout << "Chapter 1: " << std::endl;
		enum class months:unsigned char { January, February, March/*...*/ };
		enum class weekDays { Monday, Tuesday /*...*/ };

		//months m = January;
		а) Устраните проблемы (это означает, что КОМПИЛЯТОР не должен позволять программисту осуществлять опасные сравнения!)
		months m = months::January;
		//if (m == Monday) { cout << 1; }
		//á) îïòèìèçèðóéòå èñïîëüçîâàíèå ïàìÿòè
		months year[] = { months::January, months::February, months::March };
		size_t n = sizeof(year); // int 12 char (3)
		std::cout << "Size of year array: " << n << " bytes" << std::endl;
		std::cout << "Size of year array: " << sizeof(year) << " bytes" << std::endl; 
	}
#endif
#if 1
	/**********************************************************/
		//Çàäàíèå 2. Ñîçäàéòå è ñ ïîìîùüþ ñïèñêà èíèöèàëèçàöèè
		//çàïîëíèòå çíà÷åíèÿìè âåêòîð ñ ýëåìåíòàìè - string
		//Ñ ïîìîùüþ range-based for ïðåîáðàçóéòå âñå áóêâû â 	
		//âåðõíèé ðåãèñòð à îñòàëüíûå ñèìâîëû äîëæíû îñòàòüñÿ
		//íåèçìåííûìè
	{
		std::cout << "\nChapter 2: " << std::endl;
		std::vector<string> words = { "hello", "world" };
		for (auto& word : words) {
			//std::transform(word.begin(), word.end(), word.begin(), ::toupper);
			for (auto& str : word) {
				str = toupper(str);
			}
		}
		PrintAnyCont(words);
	}
#endif
#if 1
	/**********************************************************/
		///Çàäàíèå 3. Ñîçäàéòå è çàïîëíèòå çíà÷åíèÿìè
		//map äâóìÿ ñïîñîáàìè (3à è 3á) òàêèì îáðàçîì, ÷òîáû îí ñîäåðæàë 
		//â êà÷åñòâå êëþ÷à áóêâó, à â êà÷åñòâå çíà÷åíèÿ 
		//îòñîðòèðîâàííóþ ïî àëôàâèòó ñîâîêóïíîñòü ñëîâ (string), 
		//íà÷èíàþùèõñÿ ñ ýòîé áóêâû

		//3à. Ïðîèíèöèàëèçèðóéòå map "âðó÷íóþ" ïîñðåäñòâîì ñïèñêà èíèöèàëèçàöèè
		//Ñ ïîìîùüþ range-based for è structured binding
		//ðàñïå÷àòàéòå ñîäåðæèìîå, íàïðèìåð: A: any, apple, away
	{
		std::cout << "\nChapter 3a: ";
		// Ñîçäàåì map ñ êëþ÷àìè òèïà char, è çíà÷åíèÿìè string
		std::map<char, set<string>> mapExample;

		mapExample['A'] = { "away", "apple", "any" };
		mapExample['B'] = { "ball", "banana", "brown" };
		mapExample['C'] = { "cat", "car", "city" };

		for (const auto& [key, value] : mapExample) {
			std::cout << endl << key << ": ";
			for (const auto& value : value) {
				std::cout << value << " ";
			}
		}
	}
	//3á. Ñîçäàéòå ïóñòîé map è èñïîëüçóéòå çàäàííûé ìàññèâ
	//äëÿ âûïîëíåíèÿ çàäàíèÿ.
	//Ñ ïîìîùüþ range-based for è structured binding
	//ðàñïå÷àòàéòå ñîäåðæèìîå, íàïðèìåð: A: any, apple, away
	{
		std::cout << "\nChapter 3b: ";
		std::map<char, set<string>> mapExample;
		//äàíî (íàïðèìåð):
		const char* s[] = { "yong", "away", "bar", "any", "son", "Apple", "Boris"};
		for (auto str : s) {
			mapExample[toupper(*str)].insert(str);
		}
		for (const auto& [key, value] : mapExample) {
			std::cout << endl << key << ": ";
			for (const auto& value : value) { 
				std::cout << value << ", ";
			}
		}
	}
#endif
#if 1
	/*********************************************************/
	//Çàäàíèå 4. ñîçäàòü ôóíêöèþ äëÿ âûâîäà íà ïå÷àòü
	//ýëåìåíòîâ ïîñëåäîâàòåëüíîñòåé, çàäàííûõ íèæå:
	{
		std::cout << "\nChapter 4: " << endl;
		std::vector<double> vd = { 1.1,2.2,3.3 };
		PrintAnyCont(vd);

		std::string s("abc");
		PrintAnyCont(s);

		int ar[] = { 1, 2, 3 };
		PrintAnyCont(ar);

		std::initializer_list<int> il{ 3,4,5 };
		PrintAnyCont(il);		
	}
#endif
#if 1
	/********************************************************/
	///Çàäàíèå 5. 	
	//Cîçäàòü ôóíêöèþ äëÿ "îòðèöàíèÿ" çíà÷åíèé, íàïðèìåð:
	//áûëî: {1, -2, 5}, ñòàëî: {-1, 2, -5})
	//èçìåíåíèå îáúåêòîâ òèïà std::string ìîæåò âûãëÿäåòü "aBc1" -> "AbC1"
	//ýëåìåíòîâ ïîñëåäîâàòåëüíîñòåé, çàäàííûõ íèæå:
	{
		std::cout << "\nChapter 5: " << std::endl;
		std::vector<double> vd{ 1.1,2.2,3.3 };
		NegateAll(vd);
		PrintAnyCont(vd);
		std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
		NegateAll(ls);
		PrintAnyCont(ls);
		int ar[]{ 1, -2, 3, 10,-3 };
		NegateAll(ar);
		PrintAnyCont(ar);
	}
#endif
#if 1
	/********************************************************/
		//Çàäàíèå 6. Ðåàëèçîâàòü ôóíêöèþ ñîðòèðîâêè ïî ìîäóëþ
		//ýëåìåíòîâ ïîñëåäîâàòåëüíîñòåé, çàäàííûõ íèæå
		//Ñîáñòâåííî äëÿ ñîðòèðîâêè ìîæíî èñïîëüçîâàòü îáîáùåííûé
		//àëãîðèòì sort(), à äëÿ çàäàíèÿ óñëîâèÿ - ëÿìáäà-ôóíêöèþ
	{
		std::cout << "\nChapter 6: " << std::endl;
		std::vector<double> vd = { -3.3,  2.2, -1.1 };
		std::cout << " Original vector" << std::endl; 
		PrintAnyCont(vd);
		absSort(vd);
		std::cout << " Sorted vector" << std::endl;
		PrintAnyCont(vd);
		std::cout << " Original Arr" << std::endl;
		int ar[] = { -3, 2, -1 };
		PrintAnyCont(ar);
		absSort(ar);
		std::cout << " Sorted Arr" << std::endl;
		PrintAnyCont(ar);
	}
#endif
#if 1
	/********************************************************/
		//Çàäàíèå 7.
		//Íàïèøèòå ôóíêöèþ, êîòîðàÿ áóäåò ôîðìèðîâàòü è
		//âîçâðàùàòü âåêòîð, êàæäûé ýëåìåíò 
		//êîòîðîãî ÿâëÿåòñÿ ñóììîé ýëåìåíòîâ äâóõ 
		//ïîñëåäîâàòåëüíîñòåé ÐÀÇÍÎÉ äëèíû
		//è ñ ýëåìåíòàìè ÐÀÇÍÎÃÎ òèïà.

		//Ïîäñêàçêà 1: òàê êàê ïîñëåäîâàòåëüíîñòè ìîãóò áûòü
		//ðàçíîé äëèíû, ëîãè÷íî ñäåëàòü ðàçìåð ðåçóëüòèðóþùåãî
		//âåêòîðà ìàêñèìàëüíûì èç äâóõ

		//Ïîäñêàçêà 2: ïîäóìàéòå î âîçìîæíîñòè èñïîëüçîâàíèÿ
		//àëãîðèòìîâ copy() è transform(), â êîòîðîì 
		//òðàíñôîðìèðóþùåå äåéñòâèå óäîáíî â ñâîþ î÷åðåäü
		//çàäàâàòü ëÿìáäà-ôóíêöèåé
		//íàïðèìåð:
	{
		std::cout << "\nChapter 7: " << std::endl;
		std::vector<int> v{ 1,2,3,4 };
		std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5 };

		auto summed1 = sumContainers(v, l);
		PrintAnyCont(summed1);
		
		std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
		double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		auto summed2 = sumContainers(ll, ar); 
		PrintAnyCont(summed2);

		std::set<std::string> s{ "abc", "qwerty", "my" };
		std::deque<const char*> d{ "111", "22" };
		auto summed3 = sumContainers(s, d);
		PrintAnyCont(summed3);

	}
#endif
#if 1
	/********************************************************/
		//Çàäàíèå 8. Ðåàëèçóéòå ôóíêöèþ, êîòîðàÿ ïðèíèìàåò ñëåäóþùèå ïàðàìåòðû:	
		//ñôîðìèðîâàííóþ ïîñëåäîâàòåëüíîñòü ëþáîãî òèïà ñ ýëåìåíòàìè ëþáîãî òèïà, 
		//äâà (ïóñòûõ) êîíòåéíåðà ëþáîãî òèïà èç vector, list, deque, set 
		//ñ ýëåìåíòàìè òîãî æå òèïà, ÷òî è ó ñôîðìèðîâàííîé ïîñëåäîâàòåëüíîñòè 
		//Ôóíêöèÿ äîëæíà "ðàçëîæèòü" çíà÷åíèÿ çàäàííîé ïîñëåäîâàòåëüíîñòè â äâà ïóñòûõ êîíòåéíåðà 
		//ñîãëàñíî çàäàííîìó óñëîâèþ. Óñëîâèå çàäàòü ëÿìáäà-ôóíêöèåé
		//Èñõîäíàÿ ïîñëåäîâàòåëüíîñòü ïðè ýòîì íå ìåíÿåòñÿ
	{
		//Íàïðèìåð 1:
		std::cout << "\nChapter 8.1: " << std::endl;
		std::vector<int> values{ 1,2,3,4,5 };
		std::cout << " Original vector: " << std::endl;
		PrintAnyCont(values);
		std::list<int> evens; //ñþäà ÷åòíûå
		std::deque<int> odds; //à ñþäà íå÷åòíûå

		// Ðàçäåëåíèå çíà÷åíèé íà ÷åòíûå è íå÷åòíûå ñ èñïîëüçîâàíèåì ëÿìáäà-ôóíêöèè
		Separate(values, evens, odds, [](int x) { return x % 2 == 0; });
		std::cout << "×¸òíûå: ";
		for (int val : evens) {
			std::cout << val << " ";
		}
		std::cout << "\nÍå÷¸òíûå: ";
		for (int val : odds) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
	{
		std::cout << "\nChapter 8.2: " << std::endl;
		//2. Ðàçëîæèòü ñîãëàñíî óñëîâèþ: òå çíà÷åíèÿ, êîòîðûå ïîïàäàþò â çàäàííûé äèàïàçîí, 
		// â îäèí êîíòåéíåð, îñòàëüíûå - â äðóãîé
		double values[] = { 0.8, 1.1, 33.3, -4.1, 5.5 };
		std::set<double> s; //ñþäà òå, êîòîðûå ïîïàäàþò â [0,6]
		std::vector<double> v; //ñþäà îñòàëüíûå
		int start = 0, end = 6;
		std::cout << " Original: " << std::endl;
		PrintAnyCont(values);

		Separate(values, s, v, [start, end](const auto a) {return a >= start && a <= end; });
		std::cout << " in diap " << std::endl;
		PrintAnyCont(s);
		std::cout << " out diap " << std::endl;
		PrintAnyCont(v);

	}
#endif
#if 1
	/********************************************************/
		//Çàäàíèå 9. C ïîìîùüþ àëãîðèòìà for_each()!!! 
		//(à íå count_if()) ïîñ÷èòàòü ñêîëüêî áóêâ â âåðõíåì
		//ðåãèñòðå.
		//  Èñïîëüçîâàòü ëÿìáäà ôóíêöèþ
	{
		std::cout << "Chapter 9: " << std::endl;
		char s[] = "Hello World!";
		PrintAnyCont(s);
		std::cout << "Count Upper case: " << countUppercase(s) << std::endl;
	}
#endif
#if 1
	/********************************************************/
		//Çàäàíèå 10. Ðåàëèçîâàòü êîíâåðòàöèþ enum â ñòðîêîâîå ïðåäñòàâëåíèå  - enumToString
		// è íàîáîðîò - stringToEnum
		//Ïîäñêàçêè: 
		//***********
		//1. Ñîîòâåòñòâóþùèå èìåíîâàííûì êîíñòàíòàì ñòðîêè âñå ðàâíî íóæíî ãäå-òî õðàíèòü =>
		//1.1 Èìåíîâàííûå êîíñòàíòû â ïåðå÷èñëåíèè äîëæíû áûòü óíèêàëüíûìè => ñîîòâåòñòâóþùèå ñòðîêè
		//òîæå äîëæíû áûòü óíèêàëüíûìè, => óíèêàëüíûå ñòðîêè ìîãóò áûòü èñïîëüçîâàíû â êà÷åñòâå
		//êëþ÷à â std::map
		//1.2 à âîò çíà÷åíèÿ (ñîîòâåòñòâóþùèå èìåíîâàíûì êîíñòàíòàì)
		//ìîãóò áûòü ëþáûìè è äàæå ìîãóò ïîâòîðÿòüñÿ (óïðîùàåì çàäà÷ó, ñ÷èòàÿ, ÷òî çíà÷åíèÿ ÍÅ ïîâòîðÿþòñÿ) 
		//=> ïîäõîäèò êîíòåéíåð std::map<string,<çíà÷åíèå> >
		//1.3 Ñîãëàñíî ñòàíäàðòó Ñ++11 ïåðåìåííûå ïåðå÷èñëèìîãî òèïà ìîãóò áûòü ðàçíîãî ðàçìåðà è òèïà,
		//à õîòåëîñü áû îáåñïå÷èòü óíèâåðñàëüíóþ êîíâåðòàöèþ 
		//***********
		//2.1 Òàê êàê òèïû ïåðå÷èñëåíèé ðàçíûå, òî enumToString è stringToEnum äîëæíû áûòü øàáëîííûìè
		//2.2 Ïîëüçîâàòåëü ìîæåò îøèáèòüñÿ èëè çëîíàìåðåííî ïåðåäàòü â ôóíêöèè çíà÷åíèÿ, êîòîðûì
		//   íè÷åãî íå ñîîòâåòñòâóåò => çàùèòà!
		//***********
		//3. ×òîáû äåéñòâèÿ ñ map<string, <çíà÷åíèå> > íå çàâèñèëè îò òèïà ïåðå÷èñëåíèÿ, ïîäóìàéòå íàä èñïîëüçîâàíèåì
		//øàáëîííîé ïåðåìåííîé (â ÷àñòíîñòè âñïîìíèòå î âîçìîæíîñòè ñïåöèÿëèçàöèè øàáëîííîé ïåðåìåííîé)
		//***********
	{
		std::cout << "\nChapter 10: " << std::endl;
		Color color;

		try {
			color = stringToEnum<Color>("blue");
			std::cout << "Ñòðîêà â enum: " << enumToString(color) << std::endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
		auto Str = enumToString(color);
		std::cout << "Enum â ñòðîêó: " << Str << std::endl;

	}
#endif
	return 0;
}
