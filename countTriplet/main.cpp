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

struct MyGtPred {
    int main;
    
  bool operator()(const int& a) const {
      return a > main;
  }  

    MyGtPred(int m): main(m) {}
};

struct MyLtPred {
    int main;
    
  bool operator()(const int& a) const {
      return a < main;
  }  

    MyLtPred(int m): main(m) {}
};

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    auto t = map<long, vector<int>>();
    long result = 0;
    for(auto i = 0 ; i < arr.size() ; ++i)
    {
        if(t.find(arr[i]) == t.cend())
        {
            t.insert({arr[i], vector<int>()});   
        }
        t[arr[i]].push_back(i);
    }
    
    for(auto it = t.cbegin() ; it != t.cend() ; ++it)
    {
        auto cnt = 0;
        auto itt = it;
        
        if(r == 1)
        {
            long idx_cnt = it->second.size();
            result += idx_cnt >= 3 ? idx_cnt*(idx_cnt-1)*(idx_cnt-2) / 6l : 0;
        }
        else
        {
            auto idx_arr = array<vector<int>, 3>();
            while(itt != t.cend() && cnt < 3)
            {
                idx_arr[cnt] = itt->second;
                ++cnt;
                itt = t.find(itt->first * r);
            }

            if(cnt == 3)
            {
                auto hB_1 = find_if(idx_arr[1].crbegin(), idx_arr[1].crend(), MyLtPred(idx_arr[2].back()));
                auto lB_1 = find_if(idx_arr[1].cbegin(), idx_arr[1].cend(), MyGtPred(idx_arr[0].front()));
                auto lB_2 = find_if(idx_arr[2].cbegin(), idx_arr[2].cend(), MyGtPred(*lB_1));
                auto hB_0 = find_if(idx_arr[0].crbegin(), idx_arr[0].crend(), MyLtPred(*hB_1));

                //cout << "hB_0=" << *hB_0 << " lB_1=" << *lB_1 << " hB_1=" << *hB_1 << " lB_2=" << *lB_2 << endl;
                //cout << "count_1=" << (idx_arr[0].crend() - hB_0) << " count_2=" << ((idx_arr[1].cend() - lB_1) - (hB_1 - idx_arr[1].crbegin())) << " count_3=" << (idx_arr[2].cend() - lB_2) << endl;
                long poss = (idx_arr[0].crend() - hB_0) * ((idx_arr[1].cend() - lB_1) - (hB_1 - idx_arr[1].crbegin())) * (idx_arr[2].cend() - lB_2);
                result += poss;
            }
        }
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
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
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

