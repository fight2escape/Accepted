#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
bool find(string &g, char ch) {
	int gl = g.size();
	for (int i = 0; i < gl; i++) {
		if (ch == g[i]) {
			g[i] = NULL;
			return true;
		}
	}
	return false;
}

bool cmpStr(string s, string g) {
	int gl = g.size();
	int sl = s.size();
	if (gl != sl) {
		return false;
	}
	bool flag = true;
	for (int i = 0; i < sl; i++) {
		if (!find(g, s[i])){
			flag = false;
			break;
		}
	}
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int n;
	string str[50];
	string group[50];
	int i, j;
	int gp = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		cin >> str[i];
	}
	bool flag;
	group[gp++] = str[0];
	for (i = 1; i < n; i++) {
		flag = false;
		for (j = 0; j < gp; j++) {
			if (cmpStr(str[i], group[j])) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			group[gp++] = str[i];
		}
	}
	
	cout << gp << endl;
	return 0;
}