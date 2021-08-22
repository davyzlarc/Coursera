//Имеется база регионов, представленная вектором структур Region:

//struct Region {
//    string std_name;
//    string parent_std_name;
//    map<Lang, string> names;
//    int64_t population;
//};

//Здесь Lang — идентификатор языка:

//enum class Lang {
//    DE, FR, IT
//};

//Напишите функцию FindMaxRepetitionCount, принимающую базу регионов и определяющую, какое максимальное количество 
//повторов(число вхождений одного и того же элемента) она содержит.Две записи(объекты типа Region) считаются
//различными, если они отличаются хотя бы одним полем.

//int FindMaxRepetitionCount(const vector<Region>&regions);

//Если все записи уникальны, считайте максимальное количество повторов равным 1. Если записи отсутствуют, верните 0.
//Гарантируется, что типа int достаточно для хранения ответа.
//
//Пример кода:

//int main() {
//    cout << FindMaxRepetitionCount({
//        {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Russia",
//            "Eurasia",
//            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//            89
//        }, {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Russia",
//            "Eurasia",
//            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//            89
//        },
//        }) << endl;
//
//    cout << FindMaxRepetitionCount({
//        {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Russia",
//            "Eurasia",
//            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//            89
//        }, {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Moscow",
//            "Toulouse",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            89
//        }, {
//            "Moscow",
//            "Russia",
//            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//            31
//        },
//        }) << endl;
//
//    return 0;
//}

//Вывод:
//  3
//  1
// 
//Пояснение:
//В этой задаче вам надо прислать на проверку файл с реализацией функции FindMaxRepetitionCount, а также дополнительных
//функций, если это необходимо.Этот файл не должен содержать типы Lang и Region.В противном случае вы получите ошибку компиляции.

#include "struct.cpp"
#include <vector>
#include <set>
#include <tuple>

bool operator<(const Region& lhs, const Region& rhs) {
	auto lhs_key = tie(lhs.names, lhs.parent_std_name, lhs.population, lhs.std_name);
	auto rhs_key = tie(rhs.names, rhs.parent_std_name, rhs.population, rhs.std_name);
	return lhs_key < rhs_key;
}

bool operator==(const Region& lhs, const Region& rhs)
{
	auto lhs_key = tie(lhs.names, lhs.parent_std_name, lhs.population, lhs.std_name);
	auto rhs_key = tie(rhs.names, rhs.parent_std_name, rhs.population, rhs.std_name);
	return lhs_key == rhs_key;
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{

	/*if (regions.empty()) {
		return 0;
	}
	std::map<Region, int> m;
	for (const auto& r : regions) {
		++m[r];
	}
	int max_repeat = 0;
	for (const auto& i : m) {
		if (i.second > max_repeat) {
			max_repeat = i.second;
		}
	}
	return max_repeat;*/

	if (regions.size() == 0)
		return 0;
	else
	{
		int result=0;
		set <Region> unic_items;

		for (size_t i = 0; i < regions.size(); i++)
		{
			int buff_res = 1;
			Region item = regions.at(i);
			if (unic_items.count(item) == 0)
			{
				for (size_t j = i + 1; j < regions.size(); j++)
				{
					if (item == regions.at(j))
						buff_res++;
				}
				unic_items.insert(item);
			}
			if (buff_res > result)
				result = buff_res;
		}

		return result;
	}
}

int main()
{
	cout << FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Russia",
			"Eurasia",
			{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			89
		}, {
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Russia",
			"Eurasia",
			{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			89
		},
		}) << endl;

	cout << FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Russia",
			"Eurasia",
			{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			89
		}, {
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Moscow",
			"Toulouse",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			89
		}, {
			"Moscow",
			"Russia",
			{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
			31
		},
		}) << endl;

	return 0;
}