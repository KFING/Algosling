#include <iostream>
#include <vector>
#include <fstream>
#include <string>




int Fishka(int k, int n) {
    if (k != 1) {
        std::vector<unsigned long long> nums(n + 1);
        unsigned long long sum = 0;
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i <= k; i++) {
            nums[i] = (sum + nums[i - 1]) % 1000000007;
            sum = sum + nums[i - 1] % 1000000007;
            //std::cout << nums[i] << std::endl;
        }
        for (int i = k + 1; i <= n; i++) {
            sum = sum + nums[i - 1] % 1000000007;
            nums[i] = sum % 1000000007;

            sum = sum - nums[i - k] % 1000000007;


            //std::cout << sum << std::endl;
        }
        std::cout << nums[n] % 1000000007 << std::endl;
        return nums[n] % 1000000007;
    }
    return 1;
}

int main()
{
    int t = 0;
    int n = 0;
    int k = 0;


    std::string line;
    std::string num;
    std::ifstream in("input.txt");
    std::ofstream ofs;
    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    if (in.is_open())
    {
        if (getline(in, line))
        {
            t = std::stoi(line);
        }
        for (int i = 0; i < t; i++) {
            if (getline(in, line))
            {
                for (unsigned long long i = 0; i < line.size(); i++) {
                    num += line[i];
                    if (line[i + 1] == ' ') {
                        n = std::stoi(num);
                        //std::cout << "n " << n << std::endl;
                        num = "";
                    }
                }
                k = std::stoi(num);
                //std::cout << "k " << k << std::endl;
                num = "";
                if (ofs.is_open())
                {
                    ofs << std::to_string(Fishka(k, n)) << std::endl;
                }
            }
        }
    }
    ofs.close();
    in.close();
}