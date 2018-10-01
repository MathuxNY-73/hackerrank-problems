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
#include <unordered_map>
#include <functional>
#include <stack>
#include <array>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

#define INF 9999999

using namespace std;

void setUnion(vector<int>& rank, vector<int>& set, vector<int>& counts, int r, int l)
{
    if(r == l)
    {
        return;
    }

    if(rank[r] > rank[l])
    {
        set[l] = r;
        counts[r] += counts[l];
    }
    else
    {
        set[r] = l;
        counts[l] += counts[r];
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

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    if(c_lib <= c_road)
    {
        return (long)c_lib * (long)n;
    }

    auto ranks = vector<int>(n+1);
    auto set = vector<int>(n+1);
    auto counts = vector<int>(n+1);

    for(auto i = 1 ; i <= n ; ++i)
    {
        ranks[i] = 0;
        set[i] = i;
        counts[i] = 1;
    }

    for(auto c: cities)
    {
        auto c_d = c[0];
        auto c_a = c[1];
        setUnion(ranks, set, counts, findSet(set, c_d), findSet(set, c_a));
    }
    
    long res = 0;
    for(auto i = 1 ; i < n+1 ; ++i)
    {
        if(set[i] == i)
        {
            cout << "i:"<<i<<" counts:"<<counts[i]<<" ranks:" << ranks[i]<<endl;
            res += (counts[i] - 1) * c_road + c_lib;
        }
    }

    return res;
}

inline void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar_unlocked();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int main()
{
    auto q=0;
    fastscan(q);

    wl(q)
    {
        auto n = 0, m = 0, c_lib=0, c_road = 0;
        fastscan(n);
        fastscan(m);
        fastscan(c_lib);
        fastscan(c_road);

        auto g = vector<vector<int>>(m);

        int i;
        fl(i,0,m)
        {
            g[i] = vector<int>(2);
            fastscan(g[i][0]);
            fastscan(g[i][1]);
        }

        unsigned long long res = roadsAndLibraries(n, c_lib, c_road, g);

        printf("%lld\n", res);
    }

    return 0;
}
