#include <bits/stdc++.h>
using namespace std;

int N, M;
int numbers[15001];
int ret = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }

  sort(numbers, numbers + N);

  int start = 0;
  int end = N - 1;

  while (start < end) {
    int sum = numbers[start] + numbers[end];

    if (sum == M) {
      start += 1;
      end -= 1;
      ret += 1;
    } else if (sum < M) {
      start += 1;
    } else {
      end -= 1;
    }
  }

  cout << ret;

  return 0;
}