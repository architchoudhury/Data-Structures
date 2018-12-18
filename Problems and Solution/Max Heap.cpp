#include <iostream>
#include <vector>

using namespace std;
vector <int> heap;

void add(int a){
    heap.push_back(a);
    int n = heap.size()-1;
    while(true){
        int parent = heap[(n-1)/2];
        int child = heap[n];
        if(child>parent){
            heap[(n-1)/2] = child;
            heap[n] = parent;
            n = (n-1)/2;
        }
        else
            break;
        if(n==0)
            break;
    }
}

bool childExists(int n){
    if(n>heap.size()-1)
        return false;
    return true;
}

void swap(int a, int b){
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

void pop(){
    int temp = heap.front();
    heap.front() = heap.back();
    heap.back() = temp;
    heap.pop_back();
    int n = 0;
    for(n=0;n<heap.size();n++){
        int parent = n;
        int leftChild = 2*n+1;
        int rightChild = 2*n+2;
        if(childExists(rightChild)){
            //cout<<"Both Children Exist"<<endl;
            if(heap[leftChild]>heap[rightChild]){
                if(heap[leftChild]>heap[parent])
                    swap(leftChild, parent);
                else
                    continue;
            }
            else{
                if(heap[rightChild]>heap[parent])
                    swap(rightChild, parent);
                else
                    continue;
            }
        }
        else if(childExists(2*n+1)){
            //cout<<"Left Child Exists"<<endl;
            if(heap[leftChild]>heap[parent])
                swap(parent, leftChild);
            else
                continue;
        }
        else
            continue;
    }

    
}

void print(){
    int sum = 0;
    for(int i=0;i<heap.size();i++){
        sum+=heap[i];
        //cout<<heap[i]<<" ";
    }
    //cout<<endl;
    cout<<sum<<endl;
}

int main(){
    int N;
    while(cin>>N){
        heap.clear();
        while(N-->0){
            char choice;
            cin>>choice;
            switch(choice){
                case 'a':
                    int input;
                    cin>>input;
                    add(input);
                    //print();
                    break;
                case 'p':
                    pop();
                    //print();
                    break;
                case 'r':
                    print();
                    break;
            }
        }
    }
    return 0;
}