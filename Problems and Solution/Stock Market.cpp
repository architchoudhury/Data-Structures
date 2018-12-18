#include <iostream>
#include <stack>
using namespace std;

void calculateMaxArea(long long int p[], long long int N){
    stack <long long int> graph;
    
    long long int maxArea = 0;
    long long int tempTop;
    long long int areaCurrent;
    
    
    long long int i = 0;
    while (i < N){
        if (graph.empty()||(p[graph.top()] <= p[i]))
            graph.push(i++);
        else{
            tempTop = graph.top();
            graph.pop();
            if(graph.empty())
                areaCurrent = p[tempTop] * i;
            else
                areaCurrent = p[tempTop] * (i-graph.top()-1);
            
            if (maxArea < areaCurrent)
                maxArea = areaCurrent;
        }
    }
    while (!graph.empty()){
        tempTop = graph.top();
        graph.pop();
        
        if(graph.empty())
            areaCurrent = p[tempTop] * i;
        else
            areaCurrent = p[tempTop] * (i-graph.top()-1);
        
        if (maxArea < areaCurrent)
            maxArea = areaCurrent;
    }
    cout<<maxArea<<endl;
}

int main() {
    int T;
    cin>>T;
    while(T-->0){
        long long int N;
        cin>>N;
        long long int p[100000];
        for(long long int i=0;i<N;i++)
            cin>>p[i];
        calculateMaxArea(p, N);
    }
    return 0;
}