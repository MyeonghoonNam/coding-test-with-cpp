#include <bits/stdc++.h>
using namespace std;

#define N 9

int sum;
int person[N];
vector<int> ret;

pair<int, int> getCombi() {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (sum - person[i] - person[j] == 100) return {i, j};
    }
  }

  // 주어진 문제에서 무조건 경우의 수가 존재함을 보장
  return {-1, -1};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < N; i++) {
    cin >> person[i];
    sum += person[i];
  }

  // 전체 키 합 - 2명의 키 = 100 경우의 수 뽑기
  pair<int, int> combi = getCombi();

  // 경우의 수 제외한 난쟁이들 배열 생성
  for (int i = 0; i < N; i++) {
    if (i == combi.first || i == combi.second) continue;
    ret.push_back(person[i]);
  }

  // 생성 배열 오름차순 정렬
  sort(ret.begin(), ret.end());

  for (int v : ret) cout << v << "\n";

  return 0;
}