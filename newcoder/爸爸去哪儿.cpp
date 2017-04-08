#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	int val;
	cin >> val;
	int price[100];
	int p = 0;
	int s;
	int sum;
	int i;
	int pp = 0;
	while (str[p] != '\0') {
		sum = 0;
		while (str[p] != ',') {
			if (str[p] == '\0') {
				break;
			}
			s = str[p] - '0';
			sum *= 10;
			sum += s;
			p++;
		}
		price[pp++] = sum;
		if (str[p] != '\0') {
			p++;
		}
	}
	sort(price, price + pp);
	pp--;
	int time = 0;
	while (pp >= 0) {
		if (val >= price[pp]) {
			val -= price[pp];
			time++;
		}
		else {
			pp--;
		}
	}
	if (val == 0 && time>0) {
		cout << time << endl;
	}
	else {
		cout << "-1" << endl;
	}

	return 0;
}