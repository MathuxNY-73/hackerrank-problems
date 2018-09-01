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
        std::cout << 0 << endl;
    }

    vector<int> operations(n);

    for(int i = 0; i < n ; ++i)
    {
        cin >> operations[i];
    }

    // We use pairs here to store both the element and the index of the element
    // in the original vector to allow us to differentiate element.
    // Courtesy of Frederic Jardon (fjardon)
    set<pair<int,int>> medians;
    queue<set<pair<int,int>>::iterator> iterQ;

    for(int i = 0 ; i < d ; ++i)
    {
        iterQ.push(medians.insert(make_pair(operations[i],i)).first);
    }

    set<pair<int,int>>::iterator itl = medians.begin();
    set<pair<int,int>>::iterator itu = medians.begin();
    int lower = floor((d-1)/2.0);
    int upper = ceil((d-1)/2.0);
    advance(itl, lower);
    advance(itu, upper);

    int notifs = 0;
    for(int i = d ; i < operations.size() ; ++i)
    {
        int op = operations[i];
        float median = (itl->first + itu->first) / 2.0;
        if(op >= median * 2)
        {
            ++notifs;
        }
        set<pair<int,int>>::iterator iter = iterQ.front();
        set<pair<int,int>>::iterator added = medians.insert(make_pair(op,i)).first;
        iterQ.push(added);

        if(*iter <= *itl && *added > *itl)
            ++itl;
        if(*iter >= *itl && *added < *itl)
            --itl;
        if(*iter <= *itu && *added > *itu)
            ++itu;
        if(*iter >= *itu && *added < *itu)
            --itu;

        medians.erase(iter);
        iterQ.pop();
    }

    cout << notifs << endl;

    return 0;
}
