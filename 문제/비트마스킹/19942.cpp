#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int N;
int mp, mf, ms, mv;
int cp, cf, cs, cv, cost;
int sum;
int ret = INF;

struct Foods {
  int mp, mf, ms, mv, cost;
} foods[16];

map<int, vector<vector<int>>> retV;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> mp >> mf >> ms >> mv;

  for (int i = 1; i <= N; i++) {
    cin >> cp >> cf >> cs >> cv >> cost;

    foods[i].mp = cp;
    foods[i].mf = cf;
    foods[i].ms = cs;
    foods[i].mv = cv;
    foods[i].cost = cost;
  }

  for (int i = 1; i < (1 << N); i++) {
    vector<int> v;
    cp = cf = cs = cv = sum = 0;

    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        int idx = j + 1;

        v.push_back(idx);
        cp += foods[idx].mp;
        cf += foods[idx].mf;
        cs += foods[idx].ms;
        cv += foods[idx].mv;
        sum += foods[idx].cost;
      }
    }

    if (cp >= mp && cf >= mf && cs >= ms && cv >= mv) {
      if (sum <= ret) {
        ret = sum;
        retV[ret].push_back(v);
      }
    }
  }

  if (ret == INF)
    cout << -1 << "\n";
  else {
    sort(retV[ret].begin(), retV[ret].end());
    cout << ret << "\n";

    for (auto v : retV[ret][0]) {
      cout << v << " ";
    }
  }

  return 0;
}