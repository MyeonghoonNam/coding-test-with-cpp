#include <bits/stdc++.h>  // --1
using namespace std;      // --2

string a;  // --3

int main() {
  cin >> a;           // --4
  cout << a << "\n";  // --5

  return 0;  // --6
}

/*
  1.
  헤더파일을 include 시킨다.
  bits/stdc++.h는 C++의 모든 표준 라이브러리를 포함하는 헤더파일이다.
  이를 include라는 지시문을 통해 이 프로그램에 포함시킨다는 의미

  2.
  std라는 네임스페이스를 사용한다.
  네임스페이스란 많은 라이브러리를 불러서 사용하다보면 변수명 중복이 발생할 수
  있는데 이를 방지하기 위해서 변수명에 범위를 걸어놓는 것을 의미한다.
  네이스페이스를 사용하지 않는 다면 cin이나 cout의 라이브러리 메소드를 사용할
  때에 std::cin, std::cout과 같이 긴 코드를 통해 호출해야하는데 코드를 줄일 수
  있는 효과를 가져다준다.

  3.
  변수 선언은 <타입> <변수명>으로 선언한다.
  string 타입의 변수 a를 선언하였다.
  값은 초기에 지정할 수 있으며 선택값이다.
  string a = "알고리즘" 에서 a는 lvalue, 알고리즘은 rvalue라고 부른다.

  4.
  변수 a를 입력받는다.
  대표적으로 입력함수는 cin, scanf가 있다.

  5.
  변수 a를 출력한다.
  대표적으로 출력함수는 cout, printf가 있다.

  6.
  main함수를 종료시킨다는 의미
  C++로 만든 프로그램은 실행시 main() 함수 하나를 찾고 그곳이 실행 분기점이다.
  cpp 파일당 반드시 하나의 main함수가 존재해야한다.
*/