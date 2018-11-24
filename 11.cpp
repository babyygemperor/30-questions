#include <iostream>
#include <fstream>

using std::ios;
using std::cin;
using std::cout;
using std::ofstream;
using std::ifstream;

ifstream ifile;

struct Password{
    char username[24];
    char password[8];
};

void input();
void login();

int main(){
    input(); //Comment to stop refreshing password database everytime
    login();
    return 0;
}

void input(){
    ofstream file;
    file.open("password.dbf", ios::out);
    Password password[5];

    for (int i = 0; i < 5; ++i){
        cout << "Enter username " << i + 1 << " : ";
        gets(password[i].username);
        cout << "Enter password : ";
        gets(password[i].password);
        file.write((char *) &password[i], sizeof(password[i]));
    }
    cout << "__________________________________\n";

    file.close();

}

void login(){
    ifstream file;
    file.open("password.dbf", ios::in);
    Password password;
    Password storedPassword;

    int loginSuccessful = 0; //boolean variable to confirm authentication

    system("clear");

    cout << "Enter username : ";
    gets(password.username);
    cout << "Enter password : ";
    gets(password.password);

    for (int i = 0; i < 5; ++i){
        file.read((char *) &storedPassword, sizeof(storedPassword));
        if(!strcmp(password.username, storedPassword.username))  //checking username
            if (!strcmp(password.password, storedPassword.password)){  //checking password
                loginSuccessful = 1;
                break;
            }
    }

    if (loginSuccessful)
        cout << "access allowed\n";
    else
        cout << "Access denied\n";

    file.close();

}
