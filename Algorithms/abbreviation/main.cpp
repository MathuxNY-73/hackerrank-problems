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

void print(const vector<vector<bool>>& a) {
    for(auto& x: a)
    {
        for(auto y: x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

// Complete the abbreviation function below.
string abbreviation(string a, string b) {

    auto a_s = a.size();
    auto b_s = b.size();

    auto tbl = vector<vector<bool>>(a_s + 1);

    auto cap = false;
    for(auto i = 0 ; i < tbl.size() ; ++i)
    {
        tbl[i] = vector<bool>(b_s + 1);
        auto k = a_s - i;
        if((a[k] >= 'A' && a[k] <= 'Z') || cap)
        {
            cap = true;
            tbl[i][0] = false;
        }
        else
        {
            tbl[i][0] = true;
        }
    }

    for(auto i = 0 ; i <= b_s ; ++i)
    {
        tbl[0][i] = i == 0;
    }

    for(int i = a_s - 1; i >= 0; --i)
    {
        //cout << "Hello 1" << endl;
        auto k = a_s - i;
        for(int j = b_s - 1; j >= 0 ; --j)
        {
            auto l = b_s - j;

            //cout << "Hello 2 a[i]:" << a[i] << " b[j]:" << b[j] << endl;
            if(a[i] == b[j])
            {
                tbl[k][l] = tbl[k - 1][l - 1];
            }
            else if(toupper(a[i]) == b[j])
            {
                tbl[k][l] = tbl[k - 1][l - 1] || tbl[k-1][l];
            }
            else if(a[i] >= 'A' && a[i] <= 'Z')
            {
                tbl[k][l] = false;
            }
            else
            {
                tbl[k][l] = tbl[k - 1][l];
            }
        }
            //print(tbl);
    }

    return tbl[a_s][b_s] ? "YES" : "NO";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        cout << result << "\n";
    }

    return 0;
}
