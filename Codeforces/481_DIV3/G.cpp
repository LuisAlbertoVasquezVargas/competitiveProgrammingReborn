#include<bits/stdc++.h>
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

struct FlowGraph {
  int n, m, s, t, E;
  const int INF = INT_MAX / 2;
  vInt to, cap, NEXT;    // maxe * 2
  vInt last, now, dist;  // maxv
  FlowGraph() {}
  FlowGraph(int n, int m, int s, int t) : n(n), m(m), s(s), t(t) {
    // TODO(luisvasquez) : to investigate about NEXT variable.
    to = cap = NEXT = vInt(2 * m + 5);
    last = now = dist = vInt(n + 5);
    E = 0;
    last = vInt(n + 5, -1);
  }

  void add(int u, int v, int uv, int vu = 0) {
    to[E] = v;
    cap[E] = uv;
    NEXT[E] = last[u];
    last[u] = E++;
    
    to[E] = u;
    cap[E] = vu;
    NEXT[E] = last[v];
    last[v] = E++;
  }

  bool bfs() {
    REP (i, n) {
      dist[i] = INF;
    }
    queue<int> Q;
    dist[t] = 0;
    Q.push(t);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (int e = last[u]; e != -1; e = NEXT[e]) {
        int v = to[e];
        if (cap[e ^ 1] && dist[v] >= INF) {
          dist[v] = dist[u] + 1;
          Q.push(v);
        }
      }
    }
    return dist[s] < INF;
  }

  int dfs(int u, int f) {
    if (u == t) return f;
    for (int &e = now[u]; e != -1; e = NEXT[e]) {
      int v = to[e];
      if (cap[e] && dist[u] == dist[v] + 1) {
        int ret = dfs(v, min(f, cap[e]));
        if (ret) {
          cap[e] -= ret;
          cap[e ^ 1] += ret;
          return ret;
        }
      }
    }
    return 0;
  }
  Long maxFlow() {
    Long flow = 0;
    while (bfs()) {
      REP (i, n) {
        now[i] = last[i];
      }
      while (true) {
        int f = dfs(s, INF);
        if (!f) {
          break;
        }
        flow += f;
      }
    }
    return flow;
  }
};

int main(){
  int n, m;
  cin >> n >> m;
  
  vInt starts(m);
  vInt deadlines(m);
  vInt cant(m);
  REP (i, m) {
    int s, d, c;
    cin >> s >> d >> c;
    s --;
    d --;
    starts[i] = s;
    deadlines[i] = d;
    cant[i] = c;
  }
  
  vInt days(n);
  REP (i, m) {
    days[deadlines[i]] = m + 1;
  }

  int nodes = n + m + 2;
  int s = nodes - 1;
  int t = nodes - 2;
  FlowGraph G(nodes, n + m + n * m, s ,t);
  REP (i, m) {
    for (int d = starts[i]; d < deadlines[i]; d++) {
      if (days[d] != m + 1) {
        G.add(d, n + i, 1);
      }
    }
    G.add(n + i, t, cant[i]);
  }
  
  REP (i, n) {
    G.add(s, i, 1);
  }

  int tot = accumulate(ALL(cant), 0);
  int maxFlow = G.maxFlow();
  if (tot != maxFlow) {
    cout << -1 << endl;
  } else {
    REP (u, n) {
      for (int e = G.last[u]; e != -1; e = G.NEXT[e]) {
        int v = G.to[e];
        if (v != s && G.cap[e] == 0) {
          days[u] = v - n + 1;
        }
      }
    }

    REP (i , n) {
      cout << days[i] << char(i + 1 == n ? 10 : 32);
    }
  }
}