# temp

$$
\huge {\textsf {퀵 쇼트와 리스트 알고리즘 구현 및 학습}}
$$

# **`퀵 쇼트`**

```
퀵 쇼트는 전체 리스트를 2개의 부분 리스트로 분할하고 각각을 가시 퀵 쇼트한다.
하지만 합병 정렬과는 다르게 피벗을 이용하여 피벗보다 작은 요소들은 모두 피벗의 왼쪽으로 옮겨지고 피벗보다 큰
요소들은 모두 피벗의 왼쪽으로 옮겨지므로 비균등하게 분할된다.
```

## [사진]

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void qsort(std::vector<int>& a, int left, int right) {
    if (left >= right) return; // 요소가 1개인 경우 재귀를 종료
    
    int p = a[right]; // pivot
    int i = left - 1; // pivot보다 작은 요소의 위치 인덱스(0부터 이용하기 위해 -1로 초기화)
    
    for (int j = left; j < right; j++) { // 0부터 pivot 전까지 모든 요소를 순회
        if (a[j] < p) // pivot보다 작은 요소가 있을 경우
            std::swap(a[++i], a[j]); // 배열의 시작 부분부터 pivot보다 작은 요소를 위치시킴
    }
    std::swap(a[++i], a[right]); // pivot을 정렬된 자리에 위치 시킴(p보다 작은 요소 | p | p보다 큰 요소)
    qsort(a, left, i - 1); // pivot의 앞부분 재귀 호출
    qsort(a, i + 1, right); // pivot의 뒷부분 재귀 호출
}

int main() {
    std::vector<int> a = {3,2,5,1,4}; // vector 선언
    qsort(a, 0, a.size() - 1); // 퀵정렬 호출
    for (int x : a) //vector 출력
        std::cout << x << " ";
    
    return 0;
}

```

# **`연결 리스트`**

```
연결 리스트는 물리적으로 흩어져 있는 자료들을 서로 연결하여 하나로 묶는 것이다.
크기가 동적이고 삭제나 삽입 시 데이터 이동이 필요없다. 
```

```cpp
#include <iostream>

struct Node {
    int data; // 노드의 데이터 필드
    Node* next; //노드의 다음노드 주소 필드
    Node(int d) : data(d), next(nullptr) {} // 생성자를 이용한 초기화
};

class LinkedList {
    Node* head; // 헤드 포인터 노드
public:
    LinkedList() : head(nullptr) {} // 생성자를 이용한 초기화

    void add(int d) { // 삽입함수
        Node* n = new Node(d); // 새로운 노드 생성
        if (!head) { // 헤드 포인터가 "null"일 경우(공백 리스트)
            head = n; // 헤드 포인터에 새로운 노드 포인터 저장(헤드 포인터가 새로운 노드를 가리키게 됨)
        } else { // 헤드 포인터가 "null"이 아닐 경우(공백 리스트 x)
            Node* t = head; // 삽입할 위치의 선행 노드(끝 노드)
            while (t->next) // 끝 노드까지 순회 (ㅁ-ㅁ-ㅁ(t)-x)
                t = t->next; // 다음 노드로 이동
            t->next = n; // 끝 노드에 새로운 노드를 연결
        }
    }

    void print() {
        Node* t = head; // 순회할 노드 포인터
        while (t) { // 끝 노드까지 순회 (ㅁ-ㅁ-ㅁ-x(t))
            std::cout << t->data << " "; // 데이터를 출력
            t = t->next; // 다음 노드로 이동
        }
        std::cout << std::endl; // 줄바꿈
    }

    ~LinkedList() { // 소멸자
        while (head) { // 끝 노드까지 순회 (ㅁ-ㅁ-ㅁ-x(t))
            Node* t = head; // 삭제할 노드 포인터
            head = head->next; // 다음 노드로 이동
            delete t; // 삭제할 노드 삭제
        }
    }
};

int main() {
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.print();
    return 0;
}

```

