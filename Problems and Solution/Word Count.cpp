#include <iostream>
#include <string>
using namespace std;

int main()
{
string words[1000];
int count[1000];
int length = 0;
string word;
while(cin>>word){
 bool foundFlag = false;
 for(int i=0;i<length;i++){
     if(words[i]==word){
         foundFlag = true;
         count[i]++;
     }
 }
 if(foundFlag==false){
   words[length]=word;
   count[length++]=1;
 }
}
for(int i=0;i<length-1;i++){
	for(int j=i;j<length;j++){
		if(words[i]>words[j]){
			string temp = words[i];
			int tmp = count[i];
			words[i] = words[j];
			count[i] = count[j];
			words[j] = temp;
			count[j] = tmp;
		}
	}
}
for(int i=0;i<length;i++){
 cout<<words[i]<<" "<<count[i]<<endl;
}


}