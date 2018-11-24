#include <iostream>

using std::cout;
using std::cin;

void swap(int &a, int &b);
void print(int A[], int size);
void swapArray(int A[], int size);

const int size = 6;

int main(){
    int array[size] = {0, 1, 2, 52, 243, 1};
    print(array, size);
    swapArray(array, size);
    print(array, size);
    swapArray(array, size);
    print(array, size);
    return 0;
}

void swap(int &a, int &b){
    a += b;
    b = a - b;
    a -= b;
}

void print(int A[], int size){
    for (int i = 0; i < size; ++i)
        cout << A[i] << ' ';
    cout << '\n';
}

void swapArray(int A[], int size){
    if (size % 2)
        --size;

    for (int i = 0; i < size; i += 2)
        swap(A[i], A[i + 1]);
}
