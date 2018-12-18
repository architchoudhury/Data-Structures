#include <iostream>
#include <stack>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        stack <int> poker;
        stack <int> max;
        int currentMax = 0;
        int n;
        cin>>n;
        while(n-->0){
            int a;
            cin>>a;
            if(a>currentMax)
                currentMax = a;
            poker.push(a);
            max.push(currentMax);
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            char choice;
            cin>>choice;
            int a;
            switch(choice){
                case 'm':
                    cout<<max.top()<<endl;
                    break;
                case 'r':
                    max.pop();
                    poker.pop();
                    if(max.empty())
                        currentMax=0;
                    else
                        currentMax=max.top();
                    break;
                case 'a':
                    cin>>a;
                    if(a>currentMax)
                        currentMax = a;
                    poker.push(a);
                    max.push(currentMax);
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}