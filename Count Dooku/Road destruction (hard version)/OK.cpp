#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
std::vector<int> nums;
std::vector<std::vector<int>> numsA;
std::vector<bool> high;
std::vector<int> numsB;
int count;
int findDSU(int x) {
    if (nums[x] < 0) {
        return x;
    }
    else return nums[x] = findDSU(nums[x]);
}
void ob(int ud, int vd) {
    if (vd != ud) {
        if (abs(nums[vd]) < abs(nums[ud])) {
            count--;
            nums[ud] += nums[vd];
            nums[vd] = ud;
        }
        else {
            count--;
            nums[vd] += nums[ud];
            nums[ud] = vd;
        }
    }
}
int main()
{
    int n;
    int m;
    int q;
    fin >> n;
    fin >> m;
    fin >> q;
    numsB.resize(q);
    nums.resize(n);
    high.resize(m);
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
    for (int i = 0; i < q; i++) {
        fin >> a;
        numsB[i] = a - 1;
        high[a - 1] = 1;
    }
    int v;
    int ud;
    int vd;
    count = n;
    for (int i = 0; i < m; i++) {
        if (high[i] == 0) {
            u = numsA[i][0];
            v = numsA[i][1];
            ud = findDSU(u);
            vd = findDSU(v);
            ob(ud, vd);
            //std::cout << vd;
        }
    }
    std::vector<int> countStr(q);
    for (int i = 0; i < q; i++) {
        if (count == 1) {
            countStr[q - i - 1] = 1;
        }
        else {
            countStr[q - i - 1] = 0;
        }
        a = numsB[q - i - 1];
        u = numsA[a][0];
        v = numsA[a][1];
        ud = findDSU(u);
        vd = findDSU(v);
        ob(ud, vd);
        //std::cout << vd;



    }
    for (int i = 0; i < q; i++) {
        fout << countStr[i];
    }
    return 0;
}