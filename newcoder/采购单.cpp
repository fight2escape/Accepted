#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int inCar(vector<string> g,string str) {
	for (int i = 0; i < g.size();i++) {
		if (g[i] == str) {
			return i;
		}
	}
	return -1;
}

bool cmp(int a,int b) {
	return a > b;
}

int main() {
	int n, m;
	vector<int> price;
	vector<string> good;
	vector<int> num;
	string gtemp;
	int temp;
	int min,max;
	int gi;
	while (cin >> n >> m && n && m) {
		price.clear();
		good.clear();
		num.clear();
		for (int i = 0; i < n; i++) {
			cin >> temp;
			price.push_back(temp);
		}
		for (int i = 0; i < m; i++) {
			cin >> gtemp;
			gi = inCar(good, gtemp);
			if (gi >= 0) {
				num[gi]++;
			}
			else {
				good.push_back(gtemp);
				num.push_back(1);
			}
		}
		sort(price.begin(), price.end());
		sort(num.begin(), num.end(),cmp);
		min = 0;
		max = 0;
		for (int i = 0; i < num.size(); i++) {
			min += price[i] * num[i];
		}
		sort(price.begin(), price.end(), cmp);
		for (int i = 0; i < num.size(); i++) {
			max += price[i] * num[i];
		}
		cout << min << " " << max << endl;
	}
	return 0;
}