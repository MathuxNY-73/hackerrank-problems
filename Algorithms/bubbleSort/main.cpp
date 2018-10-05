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

// Complete the equal function below.
void countSwaps(vector<int> a) {
    auto cnt = 0;
    
    for (auto i = 0; i < a.size(); ++i) {
        for (auto j = a.begin(); j != a.end() - 1; ++j) {
            if (*j > *(j + 1)) {
                auto tmp = *j;
                *j = *(j + 1);
                *(j+1) = tmp;
                ++cnt;
            }
        }
    }
    
    printf("Array is sorted in %d swaps.\n", cnt);
    printf("First Element: %d\n", *a.cbegin());
    printf("Last Element: %d\n", *(a.cend() - 1));
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
    int n;
    fastscan(n);

    vector<int> arr(n);

    int i;
    fl(i,0,n)
    {
        fastscan(arr[i]);
    }

    countSwaps(arr);

    return 0;
}
