#include <iostream>
using namespace std;

#define max 5
int stack[max];
int top = -1;// awalnya kosong
    
//push
void push (int value){
    if (top == max){
        cout<< "Stack Penuh! \n";
    } else {
        top++;
        stack[top] = value;
        cout<<value << " masuk ke stack \n";
    }
}

//pop
void pop(){
    if (top == -1){
        cout<<"Stack Kosong !\n";
    } else {
        cout<<"\n"<<stack[top]<<" dihapus dari stack.\n";
        top--;
    }
}

//nampilin stack
void display(){
    if (top == -1){
        cout<<"Stack kosong!\n";
    } else {
        cout<< "\nisi stack : \n";
        for (int i = top; i>= 0; i--){
            cout<< stack[i]<<" ";
        }
        // cout<<"\nisi array (index 0 ke max-1): \n";
        // for (int i = 0; i<top; i++){
        //     cout<<"[ "<<i<<" ]"<<stack[i]<<" ";
        // }
        cout<<endl;
    }
}

int main(){
    for (int i = 1; i<6 ; i++){
        push(i*10);
    }
    for (int i = 1; i<5; i++){
        display();
        pop();
    }
    display();
    return 0;
}

