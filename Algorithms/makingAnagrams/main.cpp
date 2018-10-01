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

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    auto a_map = map<char, int>();

    auto res = 0;
    
    for(auto x: a)
    {
        if(a_map.find(x) == a_map.cend())
        {
            a_map.insert({x, 0});
        }
        ++a_map[x];
    }
    
    for(auto x: b)
    {
        auto it = a_map.find(x);
        if(it != a_map.cend() && it->second > 0)
        {
            --a_map[x];
        }
        else
        {
            ++res;
        }
    }
    
    for(auto it: a_map)
    {
        res += it.second;
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
