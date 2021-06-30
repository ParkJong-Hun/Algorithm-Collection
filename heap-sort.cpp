//힙 정렬
#include <iostream>
 
using namespace std;
//값을 서로 바꿈
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int here, int size) {
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    int max=here;
    if (left < size&&arr[left]>arr[max])
        max = left;
    if (right < size&&arr[right]>arr[max])
        max = right;
 
    if (max != here) {
        swap(&arr[here], &arr[max]);
        heapify(arr, max, size);
    }
}
 
void buildHeap(int arr[], int size) {
    int i,j;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, i, size);
        for (j = 0; j < size; j++)
            cout << arr[j];
        cout << "\n";
    }
}
 
void heapSort(int arr[],int size) {
    int treeSize;
    buildHeap(arr, size);
    for (treeSize = size - 1; treeSize >= 0; treeSize--) {
        swap(&arr[0], &arr[treeSize]);
        heapify(arr, 0,treeSize);
    }
}
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i];
    cout << "\n";
}
int main() {
    //트리에 저장될 노드
    int arr[] = { 2,5,4,7,6,8,1 };
    //몇 개의 노드인지
    int size = sizeof(arr) / sizeof(int);
    //힙 정렬 실행
    heapSort(arr, size);
    //결과 출력
    printArray(arr, size);
}
