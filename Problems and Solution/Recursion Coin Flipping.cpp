#include <iostream>
#include <string>
using namespace std;

int rows;
int columns;
int table[100][10];
int tableCopy[100][10];
int result=0;
static void brain(int level);
static int countTotal(){
    int count = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            count+=table[i][j];
        }
    }
    return count;
}

static void input(){
    while(cin>>rows>>columns){
        result = 0;
        for(int i=0;i<rows;i++){
            string row;
            cin>>row;
            for(int j=0;j<columns;j++){
                table[i][j]=(int)row.at(j)-'0';
                tableCopy[i][j]=(int)row.at(j)-'0';
            }
        }
        brain(0);
        cout<<result<<endl;
    }
}
    

static int rowCount(int row){
    int count = 0;
    for(int i=0;i<columns;i++){
            count+=table[row][i];
    }
    return count;
}

/*static int columnCount(int column){
    int count = 0;
    for(int i=0;i<rows;i++){
        count+=table[i][column];
    }
    return count;
}*/

/*static void flipRow(int row){
    for(int i=0;i<columns;i++){
        if(table[row][i]==0)
            table[row][i]=1;
        else
            table[row][i]=0;
    }
        
}*/

static void flipColumn(int column){
    for(int i=0;i<rows;i++){
        if(table[i][column]==0)
            table[i][column]=1;
        else
            table[i][column]=0;
        }
}

static void brain(int level){
    if(level<columns){
        level++;
        brain(level);
        flipColumn(level-1);
        brain(level);
    }
    if(level==columns){
        int x = countTotal();
        for(int i=0;i<rows;i++){
            if(rowCount(i)<columns/2)
                x+=columns-(2*rowCount(i));
        }
        if(x>result)
            result = x;
    }
}

int main() {
    input();
    return 0;
}