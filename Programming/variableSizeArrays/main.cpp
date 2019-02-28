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

inline char fastscan(int &number)
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

    return c;
}

inline void fastscan_vector(vector<int> &vector)
{
    int i;
    while(fastscan(i) != '\n') {
        vector.push_back(i);
    }
}

class Solution {
private:
public:
    void solve() {
        int n;
        fastscan(n);

        auto v = vector<vector<int>>(n);

        int q;
        fastscan(q);

        for(auto i = 0 ; i < n ; ++i) {
            int k;
            fastscan(k);
            v[i] = vector<int>(k);

            for(auto j = 0; j < k; ++j) {
                fastscan(v[i][j]);
            }
        }

        wl(q) {
            int i, j;
            fastscan(i); fastscan(j);
            // Indices are assumed to be inside boundaries
            printf("%d", v[i][j]);
            printf("\n");
        }
    }
};

int main()
{
    auto sol = Solution();
    sol.solve();
    printf("\n");
    return 0;
}
