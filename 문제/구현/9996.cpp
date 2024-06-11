#include <bits/stdc++.h>
using namespace std;

int N;
int pos;

string pattern;
string file;
string prefix;
string suffix;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> pattern;

  pos = pattern.find('*');
  prefix = pattern.substr(0, pos);
  suffix = pattern.substr(pos + 1);

  for (int i = 0; i < N; i++) {
    cin >> file;

    if (file.size() < prefix.size() + suffix.size()) {
      cout << "NE" << "\n";
      continue;
    }

    if (prefix == file.substr(0, prefix.size()) &&
        suffix == file.substr(file.size() - suffix.size())) {
      cout << "DA" << "\n";
    } else {
      cout << "NE" << "\n";
    }
  }

  return 0;
}