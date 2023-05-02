#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>


std::vector<__int64> nums;
std::vector<__int64> nums_(1);
std::fstream fin("input.txt");
std::ofstream fout("output.txt");
int Upper_Bound(__int64& x, int& size) {
	int q = 0;
	int k;
	int r = size;
	while (q < r) {
		k = (q + r) >> 1;
		if (x <= nums_[k]) {
			r = k;
		}
		else q = k + 1;
	}
	return q;
}
void f(int n) {
	//std::vector<__int64> temp(n);
	int size = 1;
	int pos;
	nums_[0] = nums[0];
	for (int i = 1; i < n; i++) {
		pos = Upper_Bound(nums[i], size);
		if (pos == size) {
			nums_.push_back(nums[i]);
			size++;
		}
		else nums_[pos] = nums[i];
	}
	fout << size;
}
int main() {
	
	int n;
	fin >> n;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		fin >> nums[i];
	}
	f(n);
	return 0;
}