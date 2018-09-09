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

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    if(is_matching(a,b))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

bool is_matching(string a, string b)
{
    if(b.size() == 0)
    {
        auto res = true;
        for(auto c: a)
        {
            res = res || !('A' <= c && c <= 'Z');
        }
        return res;
    }
    else if(a.size() == 0)
    {
        return false;
    }

    auto last_char_a = *(a.cend() - 1);
    auto last_char_b = *(b.cend() - 1);

    if(last_char_a == last_char_b)
    {
        return is_matching(a.substr(0, a.size() - 1), b.substr(0, b.size() - 1));
    }
    else if('A' <= last_char_a && last_char_a <= 'Z')
    {
        return false;
    }
    else
    {   
        //cout << "Before: " << a[a.size() - 1] << endl;
        a[a.size() - 1] += ('A' - 'a');
        //cout << "Cap: " << a[a.size() - 1] <<endl;
         return is_matching(a.substr(0, a.size() - 1), b) ||
            is_matching(a, b);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
