#include <bits/stdc++.h>
using namespace std;

int N, M;
string p;
string q;
map<string, int> mp;
map<int, string> mp2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> p;

    mp[p] = i;
    mp2[i] = p;
  }

  for (int i = 0; i < M; i++) {
    cin >> q;

    if (atoi(q.c_str())) {
      cout << mp2[atoi(q.c_str())] << "\n";
    } else {
      cout << mp[q] << "\n";
    }
  }

  return 0;
}