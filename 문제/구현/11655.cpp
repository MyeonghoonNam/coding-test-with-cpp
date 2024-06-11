#include <bits/stdc++.h>
using namespace std;

string originStr;
string rot13Str;

// 배열 전체 크기를 넘어 처음부터 순회하는 경우
// 넘어간 전체 크기 - 기존 배열 전체 크기를 통해 접근
int main() {
  getline(cin, originStr);
  rot13Str = originStr;

  for (int i = 0; i < (int)rot13Str.size(); i++) {
    char c = rot13Str[i];

    if (isupper(c)) {
      if (c + 13 > 'Z') {
        rot13Str[i] = c + 13 - 26;
      } else {
        rot13Str[i] = c + 13;
      }
    } else if (islower(c)) {
      if (c + 13 > 'z') {
        rot13Str[i] = c + 13 - 26;
      } else {
        rot13Str[i] = c + 13;
      }
    }

    cout << rot13Str[i];
  }

  return 0;
}