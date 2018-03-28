#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
#include <functional>

using namespace std;

bool comp(pair<int,int> l, pair<int, int> r)
{
    return l.first < r.first;
}

int main() {
    vector<int> notes(5);
    for (auto i = 0 ; i < 5 ; ++i) 
    {
        cin >> notes[i];
    }

    int n = 0, k = 0;
    cin >> n;
    cin >> k;

    priority_queue<pair<int,int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> f(comp);
    for (auto i = 0 ; i < n ; ++i){
        int n6=0;

        int ec = 0;
        for(auto j = notes.cbegin(); j != notes.cend() ;++j) {
            int note;
            cin >> note;
            ec += abs((*j) - note);
        }
        cin >> n6;


        if(f.size() < k)
        {
            f.push(make_pair(ec, n6));
        }
        else if (f.top().first > ec)
        {
            f.pop();
            f.push(make_pair(ec, n6));
        }


            //cout << "top: " << f.top().first << " ec: " << ec << endl;
    }

    int sum = 0;
    while(f.size() != 0) {
        sum += f.top().second;
        f.pop();
    }

    cout << floor(sum/k)<< endl;
}
