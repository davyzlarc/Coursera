//Напишите функцию PrintVectorPart, принимающую вектор целых чисел numbers, выполняющую поиск первого
//отрицательного числа в нём и выводящую в стандартный вывод все числа, расположенные левее 
//найденного, в обратном порядке.Если вектор не содержит отрицательных чисел, выведите все числа 
//в обратном порядке.
//
//void PrintVectorPart(const vector<int>&numbers);
// 
//Пример кода:
//int main() {
//	PrintVectorPart({ 6, 1, 8, -5, 4 });
//	cout << endl;
//	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
//	cout << endl;
//	PrintVectorPart({ 6, 1, 8, 5, 4 });
//	cout << endl;
//	return 0;
//}
//
//Вывод:
//8 1 6
//
//4 5 8 1 6

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void PrintVectorPart(const vector<int>& numbers)
{
	auto pivot = find_if(numbers.begin(), numbers.end(), [](const int& i) {return i < 0; });

	for (auto it = pivot; it != numbers.begin();)
		cout << *(--it) << " ";
}

int main()
{
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}