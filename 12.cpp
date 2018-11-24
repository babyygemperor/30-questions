#include <iostream>

using std::cin;
using std::cout;

class Travel{
    private:
        unsigned int peopleVisited;
        unsigned long amountCollected;
    public:
        Travel(){
            peopleVisited = 0;
            amountCollected = 0;
        }
        void sellTicket(){
            ++peopleVisited;
            amountCollected += 50;
        }
        void display(){
            cout << "--------------------------------\n";
            cout << "People visited\tAmount Collected\n";
            cout << "--------------------------------\n";
            cout << peopleVisited << "\t\t" << amountCollected << '\n';
        }
};

/*
int main(){
    Travel travel;
    travel.sellTicket();
    travel.sellTicket();
    travel.sellTicket();
    travel.sellTicket();
    travel.sellTicket();
    travel.sellTicket();
    travel.sellTicket();
    travel.display();
    return 0;
}
*/