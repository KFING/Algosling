#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int F(int n, std::vector<std::vector<int>> a) {
    if (n != 1) {
        int min = 0;
        for (int i = 3; i < n+3; i++) {
            min = min + a[i][0];
            if (a[i - 1][1] + a[i - 2][0] < min) {
                min = a[i - 1][1] + a[i - 2][0];
            }
            if (a[i - 2][2] + a[i - 3][0] < min) {
                min = a[i - 2][2] + a[i - 3][0];
            }
            a[i][0] = min;
        }
        return min;
    }
    return a[3][0];
}

int main()
{
    int n = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int count = 0;


    std::string line;
    std::string num;
    std::ifstream in("input.txt");
    std::ofstream ofs;
    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    if (in.is_open())
    {
        if (getline(in, line))
        {
            const int n = std::stoi(line);
            std::vector<std::vector<int>> a(n+3, std::vector <int>(3));
            for (int j = 3; j < n+3; j++) {
                if (getline(in, line))
                {
                    for (unsigned long long i = 0; i < line.size(); i++) {
                        num += line[i];
                        if (line[i + 1] == ' ') {
                            a[j][count] = std::stoi(num);
                            count++;
                            num = "";
                            i++;
                        }
                    }
                    a[j][2] = std::stoi(num);
                    count = 0;
                    num = "";
                }
            }  
            a[1][2] = a[3][0];
                a[2][0] = 0;
                a[2][1] = a[3][0];
                a[2][2] = a[3][1];
            
            if (ofs.is_open())
            {
                ofs << std::to_string(F(n, a)) << std::endl;
            }
        }

    }
    ofs.close();
    in.close();
}