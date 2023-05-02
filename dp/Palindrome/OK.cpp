#include <iostream>
#include <vector>
#include <cstdio>
#include<string>


std::vector<std::vector<int>> nums;


void f(std::string a, std::vector<char> b, int n) {
    std::string str1 = "";
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (a[i - 1] == b[j - 1]) {
                nums[i][j] = nums[i - 1][j - 1] + 1;
            }
            else nums[i][j] = (nums[i - 1][j] > nums[i][j - 1]) ? nums[i - 1][j] : nums[i][j - 1];
        }
    }
    std::cout << nums[n][n] << std::endl;
    int i = n;
    int j = n;
    while (nums[i][j] != 0) {
        if (a[i - 1] == b[j - 1]) {
            str1 = a[i - 1] + str1;
            i = i - 1;
            j = j - 1;
        }
        else if (nums[i - 1][j] == nums[i][j]) {
            i = i - 1;
        }
        else
            j = j - 1;
    }
    std::cout << str1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::string a;
    std::cin >> a;
    int n = a.size();
    std::vector<char> b(n);
    for (int i = 0; i < n ; i++) {
        b[n - i-1] = a[i];
    }
    nums.resize(n + 1, std::vector<int>(n + 1));
    f(a,b,n);
}