#include <bits/stdc++.h>

using namespace std;

int main() {
  string s = "1";
  string s2 = "atoi";

  cout << atoi(s.c_str()) << "\n";
  cout << atoi(s2.c_str()) << "\n";

  return 0;
}

/**
 * atoi(s.c_str())는 C++에서 문자열 s를 정수 int로 변환하는 방법 중 하나이다.
 * string s를 const char*로 바꿈
 * 문자열이 정수변환이 가능하면 정수변환값을, 불가능하면 0을 반환한다.
 */