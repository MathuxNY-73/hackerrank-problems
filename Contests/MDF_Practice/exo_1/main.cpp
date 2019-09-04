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

using namespace std;

class Solution {
public:
    static int solve(const vector<pair<pair<int, int>, char>>& T, int M) {
        auto threshold = M * 10;
        auto cnt = 0;
        auto alarm = false;
        auto alarm_start_h = 0;
        auto alarm_start_m = 0;
        auto res = 0;

        for(const auto& el: T) {
            cnt += (el.second == 'E' ? 1 : -1);
            if(!alarm && cnt > threshold) {
                printf("Start %d:%d\n", el.first.first, el.first.second);
                alarm = true;
                alarm_start_h = el.first.first;
                alarm_start_m = el.first.second;
            }
            else if(alarm && cnt <= threshold) {
                printf("Stop %d:%d\n", el.first.first, el.first.second);
                alarm = false;
                res += ((el.first.first - alarm_start_h) * 60 + (el.first.second - alarm_start_m));
            }
        }
        if(alarm) {
            res += (23 - alarm_start_h) * 60 - alarm_start_m;
        }

        return res;
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
    int N = 0, M = 0;
    fastscan(N);
    fastscan(M);

    auto t = vector<pair<pair<int,int>, char>>(N);

    int i = 0;
    fl(i, 0, N)
    {
        int hour = 0, minutes = 0;
        fastscan(hour); fastscan(minutes);
        char type = getchar_unlocked();
        getchar_unlocked();
        t[i] = {{hour, minutes}, type};
    }

    //for(auto& el: t) {
    //    printf("%d:%d %c\n", el.first.first, el.first.second, el.second);
    //}

    auto res = Solution::solve(t, M);

    printf("%d\n",res);

    return 0;
}
