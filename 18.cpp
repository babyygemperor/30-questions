#include <iostream>

using std::cout;

int ALTERSUM(int B[][5], int M, int N);

int main(){
    int array[5][5] = {{1, 2, 3, 4, 5},
                   {1, 7, 3, 4, 5},
                   {1, 2, 4, 4, 5},
                   {1, 2, 3, 4, 5},
                   {1, 2, 3, 4, 5}
                    };
    cout << ALTERSUM(array, 5, 5) << '\n';
    return 0;
}

int ALTERSUM(int B[][5], int M, int N){
    int sum = 0;
    int i = 0;
    int j = 0;
    int x = 0;
    while(i < M && x < N){
        sum += B[i][x];
        j += 2;
        x = j % M;
        i = j / M;
    }
    return sum;
}
