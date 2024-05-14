
#include <bits/stdc++.h>

using namespace std;

/**
 string : 문자열
 char[] or string으로 타입 지정
 배열처럼 index를 통한 접근
*/
string charTypeString() {
  string a = "Type";

  cout << a[0] << "\n";
  cout << a << "\n";

  // 문자열 이어쓰기 += 기호, +를 통해서도 이어붙일 수 있지만 시간이 오래걸림
  // push_back() 메서드를 통해 이어붙일 수 있지만 한글자씩만 가능
  a += "Strin";
  cout << a << "\n";

  a.push_back('g');
  cout << a << "\n";

  a.pop_back();  // 맨뒤 한글자 삭제
  cout << a << "\n";

  cout << a << " : " << a.size() << "\n";  // 문자열 길이
  cout << char(*a.begin()) << '\n';        // 문자열 시작요소
  cout << char(*(a.end() - 1)) << '\n';    // 문자열 마지막 요소

  // string& insert (size_t pos, const string& str);
  a.insert(0, "test ");  // 특정위치에 문자열 삽입
  cout << a << " : " << a.size() << "\n";

  // string& erase (size_t pos = 0, size_t len = npos);
  a.erase(0, 5);  // 특정위치부터 지정위치까지 문자열 삭제
  cout << a << " : " << a.size() << "\n";

  // size_t find (const string& str, size_t pos = 0);
  // auto 키워드 : 타입 자동 추론
  // find : 문자열 위치 반환
  auto it = a.find("Str");
  if (it != string::npos) {
    cout << "index : " << it << "에 포함되어 있다." << "\n";
  }

  cout << it << "\n";
  cout << string::npos << "\n";

  // string substr (size_t pos = 0, size_t len = npos) const;
  // 특정 위치에서 크기만큼의 문자열 추출
  cout << a.substr(5, 2) << '\n';

  // void reverse (BidirectionalIterator first, BidirectionalIterator last);
  // string이 아닌 STL에서 지원하는 메서드
  // 시작위치부터 마지막위치까지 문자열을 뒤집는다.
  // void 타입으로 아무것도 반환하지 않고 원본 문자열만 바꾼다.
  reverse(a.begin(), a.end());
  cout << a << "\n";

  return a;
}

int main() {
  charTypeString();
  return 0;
}
