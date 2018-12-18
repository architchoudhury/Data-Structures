#include <iostream>
#include <queue>

using namespace std;

struct task{
    int seq;
    int arrivalTime;
    int processingTime;
};
int main() {
    int N;
    
    while(cin>>N){
        queue <task> lowPriority, highPriority;
        int currentTime = 0;
        int list[100] = {0};
        for(int i=0;i<N;i++){
            //cout<<"Expecting Value"<<endl;
            int arrivalTime, processingTime, priority;
            cin>>arrivalTime>>processingTime>>priority;
            task t;
            t.seq = i;
            t.processingTime = processingTime;
            t.arrivalTime = arrivalTime;
            if(priority==0)
                highPriority.push(t);
            else
                lowPriority.push(t);
        }
        
        while((!highPriority.empty())||(!lowPriority.empty())){
            if(!highPriority.empty()){
                if(highPriority.front().arrivalTime<=currentTime){
                    currentTime += highPriority.front().processingTime;
                    list[highPriority.front().seq]=currentTime;
                    highPriority.pop();
                    continue;
                }
            }
            if(!lowPriority.empty()){
                if(lowPriority.front().arrivalTime<=currentTime){
                    currentTime += lowPriority.front().processingTime;
                    list[lowPriority.front().seq]=currentTime;
                    lowPriority.pop();
                    continue;
                }
            }
            if(lowPriority.empty()&&highPriority.empty())
                break;
            currentTime++;
        }
        
        for(int i=0;i<N-1;i++)
            cout<<list[i]<<" ";
        cout<<list[N-1];
        cout<<endl;
    }
    return 0;
}