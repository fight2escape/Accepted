#include<iostream>
#include<set>
using namespace std;
int main() {
	int a, b;
	int temp;
	set<int> s;
	set<int>::iterator si;
	int sj;
	while (cin >> a >> b && a && b) {
		s.clear();
		for (int i = 0; i < a + b; i++) {
			cin >> temp;
			s.insert(temp);
		}
		sj = 0;
		for (si = s.begin(); si != s.end(); si++,sj++) {
			if(sj>0){
				cout << " ";
			}
			cout << *si;
		}
		cout << endl;
	}
	return 0;
}