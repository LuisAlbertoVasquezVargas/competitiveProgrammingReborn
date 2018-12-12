#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef vector<int> vInt;
typedef long long Long;
typedef vector<Long> vLong;
typedef pair<int, int> Pair;
typedef map<Pair, int> Hashmap;

int main() {
	std::mt19937 mt(1729);
	int n = (int)1e5;
	cout << n << endl;
	std::uniform_int_distribution<int> dist(0, 2);
	REP (i, n) {
		cout << 500 + dist(mt) << " ";
	}
}