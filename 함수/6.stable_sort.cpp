#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<pair<int, int>> pairs = {{5, 1}, {2, 2}, {5, 3}, {3, 4}, {2, 5}};

  cout << "Origin : ";

  for (const auto& pair : pairs) {
    cout << "(";
    cout << pair.first << ", " << pair.second;
    cout << ") ";
  }

  cout << "\n";

  // 불안정 정렬 알고리즘
  // 동일한 값 비교에 대해 순서가 불명확하며 변경될 수 있음
  sort(pairs.begin(), pairs.end());

  cout << "Sorted with sort() : ";

  for (const auto& pair : pairs) {
    cout << "(";
    cout << pair.first << ", " << pair.second;
    cout << ") ";
  }

  cout << "\n";

  // 초기화
  pairs = {{5, 1}, {2, 2}, {5, 3}, {3, 4}, {2, 5}};

  stable_sort(pairs.begin(), pairs.end());

  cout << "Sorted with stable_sort() : ";

  for (const auto& pair : pairs) {
    cout << "(";
    cout << pair.first << ", " << pair.second;
    cout << ") ";
  }

  return 0;
}