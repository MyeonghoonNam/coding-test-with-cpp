#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159                              // --1
#define loop(x, n) for (int x = 0; x < n; x++)  // --2

int main() {
  int sum = 0;

  loop(i, 10) { sum += i; }

  cout << PI << "\n";
  cout << sum;
}

/*
  1. define <이름> <값>
  PI상수 정의

  2. define <이름> <값>
  for 반복문을 loop라는 문자열로 치환

  define 함수와 inline 함수의 차이
  inline 함수
  컴파일 단계에서 처리가 이루어지며, 타입 검사 적용
  define 함수
  전처리 단계에서 처리가 이루어지며, 타입 검사 미적용

  C++의 컴파일 과정
  1.전처리 : #include, #define 등 전처리기 매크로 처리
  2.컴파일 : 소스파일들을 어셈블리 명령어로 변환
  3.어셈블 : 실제 기계어로 이루어진 목적 코드로 변환
  4.링킹 : 목적코드를 모아 실행 파일 생성
*/