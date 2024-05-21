//
//  main.cpp
//  LinkedList
//
//  Created by 김성진 on 5/21/24.
//

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
