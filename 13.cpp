#include <iostream>

using std::cin;
using std::cout;

char names[10][24];

void init();
void swap(char*, char*);
void print(char array[10][24], int n);
void selectionSort(char array[10][24], int n);

int main(){
    init();
    selectionSort(names, 10);
    print(names, 10);
    return 0;
}

void init(){
    for (int i = 0; i < 10; ++i){
        cout << "Enter name : ";
        gets(names[i]);
    }
}

void swap(char *x, char *y){
    char* temp;
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

void print(char array[10][24], int n){
    for (int i = 0; i < n; ++i)
        cout << array[i] << '\n';
}

void selectionSort(char array[10][24], int n){
    int i, j, min_idx;
    char min_str[24];
    for (i = 0; i < n - 1; ++i){
        min_idx = i;
        strcpy(min_str, array[i]);
        for (j = i + 1; j < n; ++j)
            if (strcmp(min_str, array[j]) > 0){
                strcpy(min_str, array[j]);
                min_idx = j;
            }
        swap(array[min_idx], array[i]);
    }
}
