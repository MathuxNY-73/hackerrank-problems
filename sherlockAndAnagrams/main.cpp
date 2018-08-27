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


struct MyHash {
    long unsigned int operator()(const array<uint8_t, 26>& s) const {
        long unsigned int myHash = 73;

        for(auto i = 0 ; i < s.size() ; ++i)
        {
            myHash ^= hash<uint8_t>{}(s[i] * i);
        }

        return myHash;
    }
};

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    auto count = 0;

    for(auto i = 1; i <= s.size() ; ++i)
    {
        auto map = unordered_map<string, int>();
        for(auto j = 0 ; j <= s.size() - i; ++j)
        {
            auto sub_s = s.substr(j, i);
            sort(sub_s.begin(), sub_s.end());
            ++map[sub_s];
        }

        for (auto it = map.cbegin(); it != map.cend() ; ++it)
        {
            count += (it->second * (it->second - 1)) / 2;
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
