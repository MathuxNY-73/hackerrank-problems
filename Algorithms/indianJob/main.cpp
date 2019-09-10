#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

using namespace std;

int dp[1000000];


class Solution {
public:
    static string solve(const vector<int>& A, int G) {
        auto sum = accumulate(A.cbegin(), A.cend(), 0);
        auto m = 0;
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for(int i = 0; i < A.size() ; ++i) {
            m += A[i];

            for(int g = m ; g - A[i] >= 0 ; --g) {
                if(dp[g - A[i]]) {
                    dp[g] = 1;
                    if(g <= G && sum - g <= G) {
                    return "YES";
                    }
                }
            }
        }

        return "NO";
    }
};

inline void fastscan(int& number)
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
    int t = 0;
    fastscan(t);

    wl(t) {
        int N = 0, G = 0;
        fastscan(N); fastscan(G);

        auto A = vector<int>(N, 0);

        int i = 0;
        fl(i, 0, N) {
            fastscan(A[i]);
        }

        auto res = Solution::solve(A, G);

        printf("%s\n",res.c_str());

    }

    return 0;
}
