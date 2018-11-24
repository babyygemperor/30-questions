#include <iostream>

using std::cout;
using std::cin;

void swap(int*, int*);
void initArray(int A[], int n);
void printArray(int A[], int n);
void bubbleSort(int A[], int n);

int* array;
const int size = 10;

int main(){
    array = new int[size];
    initArray(array, size);
    bubbleSort(array, size);
    printArray(array, size);
    return 0;
}

void swap(int* a, int* b){
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void initArray(int A[], int n){
    for (int i = 0; i < n; ++i){
        cout << "Enter element " << i + 1 << " : ";
        cin >> A[i];
    }
}

void printArray(int A[], int n){
    for (int i = 0; i < n; ++i){
        cout << A[i] << '\n';
    }
}

void bubbleSort(int A[], int n){
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (A[j] < A[j + 1])
                swap(&A[j], &A[j + 1]);
}
