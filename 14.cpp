#include <iostream>

using std::cin;
using std::cout;

char name[24];
unsigned long totalUnits = 0;
unsigned long currentReading, previousReading, BillAmount;

void input();
void output();

int main(){
    input();
    output();
    return 0;
}

void input(){
    cout << "Enter your name : ";
    gets(name);
    cout << "Enter current reading : ";
    cin >> currentReading;
    cout << "Enter previous reading : ";
    cin >> previousReading;
    totalUnits = currentReading - previousReading;
}

void output(){
    cout << "---------------------------------------------------------------------------\n";
    cout << "Consumer's Name\t Current Reading\t Previous Reading\t BillAmount\n";
    cout << "---------------------------------------------------------------------------\n";
    cout << name << " \t " << currentReading << " \t\t\t " << previousReading << " \t\t\t ";
    if (totalUnits < 100)
        BillAmount = totalUnits * 2.0;
    else if (totalUnits < 200)
        BillAmount = totalUnits * 3.25;
    else if (totalUnits < 300)
        BillAmount = totalUnits * 4.75;
    else
        BillAmount = totalUnits * 5.25;
    cout << BillAmount << '\n';
}
