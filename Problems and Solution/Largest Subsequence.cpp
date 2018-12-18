#include <iostream>
#include <string>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	for(int z=0;z<cases;z++){
		
	string a;
	cin>>a;
	string b = "";
	int index = 0;
	while(true){
	char c = ' ';
	bool flag = false;
	for(int i=index;i<a.length();i++){
		if(a.at(i)>c){
			c=a.at(i);
			index = i+1;
			flag = true;
		}
	}
	if(flag==false)
	break;
	b += c;
	}
	cout<<b<<endl;
	}
	return 0;
}