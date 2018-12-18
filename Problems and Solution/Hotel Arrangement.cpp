#include <iostream>
using namespace std;
long N,C;
long rooms[100000];

void heapify(long list[], long n, long i)
{
    long greatest = i;
    long left = 2*i+1;
    long right = 2*i+2;
    if ((n>left)&&list[left]>(list[greatest]))
        greatest = left;
    if ((n>right)&&list[right]>(list[greatest]))
        greatest = right;
    if (greatest!=i)
    {
        swap(list[i],list[greatest]);
        heapify(list,n,greatest);
    }
}

void heapSort(long list[], long n)
{
    for (long i=n/2-1;i>=0;i--)
        heapify(list, n, i);
    for (long i=n-1;i>=0;i--)
    {
        swap(list[0],list[i]);
        heapify(list,i,0);
    }
}

bool isPossible(long space){
    //cout<<"Trying for space: "<<space<<endl;
    long c = C;
    long currentRoom = rooms[0];
    for(long i=1;i<N;i++){
        if(rooms[i]-currentRoom>=space){
            c--;
            currentRoom = rooms[i];
        }
    }
    if(c<=1){
        //cout<<"Space which worked: "<<space<<endl;
        return true;
    }
    return false;
}

int main() {
    long T;
    cin>>T;
    while(T-->0){
        cin>>N>>C;
        for(long i=0;i<N;i++){
            long a;
            cin>>a;
            rooms[i] = a;
        }
        heapSort(rooms, N);
        long start,mid,end;
        start = rooms[0];
        end = rooms[N-1]-rooms[0]+1;
        while((end-start)>1){
            mid = (start+end)>>1;
            if(isPossible(mid)){
                start = mid;
            }else{
                end = mid;
            }
        }
        cout<<start<<endl;
    }
    return 0;
}