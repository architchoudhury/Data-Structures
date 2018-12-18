#include <iostream>
using namespace std;
static int table[1050];
static int current;

static void output();

static void insert(int value, int position){
    current++;
    if(position>=current)
        table[position] = value;
    else{
        for(int i=position;i<=current;i++){
            int temp = table[i];
            table[i]=value;
            value=temp;
        }
    }
    //output();
}

static void deleteValue(int position){
    int value = table[current];
    table[current--] = NULL;
    for(int i=current;i>=position;i--){
        int temp = table[i];
        table[i]=value;
        value=temp;
    }
    //output();
}

static void reverse(int i, int j){
    for(int a=0;a<(j-i+1)/2;a++){
        int temp = table[j-a];
        table[j-a] = table[i+a];
        table[i+a] = temp;
    }
    //output();
}

static void output(int position){
    cout<<table[position]<<endl;
}

static void output(){
    for(int i=1;i<=current;i++){
        cout<<table[i]<<" ";
    }
    
}

int main() {
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>table[i];
    current = N;
    int Q;
    cin>>Q;
    for(int i=0; i<Q; i++){
        int choice;
        cin>>choice;
        int a,b;
        switch(choice){
            case 1:
                cin>>a>>b;
                insert(b, a+1);
                break;
            case 2:
                cin>>a;
                deleteValue(a);
                break;
            case 3:
                cin>>a>>b;
                reverse(a,b);
                break;
            case 4:
                cin>>a;
                output(a);
                break;
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
    
    return 0;
}