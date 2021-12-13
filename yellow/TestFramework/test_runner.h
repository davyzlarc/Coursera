#pragma once

#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u,
	const string& hint)
{
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u
			<< " hint: " << hint;
		throw runtime_error(os.str());
	}
}

inline void Assert(bool b, const string& hint);

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (runtime_error& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
	}

	~TestRunner();

private:
	int fail_count = 0;
};