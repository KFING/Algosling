#include <iostream>
#include <fstream>
#include <vector>

std::fstream fin("input.txt");
std::ofstream fout("output.txt");
std::vector<__int64> A;
int main()
{
    __int64 num;
    __int64 numTwo = 1;
    fin >> num;
    while (numTwo <= num) {
        A.push_back(numTwo);
        numTwo = numTwo + numTwo;
    }
    
    for (int i = A.size()-1; i >= 0; i-- ) {
        if (A[i] <= num) {
            num -= A[i];
            A[i] = A[i] * (-1);
        }
    }
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << '\n';
    }
    for (int i = 0; i < A.size(); i++) {
        if(A[i] < 0)
        fout << i<<'\n';
    }
}