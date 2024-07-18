#include <bits/stdc++.h>
using namespace std;

string pwd;
string ret;

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool check(string str) {
  int vowelsSequence = 0;
  int consonantsSequence = 0;
  bool hasVowel = false;
  char prev;

  for (int i = 0; i < (int)str.size(); i++) {
    char current = str[i];

    if (isVowel(current)) {
      vowelsSequence++;
      consonantsSequence = 0;
      hasVowel = true;
    } else {
      consonantsSequence++;
      vowelsSequence = 0;
    }

    if (vowelsSequence == 3 || consonantsSequence == 3) return false;
    if (i > 0 && current == prev && (current != 'e' && current != 'o')) {
      return false;
    }

    prev = current;
  }

  if (!hasVowel) return false;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> pwd;

    if (pwd == "end") break;

    if (check(pwd)) {
      ret = " is ";
    } else {
      ret = " is not ";
    }

    cout << "<" << pwd << ">" << ret << "acceptable." << "\n";
  }

  return 0;
}