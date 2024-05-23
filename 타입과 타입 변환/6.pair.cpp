#include <bits/stdc++.h>

using namespace std;

pair<int, int> pi;
pair<int, int> pi2;

int a, b, c, d;

int main() {
  pi = {1, 2};  // -- 1
  tie(a, b) = pi;

  pi2 = make_pair(3, 4);  // -- 2
  c = pi2.first;
  d = pi2.second;

  cout << a << " " << b << "\n";
  cout << c << " " << d << "\n";

  return 0;
}

/**
 pair는 first와 second 라는 멤버변수를 가지는 클래스
 두가지 값을 담아야 할 때 유용하다.

 1, 2 모두 pair를 사용하는 방법이며 1번이 좀 더 간결하다.
*/