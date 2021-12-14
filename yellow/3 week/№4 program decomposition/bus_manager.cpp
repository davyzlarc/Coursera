#include "bus_manager.h"

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	buses_to_stops.insert(make_pair(bus, stops));
	for (const auto& item : stops)
		stops_to_buses[item].push_back(bus);
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	if (stops_to_buses.count(stop) == 0)
		return { true, {} };
	else
		return { false, stops_to_buses.at(stop) };
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
	if (buses_to_stops.count(bus) == 0)
		return {};
	else
	{
		StopsForBusResponse stops;
		for (const auto& item : buses_to_stops.at(bus))
		{
			Pair_StringToVectorString p;
			p.first = item;
			if (stops_to_buses.at(item).size() != 1)
				for (const auto& elem : stops_to_buses.at(item))
					if (elem != bus)
						p.second.push_back(elem);
			stops.stops_to_buses.push_back(p);
		}
		return stops;
	}
}

AllBusesResponse BusManager::GetAllBuses() const {
	if (buses_to_stops.empty())
		return {};
	else
		return { buses_to_stops };
}

const tuple<Map_StringToVectorString, Map_StringToVectorString> BusManager::GetStruct_Test() const {
	return tie(buses_to_stops, stops_to_buses);
}
