#include <bits/stdc++.h>

using namespace std;

string a = "C++";
string b = "출력";
string c = "연습";
double number = 1.23456789;

int main() {
  cout << a << "\n";  // --1
  cout << b << " " << c << "\n";

  cout << fixed << setprecision(3) << number << "\n";  // --2

  printf("개발자 %s %s %s\n소수: %lf", a.c_str(), b.c_str(), c.c_str(),
         number);  // --3

  return 0;
}

/**
 * 1. cout을 통한 출력
 * 2. cout 실수 타입 출력
 *    특정 자리수 지정 가능
 * 3. printf를 통한 출력
 *    형식을 지정한 출력에 용이하다.
 *    문자열로 출력할 때 string 타입을 문자열에 대한 포인터 타입으로 바꿔야한다.
 *    c_str(): 문자열 타입을 포인터 타입으로 전환
 *    문자열 출력시 cout이 더 편리
 */