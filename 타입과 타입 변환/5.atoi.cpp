#include <bits/stdc++.h>

using namespace std;

int main() {
  string s = "1";
  string s2 = "atoi";

  cout << atoi(s.c_str()) << "\n";
  cout << atoi(s2.c_str()) << "\n";

  return 0;
}

/**
 * atoi(s.c_str())�� C++���� ���ڿ� s�� ���� int�� ��ȯ�ϴ� ��� �� �ϳ��̴�.
 * string s�� const char*�� �ٲ�
 * ���ڿ��� ������ȯ�� �����ϸ� ������ȯ����, �Ұ����ϸ� 0�� ��ȯ�Ѵ�.
 */