#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>


std::vector<std::vector<__int64>> nums;
std::string str1;
std::string str2;
int x;
int y;
int z;
int q(char i, char j) {
	return (i == j) ? 0 : 1;
}
__int64 min(__int64 a, __int64 b, __int64 c) {
	if (a < b) {
		if (a < c) {
			return a;
		}
	}if (c < b) return c;
	return b;

}
void f(int n1, int n2) {
	for(int i = 1; i <= n1; i++)
		for (int j = 1; j <= n2; j++) {
				nums[i][j] = min(nums[i - 1][j] + x, nums[i][ j - 1] + y, nums[i - 1][j - 1] + q(str1[i-1],str2[j-1])*z);
		}
}
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n1;
	int n2;
	std::cin >> x;
	std::cin >> y;
	std::cin >> z;
	if (z > x + y) {
		z = x + y;
	}
	std::cin >> str1;
	n1 = str1.size();
	std::cin >> str2;
	n2 = str2.size();
	nums.resize(n1+1, std::vector<__int64>(n2+1));
	nums[0][0] = 0;
	for (int i = 1; i <= n1; i++) {
		nums[i][0] = x*i;
	}
	for (int i = 1; i <= n2; i++) {
		nums[0][i] = y*i;
	}
	f(n1,n2);
	std::cout << nums[n1][n2];
	return 0;
}