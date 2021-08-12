#include <iostream>
#include <vector>

using namespace std;

class Block
{
public:
	Block()
	{
		cin >> W >> H >> D;
	}
	uint64_t GetVolume()
	{
		return CountVolume();
	}

private:
	uint16_t W;
	uint16_t H;
	uint16_t D;

	uint64_t CountVolume()
	{
		return static_cast<uint64_t>(W) * static_cast<uint64_t>(H) * static_cast<uint64_t>(D);
	}
};

int main()
{
	size_t N;
	unsigned R;
	cin >> N >> R;

	uint64_t weight = 0;
	vector<Block>blocks;
	for (size_t i = 0; i < N; i++)
	{
		blocks.push_back({});
		weight += blocks.at(i).GetVolume();
	}

	cout << weight*R;
	return 0;
}