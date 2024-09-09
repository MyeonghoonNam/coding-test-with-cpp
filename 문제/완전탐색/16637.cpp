#include <bits/stdc++.h>
using namespace std;

int N;
string S;
vector<int> numbers;
vector<char> operlist;
int ret = INT_MIN;

int oper(int number1, int number2, char op) {
  if (op == '+') return number1 + number2;
  if (op == '-') return number1 - number2;
  if (op == '*') return number1 * number2;

  return (0);
}

void go(int idx, int sum) {
  if (idx == (int)numbers.size() - 1) {
    ret = max(ret, sum);
    return;
  }

  go(idx + 1, oper(sum, numbers[idx + 1], operlist[idx]));

  if (idx + 2 <= (int)numbers.size() - 1) {
    int temp = oper(numbers[idx + 1], numbers[idx + 2], operlist[idx + 1]);
    go(idx + 2, oper(sum, temp, operlist[idx]));
  }

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> S;

  for (int i = 0; i < N; i++) {
    if (i % 2 == 0)
      numbers.push_back(S[i] - '0');
    else
      operlist.push_back(S[i]);
  }

  go(0, numbers[0]);

  cout << ret;

  return 0;
}