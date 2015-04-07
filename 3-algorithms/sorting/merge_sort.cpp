#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> v)
{
    auto echo = [&v](int i)
    {
        cout <<i<<" ";
    };
    for_each(begin(v),end(v),echo);
}

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;
    while (not left.empty() or not right.empty())
    {
        if (left.size() > 0 and right.size() > 0)
        {
            if (left.front() <= right.front())
            {
                result.push_back(left.front());
                left.erase(left.begin());
            }
            else
            {
                result.push_back(right.front());
                right.erase(right.begin());
            }
        }
        else if (left.size() > 0)
        {
            move(begin(left),end(left),back_inserter(result));
            left.erase(begin(left),end(left));
            break;
        }
        else if (right.size() > 0)
        {
            move(begin(right),end(right),back_inserter(result));
            right.erase(begin(left),end(left));
            break;
        }
    }
    return move(result);
}

vector<int> mergeSort(vector<int> m)
{
    if (m.size() <= 1)
        return m;

    vector<int> left, right, result;
    int middle = m.size() / 2;

    copy(begin(m),begin(m)+middle,back_inserter(left));
    copy(begin(m)+middle,end(m),back_inserter(right));

    left = mergeSort(left);
    right = mergeSort(right);
    return move(merge(left, right));

}

int main()
{
    vector<int> v = {38,27,43,3,9,82,10};
    print(v);
    cout << "------------------" << endl;
    v = mergeSort(v);
    print(v);
}
