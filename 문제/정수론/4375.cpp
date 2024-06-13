#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  while (scanf("%d", &N) != EOF) {
    int num = 1;
    int ret = 1;

    while (true) {
      if (num % N == 0) {
        // 3) 최종원하는 결과와 동일한 값의 경우 == 최종결과값
        // *,+로만 이루어진 연산에서의 모듈러 연산
        printf("%d\n", ret);
        break;
      } else {
        // 각 자리수에 대해 마지막에 모듈러 연산을 하는 결과는 그 과정에서
        // 모듈러 연산을 하는 경우와 동일하다. ex) 답이 1111인경우 1111 % N 이
        // 아닌 1 % 7, 11 % 7, 111 % 7의 과정에서 나머지가 0이 되는 경우의
        // 결과값과 동일하다. 그로 인해 시간 단축이 가능하다.
        num = (num * 10) + 1;  // 1) 1로만 구성된 수 대입
        num %= N;              // 2) 모듈러 연산
        ret += 1;
      }
    }
  }
}