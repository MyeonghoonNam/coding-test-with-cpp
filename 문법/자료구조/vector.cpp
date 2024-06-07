#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v;

  for (int i = 1; i <= 10; i++) {
    v.push_back(i);
  }

  for (int el : v) cout << el << " ";

  cout << "\n";

  v.pop_back();

  for (int el : v) cout << el << " ";

  cout << "\n";

  v.erase(v.begin(), v.begin() + 3);
  // v.erase(v.begin()); 위치의 요소 하나만 삭제

  for (int el : v) cout << el << " ";

  cout << "\n";

  auto a = find(v.begin(), v.end(), 2);  // STL : find

  if (a == v.end()) {
    cout << "not found";
  } else {
    cout << "has value";
  }

  cout << "\n";

  fill(v.begin(), v.end(), 10);  // STL : fill

  for (int el : v) cout << el << " ";

  cout << "\n";

  v.clear();

  cout << v.size();

  return 0;
}