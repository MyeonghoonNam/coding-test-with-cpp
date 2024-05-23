#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> tp;

int a, b, c;
int d, e, f;

int main() {
  tp = make_tuple(1, 2, 3);
  tie(a, b, c) = tp;

  d = get<0>(tp);
  e = get<1>(tp);
  f = get<2>(tp);

  cout << a << " " << b << " " << c << "\n";
  cout << d << " " << e << " " << f << "\n";

  return 0;
}

/**
 보통 3가지 이상의 멤버변수가 필요하면 tuple 보다는 struct를 많이 사용한다.
*/