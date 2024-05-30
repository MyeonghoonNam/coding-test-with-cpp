#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a = {1, 2, 3, 3, 3, 4, 5, 8};

  // 지정한 수 초과의 값이 처음 나오는 위치 -> 5
  cout << upper_bound(a.begin(), a.end(), 3) - a.begin();
  cout << "\n";

  // 지정한 수 이상의 값 -> 4
  cout << *upper_bound(a.begin(), a.end(), 3);
  cout << "\n";

  // 지정한 수 이상의 값의 메모리 주소
  cout << &*upper_bound(a.begin(), a.end(), 3);
  cout << "\n";

  // 지정한 수가 없는 경우의 반환값
  // 지정한 수 초과의 처음 나오는 값 -> 8
  cout << *upper_bound(a.begin(), a.end(), 6);
  cout << "\n";

  // 특정 숫자가 몇 개 들어있는지
  // 주소값끼리 -연산을 하면 주소값사이에 몇개의 요소가 있는지 반환한다.
  //  3은 3개 존재
  cout << upper_bound(a.begin(), a.end(), 3) -
              lower_bound(a.begin(), a.end(), 3);

  return 0;
}