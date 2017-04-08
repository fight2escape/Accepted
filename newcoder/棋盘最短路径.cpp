#include<iostream>
#include<vector>
using namespace std;
int main() {
	char vc[100][2];
	char ch[2][2];
	while (cin >> ch[0][0] >> ch[0][1]) {
		cin >> ch[1][0] >> ch[1][1];
		int lr, ud;
		char dirlr, dirud;
		if (ch[0][0] > ch[1][0]) {
			dirlr = 'L';
			lr = ch[0][0] - ch[1][0];
		}
		else {
			dirlr = 'R';
			lr = ch[1][0] - ch[0][0];
		}
		if (ch[0][1] > ch[1][1]) {
			dirud = 'D';
			ud = ch[0][1] - ch[1][1];
		}
		else {
			dirud = 'U';
			ud = ch[1][1] - ch[0][1];
		}
		for (int i = 0; i < lr; i++) {
			vc[i][0] = dirlr;
		}
		for (int i = 0; i < ud; i++) {
			if (i < lr) {
				vc[i][1] = dirud;
			}
			else {
				vc[i][0] = dirud;
			}
		}
		int max = lr > ud ? lr : ud;
		int min = lr < ud ? lr : ud;
		cout << max << endl;
		for (int i = 0; i < max; i++) {
			if (i < min) {
				cout << vc[i][0] << vc[i][1] << endl;
			}
			else {
				cout << vc[i][0] << endl;
			}
		}
	}
	return 0;
}