#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int &a, int& b){
    int temp;
    if (a > b){
        temp = b;
        b = a; 
        a = temp;
    } 
}

void TranversalVector(vector<int> A) {
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

//冒泡排序
void BubbleSort(vector<int> &A,int N) {
    for(int i = N-1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if (A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

//插入排序
void InsertSort(vector<int> &A,int N) {
    for(int i = 1; i < N; i++) {
        int temp = A[i];
        int j;
        for(j = i; j > 0 && A[j-1] > temp; j--) {
            //如果当前元素> 取出的元素， 取出的元素插入
            A[j] = A[j-1];
        }
        A[j] = temp;
    }
}

//堆排序，好吧是我偷懒了，直接用了make_heap的函数.
void HeapSort(vector<int> &A, int N) {
    for (int i = 0; i < N; i++)
    {
        make_heap(A.begin()+i,A.end(),greater<int>());
        int minValue = *(A.begin()+i);
        A[i] = minValue;
    }
    
}

int main()
{
    vector<int> A={3,5,6,9,10,12,30,21,15,14,2,1};
    int N = A.size();
    BubbleSort(A,N);
    TranversalVector(A);

    A={3,5,6,9,10,12,30,21,15,14,2,1};
    InsertSort(A,N);
    TranversalVector(A);

    A={3,5,6,9,10,12,30,21,15,14,2,1};
    HeapSort(A,N);
    TranversalVector(A);

    return 0;
}