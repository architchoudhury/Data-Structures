#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack <int> A, S, Acopy;
queue <int> B;
void AtoS(){
    S.push(A.top());
    A.pop();
    //cout<<"AtoS"<<endl;
}
void StoB(){
    S.pop();
    B.pop();
    //cout<<"StoB"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T-->0){
        while(!A.empty())
            A.pop();
        while(!Acopy.empty())
            Acopy.pop();
        while(!S.empty())
            S.pop();
        int N;
        cin>>N;
        for(int i=0;i<N;i++){
            int a;
            cin>>a;
            A.push(a);
            Acopy.push(a);
        }
        int m;
        cin>>m;
        while(m-->0){
            A = Acopy;
            while(!S.empty())
                S.pop();
            while(!B.empty())
                B.pop();
            for(int i=0;i<N;i++){
                int a;
                cin>>a;
                B.push(a);
            }
            while(true){
                if(B.empty()){
                    cout<<"Aye"<<endl;
                    break;
                }
                if((!S.empty())&&(S.top()==B.front())){
                    StoB();
                    continue;
                }
                while((!A.empty())&&(B.front()!=A.top()))
                    AtoS();
                if((!A.empty())&&(A.top()==B.front())){
                    AtoS();
                    StoB();
                    continue;
                }
                if((S.empty())&&(A.top()!=B.front())){
                    cout<<"Impossible"<<endl;
                    break;
                }
                if((S.top()!=B.front())){
                    cout<<"Impossible"<<endl;
                    break;
                }
                cout<<B.size()<<endl;
            }
        }
    }
    return 0;
}