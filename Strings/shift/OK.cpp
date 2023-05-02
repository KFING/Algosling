// ConsoleApplication20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::fstream fin("input.txt");
std::ofstream fout("output.txt");
std::vector <char> chars;
std::vector<int> nums;
int main()
{
    int size;
    fin >> size;
    std::string str1;
    std::string str2;
    int counter = 0;
    fin >> str1;
    fin >> str2;
    chars.resize(size + size+size+1);
    nums.resize(size + size + size + 1);
    for (int i = 0; i < size; i++) {
        chars[i] = str1[i];
        chars[size + i+1] = str2[i];
        chars[size+size + i + 1] = str2[i];
    }
    chars[size] = '$';
    int k;
    int pos = 0;
    for (int i = 1; i < size + size + size + 1; i++) {
        k = nums[i - 1];
        while ((k > 0) and (chars[k] != chars[i])) {
            k = nums[k - 1];

        }
        if (chars[k] == chars[i]) {
            nums[i] = k + 1;
        }
        else nums[i] = k;
        if (nums[i] == size) {
            pos = i;
        }
    }
    for (int i = 1; i < size + size + size + 1; i++) {
        std::cout << nums[i] << chars[i] << ' ';
    }
    if (pos != 0)
        fout << size + size + size - pos << "\n";
    else fout << -1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file