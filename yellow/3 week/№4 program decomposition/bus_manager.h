#pragma once
#include <vector>
#include <tuple>
#include "responses.h"

class BusManager {
public:
	void AddBus(const std::string& bus, const std::vector<std::string>& stops);

	BusesForStopResponse GetBusesForStop(const std::string& stop) const;

	StopsForBusResponse GetStopsForBus(const std::string& bus) const;

	AllBusesResponse GetAllBuses() const;

	const std::tuple<Map_StringToVectorString, Map_StringToVectorString> GetStruct_Test() const;
private:
	Map_StringToVectorString buses_to_stops, stops_to_buses;
};