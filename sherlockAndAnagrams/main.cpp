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

using namespace std;


bool checkAnagrams(const string& a, const string& b)
{
    if(a.size() != b.size())
    {
        return false;
    }

    unordered_map<char, int> countByChar;
    for(auto i = 0; i < a.size(); ++i)
    {
        auto it = countByChar.find(a[i]);
        if(it != countByChar.cend())
        {
            ++it->second;
        }
        else
        {
            countByChar.insert({a[i], 1});
        }
    }

    for(auto i = 0 ; i < b.size() ; ++i)
    {
        auto it = countByChar.find(b[i]);
        if(it != countByChar.cend() && it->second > 0)
        {
            --it->second;
        }
        else
        {
            return false;
        }
    }

    return true;
}
// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    auto count = 0;

    for(auto i = 1; i <= s.size() ; ++i)
    {
        for(auto j = 0 ; j <= s.size() - i; ++j)
        {
            auto sub_x = s.substr(j, i);

            //cout << "sub_x=" << sub_x << endl;
            for(auto k = j + 1 ; k <= s.size() - i ; ++k)
            {
                auto sub_y = s.substr(k, i);
                //cout << "sub_y=" << sub_y << endl;
                if(checkAnagrams(sub_x, sub_y))
                {
                    //cout << "sub_x=" << sub_x << " sub_y=" << sub_y << " " << endl;
                    ++count;
                }
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}
