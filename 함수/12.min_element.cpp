#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // 최솟값
  int value = *min_element(v.begin(), v.end());
  cout << value << "\n";

  // 최솟값 인덱스
  auto index = min_element(v.begin(), v.end()) - v.begin();
  cout << index;

  return 0;
}