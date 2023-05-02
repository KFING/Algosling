#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::fstream fin("bst.in");
std::ofstream fout("bst.out");
std::vector<std::vector<__int64>> nums;
int main()
{
    __int64 num;
    __int64 parent;
    bool isbts = true;
    char ch;
    __int64 size;
    __int64 numTwo = 1;
    fin >> size;
    nums.resize(size, std::vector<__int64>(3));
    fin >> num;
    nums[0][0] = num;
    nums[0][1] = LLONG_MIN;
    nums[0][2] = LLONG_MAX;


    if (size != 1)
        for (int i = 1; i < size; i++) {
            fin >> num;
            fin >> parent;
            fin >> ch;
            nums[i][0] = num;
            if (ch == 'R') {
                nums[i][2] = nums[parent - 1][2];
                nums[i][1] = nums[parent - 1][0];
                if ((nums[i][0] > nums[i][2]) or (nums[i][0] < nums[i][1])) {
                    fout << "NO";
                    return 0;
                }
                
            }
            else{
                nums[i][1] = nums[parent - 1][1];
                nums[i][2] = nums[parent - 1][0]-1;
                if ((nums[i][0] > nums[i][2]) or (nums[i][0] < nums[i][1])) {
                    fout << "NO";
                    return 0;
                }
                
            }
        }
    fout << "YES";

}