#include <set>
#include <string>
#include <map>

using namespace std;

static set<string> BuildMapValuesSet(const map<int, string> map)
{
	set <string> set;
	for (const auto& [key, value] : map)
		set.insert(value);
	return set;
}