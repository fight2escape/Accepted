#include<iostream>
using namespace std;
int main() {
	int t;
	long long int n, m, a;
	cin >> t;
	long long int nx, mx;
	while (t--) {
		cin >> n >> m >> a;
		nx = n / a;
		if (n % a != 0) {
			nx++;
		}
		mx = m / a;
		if (m%a != 0) {
			mx++;
		}
		cout << nx*mx << endl;
	}
	return 0;
}