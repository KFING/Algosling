#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>


std::vector<std::vector<__int64>> nums;
std::vector<int> n;
std::vector<int> m;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int s;
	__int64 tmp = 0;
	bool isT = true;
	std::cin >> s;
	n.resize(s+1);
	m.resize(s+1);
	nums.resize(s+1, std::vector<__int64>(s+1));
	for (int i = 1; i <=s ; i++) {
		std::cin >> n[i];
		std::cin >> m[i];
	}
	for (int i = 1; i < s; i++) {
		nums[i][i + 1] = n[i]*m[i]*m[i+1];
	}for (int j = 2; j < s; j++) {
		for (int i = 1; i < s-j+1; i++) {
			for (int k = i; k < i+j; k++) {
				tmp = nums[i][k] + nums[k+1][i+j] + n[i]* m[k] *m[i+j];
				if (isT) { nums[i][i+j] = tmp; 
				isT = false;
				}
				if (tmp < nums[i][i+j]) {
					nums[i][i+j] = tmp;
				}
			}
			isT = true;
		}
	}
	std::cout << nums[1][s];
	return 0;
	
}