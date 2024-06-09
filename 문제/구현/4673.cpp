#include <bits/stdc++.h>
using namespace std;

#define MAX_NUMBER 10001

bool selfNumber[MAX_NUMBER] = {false};

int getSum(int number) {
  int sum = number;

  while (number != 0) {
    sum += number % 10;
    number /= 10;
  }

  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 1; i < MAX_NUMBER; i++) {
    int sum = getSum(i);

    if (sum <= MAX_NUMBER) {
      selfNumber[sum] = true;
    }
  }

  for (int i = 1; i < MAX_NUMBER; i++) {
    if (selfNumber[i] == false) {
      cout << i << "\n";
    }
  }

  return 0;
}