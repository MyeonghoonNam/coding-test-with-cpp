#include <bits/stdc++.h>

using namespace std;

list<int> l;

void print(list<int> l) {
  for (auto it : l) cout << it << " ";
  cout << "\n";
}

int main() {
  for (int i = 1; i <= 3; i++) l.push_back(i);
  for (int i = 1; i <= 3; i++) l.push_front(i);

  l.insert(++l.begin(), 1000);
  print(l);

  l.erase(++l.begin()++);
  print(l);

  l.pop_front();
  l.pop_back();
  print(l);

  cout << l.front() << " : " << l.back() << "\n";

  l.clear();

  cout << l.size();

  return 0;
}