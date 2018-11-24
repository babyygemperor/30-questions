#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class STUDENT{
    protected:
        char name[20];
        char house[8];
    public:
        STUDENT(){
            strcpy(name, "");
            strcpy(house, "");
        }
};

class MARKS:private STUDENT{
    private:
        int maths;
        int cs;
        int eng;
        int phy;
        int chem;
    public:
        MARKS(){
            maths = 0;
            cs = 0;
            eng = 0;
            phy = 0;
            chem = 0;
        }
        void setName(){
            cout << "Enter name : ";
            cin.getline(name, sizeof(name));
        }
        void setHouse(){
            cout << "Enter house : ";
            cin >> house;
        }
        void setMarks(){
            cout << "Enter Mathematics marks : ";
            cin >> maths;
            cout << "Enter Computer Science marks : ";
            cin >> cs;
            cout << "Enter English marks : ";
            cin >> eng;
            cout << "Enter Physics marks : ";
            cin >> phy;
            cout << "Enter Chemistry marks : ";
            cin >> chem;
        }
        void print(){
            system("clear");
            cout << "Name : " << name << endl;
            cout << "House : " << house << endl;
            cout << "Mathematics \t| Computer Science \t| English \t| Physics \t| Chemistry\n";
            cout << maths << "\t\t|" << cs << "\t\t\t|" << eng  << "\t\t|" << phy << "\t\t|" << chem << endl ;
        }
};

int main(){
    MARKS marks;
    marks.setName();
    marks.setHouse();
    marks.setMarks();
    marks.print();
    return 0;
}
