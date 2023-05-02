#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::fstream fin("in.txt");
std::ofstream fout("out.txt");
std::vector<std::vector<int>> nums;
std::vector<int> numsObj;
std::vector<int> probStack;
std::vector<int> temp;
int a;
int b;
void funcSort() {
    if (probStack.size() <= 1) {
        return;
    }
    b = probStack[probStack.size()-1];
    probStack.pop_back();
    a = probStack[probStack.size() - 1];
    probStack.pop_back();
    if (nums[a-1][b-1] == 0) {
        probStack.push_back(a);
        probStack.push_back(b);
        return;
    }
    else {
        probStack.push_back(nums[a - 1][b - 1]);
        funcSort();
    }

}
int main()
{
    int size;
    int objSize;
    fin >> size;
    fin >> objSize;
    nums.resize(size, std::vector<int> (size));
    numsObj.resize(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fin >> nums[i][j];
        }
    }
    fin >> a;
    probStack.push_back(a);
    for (int i = 0; i < objSize - 1; i++) {
        fin >> b;
        probStack.push_back(b);
        funcSort();
    }
    for (int i = probStack.size() - 1; i >= 1; i--) {
        fout << probStack[i]<<' ';
    }
    fout << probStack[0];
    return 0;
}