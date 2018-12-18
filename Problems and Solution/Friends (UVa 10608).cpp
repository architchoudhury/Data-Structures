#include <iostream>
#include <vector>
using namespace std;

int parent[30000];
int ranks[30000]={0};
int maximum = 1;

int Find(int a){
    if(parent[a] != a)
        parent[a] = Find(parent[a]);
    return parent[a];
}

void Union(int a, int b){
    //cout<<"Union"<<endl;
    int rootOfA, rootOfB;
    rootOfA = Find(a);
    rootOfB = Find(b);
    //cout<<"Root of A: "<<rootOfA<<" Root of B: "<<rootOfB<<endl;
    if(rootOfA==rootOfB)
        return;
    parent[rootOfB] = rootOfA;
    //cout<<"Rank of A: "<<ranks[rootOfA]<<" Root of B: "<<ranks[rootOfB]<<endl;
    ranks[rootOfA] += ranks[rootOfB];
    if(ranks[rootOfA]>maximum)
        maximum = ranks[rootOfA];
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int N, M;
        cin>>N>>M;
        for(int i=1;i<=N;i++){
            parent[i] = i;
            ranks[i] = 1;
        }
        while(M-->0){
            int a,b;
            cin>>a>>b;
            Union(a,b);
        }
        cout<<maximum<<endl;
    }
    return 0;
}
