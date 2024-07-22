#include <bits/stdc++.h>
using namespace std;

int N;
int current;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  current = 665;
  while (N > 0) {
    current += 1;
    if (to_string(current).find("666") != string::npos) N--;
  }

  cout << current;

  return 0;
}