#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <cmath>
using namespace std;

ifstream myInputFile("file.txt");

typedef pair<int, int> seat_tuple;

int find_row(string binary_seat)
{
    int lo = 0;
    int hi = 127;
    for (int i = 0; i < 7; i++)
    {
        int mid = lo + floor(((hi - lo) / 2));
        if (binary_seat[i] == 'F')
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return hi;
}

int find_col(string binary_seat)
{
    int lo = 0;
    int hi = 7;
    for (int i = 7; i < 10; i++)
    {
        int mid = lo + floor(((hi - lo) / 2));
        if (binary_seat[i] == 'L')
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return hi;
}

seat_tuple binary_seat_to_seat(string binary_seat)
{
    int row = find_row(binary_seat);
    int col = find_col(binary_seat);

    seat_tuple ans(row, col);
    return ans;
}

int seat_id(seat_tuple seat)
{
    return (seat.first * 8) + seat.second;
}

int main()
{
    string line;
    int max_id = 0;
    vector<vector<bool> > seats(128, vector<bool>(8, false));

    while (myInputFile >> line)
    {
        seat_tuple seat = binary_seat_to_seat(line);
        seats[seat.first][seat.second] = true;

        int id = seat_id(seat);
        if (id > max_id)
        {
            max_id = id;
        }
    }
    cout << max_id << endl;

    for (int i = 0; i < seats.size(); i++)
    {
        vector<bool> row = seats[i];
        for (int j = 0; j < row.size(); j++)
        {
            if (!row[j])
            {
                seat_tuple seat1(i, j);
                cout << i << ',' << j << " :  " << seat_id(seat1) << endl;
            }
        }
    }

    return 0;
}