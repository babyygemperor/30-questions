#include <iostream>

using std::cin;
using std::cout;

int array[10];

void input_data();
void bubbleSort();
void Binary_search();
void swap(int *x, int *y);
int binarySearch(int arr[], int, int, int);

int main(){
    input_data();
    Binary_search();
    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void input_data(){
    for (int i = 0; i < 10; ++i){
        cout << "Enter element " << i << " : ";
        cin >> array[i];
    }
    bubbleSort();
}

void bubbleSort(){  //Function to sort array in ascending order so binary search works
    cout << "----------------------------------\n";
    cout << "Sorting array...\n";
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9 - i; ++j)
            if(array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
    cout << "Array sorted in ascending order!\n";
    cout << "----------------------------------\n";
}

void Binary_search(){   //Function that displays and calls the real binary search
    int element;

    cout << "Enter element to find : ";
    cin >> element;
    
    cout << "Element is present at index " << binarySearch(array, 0, 10, element) << '\n';
}

int binarySearch(int arr[], int l, int r, int x) { //Actual binary search function

    while (l <= r) { 
        int m = l + (r - l)/2; 
  
        if (arr[m] == x) 
            return m; 
  
        if (arr[m] < x) 
            l = m + 1; 
  
        else
            r = m - 1; 
    } 
  
    return -1; 

}
