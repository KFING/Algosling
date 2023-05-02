#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::fstream fin("input.txt");
std::ofstream fout("output.txt");
std::vector<std::vector<int>> nums;
std::vector<int> numsMas;
std::vector<bool> numsBool;
int size;
void dfs(int v) {
    numsBool[v] = 1;
    numsMas.push_back(v);
    for (int u = 0; u < size; u++) {
        if (nums[v][u] == 1 and (numsBool[u] == 0)) {
            dfs(u);
        }
    }
}
int main()
{
    
    fin >> size;
    numsBool.resize(size);
    nums.resize(size, std::vector<int>(size));
    int a;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fin >> a;
            nums[i][j] = a;
        }
    }
    int count = 0;
    while(numsMas.size() < size) {
        if (numsBool[count] == 0) {
            dfs(count);
        }
        count++;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (numsMas[j] == i)
                fout << j + 1 << ' ';
        }
    }
    return 0;
}