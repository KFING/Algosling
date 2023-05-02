#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;


int main()
{

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    int m;
    fin >> n;
    fin >> m;
    vector<bool> isNums(n);
    vector<long long> dist(n, LLONG_MIN);
    priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> qNums;
    vector<vector<pair<long long, long long>>> nums(n);
    long long a;
    long long b;
    long long c;
    for (int i = 0; i < m; i++) {
        fin >> a;
        fin >> b;
        fin >> c;
        nums[a - 1].push_back(make_pair(b - 1, c));
        nums[b - 1].push_back(make_pair(a - 1, c));
    }
    qNums.push(make_pair(0, 0));
    while (!qNums.empty()) {
        pair<long long, long long> thisNum = qNums.top();
        qNums.pop();
        if (!isNums[thisNum.second]) {
            dist[thisNum.second] = thisNum.first;
            for (pair<long long, long long> i : nums[thisNum.second]) {
                if ((!isNums[i.first]) and (thisNum.first + i.second > dist[i.first])) {
                    qNums.push(make_pair(thisNum.first + i.second, i.first));
                }
            }
        }
        isNums[thisNum.second] = true;
    }
    fout << dist[n - 1];
    return 0;
}