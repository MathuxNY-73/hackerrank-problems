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

int dp[2001];

class Solution {
public:
    static int unboundedKnapsack(int k, const vector<int>& arr) {
        memset(dp, 0, sizeof(dp));

        for(auto& c :arr) {
            for(int i = c; i <= k ; ++i) {
                //printf("c: %d, i: %d, dp[%d]=%d, dp[%d]=%d\n", c,i,i,dp[i], i-c, dp[i-c]);
                dp[i] = max(dp[i],c + dp[i-c]);
            }
        }

        //printf("DP: ");
        //for(int i = 0; i <= k; ++i) {
        //    printf("%d ", dp[i]);
        //}
        //printf("\n");

        return dp[k];
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
        int N = 0, K = 0;
        fastscan(N); fastscan(K);

        auto C = vector<int>(N, 0);

        int i = 0;
        fl(i, 0, N) {
            fastscan(C[i]);
        }

        auto res = Solution::unboundedKnapsack(K,C);

        printf("%d\n",res);

    }

    return 0;
}
