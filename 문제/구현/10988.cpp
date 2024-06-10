#include <bits/stdc++.h>
using namespace std;

string word, temp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> word;
  temp = word;

  reverse(word.begin(), word.end());

  if (temp == word)
    cout << 1;
  else
    cout << 0;

  return 0;
}