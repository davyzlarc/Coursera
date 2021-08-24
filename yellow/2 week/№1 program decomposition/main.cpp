#include <string>
#include <sstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <tuple>

using namespace std;
using Map_StringToVectorString = map<string, vector<string>>;
using Pair_StringToVectorString = pair<string, vector<string>>;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type{};
	string bus;
	string stop;
	vector<string> stops;
};

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

struct BusesForStopResponse {
	bool nostop;
	vector<string> buses;
};

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

struct StopsForBusResponse {
	vector<Pair_StringToVectorString> stops_to_buses;
};

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

struct AllBusesResponse {
	Map_StringToVectorString buses_to_stops;
};

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

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops.insert(make_pair(bus, stops));
		for (const auto& item : stops)
			stops_to_buses[item].push_back(bus);
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		if (stops_to_buses.count(stop) == 0)
			return { true, {} };
		else
			return { false, stops_to_buses.at(stop) };
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
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

	AllBusesResponse GetAllBuses() const {
		if (buses_to_stops.empty())
			return {};
		else
			return { buses_to_stops };
	}

	const tuple<Map_StringToVectorString, Map_StringToVectorString> GetStruct_Test() const	{
		return tie(buses_to_stops, stops_to_buses);
	}
private:
	Map_StringToVectorString buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

const string test_part = "====================================================",
test_all = "++++++++++++++++++++++++++++++++++++++++++++++++++++";

bool operator== (const Query& lhs, const Query& rhs)
{
	return tie(lhs.bus, lhs.stop, lhs.stops, lhs.type) == tie(rhs.bus, rhs.stop, rhs.stops, rhs.type);
}

void Test_QueryInput()
{
	cout << test_part << endl;

	{
		Query input;

		stringstream ss;
		ss << "NEW_BUS bus 3 stop1 stop2 stop3";
		ss >> input;

		const Query expected{ QueryType::NewBus, "bus", "", { "stop1", "stop2", "stop3" } };
		assert(input == expected);
	}
	{
		Query input;

		stringstream ss;
		ss << "BUSES_FOR_STOP stop";
		ss >> input;

		const Query expected{ QueryType::BusesForStop, "", "stop" , {} };
		assert(input == expected);
	}
	{
		Query input;

		stringstream ss;
		ss << "STOPS_FOR_BUS bus";
		ss >> input;

		const Query expected{ QueryType::StopsForBus, "bus", "", {} };
		assert(input == expected);
	}
	{
		Query input;

		stringstream ss;
		ss << "ALL_BUSES";
		ss >> input;

		const Query expected{ QueryType::AllBuses, "", "", {} };
		assert(input == expected);
	}

	cout << "Test_QueryInput passed" << endl;
	cout << test_part << endl << endl;
}

void Test_NewBus()
{
	cout << test_part << endl;

	{
		BusManager bm;
		bm.AddBus("bus", { "stop1", "stop2", "stop3" });
		const auto [result_first, result_last] = bm.GetStruct_Test();

		const Map_StringToVectorString
			expected_first = { { "bus", { "stop1", "stop2", "stop3" } } },
			expected_last = { { "stop1", { "bus" } },
							{ "stop2", { "bus" } },
							{ "stop3", { "bus" } } };
		assert(result_first == expected_first && result_last == expected_last);
	}

	cout << "Test_AddBus passed" << endl;
	cout << test_part << endl << endl;
}

bool operator== (const BusesForStopResponse& lhs, const BusesForStopResponse& rhs)
{
	return tie(lhs.buses, lhs.nostop) == tie(rhs.buses, rhs.nostop);
}

void Test_GetBusesForStop()
{
	{
		BusManager bm;
		bm.AddBus("bus1", { "stop1", "stop2", "stop3" });
		const BusesForStopResponse result = bm.GetBusesForStop("stop0");

		const BusesForStopResponse expected = { true, {} };
		assert(result == expected);
	}
	{
		BusManager bm;
		bm.AddBus("bus1", { "stop1", "stop2", "stop3" });
		bm.AddBus("bus2", { "stop3", "stop4", "stop5" });
		const BusesForStopResponse result = bm.GetBusesForStop("stop3");

		const BusesForStopResponse expected = { false, { "bus1", "bus2" } };
		assert(result == expected);
	}

	cout << "Test_GetBusesForStop passed" << endl;
}

void Test_OutputBusesForStopResponse()
{
	{
		BusesForStopResponse input{ true, {} };
		stringstream ss_result;
		ss_result << input;
		string result;
		getline(ss_result, result);

		const string expected = "No stop";

		assert(result == expected);
	}
	{
		BusesForStopResponse input{ false, { "bus1", "bus2" } };
		stringstream ss_result;
		ss_result << input;
		string result;
		getline(ss_result, result);

		const string expected = "bus1 bus2";

		assert(result == expected);
	}

	cout << "Test_OutputBusesForStopResponse passed" << endl;
}

void Test_BusesForStop()
{
	cout << test_part << endl;

	Test_GetBusesForStop();
	Test_OutputBusesForStopResponse();

	cout << endl << "Test_BusesForStop passed" << endl;
	cout << test_part << endl << endl;
}

bool operator== (const StopsForBusResponse& lhs, const StopsForBusResponse& rhs)
{
	return lhs.stops_to_buses == rhs.stops_to_buses;
}

