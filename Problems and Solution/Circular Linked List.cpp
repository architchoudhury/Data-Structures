#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
} *last;

class circularLinkedList{
    
public:
    static void addNode(int value, int position){
        node *temp = new node;
        int count = 0;
        temp->data=value;
        if (last == NULL)
        {
            last = temp;
            temp->next = last;
        }
        else
        {
            while(count++<position-1){
                last = last->next;
            }
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }
    
    static void deleteNode(int position){
        int count = 0;
        while(count++!=position-1){
            last = last->next;
        }
        node *next = last->next;
        last->next = next->next;
        last = last->next;
        delete next;
        //display();
    }
    
    static void displayNode(int position){
        int count = 1;
        if (last == NULL)
        {
            cout<<"List is empty!"<<endl;
        }
        else
        {
            while(count++!=position){
                last = last->next;
            }
            cout<<last->data;
        }
        cout<<endl;
    }
    
    circularLinkedList() {
        last = NULL;
    }
    
};

int main() {
    int initialNumber;
    cin>>initialNumber;
    for(int i=0; i<initialNumber; i++){
        int n;
        cin>>n;
        circularLinkedList::addNode(n, 0);
    }
    //circularLinkedList::display();
    last = last->next;
    int numOfOp;
    cin>> numOfOp;
    for(int i=0; i<numOfOp; i++){
        int choice;
        cin>>choice;
        int a,b;
        switch(choice){
            case 1:
                cin>>a>>b;
                circularLinkedList::addNode(b, a);
                break;
            case 2:
                cin>>a;
                circularLinkedList::deleteNode(a-1);
                break;
            case 3:
                cin>>a;
                circularLinkedList::displayNode(a);
                break;
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}