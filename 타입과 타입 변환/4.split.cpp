#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> split(string str, string delimeter) {
  vector<string> ret;
  ll pos;

  while ((pos = str.find(delimeter)) != string::npos) {
    string token = str.substr(0, pos);
    ret.push_back(token);
    str.erase(0, pos + delimeter.length());
  }

  ret.push_back(str);

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