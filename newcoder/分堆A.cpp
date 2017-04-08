#include<iostream>
using namespace std;

int main() {
	int n, k;
	int res;
	while (cin >> n >> k && n && k) {
		res = n / (2 * k + 1);
		res *= 2;
		if (n % (2 * k + 1) >= k) {
			res++;
		}
		cout << res << endl;
	}
	return 0;
}