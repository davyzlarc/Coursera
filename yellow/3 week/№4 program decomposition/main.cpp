//	� ������ ������������� ���������� �� ������� ���������� ��� �� ����� ������� � �������. ������ �� 
//������� ��� ���� ��� � �������� ���� ��������� �� ��������� ������. � ���� ������ ��� ����� �������
//������, ��������� �� ��������� ������:
//	
//	query.h, � ���� ����� :
//
//		enum class QueryType
//		struct Query
//		���������� istream& operator >> (istream& is, Query& q)
//
//	query.cpp, � ���� �����
//
//		����������� istream& operator >> (istream& is, Query& q);
//
//	responses.h:
//
//		struct BusesForStopResponse
//		ostream & operator << (ostream & os, const BusesForStopResponse & r)
//		struct StopsForBusResponse
//		ostream & operator << (ostream & os, const StopsForBusResponse & r)
//		struct AllBusesResponse
//		ostream & operator << (ostream & os, const AllBusesResponse & r)
//
//	responses.cpp : ����������� �����, ��� ��������� � responses.h
//
//	bus_manager.h : ���������� ������ BusManager
//
//	bus_manager.cpp : ����������� ������� ������ BusManager
//
//	main.cpp : ������� main
//
//	��� ���������� ������ �� ��������:
//	� �������� �� ���������������� Coursera ��������� ���������� �� �������� ������ ���� ����, ������� ���
//  ����, ����� ����� ���� ������ � ����������� �������, ��� ���� ���������� ��� ���� ����� � ����� � 
//	��������� ��� �� ��������. �������������� ������� ������� : rar, zip, 7z, tar, tar.gz, � ����� ������ 
//	������ (��� ���������� �� ���������� ��������� dtrx, �� �������� � � ��������� ������� ������ ������
//  �������������� ��������).
//
//	��� ����� ������������� ���� �������:
//	���� ��� ���� ��������� ��� ����� main_source.cpp, ���������� ������� main. ��� ����� ����� �� ���������, 
//	������� ���� ���� � ������ ������������� ����������. ������������ ������ ������� ����� ����������� � ���
//  �����. �� ������ ����� �������������� ����������� ������� ��������� ���������� ���� ����� � ������
//  ����������� ����� � ����������� ����. ��� ���� ������� main � ����� ������� ����� �������� �� ��, �������
//  ���� � ��������� ����� main.cpp. ����� ���� ����������� ���� ����� ������� �� ������ ������. ������������ 
//	����������� ��� ��, ��� � ��� ����������� ����� �� ����� �����: ���� ������� � stdin, ���������� �����
//  ���������� ���������, � ����� ������������� stdout.
//
//	�� ������ ����� ����� ����������� ������������ ��������� ������ ������ �������. �����������, ��� ���� query.h 
//	������������� �������� ������������ ��� QueryType, ��� BusManager::GetBusesForStop ���������� ���������
//  �������������� ������ BusesForStopResponse �.�.

#include <iostream>
#include "bus_manager.h"
#include "query.h"
#include "responses.h"

using namespace std;

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}