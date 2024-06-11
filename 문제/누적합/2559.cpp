#include <bits/stdc++.h>
using namespace std;

int N, K, temp, sum, ret = -10000001;
vector<int> psum(1000001);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> temp;
    psum[i] = psum[i - 1] + temp;
  }

  for (int i = K; i <= N; i++) {
    sum = psum[i] - psum[i - K];
    ret = max(ret, sum);
  }

  cout << ret;

  return 0;
}