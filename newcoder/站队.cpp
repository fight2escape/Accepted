#include<iostream>
#include<set>
#include<vector>
using namespace std;
int getNum(char ch) {
	if (ch >= '0' && ch <= '9') {
		return int(ch - '0');
	}
	return -1;
}
int main() {
	int n;
	vector<char> v;
	set<int> s;
	char ch;
	int no;
	int begin, end;
	while (cin >> n && n) {
		v.clear();
		s.clear();
		for (int i = 0; i < n; i++) {
			cin >> ch;
			v.push_back(ch);
		}
		for (int i = 0; i < n; i++) {
			no = getNum(v[i]);
			if (no >= 0) {
				begin = (i - no) >= 0 ? i-no : 0;
				end = (no + i) < n ? no + i : n - 1;
				for (int j = begin; j <= end; j++) {
					if (v[j] == 'X') {
						s.insert(j);
					}
				}
			}
		}
		cout << s.size() << endl;

	}
	return 0;
}