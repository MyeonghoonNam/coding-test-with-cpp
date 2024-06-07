
#include <bits/stdc++.h>

using namespace std;

int ret = 1;

/**
 void
 리턴하는 값이 없을 때의 타입 지정
*/
void voidTypeFunc() {
  ret = 2;
  cout << ret << "\n";

  return;
}

int main() {
  voidTypeFunc();
  return 0;
}