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

shared_ptr<vector<int>> coinChangeAlgo(vector<int>&, int);

// Complete the equal function below.
int equal(vector<int> arr) {
    auto coins = vector<int> { 1,2,5 };
    
    sort(arr.begin(), arr.end());
    
    auto change = coinChangeAlgo(coins, arr[arr.size() - 1] + coins[2]);
    auto m = arr[0];
    auto best = numeric_limits<int>::max();
    for(auto i = 0 ; i < coins[2] ; ++i)
    {
        auto score = 0;
        for(auto x: arr)
        {
            score += (*change)[x - m + i];
        }
        best = min(best, score);
    }
    
    return best;
}

shared_ptr<vector<int>> coinChangeAlgo(vector<int>& coins, int n) {
    auto res = make_shared<vector<int>>(vector<int>(n + 1, numeric_limits<int>::max()));
    
    sort(coins.begin(), coins.end());
    
    for(auto i = 0 ; i < coins[0] && i < n+1 ; ++i)
    {
        (*res)[i] = 0;
    }
    
    for(auto c: coins)
    {
        for(auto i = c ; i < n+1 ; ++i)
        {
            (*res)[i] = min((*res)[i], (*res)[i - c] + 1);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    fastscan(t);

    wl(t)
    {
        int n;
        fastscan(n);

        vector<int> colleagues(n);

        int i;
        fl(i,0,n)
        {
            fastscan(colleagues[i]);
        }

        int result = equal(colleagues);

        printf("%d\n", result);
    }

    return 0;
}
