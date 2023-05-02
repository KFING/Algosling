#include <iostream>
#include <string>
#include <vector>
#include <cmath>
//#include <cstdio>



int Lower_Bound(std::vector<int>& a, int x) {
	int q = 0;
	int k;
	int r = a.size();
	while (q < r) {
		k = (q + r) >> 1;
		if (x <= a[k]) {
			r = k;
		}
		else q = k + 1;
	}
	return q;
}
int Upper_Bound(std::vector<int>& a, int x) {
	int q = 0;
	int k;
	int r = a.size();
	while (q < r) {
		k = (q + r) >> 1;
		if (x < a[k]) {
			r = k;
		}
		else q = k + 1;
	}
	return q;
}
bool binary_search(std::vector<int>& a, int x) {
	int q = 0;
	int k;
	int r = a.size();
	while (q < r) {
		k = (q + r) >> 1;
		if (x == a[k]) {
			return true;
		}
		else if (x < a[k]) {
			r = k;
		}
		else q = k + 1;
	}
	return false;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int k;
	std::cin >> k;
	int q;
	for (int i = 0; i < k; i++) {
		std::cin >> q;
		std::cout << binary_search(a, q) << ' ' << Lower_Bound(a, q) << ' ' << Upper_Bound(a, q) << std::endl;
	}
	return 0;
}