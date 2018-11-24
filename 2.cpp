#include <iostream>

using std::cout;
using std::cin;

void swap(int &a, int &b);
void print(int A[], int size);
void swapArray(int A[], int size);

const int size = 6;

int main(){
    int array[size] = {0, 1, 2, 52, 243, 69};
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
    if (size % 2){
        cout << "Can't swap an array with odd number of elements! \n";
        return; 
    }

    int half = size/2;

    for (int i = 0; i < half; ++i)
        swap(A[i], A[i + half]);
}
