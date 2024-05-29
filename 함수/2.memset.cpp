#include <bits/stdc++.h>

using namespace std;

const int MAX = 8;

int a[MAX];

int main() {
  // 0 또는 -1이란 값, char형의 하나의 문자(a, b, c, 등..)
  // 위 사항에만 사용가능
  memset(a, 0, sizeof(a));
  for (int i = 0; i < MAX; i++) {
    cout << a[i] << " ";
  }
  return 0;
}