#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// �ð����⵵ ���� ���� ���� split �Լ�
// vector<string> split(string str, string delimiter) {
//   vector<string> ret;
//   ll pos;

//   while ((pos = str.find(delimiter)) != string::npos) {
//     string token = str.substr(0, pos);
//     ret.push_back(token);
//     str.erase(0, pos + delimiter.length());
//   }

//   ret.push_back(str);

//   return ret;
// }

// �ð����⵵�� �� �� ������ split �Լ�
vector<string> split(string str, string delimiter) {
  vector<string> ret;
  ll start = 0;
  ll end = str.find(delimiter);

  while (end != string::npos) {
    string token = str.substr(start, end - start);

    ret.push_back(token);
    start = end + delimiter.length();
    end = str.find(delimiter, start);
  }

  ret.push_back(str.substr(start));

  return ret;
}

int main() {
  string s = "String Split Test";
  string d = " ";

  vector<string> ret = split(s, d);

  for (string el : ret) {
    cout << el << "\n";
  }

  return 0;
}