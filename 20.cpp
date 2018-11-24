#include <iostream>
#include <fstream>
#include "stdio_linux.h"

using std::ios;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

struct Database{
    char name[24];
    unsigned int grade;
    int BSP;
    char sex;
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
    Database database[5];

    file.open("students.txt", ios::out);

    for (int i = 0; i < 5; ++i) {
        cout << "Enter name : ";
        cin.getline(database[i].name, sizeof(database[i].name));
        cout << "Enter class : ";
        cin >> database[i].grade;
        cout << "Press 0 for NBSP, 1 for BSP : ";
        cin.ignore();
        database[i].BSP = getche();
        cout << "\nPress M for Male, F for Female, T for Transgender : ";
        database[i].sex = getche();
        file.write((char*) &database[i], sizeof(Database));
        if (i != 4)
            cout << "\n----------------------------\n";
    }

}

void output(){
    int i = 0;
    int BSP, NBSP, F, M;
    BSP = NBSP = F = M = 0;
    ifstream file;
    Database databases[5];

    file.open("students.txt", ios::in);

    while(!file.eof())
        file.read((char*) &databases[i++], sizeof(Database));
    
    cout << "-----------------------------------------------------\n";
    cout << "Name\t\tClass\t\tCat(BSP/NBSP)\tSex\n";
    cout << "-----------------------------------------------------\n";
    
    for (int i = 0; i < 5; ++i){
        cout << databases[i].name << "\t\t" << databases[i].grade << "\t\t";
    
        if (databases[i].BSP == '1'){ //getche saves as a character, not integer
            cout << "BSP";
            ++BSP;
        } else {
            cout << "NBSP";
            ++NBSP;
        }

        cout << "\t\t" << databases[i].sex << "\t\t" << (char) databases[i].BSP << '\n';

        if (databases[i].sex == 'F' || databases[i].sex == 'f')
            ++F;
        else if (databases[i].sex == 'M' || databases[i].sex == 'm')
            ++M;

    }
    
    cout << "-----------------------------------------------------\n";
    cout << "Total BSP\t: " << BSP << '\n';
    cout << "Total NBSP\t: " << NBSP << '\n';
    cout << "Total Boys\t: " << M << '\n';
    cout << "Total Girls\t: " << F << '\n';

}
