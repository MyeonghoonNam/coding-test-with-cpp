#include <bits/stdc++.h>
using namespace std;

int N, C;
int a[1004];

map<int, tuple<int, int, int>> mp;
vector<tuple<int, int, int>> ret;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
  if (get<1>(a) == get<1>(b)) {
    return get<2>(a) < get<2>(b);
  }

  return get<1>(a) > get<1>(b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> C;

  for (int i = 0; i < N; i++) {
    cin >> a[i];

    // tuple : value, count, order
    if (mp.find(a[i]) == mp.end()) {
      mp[a[i]] = {a[i], 1, i};
    } else {
      get<1>(mp[a[i]]) += 1;
    }
  }

  for (auto it : mp) {
    ret.push_back(it.second);
  }

  sort(ret.begin(), ret.end(), cmp);

  for (auto it : ret) {
    int value = get<0>(it);
    int count = get<1>(it);

    for (int i = 0; i < count; i++) {
      cout << value << " ";
    }
  }

  return 0;
}