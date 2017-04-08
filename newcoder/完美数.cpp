#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPerfect(int n) {
	vector<int> fac;
	vector<int>::iterator it;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n%i == 0) {
			fac.push_back(i);
			if (n / i != i) {
				fac.push_back(n / i);
			}
		}
	}
	int sum = 0;
	for (it = fac.begin(); it != fac.end(); it++) {
		sum += (*it) * (*it);
	}
	int tmp = sqrt(sum);
	return pow(tmp, 2) == sum;
}

int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (isPerfect(i)) {
			sum += i;
		}
	}
	cout << sum << endl;
	
	return 0;
}