#include <iostream>;
#include <stack>;
#include <string>;
using namespace std;

struct brack {
	bool type;
	int start;
};
int main() {
	stack <brack> bracket;
	string line;
	while (cin >> line) {
		int a[1000];
		int count = 0;
		for (int i = 0; i < line.length(); i++) {
			char c = line.at(i);
			if (c == '(') {
				brack a;
				a.type = 1;
				a.start = i;
				bracket.push(a);
			}
			if (c == ')') {
				a[count++] = ((i - bracket.top().start) / 2) + 1;
				bracket.pop();
			}
		}
		int answer = a[0];
		for (int i = 1; i < count; i++)
			answer = answer ^ a[i];
		cout << answer << endl;
	}
	return 0;
}