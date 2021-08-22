//Реализуйте шаблонную функцию Sqr, которая работает не только для чисел, но и для контейнеров. Функция должна 
//возвращать копию исходного контейнера, модифицировав его следующим образом :
// - для vector элементы нужно возвести в квадрат;
// - для map в квадрат нужно возвести только значения, но не ключи;
// - для pair в квадрат нужно возвести каждый элемент пары.

/*
// Пример вызова функции
vector<int> v = { 1, 2, 3 };
cout << "vector:";
for (int x : Sqr(v)) {
	cout << ' ' << x;
}
cout << endl;

map<int, pair<int, int>> map_of_pairs = {
  {4, {2, 2}},
*/

//Код выше должен вывести
//vector: 1 4 9
//map of pairs :
//4 4 4
//7 16 9
// 
//Функция должна корректно работать не только для контейнеров, состоящих из чисел, но и для составных объектов, 
//например, векторов словарей пар чисел.
//
//Для успешной сдачи решения необходимо сделать предварительное объявление шаблонных функций перед всеми шаблонными функциями.
//
//Пример предварительного объявления шаблонной функции:

//// Предварительное объявление шаблонных функций
//template<typename T> T FuncA(T x);
//template<typename T> void FuncB(T x);
//
//// Объявляем шаблонные функции
//template <typename T>
//T FuncA(T x) { /*...*/ }
//
//template <typename T>
//void FuncB(T x) { /*...*/ }

#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T> T Sqr(const T& x);
template <typename T_ItemVector> vector<T_ItemVector> Sqr(vector<T_ItemVector> v);
template <typename T_MapFirst, typename T_MapSecond> map<T_MapFirst, T_MapSecond> Sqr(map<T_MapFirst, T_MapSecond> m);
template <typename T_PairFirst, typename T_PairSecond> pair<T_PairFirst, T_PairSecond> Sqr(pair<T_PairFirst, T_PairSecond> p);

template <typename T>
T Sqr(const T& x)
{
	return x * x;
}

template<typename T_ItemVector>
vector<T_ItemVector> Sqr(vector<T_ItemVector> v)
{
	for (auto& item : v)
		item = Sqr(item);

	return v;
}

template<typename T_MapFirst, typename T_MapSecond>
map<T_MapFirst, T_MapSecond> Sqr(map<T_MapFirst, T_MapSecond> m)
{
	for (auto& [key, value] : m)
		value = Sqr(value);

	return m;
}

template <typename T_PairFirst, typename T_PairSecond> 
pair<T_PairFirst, T_PairSecond> Sqr(pair<T_PairFirst, T_PairSecond> p)
{
	p.first = Sqr(p.first);
	p.second = Sqr(p.second);
	
	return p;
}

int main()
{
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}