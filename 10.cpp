#include <iostream>
#include <fstream>

using std::ios;
using std::cin;
using std::cout;
using std::ofstream;
using std::ifstream;

ifstream ifile;

struct Student{
    char name[24];
    char house[8];
    unsigned int amount;
};

void input();
void output();

int main(){
    input();
    output();
    return 0;
}

void input(){
    ofstream file;
    file.open("STUDENT.TXT", ios::out);
    Student student[5];

    for (int i = 0; i < 5; ++i){
        cout << "Enter name of student " << i + 1 << " : ";
        cin.getline(student[i].name, sizeof(student[i].name));
        cout << "Enter house : ";
        cin >> student[i].house;
        cout << "Enter amount collected : ";
        cin >> student[i].amount;
        file.write((char *) &student[i], sizeof(student[i]));
    }
    cout << "__________________________________\n";
    file.close();

}

void output(){
    ifstream file;
    file.open("STUDENT.TXT", ios::in);
    Student student[5];

    system("clear");

    cout << "_________________________________________________\n";
    cout << "Name of the student\tHouse\tAmount Collected\n";
    cout << "_________________________________________________\n";

    for (int i = 0; i < 5; ++i){
        file.read((char *) &student[i], sizeof(student[i]));
        cout << student[i].name << "\t\t\t" << student[i].house 
        << '\t' << student[i].amount << '\n';    
    }

    cout << "_________________________________________________\n";

    file.close();

}
