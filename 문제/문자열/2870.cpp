#include <bits/stdc++.h>
using namespace std;

int N;
string line, ret;
vector<string> v;

void go() {
  while (true) {
    if (ret.size() && ret.front() == '0') {
      ret.erase(ret.begin());
    } else {
      break;
    }
  }

  if (ret.size() == 0) ret = "0";
  v.push_back(ret);
  ret = "";
}

bool cmp(string a, string b) {
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> line;

    for (int i = 0; i < (int)line.size(); i++) {
      char c = line[i];

      if (c < 97) {
        ret += c;
      } else if (ret.size()) {
        go();
      }
    }

    if (ret.size()) go();
  }

  sort(v.begin(), v.end(), cmp);
  for (auto it : v) cout << it << "\n";

  return 0;
}