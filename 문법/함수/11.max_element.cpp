#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // 최대값
  int value = *max_element(v.begin(), v.end());
  cout << value << "\n";

  // 최대값 인덱스
  auto index = max_element(v.begin(), v.end()) - v.begin();
  cout << index;

  return 0;
}