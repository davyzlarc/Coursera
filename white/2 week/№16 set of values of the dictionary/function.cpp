#include "function.h"

set<string>BuildMapValuesSet(const map<int,string> MAP)
{
	set <string> SET;
	for (const auto& [key, value] : MAP)
		SET.insert(value);
	return SET;
}
