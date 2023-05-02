#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::vector<int> nums;

std::vector<std::vector<int>> numsA;

int findDSU(int x) {
    if (nums[x] < 0) {
        return x;
    }
    else return nums[x] = findDSU(nums[x]);
}
int main()
{
    int n;
    int m;
    int q;
    fin >> n;
    fin >> m;
    nums.resize(n);
    numsA.resize(m, std::vector<int>(2));
    int u;
    for (int i = 0; i < n; i++) {
        nums[i] = -1;
    }
    int a;
    int b;
    for (int i = 0; i < m; i++) {
        fin >> a;
        numsA[i][0] = a - 1;
        fin >> b;
        numsA[i][1] = b - 1;
    }
    int v;
    int ud;
    int vd;
    int count = n;
    for (int i = 0; i < m; i++) {
        u = numsA[i][0];
        v = numsA[i][1];
        if (u != v) {
            ud = findDSU(u);
            vd = findDSU(v);
            if (ud > vd) {
                count--;
                nums[vd] = ud;
            }
            else if (vd > ud) {
                count--;
                nums[ud] = vd;
            }
            fout << count << '\n';
        }
    }
    return 0;
}