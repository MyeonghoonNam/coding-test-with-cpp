#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v = {1, 2, 3};
  vector<int> ret(3);

  copy(v.begin(), v.end(), ret.begin());

  cout << ret[1] << "\n";

  ret[1] = 100;

  // vector 깊은 복사
  cout << ret[1] << "\n";
  cout << v[1] << "\n";

  // C++에서 배열의 크기는 컴파일 시간에 상수여야 한다.
  // 확실히 숫자로 명시하거나, 상수 대입

  const int N = 3;

  // int v2[3] = {1, 2, 3};
  // int ret2[3];

  // copy(v2, v2 + 3, ret2);

  int v2[N] = {1, 2, 3};
  int ret2[N];

  copy(v2, v2 + N, ret2);

  cout << ret2[1] << "\n";

  ret2[1] = 100;

  // array 깊은 복사
  cout << ret2[1] << "\n";
  cout << v2[1] << "\n";

  return 0;
}