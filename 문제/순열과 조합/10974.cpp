#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

// 백준
int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    v.push_back(i);
  }

  do {
    for (int el : v) cout << el << ' ';
    cout << "\n";
  } while (next_permutation(v.begin(), v.end()));

  return 0;
}