#include <iostream>
#include <fstream>
#include "stdio_linux.h"

using std::ios;
using std::cin;
using std::cout;
using std::getchar;
using std::ofstream;
using std::ifstream;

ofstream file;
ifstream ifile;

void writeFile();
void count();

int main(){
    writeFile();
    count();
    return 0;
}

void writeFile(){
    file.open("SENT.TXT", ios::out);
    char string[80];
    char ch;
    cout << "Enter line to be stored in file \n";
    while(1){
        cin.getline(string, 80);
        file << string;
        file << '\n';
        cout << "Continue (y/n)? : ";
        ch = getche();
        cout << '\n';
        if (ch == 'y' || ch == 'Y')
            continue;
        else
            break;
    }
    file.close();
}

void count(){
    ifile.open("SENT.TXT", ios::in);
    int countTo = 0;
    int countThe = 0;
    char word[4];
    while(1){
        ifile >> word;
        if (!strcasecmp(word, "to"))
            countTo++;
        else if (!strcasecmp(word, "the"))
            countThe++;
        if (ifile.eof())
            break;
    }

    cout << "Total number of \"to\"s = " << countTo << '\n';
    cout << "Total number of \"the\"s = " << countThe << '\n';
    ifile.close();
}
