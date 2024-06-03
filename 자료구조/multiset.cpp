#include <bits/stdc++.h>

using namespace std;

int main() {
  multiset<int> mst;

  mst.insert(2);
  mst.insert(1);
  mst.insert(1);
  mst.insert(2);

  for (auto it : mst) cout << it << " ";

  return 0;
}