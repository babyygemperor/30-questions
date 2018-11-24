#include <iostream>
#include "stdio_linux.h"

#define SIZE 24    //because it's better
#define ELEMENTS 10

using std::cin;
using std::cout;

char queue[ELEMENTS][SIZE];
int rear = -1;
int front = -1;

void menu();
void addName();
void viewNames();
void deleteName();

int main(){
    menu();
    return 0;
}

void menu(){
    char choice;
    cout << "Queue for storing city names!\n";
    while(1){   //infinite loop for menu
        cout << "-----------------------------\n";
        cout << "1 : Add Name\n";
        cout << "2 : Delete Name\n";
        cout << "3 : View Names\n";
        cout << "4 : Quit\n";
        cout << "Enter Choice : ";
        choice = getche();
        cout << "\n-----------------------------\n";
        switch(choice){
            case '1':
                addName();
                break;
            case '2':
                deleteName();
                break;
            case '3':
                viewNames();
                break;
            case '4':
                return;
            default:
                cout << "Wrong choice!\n";
        }
    }
}

void addName(){
    char choice[SIZE];
    cout << "Enter name to enter : ";
    cin.ignore();    //No need to add this in your code
    gets(choice);
    if (rear == SIZE - 1)
        cout << "Memory overflow!\n";   //queue is full
    else if (rear == -1){
        strcpy(queue[0], choice);
        front = rear = 0;
        cout << choice << " inserted successfully!\n";
    } else {
        ++rear;
        strcpy(queue[rear], choice);
        cout << choice << " inserted successfully!\n";
    }
}

void viewNames(){
    if (front == -1)
        cout << "Memory underflow!";    //the queue is empty
    else
        for (int i = front; i <= rear; ++i)
            cout << queue[i] << ' ';
    cout <<'\n';
}

void deleteName(){
    if (front == -1)
        cout << "Memory underflow!\n";   //the queue is empty
    else {
        char temp[SIZE]; 
        strcpy(temp, queue[front]);
        cout << temp << " is deleted from the queue!\n";
        if (front == rear){             //implies queue has 1 element
            front = rear = -1;
            cout << "Queue is empty now!\n";
        } else 
            ++front;
    }
}
