#include <bits/stdc++.h>
using namespace std;

int N;
int team;
int score1, score2;
int aSum, bSum;

string prevTime, currentTime;

string printTime(int time) {
  string m = "00" + to_string(time / 60);
  string s = "00" + to_string(time % 60);

  return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
}

int changeToInt(string t) {
  return atoi(t.substr(0, 2).c_str()) * 60 + atoi(t.substr(3, 2).c_str());
}

void go(int &sum, string currentTime) {
  sum += (changeToInt(currentTime) - changeToInt(prevTime));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> team >> currentTime;

    if (score1 > score2) {
      go(aSum, currentTime);
    } else if (score2 > score1) {
      go(bSum, currentTime);
    }

    team == 1 ? score1++ : score2++;
    prevTime = currentTime;
  }

  if (score1 > score2) {
    go(aSum, "48:00");
  } else if (score2 > score1) {
    go(bSum, "48:00");
  }

  cout << printTime(aSum) << "\n";
  cout << printTime(bSum) << "\n";

  return 0;
}