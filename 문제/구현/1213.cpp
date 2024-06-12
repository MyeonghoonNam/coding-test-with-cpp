#include <bits/stdc++.h>
using namespace std;

string name, ret;
char mid;
int flag;

vector<int> cnt(26);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> name;

  for (int i = 0; i < (int)name.size(); i++) {
    cnt[name[i] - 'A'] += 1;
  }

  for (int i = 'Z' - 'A'; i >= 'A' - 'A'; i--) {
    if (cnt[i] != 0) {
      if (cnt[i] % 2 == 1) {
        mid = char(i + 'A');
        cnt[i] -= 1;
        flag += 1;
      }

      if (flag == 2) {
        cout << "I'm Sorry Hansoo";
        exit(0);
      }

      for (int j = 0; j < cnt[i]; j += 2) {
        char c = char(i + 'A');

        ret = c + ret;
        ret += c;
      }
    }
  }

  if (mid) {
    ret.insert(ret.begin() + ret.size() / 2, mid);
  }

  cout << ret;

  return 0;
}