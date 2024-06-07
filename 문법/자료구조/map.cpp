#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main() {
  mp.insert({"jenn", 19});
  mp.insert({"dobydd", 25});

  // {jenn, 19}만 조회
  auto it = mp.find("jenn");

  if (it != mp.end()) {
    cout << (*it).first << " : " << (*it).second << "\n";
  }

  cout << "---------------" << "\n";

  // 주의!!
  // map의 특정 요소를 대괄호 조회시 없는 키값의 경우 키:0으로 자동 추가 된다.
  mp["joon"];  // 기존에 없던 키값이므로 값이 0인 키로 추가된다.

  for (auto it : mp) {
    cout << it.first << " : " << it.second << "\n";
  }

  cout << "---------------" << "\n";

  mp.erase("joon");

  for (auto it : mp) {
    cout << it.first << " : " << it.second << "\n";
  }

  cout << "---------------" << "\n";

  mp.clear();

  for (auto it : mp) {
    cout << it.first << " : " << it.second << "\n";
  }

  cout << "---------------" << "\n";

  cout << mp.size() << "\n";
  cout << "end";

  return 0;
}