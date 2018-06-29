#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <unordered_set>

using namespace std;

void pushToQueue(double i, priority_queue<double>& l,
    priority_queue<double, vector<double>, greater<double>>& u)
{
    if(l.size() > 0 && i > l.top())
    {
        u.push(i);
    }
    else
    {
        l.push(i);
    }
}

void balanceQueues(priority_queue<double>& l,
    priority_queue<double, vector<double>, greater<double>>& u)
{
    while(u.size() > l.size())
    {
        l.push(u.top());
        u.pop();
    }

    while(l.size() > u.size() + 1)
    {
        u.push(l.top());
        l.pop();
    }
}

double getMedian(const priority_queue<double>& l,
    const priority_queue<double, vector<double>, greater<double>>& u)
{
    if((l.size() + u.size()) % 2 == 0)
    {
        return (l.top() + u.top()) / (double)2.0;
    }
    else
    {
        return l.top();
    }
}

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    vector<double> medians(a.size());

    priority_queue<double> lower;
    priority_queue<double, vector<double>, greater<double>> upper;

    for(auto i = 0; i < a.size() ; ++i)
    {
        pushToQueue(a[i], lower, upper);
        balanceQueues(lower, upper);
        medians[i] = getMedian(lower, upper);
    }

    return medians;
}

int main()
{
    //ofstream fout("stdout");

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << result[result_itr];

        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    //fout.close();

    return 0;
}