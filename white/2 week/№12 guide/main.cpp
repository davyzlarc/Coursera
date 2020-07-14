//Реализуйте справочник столиц стран.
//
//На вход программе поступают следующие запросы :
//CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, если раньше её не было.
//RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
//ABOUT country — вывод столицы страны country.
//DUMP — вывод столиц всех стран.
//
//Формат ввода:
//В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов.Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.
//
//Формат вывода:
//Выведите результат обработки каждого запроса :
//
//В ответ на запрос CHANGE_CAPITAL country new_capital выведите:
//Introduce new country country with capital new_capital, если страны country раньше не существовало;
//Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
//Country country has changed its capital from old_capital to new_capital, если страна country до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.
//
//В ответ на запрос RENAME old_country_name new_country_name выведите:
//Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует;
//Country old_country_name with capital capital has been renamed to new_country_name, если запрос корректен и страна имеет столицу capital.
//
//В ответ на запрос ABOUT country выведите:
//Country country doesn't exist, если страны с названием country не существует;
//Country country has capital capital, если страна country существует и имеет столицу capital.
//
//В ответ на запрос DUMP выведите:
//There are no countries in the world, если пока не было добавлено ни одной страны;
//последовательность пар вида country / capital, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна.
//При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.
//
//Пример 1:
//Ввод
//6
//CHANGE_CAPITAL RussianEmpire Petrograd
//RENAME RussianEmpire RussianRepublic
//ABOUT RussianRepublic
//RENAME RussianRepublic USSR
//CHANGE_CAPITAL USSR Moscow
//DUMP
//
//Вывод
//Introduce new country RussianEmpire with capital Petrograd
//Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
//Country RussianRepublic has capital Petrograd
//Country RussianRepublic with capital Petrograd has been renamed to USSR
//Country USSR has changed its capital from Petrograd to Moscow
//USSR / Moscow
//
//Пример 2:
//Ввод
//24
//RENAME FakeCountry FarFarAway
//ABOUT FarFarAway
//DUMP
//CHANGE_CAPITAL TsardomOfRussia Moscow
//CHANGE_CAPITAL TsardomOfRussia Moscow
//CHANGE_CAPITAL ColonialBrazil Salvador
//CHANGE_CAPITAL TsardomOfRussia SaintPetersburg
//RENAME TsardomOfRussia RussianEmpire
//CHANGE_CAPITAL RussianEmpire Moscow
//CHANGE_CAPITAL RussianEmpire SaintPetersburg
//CHANGE_CAPITAL ColonialBrazil RioDeJaneiro
//DUMP
//RENAME ColonialBrazil EmpireOfBrazil
//ABOUT RussianEmpire
//RENAME EmpireOfBrazil UnitedStatesOfBrazil
//CHANGE_CAPITAL RussianEmpire Petrograd
//RENAME RussianEmpire RussianRepublic
//RENAME RussianRepublic USSR
//CHANGE_CAPITAL USSR Moscow
//CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
//RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil
//ABOUT RussianEmpire
//DUMP
//RENAME USSR USSR
//
//Вывод
//Incorrect rename, skip
//Country FarFarAway doesn't exist
//There are no countries in the world
//Introduce new country TsardomOfRussia with capital Moscow
//Country TsardomOfRussia hasn't changed its capital
//Introduce new country ColonialBrazil with capital Salvador
//Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg
//Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
//Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
//Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
//Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
//ColonialBrazil / RioDeJaneiro RussianEmpire / SaintPetersburg
//Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
//Country RussianEmpire has capital SaintPetersburg
//Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
//Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
//Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
//Country RussianRepublic with capital Petrograd has been renamed to USSR
//Country USSR has changed its capital from Petrograd to Moscow
//Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
//Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
//Country RussianEmpire doesn't exist
//FederativeRepublicOfBrazil / Brasilia USSR / Moscow
//Incorrect rename, skip
//
//Пример 3:
//Ввод
//10
//CHANGE_CAPITAL RussianEmpire Petrograd
//RENAME USSR RussianEmpire
//DUMP
//ABOUT USSR
//DUMP
//RENAME RussianEmpire RussianEmpire
//DUMP
//CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
//RENAME RussianEmpire UnitedStatesOfBrazil
//DUMP
//
//Вывод
//Introduce new country RussianEmpire with capital Petrograd
//Incorrect rename, skip
//RussianEmpire / Petrograd
//Country USSR doesn't exist
//RussianEmpire / Petrograd
//Incorrect rename, skip
//RussianEmpire / Petrograd
//Introduce new country UnitedStatesOfBrazil with capital Brasilia
//Incorrect rename, skip
//RussianEmpire / Petrograd UnitedStatesOfBrazil / Brasilia

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int CHANGE_CAPITAL(map<string, string>& GUIDE, const string& COUNTRY, const string& NEW_CAPITAL, string& OLD_CAPITAL)
{
	if (GUIDE.count(COUNTRY) == 0)
	{
		GUIDE[COUNTRY] = NEW_CAPITAL;
		return 1;
	}
	if (GUIDE.at(COUNTRY) == NEW_CAPITAL)
		return -1;
	OLD_CAPITAL = GUIDE.at(COUNTRY);
	GUIDE.at(COUNTRY) = NEW_CAPITAL;
	return 0;
}

