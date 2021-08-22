//Реализуйте шаблонную функцию GetRefStrict, которая на вход принимает : map и значение ключа k. Если 
//элемент по ключу k в коллекции отсутствует, то функция должна бросить исключение runtime_error,
//иначе вернуть ссылку на элемент в коллекции.
//
//Пример использования функции:

/*
map<int, string> m = {{0, "value"}};
string& item = GetRefStrict(m, 0);
item = "newvalue";
cout << m[0] << endl; // выведет newvalue
*/

#include <iostream>
#include <map>

using namespace std;

template <typename T_MapKey, typename T_MapValue> T_MapValue& GetRefStrict(const map<T_MapKey, T_MapValue>& m, const T_MapKey& key);

template<typename T_MapKey, typename T_MapValue>
T_MapValue& GetRefStrict(map<T_MapKey, T_MapValue>& m, const T_MapKey& key)
{
	if (m.count(key) == 0)
		throw runtime_error("");
	return m.at(key);
}

int main()
{
	map<int, string> m = { {0, "value"} };
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
	return 0;
}
