#include <iostream>
#include <vector>
#include<string>


std::vector<std::vector<int>> nums;


void f(std::vector<int> a, std::vector<int> b, int n) {
    std::string str1 = "";
    std::string str2 = "";
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (a[i] == b[j]) {
                nums[i][j] = nums[i - 1][j - 1] + 1;
            }
            else nums[i][j] = (nums[i - 1][j] > nums[i][j - 1]) ? nums[i - 1][j] : nums[i][j - 1];
            }
    }
    std::cout << nums[n][n] << std::endl;
    int i = n;
    int j = n;
    while (nums[i][j] != 0) {
        if (a[i] == b[j]) {
            str1 = std::to_string(i-1) + ' ' + str1;
            str2 = std::to_string(j-1) + ' ' + str2;
            i = i - 1;
            j = j - 1;
        }
        else if(nums[i-1][j] == nums[i][j]){
            i = i - 1;
        }
        else
            j = j - 1;
    }
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n+1);
    std::vector<int> b(n+1);
    for (int i = 1; i < n + 1; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i < n + 1; i++) {
        std::cin >> b[i];
    }
    nums.resize(n + 1, std::vector<int>(n + 1));
    f(a, b, n);
}