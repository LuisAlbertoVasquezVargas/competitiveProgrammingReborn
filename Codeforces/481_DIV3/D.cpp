#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef vector<int> vInt;
typedef long long Long;
typedef vector<Long> vLong;
typedef pair<int, int> Pair;
typedef map<Pair, int> Hashmap;

const int INF = INT_MAX / 2;
int n;
vInt A;
Hashmap memo;
int dif;

int dp(int pos, int lastDelta) {
  if (pos == n) {
    return 0;
  }
  Pair state(pos, lastDelta);
  if (memo.count(state)) {
    return memo[state];
  }
  int &ans = memo[state] = INF;
  for (int delta = -1; delta <= 1; delta++) {
    int curVal = A[pos] + delta;
    if (pos == 0) {
      ans = min(ans, abs(delta) + dp(pos + 1, delta));
    } else {
      int curDif = curVal - (A[pos - 1] + lastDelta);
      if (curDif == dif) {
        ans = min(ans, abs(delta) + dp(pos + 1, delta));
      }
    }
  }
  return ans;
}

int main() {
  cin >> n;
  A.resize(n);
  REP(i, n) { cin >> A[i]; }

  if (n <= 2) {
    cout << 0 << '\n';
    return 0;
  }

  int originalDif = A[1] - A[0];
  int ans = INF;
  for (dif = originalDif - 2; dif <= originalDif + 2; dif++) {
    memo.clear();
    ans = min(ans, dp(0, 0));
  }
  if (ans >= INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}