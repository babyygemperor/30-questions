#include <iostream>
#include <fstream>

using std::ios;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

struct Database{
    char country[24];
    char capital[24];
};

void initDatabases();
void quiz();

int main(){
    initDatabases();
    quiz();
    return 0;
}

void initDatabases(){
    Database database;
    ofstream file;

    file.open("QUIZ.DBF", ios::out);    
    
    cout << "------------------------------------\n";

    for (int i = 0; i < 5; ++i){
        cout << "Enter country name : ";
        gets(database.country);
        cin.ignore();
        cout << "Enter its Capital : ";
        gets(database.capital);
        cin.ignore();        
        file.write((char *) &database, sizeof(database));
        cout << "------------------------------------\n\n";
    }
    cout << "------------------------------------\n";
    file.close();
}

void quiz(){
    int capitalFound = 0;
    Database database;
    char country[24];
    ifstream file;

    cout << "Enter name of country : ";
    cin.getline(country, sizeof(country));

    file.open("QUIZ.DBF", ios::in);

    while(!file.eof()){
        file.read((char *) &database, sizeof(Database));
        if (!strcasecmp(country, database.country)){
            cout << "Its capital : " << database.capital << '\n';
            capitalFound = 1;
            break;
        }
    }

    if(!capitalFound)
        cout << "Country does not exist in the directory\n";
    
}
