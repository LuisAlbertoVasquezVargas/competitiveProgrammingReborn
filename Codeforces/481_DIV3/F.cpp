#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef vector<int> vInt;
typedef vector<vInt> vvInt;
typedef vector<vvInt> vvvInt;
typedef vector<string> vStr;
typedef pair<int, int> Pair;
typedef vector<Pair> vPair;
typedef vector<vPair> vvPair;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int)v.size()

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vInt skills(n);
  vPair combined;
  REP (i, n) {
    scanf("%d", &skills[i]);
    combined.push_back({skills[i], i});
  }

  sort(ALL(combined));
  vvPair adj(n);
  REP (i, k) {
    int u, v;
    scanf("%d%d", &u, &v);
    u --, v --;
    adj[u].push_back({skills[v], v});
    adj[v].push_back({skills[u], u});
  }
  for (vPair &item:adj) {
    sort(ALL(item));
  }

  REP (i, n) {
    Pair item(skills[i], INT_MIN);
    int cnt1 = lower_bound(ALL(combined), item) - combined.begin();
    int cnt2 = lower_bound(ALL(adj[i]), item) - adj[i].begin();
    printf("%d%c", cnt1 - cnt2, (i + 1 == n ? 10 :32));
  }
}

