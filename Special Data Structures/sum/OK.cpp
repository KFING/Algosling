#include <iostream>
#include <string>
#include <vector>
#include <cmath>


std::vector<__int64> nums;
std::vector<__int64> nums_;
int size;
int num;
int n;

void Add(int i, int k) {
	nums[i] += k;
	nums_[i / size] += k;
}
__int64 FindSum(int l, int r) {
	__int64 sum = 0;
	while (l < r) {
		if ((l % size == 0) and ((r > l + size) or (r == n))) {
			sum += nums_[l / size];
			l += size-1;
		}
		else {
			sum += nums[l];
		}
		l++;
	}
	return sum;
}
int main() {
	
	int count = 0;

	std::cin >> n;
	nums.resize(n);
	size = ceil(sqrt(n));
	nums_.resize(size);
	for (int i = 0; i < n; i++) {
		std::cin >> nums[i];
		nums_[i/size] += nums[i];
	}
	int q;
	std::cin >> q;
	std::string str;
	int a;
	int b;
	for (int i = 0; i < q; i++) {
		std::cin >> str;
		std::cin >> a;
		std::cin >> b;
		if (str == "Add"){
			Add(a, b);
		    
		}else
			std::cout << FindSum(a, b) << std::endl;
	}
	return 0;
}