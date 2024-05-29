#include <bits/stdc++.h>

using namespace std;

int a[10];
int b[10][10];

int main() {
  // 1차원 배열 초기화
  // fill(&a[0], &a[10], 100);
  fill(a, a + 10, 100);  // 배열 이름으로도 가능
  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }

  cout << "\n";

  // 2차원 배열 초기화
  // fill(&b[0][0], &b[10][10], 1);

  // 2차원 이상 부터는 시작위치로 접근시 반드시 시작 위치 + 숫자로 접근
  fill(&b[0][0], &b[0][0] + 100, 1);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << b[i][j] << " ";
    }

    cout << "\n";
  }
}