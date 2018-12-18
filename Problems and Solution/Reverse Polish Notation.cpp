#include <iostream>;
#include <stack>;
#include <string>;
using namespace std;

int main() {
	string line;
	while (getline(cin, line)) {
	stack <int> list;
	for (int i = 0; i < line.length(); i++) {
		char c = line.at(i);
		//cout << "C is " << c << endl;
		int a = (int)c;
		if ((a > 47) && (a < 58)) {
			list.push(a - 48);
			//cout << "Pushing " << a-48 << endl;
		}
		else if (c == '+') {
			int x = list.top();
			//cout << "Popping " << list.top() << endl;
			list.pop();
			int y = list.top();
			//cout << "Popping " << list.top() << endl;
			list.pop();
			list.push(x + y);
			//cout << "Pushing " << x + y << endl
		}
		else if (c == '-') {
			int x = list.top();
			//cout << "Popping " << list.top() << endl;
			list.pop();
			int y = list.top();
			//cout << "Popping " << list.top() << endl;
			list.pop();
			//cout << "Pushing " << y - x << endl;
			list.push(y - x);
		}
		else if (c == '*') {
			int x = list.top();
			//cout << "Popping " << list.top() << endl;
			list.pop();
			int y = list.top();
			//cout << "Popping " << list.top() << endl;
			list.pop();
			//cout << "Pushing " << x * y << endl;
			list.push(x * y);
		}
		else {
			continue;
		}
	}
	cout << list.top() << endl;
	list.pop();
}
	return 0;
}