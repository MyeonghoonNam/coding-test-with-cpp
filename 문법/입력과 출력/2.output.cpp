#include <bits/stdc++.h>

using namespace std;

string a = "C++";
string b = "���";
string c = "����";
double number = 1.23456789;

int main() {
  cout << a << "\n";  // --1
  cout << b << " " << c << "\n";

  cout << fixed << setprecision(3) << number << "\n";  // --2

  printf("������ %s %s %s\n�Ҽ�: %lf", a.c_str(), b.c_str(), c.c_str(),
         number);  // --3

  return 0;
}

/**
 * 1. cout�� ���� ���
 * 2. cout �Ǽ� Ÿ�� ���
 *    Ư�� �ڸ��� ���� ����
 * 3. printf�� ���� ���
 *    ������ ������ ��¿� �����ϴ�.
 *    ���ڿ��� ����� �� string Ÿ���� ���ڿ��� ���� ������ Ÿ������ �ٲ���Ѵ�.
 *    c_str(): ���ڿ� Ÿ���� ������ Ÿ������ ��ȯ
 *    ���ڿ� ��½� cout�� �� ��
 */