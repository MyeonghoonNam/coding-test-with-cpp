#include <bits/stdc++.h>
using namespace std;

string S;
int alphabet[26];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;

  for (char c : S) alphabet[c - 'a']++;
  for (int v : alphabet) cout << v << " ";

  return 0;
}