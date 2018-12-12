#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  REP(i, n) {
    if (s[i] != 'x') {
      continue;
    }
    int index = -1;
    for (int j = i; j < n; j++) {
      if (s[j] == 'x') {
        index = j;
      } else {
        break;
      }
    }
    int cnt = index - i + 1;
    if (cnt >= 3) {
      ans += cnt - 2;
    }
    i = index;
  }
  cout << ans << endl;
}
