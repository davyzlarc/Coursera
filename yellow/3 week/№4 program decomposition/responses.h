#pragma once
#include <vector>
#include <map>
#include <sstream>

using Map_StringToVectorString = std::map<std::string, std::vector<std::string>>;
using Pair_StringToVectorString = std::pair<std::string, std::vector<std::string>>;

struct BusesForStopResponse {
	bool nostop;
	std::vector<std::string> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	std::vector<Pair_StringToVectorString> stops_to_buses;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	Map_StringToVectorString buses_to_stops;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);