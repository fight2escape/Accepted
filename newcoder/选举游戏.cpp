#include<iostream>
#include<vector>
using namespace std;

int getMaxPos(vector<int> v, int n) {
	int max = v[0];
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] >= max) {
			max = v[i];
			pos = i;
		}
	}
	return pos;
}

int main() {
	int n;
	vector<int> v;
	int mi;
	int sum;
	int ori;
	int temp;
	int ave;
	int ave_n;
	while (cin >> n && n) {
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		ave = v[0];
		ave_n = 1;
		for (int i = 1; i < n; i++) {
			if (v[i] >= v[0]) {
				ave += v[i];
				ave_n++;
			}
		}
		ave = ave / ave_n;
		ori = v[0];
		for (int i = 1; i < n; i++) {
			mi = getMaxPos(v, n);
			if (mi > 0 && v[mi] > v[0]) {
				sum = v[0] + v[mi];
				v[mi] = ave;
				v[0] = sum - v[mi];
			}
			else if (mi > 0 && v[mi] == v[0]) {
				sum = v[0] + v[mi];
				v[mi] = ave - 1;
				v[0] = sum - v[mi];
			}
		}
		int res = v[0] - ori;
		cout << res << endl;
	}
	return 0;
}
