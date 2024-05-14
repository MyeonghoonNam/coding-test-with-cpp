#include <bits/stdc++.h>

using namespace std;

/**
 char
 작은 따옴표('')로 선언하는 문자열 타입 지정
 1바이트 크기를 가진다.

 char 타입 초기화시 기본값이 없다면 널문자(‘\0’, NULL, 0)로 초기화 되므로
 주의하자. 이는 빈 문자열이 아니다.
*/
char charTypeFunc() {
  char a = 'a';
  cout << a << "\n";

  return a;
}

int main() {
  charTypeFunc();
  return 0;
}