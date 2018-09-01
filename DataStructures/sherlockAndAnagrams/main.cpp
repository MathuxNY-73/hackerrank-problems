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

using namespace std;

long unsigned myHash(const array<uint8_t, 26>& s) {
    long unsigned t=73,myHash=0;

    for(auto i = 0 ; i < s.size() ; ++i)
    {
        myHash += t*s[i]*('a' - i);
        t=t*(long unsigned)1000003;
    }
    return myHash;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    auto count = 0;
    auto map = unordered_map<long long unsigned, int>();

    for(auto i = 0; i < s.size() ; ++i)
    {
        auto frequence = array<uint8_t, 26>();
        fill(frequence.begin(), frequence.end(), 0);

        for(auto j = i ; j < s.size() ; ++j)
        {
            ++frequence[s[j] - 'a'];
            ++map[myHash(frequence)];
        }
    }

    for (auto it = map.cbegin(); it != map.cend() ; ++it)
    {
        count += (it->second * (it->second - 1)) / 2;
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
