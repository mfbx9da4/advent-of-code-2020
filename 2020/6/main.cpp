#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <utility>
#include <cmath>
using namespace std;

ifstream myInputFile("file.txt");

int main()
{
    string line;
    set<char> group_set;
    int sum = 0;
    bool is_first = true;
    while (getline(myInputFile, line))
    {

        if (line == "")
        {
            sum += group_set.size();
            group_set.clear();
            is_first = true;
            continue;
        }

        set<char> new_group_set;

        for (int i = 0; i < line.size(); i++)
        {
            char c = line[i];
            int is_found = group_set.count(c);
            if (is_first)
            {
                new_group_set.insert(c);
            }
            else if (is_found)
            {
                new_group_set.insert(c);
            }
        }
        group_set = new_group_set;
        is_first = false;
    }
    sum += group_set.size();
    cout << "sum" << sum << endl;
    return 0;
}