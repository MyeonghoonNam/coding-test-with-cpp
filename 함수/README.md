## fill()과 memset()

fill()과 memset()은 배열을 초기화 할 때 사용한다.

fill은 모든 값으로 초기화 할 수다.
0, 1, 100 등 모든 숫자로 초기화가 가능하다.

memset()같은 경우 -1, 0으로만 초기화가 가능하다.

### fill()

```c++
void fill (ForwardIterator first, ForwardIterator last, const T& val);
```

- `first` : 채우고자 하는 자료구조의 시작위치 iterator
- `last` : 채우고자 하는 자료구조의 끝위치 iterator이며 last는 포함하지 않는다.
- `val` : first부터 last전까지 채우고자 하는 값으로 어떤 객체나 자료형을 넘겨줘도 템플릿 T에 의해서 가능하다.

### memset()

```c++
void * memset ( void * ptr, int value, size_t num );
```

- `ptr` : 메모리의 시작 주소
- `value` : 메모리에 세팅하고자 하는 값
- `num` : 초기화하고자 하는 길이

## memcpy()와 copy()

어떤 변수를 깊은 복사할 때 `memcpy()`와 `copy()`를 사용한다.
`memcpy()`는 Array끼리 복사할 때, `copy()`는 Array, vector에 모두 사용

### memcpy()

memcpy()는 어떤 변수의 메모리에 있는 값들을 다른 변수의 `특정 메모리값`으로 복사할 때 사용

```c++
void * memcpy ( void * destination, const void * source, size_t num );
```

### copy()

memcpy()와 똑같은 동작을 하지만 vector와 Array 모두 쓰일 수 있다.

```c++
copy (InputIterator first, InputIterator last, OutputIterator result)
```

## sort()

배열 등 컨테이너들의 요소를 정렬하는 함수.

```
sort(first, last, *커스텀비교함수)
```

`first`는 정렬하고 싶은 배열의 첫번째 이터레이터로 주소값이 들어가야한다.
`last`는 정렬하고 싶은 배열의 마지막 이터레이터
first <= 범위 < last 라는 범위를 갖는다.

즉, first는 포함하고 last는 포함하지 않는다.

세번째 매개변수, 커스텀비교함수를 넣지 않으면 기본적으로 오름차순이며 이를 커스텀비교함수에 `greater<타입>()`을 넣어 내림차순으로 변경할 수 있다.

`less<타입>()`을 통해 오름차순으로 정렬할 수 도 있다.
