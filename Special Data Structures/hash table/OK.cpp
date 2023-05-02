#include <iostream>
#include <vector>
#include <fstream>


std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int main() {
    __int64 n;
    std::vector<__int64> nums;
    std::vector<bool> numsB;
    __int64 m;
    __int64 c;
    fin >> m;
    fin >> c;
    fin >> n;
    nums.resize(m, -1);
    numsB.resize(1000000007);
    __int64 num;
    __int64 i = 0;
    __int64 pos;
    for (int j = 0; j < n; j++) {
        fin >> num;
        if (!numsB[num]) {
            pos = (((num % m) + c * i) % m);
            i++;
            while (nums[pos] != -1) {
                pos = (((num % m) + c * i) % m);
                i++;
            }
            nums[pos] = num;
            i = 0;
        }
        numsB[num] = true;
    }
    for (int i = 0; i < m - 1; i++) {
        fout << nums[i] << ' ';
    }
    fout << nums[m - 1];
    return 0;
}