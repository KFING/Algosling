#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::fstream fin("input.in");
std::ofstream fout("output.out");
std::vector<std::vector<int>> nums;
std::vector<int> numsMas;
std::vector<bool> numsBool;
int size;
void bfs(int v) {
    numsBool[v] = 1;
    numsMas.push_back(v);
    for (int u = 0; u < size; u++) {
        if (nums[v][u] == 1 and (numsBool[u] == 0)) {
            bfs(u);
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
    bfs(1);
    if (numsMas.size() == size) {
        fout << "YES";
    }
    else fout << "NO";
    return 0;
}