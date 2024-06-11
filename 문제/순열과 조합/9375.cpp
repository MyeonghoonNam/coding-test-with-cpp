#include <bits/stdc++.h>
using namespace std;

int T, N;
string name, type;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  while (T--) {
    cin >> N;

    long long ret = 1;
    map<string, int> mp;

    for (int i = 0; i < N; i++) {
      cin >> name >> type;
      mp[type] += 1;
    }

    for (auto it : mp) {
      ret *= it.second + 1;
    }

    ret -= 1;
    cout << ret << "\n";
  }

  return 0;
}