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
int main()
{
    int size;
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
    int countReal = 1;
    int counti = 0;
    numsMas.push_back(0);

    while (countReal < size) {

        numsBool[count] = 1;
        for (int i = 0; i < size; i++) {
            if (nums[count][i] == 1 and numsBool[i] == 0) {
                numsMas.push_back(i);
                numsBool[i] = 1;
                //std::cout << counti << ' ';
            }
        }

        if ((countReal >= numsMas.size()) and (countReal < size)) {
            while (numsBool[counti] == 1 and counti < size) {
                counti++;
            }

            //numsBool[counti] = 1;
            numsMas.push_back(counti);
        }
        /*while (numsBool[countReal] == 1) {
            countReal++;
        }*/
        count = numsMas[countReal];
        countReal++;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(numsMas[j] == i)
            fout << j + 1 << ' ';
        }
    }
    return 0;
}