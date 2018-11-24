#include <iostream>

using std::cin;
using std::cout;

class ITR{
    private:
        char name[24];
        unsigned long totalIncome;
        
        void getName(){
            cout << "Enter name : ";
            gets(name);
        }
        
        void getIncome(){
            cout << "Enter Total Income : ";
            cin >> totalIncome;
        }

        void calculateTax(){
            if (totalIncome <= 35000)
                cout << "Taxation amount = 0";
            else if (totalIncome <= 60000)
                cout << "Taxation amount = " << (long) (totalIncome * 0.2);
            else if (totalIncome <= 120000)
                cout << "Taxation amount = " << (long) (totalIncome * 0.3);
            else
                cout << "Taxation amount = " << (long) (totalIncome * 0.4);
            cout << '\n';
        }
    
    public:
        ITR(){
            getName();
            getIncome();
            calculateTax();
        }    
};

int main(){
    ITR itr;
    return 0;
}
