#include <iostream>

using std::cin;
using std::cout;

int IS_SORT(int*);
int isAscending(int*);
int isDescending(int*);

int main(){
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    if (IS_SORT(array))
        cout << "The array is sorted!\n";
    else
        cout << "The array is not sorted!\n";
    return 0;
}

int IS_SORT(int array[10]){
    if (array[0] <= array[1])
        return isAscending(array);
    if (array[0] >= array[1])
        return isDescending(array);
    return 0;
}

int isAscending(int array[10]){
    for (int i = 0; i < 9; ++i)
        if (!(array[i] <= array[i + 1]))
            return 0;
    return 1;
}

int isDescending(int array[10]){
    for (int i = 0; i < 9; ++i)
        if (!(array[i] >= array[i + 1]))
            return 0;
    return 1;
}
