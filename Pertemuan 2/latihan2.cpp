#include <iostream>
#include <stack>
using namespace std;

struct node{
    int value;
    node *next;
};

node *top = NULL;

void push(int n){
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = top;
    top = newNode;
    cout << n << " into ke Stack\n";
}

void pop(){
    if (top == NULL){
        cout<<"Stack kosong bre\n";
        return;
    }
    node *temp = top;
    top = top -> next;
    cout <<temp -> value << " begone dari Stack\n";
    delete temp;
}

void display(){
    if (top == NULL){
        cout<<"Stack kosong bre\n";
        return;
    }
    node *temp = top;
    cout<<"Isi stack: ";
    while (temp != NULL){
        cout<<temp->value <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    for (int i = 1; i<=3; i++){
        push(i*10);
        display();
    }
    pop();
    display();
}