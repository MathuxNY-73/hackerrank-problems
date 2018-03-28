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

using namespace std;

bool nextActions(int start,
queue<int>& q,
unordered_set<int>& v,
const map<int, int>& ladders,
const map<int, int>& snakes) {
    bool res = false;
    for(auto i = 0 ; i < 6 ; ++i)
    {
        int next = start + (i + 1);
        auto lad = ladders.find(next);
        auto sn = snakes.find(next);
        if(lad != ladders.cend())
        {
            next = lad->second;
        }
        else if(sn != snakes.cend())
        {
            next = sn->second;
        }

        if(next >= 100)
        {
            next = 100;
            res = true;
        }

        if(v.find(next) == v.cend())
        {
            v.insert(next);
            q.push(next);
        }
    }
    return res;
}

void print(const unordered_set<int>& v) {
    for(auto it = v.cbegin(); it != v.cend() ; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void print(queue<int> q) {
    while(q.size() > 0) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {

    int T = 0, nl = 0, ns = 0;

    cin >> T;

    for(int i = 0; i < T ; ++i)
    {
        cin >> nl;
        map<int, int> ladders;
        for(auto j = 0 ; j < nl ; ++j)
        {
            int start = 0, end = 0;
            cin >> start >> end;
            ladders.insert(make_pair(start, end));
        }
        cin >> ns;
        map<int, int> snakes;
        for(auto j = 0 ; j < ns ; ++j)
        {
            int start = 0, end = 0;
            cin >> start >> end;
            snakes.insert(make_pair(start, end));
        }

        // Check if possible
        int checks = 0;
        for(auto it = snakes.cbegin(); it != snakes.cend() ; ++it)
        {
            if(it->first == 94 ||
            it->first == 95 ||
            it->first == 96 ||
            it->first == 97 ||
            it->first == 98 ||
            it->first == 99)
            {
                ++checks;
            }
        }
        if(checks == 6)
        {
            cout << -1 << endl;
            continue;
        }

        unordered_set<int> v(100);
        queue<int> q;
        int start = 1;
        int nActions = 1;

        if(nextActions(start, q, v, ladders,snakes))
        {
            cout << nActions << endl;
            continue;
        }

        bool solved = false;
        queue<int> nLQ;
        while(q.size() > 0 && !solved)
        {
            int curr = q.front();
            q.pop();

            if(nextActions(curr, nLQ, v, ladders, snakes))
            {
                cout << nActions + 1 << endl;
                solved = true;
            }

            cout << "nLQ: ";
            print(nLQ);
            cout << "q: ";
            print(q);

            if(q.size() == 0 && nLQ.size() != 0)
            {
                print(v);
                q = queue<int>(nLQ);
                nLQ = queue<int>();
                ++nActions;
            }
        }

        if(!solved) {
            cout << -1 << endl;
        }
    }

}
