//
//  main.cpp
//  QuickSort
//
//  Created by 김성진 on 5/20/24.
//

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
