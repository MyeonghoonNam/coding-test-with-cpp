#include <bits/stdc++.h>
using namespace std;

int N;
int ret;
string word;

bool isGroupWord(string word) {
  set<char> st;
  st.insert({word[0], 1});

  for (int i = 0; i < (int)word.length() - 1; i++) {
    if (word[i] == word[i + 1]) continue;
    if (st.find(word[i + 1]) != st.end()) return false;

    st.insert({word[i + 1], 1});
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> word;

    if (isGroupWord(word)) {
      ret++;
    }
  }

  cout << ret;

  return 0;
}