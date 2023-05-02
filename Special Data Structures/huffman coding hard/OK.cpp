#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;



bool Comparator(__int64& first, __int64& second)
{
	return first < second;
}
int main()
{
	ifstream fin("huffman.in");
	ofstream fout("huffman.out");
	priority_queue <long long, std::vector<long long>, std::greater<long long>>  nums;
	long long size;
	fin >> size;
	long long a;
	for (int i = 0; i < size; i++) {
		fin >> a;
		nums.push(a);
	}
	long long b;
	long long c;
	long long count = 0;
	long long sum;
	while (nums.size() > 1) {
		b = nums.top();
		nums.pop();
		c = nums.top();
		nums.pop();
		//std::cout << b << ' ' << c << ' ' << b + c << '\n';
		sum = c+b;
		count += sum;
		nums.push(sum);
	}
	fout << count;
}