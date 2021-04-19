#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <utility>
#include <cmath>
// #include <algorithm>
using namespace std;

ifstream myInputFile("file.txt");

vector<string> split_string(string str, string delimiter)
{
    string token;
    vector<string> vec;
    int last = 0;
    int next = 0;
    while ((next = str.find(delimiter, last)) != string::npos)
    {
        token = str.substr(last, next - last);
        vec.push_back(token);
        last = next + 1;
    }
    token = str.substr(last);
    vec.push_back(token);
    return vec;
}

int main()
{
    string line;
    int valid_total = 0;
    while (getline(myInputFile, line))
    {
        vector<string> parts = split_string(line, " ");

        vector<string> range = split_string(parts[0], "-");
        int min = atoi(range[0].c_str());
        int max = atoi(range[1].c_str());
        string target = parts[1];
        char targetC = target[0];
        string pwd = parts[2];
        int count = 0;

        for (int i = 0; i < pwd.size(); i++)
        {
            char c = pwd[i];
            if (c == targetC)
            {
                count++;
            }
        }

        if (count >= min && count <= max)
        {
            valid_total++;
        }
    }
    cout << valid_total << endl;

    return 0;
}