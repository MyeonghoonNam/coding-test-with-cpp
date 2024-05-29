#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int b[5];

vector<pair<int, int>> c;

int main() {
  for (int i = 5; i >= 1; i--) {
    b[i - 1] = i;
  }

  for (int i = 5; i >= 1; i--) {
    a.push_back(i);
  }

  // 오름차순
  sort(a.begin(), a.end());
  sort(b, b + 5);

  for (int i : a) cout << i << " ";
  cout << "\n";

  for (int i : b) cout << i << " ";
  cout << "\n";

  // 내림차순
  sort(a.begin(), a.end(), greater<int>());
  sort(b, b + 5, greater<int>());

  for (int i : a) cout << i << " ";
  cout << "\n";

  for (int i : b) cout << i << " ";
  cout << "\n";

  // 오름차순
  // sort(a.begin(), a.end());
  // sort(b, b + 5);
  sort(a.begin(), a.end(), less<int>());
  sort(b, b + 5, less<int>());

  for (int i : a) cout << i << " ";
  cout << "\n";

  for (int i : b) cout << i << " ";
  cout << "\n";

  // pair 기반 vecotr의 경우 first, second 순으로 오름차순 정렬
  for (int i = 10; i >= 1; i--) {
    c.push_back({i, 10 - i});
  }

  sort(c.begin(), c.end());

  for (auto it : c) {
    cout << it.first << " : " << it.second << "\n";
  }

  return 0;
}