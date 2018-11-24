#include <iostream>
#include <fstream>

using std::ios;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

struct Database{
    char name[24];
    unsigned long long phone;
};

void initDatabases();
void truecaller();

int main(){
    initDatabases();
    truecaller();
    return 0;
}

void initDatabases(){
    Database database;
    ofstream file;

    file.open("PHONE.DAT", ios::out);    
    
    for (int i = 0; i < 5; ++i){
        cout << "Enter name : ";
        gets(database.name);
        cout << "Enter phone number : ";
        cin >> database.phone;
        file.write((char *) &database, sizeof(database));
    }

    file.close();
}

void truecaller(){
    int numberFound = 0;
    Database database;
    char student[24];
    ifstream file;

    cout << "Enter name of student : ";
    cin.getline(student, sizeof(student));

    file.open("PHONE.DAT", ios::in);

    while(!file.eof()){
        file.read((char *) &database, sizeof(Database));
        if (!strcasecmp(student, database.name)){
            cout << "Phone number : " << database.phone << '\n';
            numberFound = 1;
            break;
        }
    }

    if(!numberFound)
        cout << "NOT FOUND in the directory\n";
    
}
