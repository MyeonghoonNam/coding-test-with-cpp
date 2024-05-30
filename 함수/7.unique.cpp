#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
  v = {4, 3, 3, 5, 1, 2, 3};

  for (int i : v) cout << i << " ";
  cout << '\n';

  // 중복되지 않은 요소로 채운 후, 그 다음 이터레이터를 반환한다.
  auto it = unique(v.begin(), v.end());

  cout << it - v.begin() << '\n';
  // 앞에서 부터 중복되지 않게 채운 후 나머지 요소들의 위치는 그대로 유지
  for (int i : v) cout << i << " ";
  cout << '\n';

  sort(v.begin(), v.end());

  // erase(from, to)
  // from = unique iterator
  // end = v.end
  it = v.erase(unique(v.begin(), v.end()), v.end());

  for (int i : v) cout << i << " ";
  cout << '\n';

  return 0;
}