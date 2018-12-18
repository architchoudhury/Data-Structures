#include <iostream>
#include <string>
using namespace std;

string brain(int inorder[], int preorder[], int depth)
{
    string s;
    int i=0;
    for(;i<depth;i++){
        if(inorder[i]==preorder[0])
            break;
    }
    if(i!=0)
        s+=brain(inorder, preorder+1, i);
    if(i!=depth-1)
        s+=brain(inorder+i+1, preorder+i+1, depth-i-1);
    return s+to_string(preorder[0])+" ";
}

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int N;
        cin>>N;
        int inorder[100],preorder[100];
        for(int i=0;i<N;i++){
            cin>>preorder[i];
        }
        for(int j=0;j<N;j++){
            cin>>inorder[j];
        }
        string output = brain(inorder, preorder, N);
        for(int i=0;i<output.length()-1;i++){
            cout<<output.at(i);
        }
        cout<<endl;
    }
    return 0;
}