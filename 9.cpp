#include <iostream>

using std::cin;
using std::cout;

struct Marks{
    unsigned int maths;
    unsigned int chem;
    unsigned int phy;
    unsigned int eng;
    unsigned int cs;
};

class Student{
    private:
        char name[24];
        char streamAllotted[7][17];
        int streamAllottedInt;
        int rollNo;
        int percentage;
        Marks marks;

        void getStream(){
            percentage = (marks.chem + marks.cs + marks.eng + marks.maths + marks.phy ) / 5;
            if (percentage > 96)
                streamAllottedInt = 0;
            else if (percentage > 91)
                streamAllottedInt = 1;
            else if (percentage > 86)
                streamAllottedInt = 2;
            else if (percentage > 81)
                streamAllottedInt = 3;
            else if (percentage > 76)
                streamAllottedInt = 4;
            else if (percentage > 71)
                streamAllottedInt = 5;
        }

    public:
        Student(){
            streamAllottedInt = 6;
            strcpy(streamAllotted[0], "Computer Science");
            strcpy(streamAllotted[1], "Electronics");
            strcpy(streamAllotted[2], "Mechanical");
            strcpy(streamAllotted[3], "Electrical");
            strcpy(streamAllotted[4], "Chemical");
            strcpy(streamAllotted[5], "Civil");
            strcpy(streamAllotted[6], "No stream allotted");
        }

        void input(){
            cout << "Enter name : ";
            cin.getline(name, sizeof(name));
            cout << "Enter Roll Number : ";
            cin >> rollNo;
            cout << "Enter marks in Computer Science : ";
            cin >> marks.cs;
            cout << "Enter marks in Mathematics : ";
            cin >> marks.maths;
            cout << "Enter marks in Chemistry : ";
            cin >> marks.chem;
            cout << "Enter marks in Physics : ";
            cin >> marks.phy;
            cout << "Enter marks in English : ";
            cin >> marks.eng;
        }

        void output(){
            getStream();
            cout << "Name : " << name << '\n';
            cout << "Roll Number : " << rollNo << '\n';
            cout << "Percentage : " << percentage << '\n';
            cout << "Stream allotted : " << streamAllotted[streamAllottedInt] << '\n';
        }
};


int main(){
    Student student;
    student.input();
    student.output();
    return 0;
}
