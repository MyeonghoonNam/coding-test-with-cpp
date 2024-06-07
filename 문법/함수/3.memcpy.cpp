#include <bits/stdc++.h>

using namespace std;

int main() {
  int source[3] = {1, 2, 3};
  int destination[3];

  vector<int> v_source = {1, 2, 3};
  vector<int> v_destination(3);

  memcpy(destination, source, sizeof(source));

  cout << destination[1] << "\n";

  destination[1] = 100;

  // 일반 배열은 깊은 복사로 동작
  cout << destination[1] << "\n";
  cout << source[1] << "\n";

  memcpy(&v_destination, &v_source, 3 * sizeof(int));

  cout << v_destination[1] << "\n";

  // vector에서는 얇은 복사로 동작
  v_destination[1] = 200;
  cout << v_destination[1] << "\n";
  cout << v_source[1] << "\n";

  return 0;
}