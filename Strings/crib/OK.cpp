// ConsoleApplication20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::fstream fin("input.txt");
std::ofstream fout("output.txt");
std::vector<char> A;
std::vector<char> B;
int main()
{
    int L;
    int R;
    int size;
    char ch;
    bool isPlag = true;
    fin >> size;
    for (int i = 0; i < size; i++) {
        fin >> ch;
        A.push_back(ch);
    }
    for (int i = 0; i < size; i++) {
        fin >> ch;
        B.push_back(ch);
    }
    for (int i = 0; i < size; i++) {
        if (A[i] != B[i]) {
            L = i;
            i = size;
        }
    }
    for (int i = 0; i < size; i++) {
        if (A[size - i-1] != B[size - i-1]) {
            R = size - i - 1;
            i = size;
        }
    }
    for (int i = L; i <= R; i++) {
        if (A[i] != B[R+L-i]) {
            i = R;
            isPlag = false;
        }
    }
    if (isPlag) {
        fout << "Yes" << '\n';
        fout << L + 1 << ' ' << R + 1 << '\n';
    }
    else fout << "No" << '\n';
    return 0;
}