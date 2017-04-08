#include<iostream>
using namespace std;
int main() {
	int n;
	char word[50][50];
	scanf("%d", &n);
	int i, j;
	int g[50];
	for (i = 0; i < n; i++) {
		g[i] = i;
		scanf("%s", &word[i]);
	}

	bool flag;
	int p, q;
	int tmp;
	int len;
	for (i = 1; i < n; i++) {
		//printf("i=%d\n", i);
		for (j = 0; j < i; j++) {
			//printf("j=%d\n", j);
			len = 0;
			p = 0;
			q = 0;
			tmp = 0;
			while (word[i][p] != '\0') {
				//printf("i=%d,p=%d,q=%d\n", i,p,q);
				if (word[i][p] == word[j][q]) {
					tmp++;
					q++;
					p++;
				}
				else {
					if (word[j][q] == '\0') {
						if (tmp == 0) {
							break;
						}
						else {
							len = q;
							q = 0;
						}
						
					}
					else {
						q++;
					}
				}
			}
			if (tmp>0 && tmp==len) {
				g[i] = g[j];
				break;
			}
		}
		if (g[i] == i) {
			g[i] = g[i - 1] + 1;
		}
	}
	printf("%d", g[n - 1] + 1);
	

	return 0;
}