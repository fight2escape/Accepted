#include<iostream>
#include<stack>
using namespace std;
void convert(stack<int> &s, __int64 n, int base) {
	char digit[] = {'0', '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (n > 0) {
		s.push(digit[n%base]);
		n /= base;
	}
}
void display(stack<int> &s) {
	while (!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}
	printf("\n");
}
int main() {
	stack<int> sta;
	int n, base;
	while (scanf("%d%d", &n, &base) && n+base) {
		
		convert(sta, n, base);
		display(sta);
	}
	return 0;
}