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


int main() {
    auto n=0;
    fastscan(n);

    auto k_i = 0;
    fastscan(k_i);
    
    auto res = 0;
    auto k = k_i;

    wl(n)
    {
        int m = 0, r = 0;
        string q;
        cin >> m >> q >> r;
        
        if((q.compare("P")==0 && r != 0 && r % 2 == 0) || (q.compare("I")==0 && r % 2 == 1))
        {
            k += m;
        }
        else if(q.compare("P")!=0 && q.compare("I")!=0 && stoi(q) == r)
        {
            k += 35 * m;
        }
        else
        {
            k -= m;
        }

        if(k == 0)
        {
            ++res;
            k = k_i;
        }

        printf("res: %d, k : %d\n", res, k);
    }
    
    printf("%d\n", res);
    return 0;
}