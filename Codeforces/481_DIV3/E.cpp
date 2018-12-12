#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef vector<int> vInt;
typedef long long Long;
typedef vector<Long> vLong;
typedef pair<int, int> Pair;
typedef unordered_map<int, int> Hashmap;

int main() {
  int n;
  int W;
  cin >> n >> W;
  int curX = 0;
  int maxX = 0;
  int minX = 0;
  REP(i, n) {
    int delta;
    cin >> delta;

    curX += delta;
    maxX = max(maxX, curX);
    minX = min(minX, curX);
  }

  int len = maxX - minX;
  if (len > W) {
    cout << 0 << endl;
  } else {
    cout << W - len + 1 << endl;
  }
}