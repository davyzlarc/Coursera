//Определите тип Incognizable, для которого следующий код будет корректен:
//int main() {
//	Incognizable a;
//	Incognizable b = {};
//	Incognizable c = { 0 };
//	Incognizable d = { 0, 1 };
//	return 0;
//}

#include <iostream>

using namespace std;

class Incognizable {
public:
	Incognizable(const int& x = 0, const int& y = 0) {
		a = x;
		b = y;
	}
private:
	int a;
	int b;
};

int main()
{
	Incognizable a;
	Incognizable b = {};
	Incognizable c = { 0 };
	Incognizable d = { 0, 1 };
	return 0;
}