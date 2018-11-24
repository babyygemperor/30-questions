#include <iostream>
#include "stdio_linux.h"

#define SIZE 10

using std::cin;
using std::cout;

class Stack{
    private:
        int STACK[SIZE];
        int top;

        void pop();
        void menu();
        void push();
        void view();
    public:
        Stack(){
            top = -1;
            menu();
        }
};

void Stack::pop(){
    if (top == -1)  //Stack is empty!
        cout << "Memory underflow!\n";      
    else {
        int t = STACK[top--];
        cout << t << " is sucessfully removed from the stack!\n";
    }
}

void Stack::menu(){
    char choice;

    do {
        cout << "-----------------------------------\n";
        cout << "1 : Push \n";
        cout << "2 : Pop \n";
        cout << "3 : View stack contents \n";
        cout << "4 : Quit \n";
        cout << "Choice : ";
        choice = getche();
        cout << "\n-----------------------------------\n";
        switch(choice){
            case '1':
                push();
                break;
            case '2':
                pop();
                break;
            case '3':
                view();
                break;
            case '4':
                break;
            default:
                cout << "WRONG INPUT!!!\n";
        }
    } while(choice != '4');             //Keeps running until quit option selected

}

void Stack::push(){
    if (top == SIZE - 1)                //Stack is full!
        cout << "Memory Overflow!\n";
    else {
        int element;
        cout << "Enter number to insert in stack : ";
        cin >> element;
        STACK[++top] = element;
        cout << element << " sucessfully added\n";
        cin.ignore();                   //Don't write this
    }
}

void Stack::view(){
    if (top == -1)
        cout << "Memory underflow!\n";  //Stack is empty
    else {
        for (int i = 0; i <= top; ++i)
            cout << STACK[i] << ' ';
        cout << '\n';
    }
}

int main(){
    Stack stack;    //Everything in constructor, no need to call functions
    return 0;
}
