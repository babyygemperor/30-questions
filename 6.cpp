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
    Database database[5];
    ofstream file;

    file.open("STD.TXT", ios::out);    
    
    for (int i = 0; i < 5; ++i){
        cout << "Enter name : ";
        gets(database[i].name);
        cout << "Enter phone number : ";
        cin >> database[i].phone;
        file.write((char *) &database[i], sizeof(database[i]));
    }

    /*
    strcpy(database[0].name, "Aamin Gem");
    database[0].phone = 919838666420;
    file.write((char *) &database[0], sizeof(database[0]));

    strcpy(database[1].name, "Mum of Aamin Gem");
    database[1].phone = 919839666420;
    file.write((char *) &database[1], sizeof(database[1]));
    
    strcpy(database[2].name, "Pops of Aamin Gem");
    database[2].phone = 919833666420;
    file.write((char *) &database[2], sizeof(database[2]));
    
    strcpy(database[3].name, "Sis of Aamin Gem");
    database[3].phone = 919836666420;
    file.write((char *) &database[3], sizeof(database[3]));
    
    strcpy(database[4].name, "Girlfriend of Aamin Gem");
    database[4].phone = 499118666420;
    file.write((char *) &database[4], sizeof(database[4]));
    */
    file.close();
}

void truecaller(){
    int numberFound = 0;
    Database database;
    char student[24];
    ifstream file;

    cout << "Enter name of student : ";
    cin.getline(student, sizeof(student));

    file.open("STD.TXT", ios::in);

    while(!file.eof()){
        file.read((char *) &database, sizeof(Database));
        if (!strcasecmp(student, database.name)){
            cout << "Phone number : " << database.phone << '\n';
            numberFound = 1;
            break;
        }
    }

    if(!numberFound)
        cout << "Not found in the directory\n";
    
}
