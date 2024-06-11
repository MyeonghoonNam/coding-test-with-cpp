#include <bits/stdc++.h>
using namespace std;

int N;
string name;
string ret;

map<char, int> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> name;
    mp[name[0]] += 1;
  }

  for (auto obj : mp) {
    if (obj.second >= 5) {
      ret += obj.first;
    }
  }

  if (ret.size() == 0) {
    cout << "PREDAJA";
  } else {
    cout << ret;
  }

  return 0;
}