#include <iostream>
using namespace std;

int main() {
    int input;
    while(cin>>input){
    if(input>2){
        int first=0;
        int second=1;
        int next;
        for(int i=2;i<=input;i++){
            next = (first + second) % 10;
            first = second;
            second = next;
        }
        cout<<second<<'\n';
    }
    else if(input>0){
        cout<<'1'<<'\n';
    }
    else{
        cout<<'0'<<'\n';
    }
    }
    return 0;
}