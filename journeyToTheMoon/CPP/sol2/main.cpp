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

void setUnion(vector<int>& rank, vector<int>& set, int r, int l)
{
    if(rank[r] > rank[l])
    {
        set[l] = r;
    }
    else
    {
        set[r] = l;
        if(rank[r] == rank[l])
        {
            ++rank[r];
        }
    }
}

int findSet(vector<int>& set, int i) {
    if(set[i] != i)
    {
        set[i] = findSet(set, set[i]);
    }
    return set[i];
}

int main() {

    int n = 0, p = 0;
    cin >> n >> p;

    vector<int> ranks(n);
    vector<int> sets(n);
    vector<int> counts(n);

    for(auto i = 0; i < n ; ++i)
    {
        sets[i] = i;
        ranks[i] = 0;
        counts[i] = 0;
    }

    for (auto i = 0; i < p ; ++i)
    {
        int r,l;
        cin >> r >> l;
        setUnion(ranks, sets, findSet(sets, r), findSet(sets, l));
    }

    for(auto i = 0 ; i < n ; ++i)
    {
        ++counts[findSet(sets,i)];
    }

    unsigned long res = 0;
    for(auto it = counts.cbegin() ; it != counts.cend() ; ++it)
    {
        res += *it * (n - *it);
    }

    cout << res/2 << endl;
    return 0;
}