#include <iostream>
#include <vector>
#include <string>


void L(int k, int n) {
    unsigned long long b = 1;
    unsigned long long b_ = 1;
    unsigned long long a = 1;
    int st = 1000000005;
    for (int i = 2; i <= k; i++) {
        b = (i  * b ) % 1000000007;
    }
    for (int i = 0; i <= k - 1; i++) {
        a = ((n - i) * a) % 1000000007;
    }
    while (st > 0) {
        if (st % 2 == 1) {
            b_ = (b_ * b) % 1000000007;
        }
        st >>= 1;
        b = (b * b) % 1000000007;        
    } 
    b_ = b_ % 1000000007;
    std::cout << ((a % 1000000007) * b_) % 1000000007;
}
int main()
{
    int n;
    int k;
    std::cin >> n;
    std::cin >> k;
    if ((n - k) < k)
        k = n - k;
    L(k, n);
}
// 1 100 3 4 1000 0