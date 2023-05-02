#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
std::vector<std::vector<int>> nums;
int men = 0;
bool isE = false;
int shag(int plitkaI, int plitkaJ) {
	int q = -men;
	nums[plitkaI][plitkaJ] = men;
	if (plitkaI != nums.size() - 1) {
		if ((plitkaI > 0) and (!isE)) {
			if (nums[plitkaI - 1][plitkaJ] == 0) {
				q = shag(plitkaI - 1, plitkaJ);
			}
		}if ((plitkaJ > 0) and (!isE)) {
			if (nums[plitkaI][plitkaJ - 1] == 0) {
				q = shag(plitkaI, plitkaJ - 1);
			}
		}
		if ((plitkaI < nums.size()-1) and (!isE)) {
			if (nums[plitkaI + 1][plitkaJ] == 0) {
				q = shag(plitkaI + 1, plitkaJ);
			}
		}
		if ((plitkaJ < nums[0].size()-1) and (!isE)) {
			if (nums[plitkaI][plitkaJ + 1] == 0) {
				q = shag(plitkaI, plitkaJ + 1);
			}
		}
	}
	else isE = true;
	return men;
}
int main() {
	men = 2;
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	int sizeI;
	int sizeJ; 
	fin >> sizeI;
	fin >> sizeJ;
	nums.resize(sizeI, std::vector<int>(sizeJ));
	std::string str = "0";
	for (int i = 0; i < sizeI; i++) {
		fin >> str;
		for (int j = 0; j < sizeJ; j++) {
			if (str[j] == '0') {
				nums[i][j] = 0;
			}
			else nums[i][j] = 1;
		}
	}
	std::vector<int> cExit;
	for (int i = 0; i < sizeJ; i++) {
		if (nums[0][i] == 0) {
			cExit.push_back(i);
		}
	}
	int plitkaI;
	int plitkaJ;
	for (int i = 0; i < cExit.size(); i++) {
		plitkaI = 0;
		plitkaJ = cExit[i];
		
		shag(plitkaI, plitkaJ);

		isE = false;
		men++;
	}
	men = 2;
	for (int i = 0; i < sizeJ; i++) {
		if (nums[nums.size()-1][i] == men) {
			men++;
		}
	}
	if (men == cExit.size()+2) {
		fout << "Possible";
		return 0;
	}
    fout << "Impossible";
	return 0;
}