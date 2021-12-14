#include <iostream>

#include "query.h"

using namespace std;

istream& operator >> (istream& is, Query& q) {
	q = {};
	string command;
	is >> command;

	if (command == "NEW_BUS")
	{
		q.type = QueryType::NewBus;
		is >> q.bus;

		int num_stops;
		is >> num_stops;

		for (size_t i = 0; i < num_stops; i++)
		{
			string stop;
			is >> stop;
			q.stops.push_back(stop);
		}
	}
	else if (command == "BUSES_FOR_STOP")
	{
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (command == "STOPS_FOR_BUS")
	{
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (command == "ALL_BUSES")
	{
		q.type = QueryType::AllBuses;
	}

	return is;
}