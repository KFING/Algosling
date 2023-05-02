// ConsoleApplication20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
std::fstream fin("huffman.in");
std::ofstream fout("huffman.out");
std::priority_queue <long long, std::vector<long long>, std::greater<long long>>  nums;
int main()
{
	__int64 size;
	fin >> size;
	__int64 a;
	for (int i = 0; i < size; i++) {
		fin >> a;
		nums.push(a);
	}
	__int64 b;
	__int64 c;
	__int64 count = 0;
	while (nums.size() > 1) {
		b = nums.top();
		nums.pop();
		c = nums.top();
		nums.pop();
		//std::cout << b << ' ' << c << ' ' << b + c << '\n';
		count = count + c + b;
		std::cout << b << ' ' << c << '\n';
		nums.push(c + b);
	}
	fout << count;
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