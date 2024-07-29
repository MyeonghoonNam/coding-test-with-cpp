#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[54][54];
int ret = INT_MAX;
vector<pair<int, int>> chickenList;
vector<pair<int, int>> homeList;
vector<int> selected;

void go() {
  int sum = 0;

  for (pair<int, int> h : homeList) {
    int hy = h.first;
    int hx = h.second;
    int dist = INT_MAX;

    for (int i : selected) {
      int cy = chickenList[i].first;
      int cx = chickenList[i].second;

      dist = min(abs(hy - cy) + abs(hx - cx), dist);
    }

    sum += dist;
  }

  ret = min(ret, sum);
}

void combi(int idx, int cnt) {
  if (cnt == M) {
    go();
    return;
  }

  for (int i = idx; i < (int)chickenList.size(); i++) {
    selected.push_back(i);
    combi(i + 1, cnt + 1);
    selected.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];

      if (a[i][j] == 1) {
        homeList.push_back({i, j});
      } else if (a[i][j] == 2) {
        chickenList.push_back({i, j});
      }
    }
  }

  combi(0, 0);

  cout << ret;

  return 0;
}