int RENAME(map<string, string>& GUIDE, const string& NEW_COUNTRY_NAME, const string& OLD_COUNTRY_NAME, string& CAPITAL)
{
	if (OLD_COUNTRY_NAME == NEW_COUNTRY_NAME)
		return -1;
	if (GUIDE.count(OLD_COUNTRY_NAME) == 0)
		return -1;
	if (GUIDE.count(NEW_COUNTRY_NAME) != 0)
		return -1;
	CAPITAL = GUIDE.at(OLD_COUNTRY_NAME);
	GUIDE.erase(OLD_COUNTRY_NAME);
	GUIDE[NEW_COUNTRY_NAME] = CAPITAL;
	return 0;
}

int ABOUT(const map<string, string>& GUIDE, const string& COUNTRY, string& CAPITAL)
{
	if (GUIDE.count(COUNTRY) == 0)
		return -1;
	CAPITAL = GUIDE.at(COUNTRY);
	return 0;
}

int DUMP(const map<string, string>& GUIDE)
{
	if (GUIDE.empty())
		return -1;
	return 0;
}

int main()
{
	map<string, int>command = { {"CHANGE_CAPITAL",1},{"RENAME",2},{"ABOUT",3},{"DUMP",4} };
	map<string, string>GUIDE;//COUNTRY, CAPITAL
	int n;
	cin >> n;
	vector<string>result(0);

	for (auto i = 1; i <= n; i++)
	{
		string operation;
		cin >> operation;
		switch (command[operation])
		{
		case 1://CHANGE_CAPITAL
		{
			string COUNTRY, NEW_CAPITAL, OLD_CAPITAL;
			cin >> COUNTRY >> NEW_CAPITAL;
			switch (CHANGE_CAPITAL(GUIDE/*non r-o*/, COUNTRY, NEW_CAPITAL, OLD_CAPITAL/*non r-o*/))
			{
			case 0:
				result.push_back("Country " + COUNTRY + " has changed its capital from " + OLD_CAPITAL + " to " + NEW_CAPITAL);
				break;
			case 1:
				result.push_back("Introduce new country " + COUNTRY + " with capital " + NEW_CAPITAL);
				break;
			case -1:
				result.push_back("Country " + COUNTRY + " hasn't changed its capital");
				break;
			}
		}
		break;
		case 2://RENAME
		{
			string NEW_COUNTRY_NAME, OLD_COUNTRY_NAME, CAPITAL;
			cin >> OLD_COUNTRY_NAME >> NEW_COUNTRY_NAME ;
			switch (RENAME(GUIDE/*non r-o*/, NEW_COUNTRY_NAME, OLD_COUNTRY_NAME, CAPITAL/*non r-o*/))
			{
			case 0:
				result.push_back("Country " + OLD_COUNTRY_NAME + " with capital " + CAPITAL + " has been renamed to " + NEW_COUNTRY_NAME);
				break;
			case -1:
				result.push_back("Incorrect rename, skip");
				break;
			}
		}
		break;
		case 3://ABOUT
		{
			string COUNTRY, CAPITAL;
			cin >> COUNTRY;
			switch (ABOUT(GUIDE, COUNTRY, CAPITAL/*non r-o*/))
			{
			case 0:
				result.push_back("Country " + COUNTRY + " has capital " + CAPITAL);
				break;
			case -1:
				result.push_back("Country " + COUNTRY + " doesn't exist");
				break;
			}
		}
		break;
		case 4://DUMP
			switch (DUMP(GUIDE))
			{
			case 0:
			{
				string result_string;
				for (const auto& [key, value] : GUIDE)
				{
					if (result_string != "")
						result_string += " ";
					result_string += key + "/" + value;
				}
				result.push_back(result_string);
			}
			break;
			case -1:
				result.push_back("There are no countries in the world");
				break;
			}
		}
	}

	for (const auto& item : result)
		cout << item << endl;

	return 0;
}