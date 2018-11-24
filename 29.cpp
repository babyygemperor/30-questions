#include <iostream>
#include <fstream>
#include "stdio_linux.h"

using std::ios;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

void init();
void List_palindrome();
int isPalindrome(char word[24]);

int main(){
    init();
    List_palindrome();
    return 0;
}

void init(){
    char Continue;
    char word[24];
    ofstream file;
    
    file.open("WORDS.TXT", ios::out);

    while (1) {         //infinite loop to enter words
        cout << "Enter a word into the file : ";
        cin >> word;
        file << word << ' ';
        cin.ignore();
        cout << "Continue? (y/n) : ";
        Continue = getche();
        cout << '\n';
        if (Continue == 'n' || Continue == 'N')     //stop infinite loop when user says no
            break;
    }

    cout << "---------------------------------------------------------------\n";    

    file.close();
}

void List_palindrome(){
    int isPalindrome = 0;
    int start, length;
    int count = 0;
    char word[24];
    ifstream file;

    file.open("WORDS.TXT", ios::in);

    cout << "---------------------------------------------------------------\n";

    while(!file.eof()){
        file >> word;               //geting word by word from file
        start = 0;
        isPalindrome = 1;
        length = strlen(word) - 1;

        while (length > 1)
            if (word[start++] != word[length--])        //checks from end to end
                isPalindrome = 0;                       //CASE SENSITIVE!!!!!
        
        if (isPalindrome)
            cout << count++ + 1 << " : " << word << " is pallindrome!\n";
    
    }

    cout << "---------------------------------------------------------------\n";
    cout << "END OF FILE!\n";
    cout << "Total " << count << " case sensitive palindromes found in file!\n";
    cout << "---------------------------------------------------------------\n";
    cout << "---------------------------------------------------------------\n";

}
