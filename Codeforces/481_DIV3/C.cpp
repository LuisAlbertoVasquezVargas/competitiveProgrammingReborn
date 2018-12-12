#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long Long;
typedef vector<Long> vLong;

int main() {
	int n;
	int m;
	cin >> n >> m;
	vLong AC(n + 1);
	REP (i, n) {
		Long item;
		cin >> item;
		AC[i + 1] = AC[i] + item;
	}

	REP (i, m) {
		Long target;
		cin >> target;

		int x = lower_bound(ALL(AC), target) - AC.begin();
		x --;
		Long y = target - AC[x];
		cout << x + 1 << " " << y << '\n';
	}
}

