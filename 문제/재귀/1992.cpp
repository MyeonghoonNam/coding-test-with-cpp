#include <bits/stdc++.h>
using namespace std;

int N;
string ret;
char a[68][68];

string quad(int y, int x, int size) {
  char c = a[y][x];
  string temp;

  if (size == 1) return string(1, c);

  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      if (c != a[i][j]) {
        temp += '(';
        temp += quad(y, x, size / 2);
        temp += quad(y, x + (size / 2), size / 2);
        temp += quad(y + (size / 2), x, size / 2);
        temp += quad(y + (size / 2), x + (size / 2), size / 2);
        temp += ')';

        return temp;
      }
    }
  }

  return string(1, c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  ret = quad(0, 0, N);

  cout << ret;

  return 0;
}
