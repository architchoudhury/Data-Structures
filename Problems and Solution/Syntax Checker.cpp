#include <iostream>
#include <stack>
using namespace std;

struct brackets{
    int type;
    int position;
};

int main() {
    string s;
    while(getline(cin, s)){
        stack <brackets> openBracket;
        char c;
        int count = 1;
        bool flag = false;
        for(int i=0;i<s.length();i++){
            c=s.at(i);
            int a = (int)c;
            if(a==91||a==123||a==40){
                brackets a;
                a.type = c;
                a.position = count;
                openBracket.push(a);
                //cout<<"Pushing "<<openBracket.top()<<endl;
            }
            else if(a==93||a==125||a==41){
                if(!openBracket.empty()){
                    if((openBracket.top().type==a-1)||(openBracket.top().type==a-2)){
                        //cout<<"Popping "<<openBracket.top()<<endl;
                        openBracket.pop();
                    }
                    else{
                        cout<<count<<endl;
                        flag = true;
                        break;
                    }
                }
                else{
                    cout<<count<<endl;
                    flag = true;
                    break;
                }
            }
            count++;
        }
        if(!openBracket.empty()&&!flag){
            flag = true;
            int a;
            while(!openBracket.empty()){
                a = openBracket.top().position;
                openBracket.pop();
            }
            cout<<a<<endl;
        }
        if(!flag)
            cout<<"Success"<<endl;
    }
    return 0;
}