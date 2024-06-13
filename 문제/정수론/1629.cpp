#include <bits/stdc++.h>
using namespace std;

// 일반적인 반복의 거듭제곱의 경우 시간복잡도 = O(n)
// 분할 정복을 이용한 거듭제곱 공식, 시간복잡도 = O(log2(n))

// C^N
// (1) N = 짝수, C^N/2 * C^N/2
// (2) N = 홀수, C^(N-1)/2 * C^(N-1)/2 * C

// MOD 연산
// (A * B) % C = ((A % C) * (B % C)) % C

typedef long long ll;
ll A, B, C;

ll pow(ll a, ll b) {
  if (b == (ll)1) {
    return a % C;
  }

  ll ret = pow(a, b / (ll)2);

  ret = (ret * ret) % C;
  if (b % (ll)2 == (ll)1) ret = (ret * a) % C;

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;
  cout << pow(A, B);

  return 0;
}