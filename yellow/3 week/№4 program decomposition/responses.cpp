#include "responses.h"

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.nostop)
		os << "No stop";
	else
		for (const auto& item : r.buses)
		{
			os << item;
			if (item != *(r.buses.cend() - 1))
				os << " ";
		}

	return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stops_to_buses.empty())
		os << "No bus";
	else
	{
		for (const auto& elem : r.stops_to_buses)
		{
			os << "Stop " << elem.first << ": ";
			if (elem.second.size() == 0)
				os << "no interchange";
			else
				for (const auto& item : elem.second)
				{
					os << item;
					if (item != *(--elem.second.end()))
						os << " ";
				}
			if (elem != *(--r.stops_to_buses.end()))
				os << endl;
		}
	}

	return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses_to_stops.empty())
		os << "No buses";
	else
		for (const auto& elem : r.buses_to_stops)
		{
			os << "Bus " << elem.first << ": ";
			for (const auto& item : elem.second)
			{
				os << item;
				if (item != *(--elem.second.end()))
					os << " ";
			}
			if (elem != *(--r.buses_to_stops.end()))
				os << endl;
		}

	return os;
}