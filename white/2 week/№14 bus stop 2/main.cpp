#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main()
{
	map<vector <string>, int>GUIDE;
	int num_guides = 1;

	int n;
	cin >> n;
	vector<string>result(0);

	for (auto i = 1; i <= n; i++)
	{
		int num_stops;
		cin >> num_stops;
		vector<string> tmp_stops(num_stops);
		for (auto& item : tmp_stops)
			cin >> item;

		if (GUIDE.count(tmp_stops) == 0)
		{
			GUIDE[tmp_stops] = num_guides;
			result.push_back("New bus " + to_string(GUIDE.at(tmp_stops)));
			num_guides++;
		}
		else result.push_back("Already exists for " + to_string(GUIDE.at(tmp_stops)));
	}

	for (const auto& item : result)
		cout << item << endl;

	return 0;
}