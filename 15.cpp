#include <iostream>
#include "stdio_linux.h"

#define SIZE 20    //because it's better

using std::cin;
using std::cout;

int queue[SIZE];
int rear = -1;
int front = -1;

void menu();
void addElement();
void deleteElement();
void viewElements();

int main(){
    menu();
    return 0;
}

void menu(){
    char choice;
    while(1){
        cout << "-----------------------------\n";
        cout << "1 : Add Element\n";
        cout << "2 : Delete Element\n";
        cout << "3 : View Elements\n";
        cout << "4 : Quit\n";
        cout << "Enter Choice : ";
        choice = getche();
        cout << "\n-----------------------------\n";
        switch(choice){
            case '1':
                addElement();
                break;
            case '2':
                deleteElement();
                break;
            case '3':
                viewElements();
                break;
            case '4':
                return;
            default:
                cout << "Wrong choice!\n";
        }
    }
}

void addElement(){
    int choice;
    cout << "Enter number to enter : ";
    cin >> choice;
    cin.ignore();    //No need to add this in your code
    if (rear == SIZE - 1)
        cout << "Memory overflow!\n";   //queue is full
    else if (rear == -1){
        queue[0] = choice;
        front = rear = 0;
        cout << choice << " inserted successfully!\n";
    } else {
        ++rear;
        queue[rear] = choice;
        cout << choice << " inserted successfully!\n";
    }
}

void deleteElement(){
    if (front == -1)
        cout << "Memory underflow!\n";   //the queue is empty
    else {
        int temp = queue[front];
        cout << temp << " is deleted from the queue!\n";
        if (front == rear){
            front = rear = -1;
            cout << "Queue is empty now!\n";
        } else
            ++front;
    }
}

void viewElements(){
    if (front == -1)
        cout << "Memory underflow!";    //the queue is empty
    else
        for (int i = front; i <= rear; ++i)
            cout << queue[i] << ' ';
    cout <<'\n';
}
