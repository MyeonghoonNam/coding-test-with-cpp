
#include <bits/stdc++.h>

using namespace std;

/**
 string : ���ڿ�
 char[] or string���� Ÿ�� ����
 �迭ó�� index�� ���� ����
*/
string charTypeString() {
  string a = "Type";

  cout << a[0] << "\n";
  cout << a << "\n";

  // ���ڿ� �̾�� += ��ȣ, +�� ���ؼ��� �̾���� �� ������ �ð��� �����ɸ�
  // push_back() �޼��带 ���� �̾���� �� ������ �ѱ��ھ��� ����
  a += "Strin";
  cout << a << "\n";

  a.push_back('g');
  cout << a << "\n";

  a.pop_back();  // �ǵ� �ѱ��� ����
  cout << a << "\n";

  cout << a << " : " << a.size() << "\n";  // ���ڿ� ����
  cout << char(*a.begin()) << '\n';        // ���ڿ� ���ۿ��
  cout << char(*(a.end() - 1)) << '\n';    // ���ڿ� ������ ���

  // string& insert (size_t pos, const string& str);
  a.insert(0, "test ");  // Ư����ġ�� ���ڿ� ����
  cout << a << " : " << a.size() << "\n";

  // string& erase (size_t pos = 0, size_t len = npos);
  a.erase(0, 5);  // Ư����ġ���� ������ġ���� ���ڿ� ����
  cout << a << " : " << a.size() << "\n";

  // size_t find (const string& str, size_t pos = 0);
  // auto Ű���� : Ÿ�� �ڵ� �߷�
  // find : ���ڿ� ��ġ ��ȯ
  auto it = a.find("Str");
  if (it != string::npos) {
    cout << "index : " << it << "�� ���ԵǾ� �ִ�." << "\n";
  }

  cout << it << "\n";
  cout << string::npos << "\n";

  // string substr (size_t pos = 0, size_t len = npos) const;
  // Ư�� ��ġ���� ũ�⸸ŭ�� ���ڿ� ����
  cout << a.substr(5, 2) << '\n';

  // void reverse (BidirectionalIterator first, BidirectionalIterator last);
  // string�� �ƴ� STL���� �����ϴ� �޼���
  // ������ġ���� ��������ġ���� ���ڿ��� �����´�.
  // void Ÿ������ �ƹ��͵� ��ȯ���� �ʰ� ���� ���ڿ��� �ٲ۴�.
  reverse(a.begin(), a.end());
  cout << a << "\n";

  return a;
}

int main() {
  charTypeString();
  return 0;
}
