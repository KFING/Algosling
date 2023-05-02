#include <iostream>
#include <vector>
#include <string>


void L(int n, std::vector<long long> nums) {
    std::string str = "";
    std::vector<int> A(n - 2);
    //A[0] = 1;
    for (int i = n-3; i >= 0; i--) {
        if (nums[i + 2] > nums[i + 3]) {
            nums[i] += nums[i + 2];
            A[i] = i + 2;
        }
        else {
            nums[i] += nums[i + 3];
            A[i] = i + 3;
        }
    }
    std::cout << nums[0] << std::endl;
    int i = 0;
    if (n  != 2) {
        std::cout << 1 << ' ';
        while (i < n-2) {
            i = A[i];
            std::cout << i+1 << ' ';
        }
    }
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> nums(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    nums[n] = -1;
    if (n >= 2)
        nums[n-2] = -1;
    if (n == 1) {
        std::cout << nums[0] << std::endl;
        std::cout << 1;
    }else
    L(n, nums);
}
// 1 100 3 4 1000 0