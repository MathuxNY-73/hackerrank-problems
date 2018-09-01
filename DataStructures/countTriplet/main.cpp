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
#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long countTriplets(vector<long> arr, long r) {
    auto t = unordered_map<long, long>();
    auto p = unordered_map<long, long>();
    long result = 0;
    for(int i = arr.size() - 1 ; i >= 0 ; --i)
    {
        auto cur = arr[i];
        if(t.find(cur) == t.cend())
        {
            t.insert({cur, 0});
        }

        if(p.find(cur) == p.cend())
        {
            p.insert({cur, 0});
        }

        auto r_1 = cur * r;
        auto p_r1 = p.find(r_1);

        if(p_r1 != p.cend())
        {
            result += p_r1->second;
        }

        auto t_r1 = t.find(r_1);
        if(t_r1 != t.cend())
        {
            p[cur] += t[r_1];
        }

        ++t[cur];
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    cout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not_fn([] (const char& c) -> bool { return isspace(c);}))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not_fn([] (const char& c) -> bool { return isspace(c);})).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

