#include<iostream>
using namespace std;
int main() {
	int min, max;
	int i, tmp, sum, x;
	int flag;
	while (scanf("%d%d", &min, &max)) {
		flag = 0;
		for (i = min; i <= max; i++) {
			tmp = i;
			sum = 0;
			while (tmp) {
				x = tmp % 10;
				tmp /= 10;
				sum += x*x*x;
			}
			if (sum == i) {
				if (flag) {
					printf(" ");
				}
				printf("%d", i);
				flag++;
			}
		}
		if (flag <= 0) {
			printf("no");
		}
		printf("\n");
	}

	return 0;
}