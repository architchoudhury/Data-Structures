#include <iostream>;
#include <queue>;
using namespace std;

int main() {
	int T;
	cin >> T;
	int count = 1;
	while (T-- > 0) {
		queue <int> list;
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			list.push(a);
		}
		int high, low;
		high = 0;
		low = 0;
		int previous;
		previous = list.front();
		list.pop();
		while (!list.empty()) {
			int current = list.front();
			if (current > previous)
				high++;
			if (current < previous)
				low++;
			previous = current;
			list.pop();
		}
		cout<<"Case "<<count++<<": " << high <<" "<<low<< endl;
	}
	return 0;
}