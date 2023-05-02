#include <iostream>
#include <vector>
#include <fstream>
#include <string>




bool kycha(int n, std::vector<long long> nums) {
    for (int i = n; i >= 2; i--) {
        if (nums[i] >= nums[i/2])
            continue;
        else return 0;
    }
    return 1;
}

int main()
{
    int n = 0;
    int j = 1;
    bool result;
    std::string line;
    std::string num;
    std::ifstream in("input.txt");
    std::ofstream ofs;
    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    if (in.is_open())
    {
        if (getline(in, line))
        {
            n = std::stoi(line);
            
        }
        std::vector<long long> nums(n + 2);
            if (getline(in, line))
            {
                line += ' ';
                for (unsigned long long i = 0; i < line.size(); i++) {
                    num += line[i];
                    if (line[i + 1] == ' ') {
                        nums[j] = std::stoi(num);
                        std::cout << nums[j] << std::endl;
                        j++;
                        i++;
                        num = "";
                    }

                }
                //nums[n+1] = std::stoi(num);
                //std::cout << nums[j] << std::endl;
                
            }
        if (ofs.is_open())
        {
            result = kycha(n, nums);
            if(result == 0)
            ofs << "No" << std::endl;
            else
                ofs << "Yes" << std::endl;
        }
    }
    ofs.close();
    in.close();
}