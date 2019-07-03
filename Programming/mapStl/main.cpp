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

#define BUF_SIZE 20
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

inline int fastscan_string(array<char, BUF_SIZE> &str) {
    int c = 0, cnt = 0;
    c = getchar_unlocked();

    for(; c != (int)' ' &&
          c != '\n' &&
          c != '\0' &&
          c != EOF &&
          cnt < BUF_SIZE; c = getchar_unlocked(), ++cnt) {
        str[cnt] = (char)c;
    }

    str[cnt] = '\0';

    return cnt;
}

class Solution {
private:
public:
    void solve_simple() {
        int n;
        fastscan(n);

        map<string, int> clas;

        wl(n) {
            int type = 0; string name;
            cin >> type >> name;

            switch(type) {
                case 1: {
                    int grade = 0;
                    cin >> grade;

                    clas[name] += grade;
                    break;
                }
                case 2: {
                    clas.erase(name);
                    break;
                }
                case 3: {
                    printf("%d\n", clas[name]);
                    break;
                }
            }
        }
    }

    void solve() {
        int n;
        fastscan(n);

        auto m = map<array<char, BUF_SIZE>, int>();

        wl(n) {
            int q = 0;
            fastscan(q);
            auto buff = array<char, BUF_SIZE>();
            fastscan_string(buff);

            switch (q) {
            case 1:
                {
                int grade = 0;
                fastscan(grade);

                auto it = m.find(buff);
                if(it == m.cend())
                    m.insert(make_pair(buff, grade));
                else
                    it->second += grade;
                break;
                }
            case 2:
                {
                m.erase(buff);
                break;
                }
            case 3:
                {
                auto it = m.find(buff);
                if(it == m.cend())
                    printf("0\n");
                else
                    printf("%d\n", it->second);
                break;
                }
            default:
                exit(-1);
            }
        }
    }
};

int main()
{
    auto sol = Solution();
    sol.solve_simple();
    return 0;
}
