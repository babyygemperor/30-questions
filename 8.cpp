#include <iostream>
#include <fstream>

using std::ios;
using std::cin;
using std::cout;
using std::getline;
using std::ifstream;
using std::ofstream;

struct Employee{
    char name[16];
    unsigned long basic;
};

void printDash(int);
void initDatabases();
void displayTable();

int main(){
    initDatabases();
    displayTable();
    return 0;
}

void printDash(int a){
    while(a--)
        cout << "-";
    cout << '\n';
}

void initDatabases(){
    ofstream file;
    Employee employee[5];

    file.open("EMP.TXT", ios::out);    

    for (int i = 0; i < 5; ++i){
        cout << "Enter name of Employee " << i + 1 << " : ";
        cin.ignore();
        cin.getline(employee[i].name, sizeof(employee[i].name));
        cout << "Enter basic of Employee " << i + 1 << " : ";
        cin >> employee[i].basic;
        file.write((char *) &employee[i], sizeof(employee[i]));
    }
    

    file.close();
}

void displayTable(){
    Employee employee;
    int Sno = 1;
    ifstream file;

    file.open("EMP.TXT", ios::in);

    cout << "\t\t\t\t SALARY REGISTER \n";
    printDash(72);
    cout << "S.No \t Name \t\t Basic \t  DA \t HRA \t Total \t PF \t Net-pay \n";
    printDash(72);

    while(Sno <= 5){
        file.read((char *) &employee, sizeof(Employee));
        cout << Sno++ << " \t " << employee.name << " \t " << employee.basic
             << "\t " << employee.basic * 0.3 << " \t " << employee.basic * 0.1
             << " \t " << employee.basic * 1.4 << " \t " << employee.basic * 0.13
             << " \t " << employee.basic * 1.53 << '\n';
    }

    printDash(72);

    file.close();    
}
