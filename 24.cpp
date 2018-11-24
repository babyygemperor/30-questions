#include <iostream>

using std::cin;
using std::cout;

int array[3][3];

void input();
int isMagicSquare();

int main(){
    input();
    return 0;
}

void input(){
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            cout << "Enter element (" << i + 1 << ", " << j + 1 << ") : ";
            cin >> array[i][j];
        }
    }

    cout << '\n';

    int sum = isMagicSquare();

    if (sum)
        cout << "Magic square with sum = " << sum << "\n\n";
    else
        cout << "Not a magic square :\\\n\n";

}

int isMagicSquare(){    //returns false if not magic sqaure, else returns the sum
    int sumReference = 0;
    int newSum;
    
    for (int i = 0; i < 3; ++i)
        sumReference += array[0][i]; //Reference sum to compare with
    

    for (int i = 0; i < 3; ++i){
        newSum = 0;
        for (int j = 0; j < 3; ++j){
            newSum += array[i][j];  //Sum of each row
        }
        if (newSum != sumReference)
            return 0;
    }

    for (int i = 0; i < 3; ++i){
        newSum = 0;
        for (int j = 0; j < 3; ++j){
            newSum += array[j][i];  //Sum of each collumn
        }
        if (newSum != sumReference)
            return 0;
    }

    newSum = 0;
    
    for (int i = 0; i < 3; ++i)
        newSum += array[i][i];     //Sum of diagonal 1
    
    if (newSum != sumReference)
        return 0;

    newSum = 0;

    for (int i = 0; i < 3; ++i)
        newSum += array[i][2-i];  //Sum of diagonal 2

    if (newSum != sumReference)
        return 0;

    return sumReference;         //returning the sum of the magic square
}
