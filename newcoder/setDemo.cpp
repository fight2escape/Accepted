#include<iostream>
#include<set>
using namespace std;
int main() {
	set<int> eg;
	set<int>::iterator it;
	eg.insert(10);
	eg.insert(100);
	eg.insert(90);
	eg.insert(90);
	eg.insert(89);
	eg.insert(890);
	eg.insert(890);
	eg.insert(890);
	eg.insert(890);
	cout << eg.size() << endl;
	for (it = eg.begin(); it != eg.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}