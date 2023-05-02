#include <iostream>
#include <vector>
#include <string>


void L(int k, int n) {
    std::vector <std::vector<unsigned long long>> a(k + 1, std::vector<unsigned long long>(n+1));
    for (int i = 0; i <= n-k; i++) {
        a[0][i] = 1;
    }
    for (int j = 1; j <= k; j++) {
        for (int i = j; i <= n-k+j; i++) {
            a[j][i] = (a[j][i - 1] + a[j - 1][i - 1]) % 1000000007;
        }
    }
    std::cout << a[k][n] % 1000000007;
}
int main()
{
    int n;
    int k;
    std::cin >> n;
    std::cin >> k;
    L(k, n);
}
// 1 100 3 4 1000 0