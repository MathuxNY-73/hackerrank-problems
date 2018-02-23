#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
#include <functional>
#include "main.h"

using namespace std;

queue<float> computeMedians(int, const vector<int>);
void balanceQueues(hacked_priority_queue<int, greater<int>>&, hacked_priority_queue<int, less<int>>&);

int main() {
    int n = 0, d = 0;
    cin >> n >> d;

    if( n <= d ) {
        cout << 0 << endl;
    }

    vector<int> operations(n);

    for(int i = 0; i < n ; ++i)
    {
        cin >> operations[i];
    }

    queue<float> medians = computeMedians(d, operations);

    int notifs = 0;
    for(int i = d ; i < operations.size() ; ++i) {
        if(operations[i] >= medians.front() * 2)
        {
            ++notifs;
        }
        medians.pop();
    }

    cout << notifs << endl;

    return 0;
}

queue<float> computeMedians(int d, const vector<int> operations) {
    hacked_priority_queue<int, greater<int>> upper;
    hacked_priority_queue<int, less<int>> lower;

    queue<float> medians;

    for(int i = 0 ; i < operations.size() ; ++i)
    {
        if(upper.empty() || upper.top() < operations[i])
        {
            upper.push(operations[i]);
        }
        else
        {
            lower.push(operations[i]);
        }

        balanceQueues(upper, lower);

        int upperSize = upper.size(), lowerSize = lower.size();
        if(upperSize + lowerSize == d)
        {
            if(upperSize == lowerSize) {
                medians.push((upper.top() + lower.top())/ 2.0);
            }
            else
            {
                medians.push(upper.top());
            }

            int toBeRemoved = operations[i - d + 1];
            if(upper.top() <= toBeRemoved)
            {
                upper.remove(toBeRemoved);
            }
            else
            {
                lower.remove(toBeRemoved);
            }
        }
    }

    return medians;
}

void balanceQueues(hacked_priority_queue<int, greater<int>>& upper,
    hacked_priority_queue<int, less<int>>& lower)
{
    while(upper.size() >= lower.size() + 2)
    {
        lower.push(upper.top());
        upper.pop();
    }
    while(lower.size() >= upper.size() + 1)
    {
        upper.push(lower.top());
        lower.pop();
    }
}
