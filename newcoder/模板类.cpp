#include<iostream>
using namespace std;
template<class T>
class Array {
	T *set;
	int n;
public:
	Array(T *data,int i):set(data),n(i){}
	~Array() { printf("析构函数执行完毕。"); }
	void sort();
	int seek(T key);
	T sum();
	void display();
};
template<class T>
void Array<T>::sort() {
	int i, j;
	T temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (set[j] > set[j + 1]) {
				temp = set[j];
				set[j] = set[j + 1];
				set[j + 1] = temp;
			}
		}
	}
}
template<class T>
int Array<T>::seek(T key) {
	int i;
	for (i = 0; i < n; i++) {
		if (set[i] == key) {
			return i;
		}
	}
	return -1;
}
template<class T>
T Array<T>::sum() {
	T sum = 0;
	for (int i = 0; i < n; i++) {
		sum += set[i];
	}
	return sum;
}
template<class T>
void Array<T>::display() {
	for (int i = 0; i < n; i++) {
		printf("%d\t", set[i]);
	}
	printf("\n");
}

int main() {
	const int n = 3;
	int data[n] = { 7,5,6 };
	Array<int> arr(data, n);
	arr.display();
	arr.sort();
	arr.display();
	int find = 6;
	int site = arr.seek(find);
	printf("%d is in %d site.\n",find, site);
	arr.display();
	return 0;
}