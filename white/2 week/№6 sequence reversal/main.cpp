//Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.
//
//Пример
//vector<int> numbers = { 1, 5, 3, 4, 2 };
//Reverse(numbers); /*numbers должен оказаться равен {2, 4, 3, 5, 1}*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(vector<int>& v)
{
    size_t n = v.size();  
    for (int i = 0; i < n / 2; ++i) 
    {
        int tmp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = tmp;
    }
}

int main()
{
	return 0;
}