void Test_GetStopsForBus()
{
	{
		BusManager bm;
		const StopsForBusResponse result = bm.GetStopsForBus("bus");

		const StopsForBusResponse expected = { {} };
		assert(result == expected);
	}
	{
		BusManager bm;
		bm.AddBus("bus1", { "stop1", "stop2", "stop3" });
		const StopsForBusResponse result = bm.GetStopsForBus("bus1");

		const StopsForBusResponse expected = { { { "stop1", {} }, { "stop2", {} }, { "stop3", {} } } };
		assert(result == expected);
	}
	{
		BusManager bm;
		bm.AddBus("bus1", { "stop1", "stop2", "stop3" });
		bm.AddBus("bus2", { "stop1", "stop2", "stop3" });
		const StopsForBusResponse result = bm.GetStopsForBus("bus2");

		const StopsForBusResponse expected = { { { "stop1", { "bus1" } },
												{ "stop2", { "bus1" } },
												{ "stop3", { "bus1" } } } };
		assert(result == expected);
	}
	{
		BusManager bm;
		bm.AddBus("bus1", { "stop1", "stop2", "stop3" });
		bm.AddBus("bus2", { "stop3", "stop4", "stop5" });
		const StopsForBusResponse result = bm.GetStopsForBus("bus1");

		const StopsForBusResponse expected = { { { "stop1", {} },
												{ "stop2", {} },
												{ "stop3", { "bus2" } } } };
		assert(result == expected);
	}

	cout << "Test_GetStopsForBus passed" << endl;
}

void Test_OutputStopsForBusResponse()
{
	{
		StopsForBusResponse input{ {} };
		stringstream ss_result;
		ss_result << input;
		string result;
		getline(ss_result, result);

		const string expected = "No bus";

		assert(result == expected);
	}
	{
		StopsForBusResponse input{ { { "stop1", {} }, { "stop2", {} }, { "stop3", {} } } };
		stringstream ss_result;
		ss_result << input;
		vector<string> result;
		string str;
		while (getline(ss_result, str))
			result.push_back(str);

		const vector<string> expected = { "Stop stop1: no interchange",
										"Stop stop2: no interchange",
										"Stop stop3: no interchange" };

		assert(result == expected);
	}
	{
		StopsForBusResponse input{ { { "stop1", { "bus1" } },
									{ "stop2", { "bus1" } },
									{ "stop3", { "bus1" } } } };
		stringstream ss_result;
		ss_result << input;
		vector<string> result;
		string str;
		while (getline(ss_result, str))
			result.push_back(str);

		const vector<string> expected = { "Stop stop1: bus1",
										"Stop stop2: bus1",
										"Stop stop3: bus1" };

		assert(result == expected);
	}
	{
		StopsForBusResponse input{ { { "stop1", {} },
									{ "stop2", {} },
									{ "stop3", { "bus2" } } } };
		stringstream ss_result;
		ss_result << input;
		vector<string> result;
		string str;
		while (getline(ss_result, str))
			result.push_back(str);

		const vector<string> expected = { "Stop stop1: no interchange",
										"Stop stop2: no interchange",
										"Stop stop3: bus2" };

		assert(result == expected);
	}

	cout << "Test_OutputStopsForBusResponse passed" << endl;
}

void Test_StopsForBus()
{
	cout << test_part << endl;

	Test_GetStopsForBus();
	Test_OutputStopsForBusResponse();

	cout << endl << "Test_StopsForBus passed" << endl;
	cout << test_part << endl << endl;
}

bool operator== (const AllBusesResponse& lhs, const AllBusesResponse& rhs)
{
	return lhs.buses_to_stops == rhs.buses_to_stops;
}

void Test_GetAllBuses()
{
	{
		BusManager bm;
		const AllBusesResponse result = bm.GetAllBuses();

		const AllBusesResponse expected = { {} };
		assert(result == expected);
	}
	{
		BusManager bm;
		bm.AddBus("bus1", { "stop1", "stop2", "stop3" });
		bm.AddBus("bus2", { "stop3", "stop4", "stop5" });
		const AllBusesResponse result = bm.GetAllBuses();

		const AllBusesResponse expected = { { { "bus1", { "stop1", "stop2", "stop3" } },
										{ "bus2", { "stop3", "stop4", "stop5" } } } };
		assert(result == expected);
	}

	cout << "Test_GetAllBuses passed" << endl;
}

void Test_OutputAllBusesResponse()
{
	{
		AllBusesResponse input{ {} };
		stringstream ss_result;
		ss_result << input;
		string result;
		getline(ss_result, result);

		const string expected = "No buses";

		assert(result == expected);
	}
	{
		AllBusesResponse input{ { { "bus1", { "stop1", "stop2", "stop3" } },
								{ "bus2", { "stop3", "stop4", "stop5" } } } };
		stringstream ss_result;
		ss_result << input;
		vector<string> result;
		string str;
		while (getline(ss_result, str))
			result.push_back(str);

		const vector<string> expected = { "Bus bus1: stop1 stop2 stop3",
										"Bus bus2: stop3 stop4 stop5" };

		assert(result == expected);
	}

	cout << "Test_OutputAllBusesResponse passed" << endl;
}

void Test_AllBuses()
{
	cout << test_part << endl;

	Test_GetAllBuses();
	Test_OutputAllBusesResponse();

	cout << endl << "Test_AllBuses passed" << endl;
	cout << test_part << endl << endl;
}

void Test_All()
{
	cout << test_all << endl;

	Test_QueryInput();
	Test_NewBus();
	Test_BusesForStop();
	Test_StopsForBus();
	Test_AllBuses();

	cout << "Test_All passed" << endl;
	cout << test_all << endl;
}

int main() {
	/*Test_All();
	return 0;*/

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