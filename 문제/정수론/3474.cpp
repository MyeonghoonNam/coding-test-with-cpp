#include <bits/stdc++.h>
using namespace std;

int T, N;
int ret2, ret5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  while (T--) {
    cin >> N;

    ret2 = 0;
    ret5 = 0;

    for (int i = 2; i <= N; i *= 2) {
      ret2 += N / i;
    }

    for (int i = 5; i <= N; i *= 5) {
      ret5 += N / i;
    }

    cout << min(ret2, ret5) << "\n";
  }

  return 0;
}

/**
 * 정수론 N!의 0의 수 찾기
 * ex) N = 5
 * 5 4 3 2 1
 * 2^1 2
 * 2^2 1
 * 5^1 1
 *
 * 2의 배수 총 3개
 * 5의 배수 총 1개
 * min(2의 배수 수, 5의 배수 수)
 * min(3, 1) = 1
 */