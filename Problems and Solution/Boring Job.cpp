#include <queue>
#include <iostream>

using namespace std;

struct number{
    long value;
    long index;
};

int main() {
    int T;
    cin>>T;
    while(T-->0){
        long N,K;
        cin>>N>>K;
        queue <number> list, magic;
        for(long i=1;i<=N;i++){
            long a;
            cin>>a;
            number n;
            n.value = a;
            n.index = i;
            list.push(n);
        }
        while(true){
            long max = (K>list.size()) ? list.size():K;
            //cout<<"Max: "<<max<<endl;
            //cout<<list.front().value<<" ";
            //cout<<list.back().value<<endl;
            long maximumValue = -999999;
            if(list.size()==1){
                cout<<list.front().index<<endl;
                list.pop();
                break;
            }
            if(max==1){
                cout<<list.front().index<<" ";
                list.pop();
                continue;
            }
            for(long i=0;i<max;i++){
                magic.push(list.front());
                list.pop();
                if(magic.back().value>maximumValue)
                    maximumValue = magic.back().value;
            }
            //cout<<"Maximum value: "<<maximumValue<<endl;
            bool flag = true;
            for(long i=0;i<max;i++){
                if((magic.front().value==maximumValue)&&(flag)){
                    cout<<magic.front().index<<" ";
                    magic.pop();
                    flag = false;
                    continue;
                }
                magic.front().value -= 1;
                list.push(magic.front());
                magic.pop();
            }
            if(max==0)
                break;
        }
    }
    return 0;
}