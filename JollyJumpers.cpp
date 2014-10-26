#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool isJolly(const vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
        if (v[i] != v[i + 1] + 1)
            return false;
    return true;
}

int main()
{
    vector<int> numbers;
    vector<int> diff;
    int count;
    int num;
    while (true)
    {
        cin >> count;
        for (int i = 0; i < count; i++)
        {
            cin >> num;
            numbers.push_back(num);
        }
        for (int i = 0; i < numbers.size() - 1; i++)
            diff.push_back(abs(numbers[i] - numbers[i + 1]));
        
        for (int i = 0; i < diff.size(); i++)
            cout << diff[i] << ' ';
        cout << endl;
        
        if (diff[0] == count - 1 && isJolly(diff))
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
        numbers.clear();
        diff.clear();
    }
}
