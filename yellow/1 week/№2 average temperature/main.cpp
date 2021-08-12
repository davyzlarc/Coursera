#include <iostream>
#include <vector>
using namespace std;

int main()
{
	size_t N;
	cin >> N;
	vector<int>values(N);

	int64_t avg = 0;
	for (auto& item : values)
	{
		cin >> item;
		avg += item;
	}

	avg /= static_cast<int>(N);

	vector<int>result;
	for (size_t i = 0; i < values.size(); i++)
		if (values.at(i) > avg)
			result.push_back(i);

	cout << result.size() << endl;
	for (const auto& item : result)
		cout << item << " ";
	return 0;
}