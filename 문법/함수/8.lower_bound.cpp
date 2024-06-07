#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a = {1, 2, 3, 3, 3, 4, 5, 8};

  // 지정한 수 이상의 값이 처음 나오는 위치 -> 2
  cout << lower_bound(a.begin(), a.end(), 3) - a.begin();
  cout << "\n";

  // 지정한 수 이상의 값 -> 3
  cout << *lower_bound(a.begin(), a.end(), 3);
  cout << "\n";

  // 지정한 수 이상의 값의 메모리 주소
  cout << &*lower_bound(a.begin(), a.end(), 3);
  cout << "\n";

  // 지정한 수가 없는 경우의 반환값
  // 지정한 수 이상의 처음 나오는 값 -> 8
  cout << *lower_bound(a.begin(), a.end(), 6);

  return 0;
}