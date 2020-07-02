//���������� ������� �������� ���������� ���������.��� ����� ������������ ��������� ������� :
//NEW_BUS bus stop_count stop1 stop2 ... � �������� ������� �������� � ��������� bus � stop_count ����������� � ���������� stop1, stop2, ...
//BUSES_FOR_STOP stop � ������� �������� ���� ��������� ��������, ���������� ����� ��������� stop.
//STOPS_FOR_BUS bus � ������� �������� ���� ��������� �������� bus �� ������� ���������, �� ������� ����� ��������� �� ������ �� ���������.
//ALL_BUSES � ������� ������ ���� ��������� � �����������.
//
//������ �����
//� ������ ������ ����� ���������� ���������� �������� Q, ����� � Q ������� ������� �������� ��������.
//
//�������������, ��� ��� �������� ��������� � ��������� ������� ���� �� ��������� ����, ���� � ������ �������������.
//
//��� ������� ������� NEW_BUS bus stop_count stop1stop2 ... �������������, ��� ������� bus �����������, ���������� ��������� ������ 0,
//� ����� ����� stop_count ������� ������ ����� ���������� �������� ���������, ������ ��� �������� � ������ ������ ��������.
//
//������ ������:
//	��� ������� �������, ����� NEW_BUS, �������� ��������������� ����� �� ���� :
//	�� ������ BUSES_FOR_STOP stop �������� ����� ������ ������ ���������, ����������� ����� ��� ���������, � ��� �������, � ������� ��� ����������� 
//��������� NEW_BUS.���� ��������� stop �� ����������, �������� No stop.
//	�� ������ STOPS_FOR_BUS bus �������� �������� ��������� �������� bus � ��������� ������� � ��� �������, � ������� ��� ���� ������ 
//� ��������������� ������� NEW_BUS.�������� ������ ��������� stop ������ ����� ��� Stop stop : bus1bus2 ..., ��� bus1bus2 ... � ������ 
//���������, ����������� ����� ��������� stop, � �������, � ������� ��� ����������� ��������� NEW_BUS, �� ����������� ��������� ��������
//bus.���� ����� ��������� stop �� ��������� �� ���� �������, ����� bus, ������ ������ ��������� ��� �� �������� no interchange.���� �������
//bus �� ����������, �������� No bus.
//	�� ������ ALL_BUSES �������� �������� ���� ��������� � ���������� �������.�������� ������� �������� bus ������ ����� ��� Bus bus :
//stop1stop2 ..., ��� stop1stop2 ... � ������ ��������� �������� bus � �������, � ������� ��� ���� ������ � ��������������� �������
//NEW_BUS.���� �������� �����������, �������� No buses.
//
//��������������:
//������� ������ ���� �������� ����� ������ �������.���� �� �� ������� � ���, ��� �� �������� �� �����, ����������� ������� ��� ���.
//
//������:
//����
//10
//ALL_BUSES
//BUSES_FOR_STOP Marushkino
//STOPS_FOR_BUS 32K
//NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
//NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//BUSES_FOR_STOP Vnukovo
//NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
//NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
//STOPS_FOR_BUS 272
//ALL_BUSES
//
//�����
//No buses
//No stop
//No bus
//32 32K
//Stop Vnukovo : 32 32K 950
//Stop Moskovsky : no interchange
//Stop Rumyantsevo : no interchange
//Stop Troparyovo : 950
//Bus 272 : Vnukovo Moskovsky Rumyantsevo Troparyovo
//Bus 32 : Tolstopaltsevo Marushkino Vnukovo
//Bus 32K : Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//Bus 950 : Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void NEW_BUS(map<string, vector<string>>& BUSES, const string& BUS, const int& STOP_COUNT, const vector<string>& STOPS, const int& NUM_NEW_BUS)//� 1 ������ ������� - NUM_NEW_BUS
{
	BUSES[BUS].push_back(to_string(NUM_NEW_BUS));
	for (const auto& item : STOPS)
		BUSES[BUS].push_back(item);
}

int BUSES_FOR_STOP(const map<string, vector<string>>& BUSES, const string& STOP, string& LIST_BUSES, const string& self_bus)
{
	map <int, string> NEW_BUSES;
	for (const auto& [key, value] : BUSES)
	{
		if (key != self_bus)
		{
			int temp_num;
			for (const auto item : value)
			{
				if (item == value[0])
					temp_num = stoi(item);
				else
					if (item == STOP)
					{
						NEW_BUSES[temp_num];
						NEW_BUSES.at(temp_num) = key;
						break;
					}
			}
		}
	}

	if (NEW_BUSES.size() == 0)
		return -1;

	for (const auto& [key, value] : NEW_BUSES)
	{
		if (LIST_BUSES != "")
			LIST_BUSES += " ";
		LIST_BUSES += value;
	}

	return 0;
}

int main()
{
	map<string, int>command = { {"NEW_BUS",1},{"BUSES_FOR_STOP",2},{"STOPS_FOR_BUS",3},{"ALL_BUSES",4} };
	map<string, vector<string>>BUSES;
	int n;
	cin >> n;
	vector<string>result(0);
	int NUM_NEW_BUS = 0;

	for (auto i = 1; i <= n; i++)
	{
		string operation;
		cin >> operation;
		switch (command[operation])
		{
		case 1://NEW_BUS 
		{
			NUM_NEW_BUS++;
			string BUS;
			int STOP_COUNT;
			cin >> BUS >> STOP_COUNT;
			vector<string> STOPS(STOP_COUNT);
			for (auto& item : STOPS)
				cin >> item;
			NEW_BUS(BUSES/*non r-o*/, BUS, STOP_COUNT, STOPS, NUM_NEW_BUS);
		}
		break;
		case 2://BUSES_FOR_STOP 
		{
			string STOP, LIST_BUSES;
			cin >> STOP;

			switch (BUSES_FOR_STOP(BUSES, STOP, LIST_BUSES/*non r-o*/, ""))
			{
			case 0:
				result.push_back(LIST_BUSES);
				break;
			case -1:
				result.push_back("No stop");
				break;
			}
		}
		break;
		case 3://STOPS_FOR_BUS
		{
			string BUS;
			cin >> BUS;

			if (BUSES.count(BUS) == 0)
				result.push_back("No bus");
			else
				for (const auto& item : BUSES.at(BUS))
				{
					if (item != BUSES.at(BUS)[0])
					{
						string result_string, LIST_BUSES;
						result_string += "Stop " + item + ": ";
						BUSES_FOR_STOP(BUSES, item, LIST_BUSES, BUS);
						if (int(LIST_BUSES.size()) == 0)
							result_string += "no interchange";
						else
							result_string += LIST_BUSES;
						result.push_back(result_string);
					}
				}
		}
		break;
		case 4://ALL_BUSES 
			if (BUSES.size() == 0)
				result.push_back("No buses");
			else
				for (const auto& [key, value] : BUSES)
				{
					string result_string;
					result_string += "Bus " + key + ": ";
					for (const auto& item : value)
					{
						if (item != value[0])
						{
							if (result_string != "Bus " + key + ": ")
								result_string += " ";
							result_string += item;
						}
					}
					result.push_back(result_string);
				}
		}
	}

	for (const auto& item : result)
		cout << item << endl;

	return 0;
}