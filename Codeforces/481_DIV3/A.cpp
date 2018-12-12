#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef vector<int> vInt;
typedef vector<vInt> vvInt;
typedef vector<vvInt> vvvInt;
typedef vector<string> vStr;
typedef pair<int, int> Pair;
typedef vector<Pair> vPair;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int)v.size()

void print(vInt &ans) {
  cout << SZ(ans) << endl;
  for (auto item : ans) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  const int MAX_VAL = 1000;
  vInt last(MAX_VAL + 1, -1);
  vInt array;
  REP (i, n) {
    int item;
    cin >> item;
    last[item] = i;
    array.push_back(item);
  }
  vInt ans;
  REP (i, n) {
    int item = array[i];
    if (last[item] == i) {
      ans.push_back(item);
    }
  }
  print(ans);
}