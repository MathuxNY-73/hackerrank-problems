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

using namespace std;

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

    multiset<int> medians;
    queue<multiset<int>::iterator> iterQ;

    for(int i = 0 ; i < d ; ++i)
    {
        iterQ.push(medians.insert(operations[i]));
    }

    //cout << "Hello 4: ";
    //    for(auto it = medians.cbegin(); it != medians.cend() ; ++it)
    //        cout << *it << " ";
    //    cout << endl;

    multiset<int>::iterator itl = medians.begin();
    multiset<int>::iterator itu = medians.begin();
    int lower = floor((d-1)/2.0);
    int upper = ceil((d-1)/2.0);
    advance(itl, lower);
    //cout << "Test: " << (d-1)/2.0 << " Floor: " <<floor((d-1)/2.0) << endl;
    //cout << "Test: " << (d-1)/2.0 << " Ceil: " <<ceil((d-1)/2.0) << endl;
    advance(itu, upper);

    int notifs = 0;
    for(int i = d ; i < operations.size() ; ++i)
    {
        //cout << "Medians: " << &medians << endl;
        int op = operations[i];
        //cout << "i: " << i << endl;
        //cout << "notif: " << notifs << endl;
        float median = (*itl + *itu) / 2.0;
        //cout << "Hello 1: " << *(itl) << endl;
        //cout << "Hello 2: " << *(itu) << endl;
        //cout << "Hello 3: " << median << endl;
        //cout << "Hello 5: " << distance(medians.cbegin(), itl) << " " << distance(medians.cbegin(), itu) << endl;
        if(op >= median * 2)
        {
            ++notifs;
        }
        multiset<int>::iterator iter = iterQ.front();
        iterQ.push(medians.insert(op));
        cout << "Test violent: " << &itl << endl;

        if(*iter <= *itl && op > *itl)
            advance(itl, 1);
        else if(*iter >= *itl && op < *itl)
            advance(itl, -1);
        if(*iter <= *itu && op > *itu)
            advance(itu, 1);
        else if(*iter >= *itu && op < *itu)
            advance(itu, -1);

        medians.erase(iter);
        iterQ.pop();
        //cout << "Hello 6" << endl;
        //cout << "Hello 7" << endl;
        //cout << "Hello 4: ";
        //for(auto it = medians.cbegin(); it != medians.cend() ; ++it)
        //    cout << *it << " ";
        //cout << endl;

    }

    cout << notifs << endl;

    return 0;
}
