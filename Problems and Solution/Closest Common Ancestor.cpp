#include <iostream>
using namespace std;

int parent[100];
int root,N;
int commonAncestor(int a, int b){
    int copyB = b;
    while(a!=root){
        b = copyB;
        while(b!=root){
            if(a==b){
                //cout<<"A and B are equal at:"<<a<<endl;
                return a;
            }
            //cout<<"A: "<<a<<" B: "<<b<<endl;
            b = parent[b];
        }
        a = parent[a];
    }
    if(a==root)
        return a;
    if(b==root)
        return b;
    return root;
}

int main() {
    int T;
    cin>>T;
    while(T-->0){
        cin>>root>>N;
        while(N-->1){
            int a,b;
            cin>>a>>b;
            parent[a] = b;
        }
        int a,b;
        cin>>a>>b;
        cout<<commonAncestor(a, b)<<endl;
    }
    return 0;
}