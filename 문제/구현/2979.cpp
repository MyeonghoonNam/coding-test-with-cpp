#include <bits/stdc++.h>
using namespace std;

#define TRUCK_COUNT 3
#define MIN_TIME 1
#define MAX_TIME 100

int A, B, C;
int s, e;
int ret;
int used[MAX_TIME + 4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;

  for (int i = 0; i < TRUCK_COUNT; i++) {
    cin >> s >> e;

    for (int i = s; i < e; i++) {
      used[i]++;
    }
  }

  for (int i = MIN_TIME; i < MAX_TIME; i++) {
    if (used[i] == 0) continue;

    if (used[i] == 1)
      ret += A;
    else if (used[i] == 2)
      ret += B * 2;
    else if (used[i] == 3)
      ret += C * 3;
  }

  cout << ret;

  return 0;
}