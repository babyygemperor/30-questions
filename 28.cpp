#include <iostream>

using std::cin;
using std::cout;

class Hostel{
    private:
        unsigned int roomNumber;
        char name[24];
        unsigned int tarrif;
        unsigned int NOD;           //NOD = Number of days

        unsigned long CALC(){
            unsigned long returnAmount = NOD * tarrif;
            if (returnAmount > 10000)
                return returnAmount * 1.05;
            else
                return returnAmount;
        }

    public:
        Hostel(){
            tarrif = 999;
        }
        void CHECKIN(){
            cout << "Enter name : ";
            gets(name);
            cout << "Number of days : ";
            cin >> NOD;
            roomNumber = 101;
        }
        void CHECKOUT(){
            cout << "------------------------------------------------------\n";
            cout << "Room Number\tName\t\tTarrif\tNOD\tAmount\n";
            cout << roomNumber << "\t\t" << name << '\t' << tarrif << '\t'
                 << NOD << '\t' << CALC() << '\n';
            cout << "------------------------------------------------------\n";
        }
};

int main(){
    Hostel hostel;
    hostel.CHECKIN();
    hostel.CHECKOUT();
    return 0;
}
