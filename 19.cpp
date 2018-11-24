#include <iostream>
#include <fstream>

using std::ios;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

struct Student{
    unsigned int rollNo;
    unsigned int percentage;
};

void input();
void output();
void swap(Student *x, Student *y);
void bubbleSort(Student student[]);

int main(){
    //input();
    output();
    return 0;
}

void input(){
    Student student[10];
    ofstream file;

    file.open("RESULT.TXT", ios::out);

    for (int i = 0; i < 10; ++i){
        cout << "Enter Roll Number : ";
        cin >> student[i].rollNo;
        cout << "Enter percentage : ";
        cin >> student[i].percentage;
        file.write((char*) &student[i], sizeof(Student));
    }

    cout << "---------------------------------------\n";

}

void output(){
    Student students[10];
    ifstream file;
    int i = 0;
    
    file.open("RESULT.TXT", ios::in);

    while(!file.eof())
        file.read((char*) &students[i++], sizeof(Student));

    bubbleSort(students);

    cout << "Rank\tRollNo\tPercentage\n";

    for (int i = 0; i < 10; ++i){
        cout << i + 1 << '\t' << students[i].rollNo << '\t' << students[i].percentage << '\n';
    }
}

void swap(Student *x, Student *y){
    Student temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(Student student[]){
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9 - i; ++j)
            if (student[j].percentage < student[j + 1].percentage) //arranging in ascending order
                swap(&student[j], &student[j + 1]);
}
