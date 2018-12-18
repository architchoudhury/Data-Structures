#include <iostream>
#include <math.h>
using namespace std;

static int brain(int i0, int i1, int j0, int j1, int table[1024][1024]){
    int counter0=0;
    int counter1=0;
    //cout<<i0<<" "<<i1<<" "<<j0<<" "<<j1<<endl;
    for(int i = i0; i<i1; i++){
        for(int j = j0; j<j1; j++){
            if(table[i][j]==0)
                counter0++;
            else
                counter1++;
        }
    }
    if((counter0==0)||(counter1==0))
        return 1;
    else
        return 1 + brain(i0,(i0+i1)/2,j0,(j0+j1)/2,table) + brain(i0,(i0+i1)/2,(j0+j1)/2,j1,table) + brain((i0+i1)/2,i1,(j0+j1)/2,j1,table) + brain((i0+i1)/2,i1,j0,(j0+j1)/2,table);
    
}

int main() {
    int n;
    while(cin>>n){
        n = pow(2, n);
        static int table[1024][1024];
        for(int i=0;i<n;i++){
            string row;
            cin>>row;
            for(int j=0;j<n;j++){
                table[i][j]=(int)row.at(j)-'0';
            }
        }
        
        cout<<brain(0,n,0,n,table)<<endl;
    }
    
    return 0;
}