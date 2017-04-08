// 有N个人围城一圈，顺序排好。从第一个人开始报数，凡报到K的人退出圈子，问最后留下的是原来的第几号。
#include<iostream>
using namespace std;
int main() {
	int n, k;
	const int max = 10000;
	while (scanf("%d %d", &n, &k) && n + k) {
		int num[max], *p;
		p = num;
		for (int i = 0; i < n; i++) {
			*(p + i) = i + 1;
		}
		int m = 0;
		int kk = 0;
		int i = 0;
		while (m < n - 1) {
			if (*(p + i) != 0) { kk++; }
			if (kk == k) {
				kk = 0;
				m++;
				printf("left:\t%d\n", *(p + i));
				*(p + i) = 0;
			}
			i++;
			if (i == n) { i = 0; }
		}
		while (*p == 0) { p++; }
		printf("the last one is:%d\n", *p);
	}
	
	return 0;
}