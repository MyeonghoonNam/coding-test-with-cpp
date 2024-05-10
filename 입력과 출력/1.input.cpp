#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main() {
  cin >> a;         // --1 입력
  cin >> b >> c;    // --2 입력과 출력
  scanf("%d", &a);  // --3

  cout << a << b << c;

  return 0;
}

/**
 1. cin
  개행문자(띄어쓰기, 엔터) 직전 까지 입력을 받는다.

 2. cin(여러개)
  개행을 기준으로 b, c로 분리


 3. scanf
  첫 매개변수로 받는 값의 형식을 지정

  형식 타입
  %d int
  %c char
  %s string
  %lf double
  %ld long long
*/