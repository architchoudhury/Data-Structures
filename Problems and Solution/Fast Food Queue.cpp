#include <iostream>
#include <queue>

using namespace std;

struct person{
    int finishTime;
};

int main(){
    int N;
    while(cin>>N){
        queue <person> line;
        int queueTime = 0;
        while(N-->0){
            int arrivalTime, orderTime, waitTime;
            cin>>arrivalTime>>orderTime>>waitTime;
            if(arrivalTime>queueTime)
                queueTime = arrivalTime;
            while(!line.empty()){
                if(line.front().finishTime<=arrivalTime)
                    line.pop();
                else
                    break;
            }
            //cout<<"Wait time: "<<waitTime<<" Line Size: "<<line.size()<<endl;
            if(waitTime<line.size()){
                if(N==0){
                    cout<<"-1"<<endl;
                    break;
                }
            }
            else{
                if(N==0){
                    cout<<queueTime<<endl;
                    break;
                }
                queueTime += orderTime;
                person a;
                a.finishTime = queueTime;
                line.push(a);
                //cout<<"The time now is "<<queueTime<<endl;
            }
        }
        while(!line.empty())
            line.pop();
    }
    return 0;
}