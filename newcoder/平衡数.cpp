#include<iostream>
#include<cstdio>
using namespace std;

int getSum(int n) {
	int sum = 1;
	while (n > 0) {
		sum *= n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int n;
	int mul;
	int tmp;
	bool flag;
	scanf("%d", &n);
	if (n <= 10) {
		printf("NO\n");
			
	}
	mul = 1;
	tmp = 0;
	flag = false;
	while (n >= 10) {
		mul *= n % 10;
		n = n / 10;
		tmp = getSum(n);
		if (tmp == mul) {
			printf("YES\n");
			flag = true;
			break;
		}
	}
	if (!flag) {
		printf("NO\n");
	}
	return 0;
}