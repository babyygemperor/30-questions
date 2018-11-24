#include <iostream>

using std::cout;

void swap(int &a, int &b);
void print(int a[], int b[]);
void TRANSFER(int a[6], int b[6]);

int main(){
    int array1[6] = {15, 10, 12, 21, 52, 76};
    int array2[6] = {23, 41, 67, 83, 13, 53};
    print(array1, array2);
    TRANSFER(array1, array2);
    print(array1, array2);
    return 0;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void print(int a[], int b[]){
    cout << "\n-----------------\n";
    for (int i = 0; i < 6; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
    for (int j = 0; j < 6; j++){
        cout << b[j] << ' ';
    }
    cout << "\n-----------------\n";
}

void TRANSFER(int a[6], int b[6]){
    for (int i = 1; i < 6; i+=2) //swapping every odd position, adding by 2 to keep odd only
        swap(a[i], b[i]);
}
