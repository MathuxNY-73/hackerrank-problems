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
#include <functional>
#include <stack>

using namespace std;

struct node{
    int s;
    int p;
    vector<int> remainingMandragora;
};

vector<int> copyMinusIndex(vector<int> v, int idx) {
    vector<int> res = vector<int>();
    for(auto i = v.cbegin(); i != v.cend() ; ++i)
    {
        if(std::distance(v.cbegin(), i) != idx) 
        {
            res.push_back(*i);
        }
    }
    return res;
}

void printArray(vector<int> v) 
{
    for(auto it = v.cbegin() ; it != v.cend() ; ++it)
    {
        cout << *it << " ";
    }
    cout <<endl;
}

int main() {

    node initNode;
    initNode.s =1;
    initNode.p = 0;

    int t = 0;

    cin >> t;

    for (int i = 0 ; i < t ; ++i) {
        int n = 0;
        int maxP = -1;
        cin >> n;
        initNode.remainingMandragora = vector<int>();
        for (int j = 0 ; j < n ; ++j)
        {
            int hi;
            cin >> hi;
            initNode.remainingMandragora.push_back(hi);
        }

        queue <node> qNode;
        qNode.push(initNode);

        while(!qNode.empty()) {
            node t = qNode.front();
            qNode.pop();

            //cout << "Xp: " << t.p << ", S: " << t.s << endl;
            //printArray(t.remainingMandragora);

            if(maxP < t.p) {
                maxP = t.p;
            }

            for(auto it = t.remainingMandragora.cbegin(); it != t.remainingMandragora.cend() ;++it) {
                node childBattle;
                childBattle.p = t.p + t.s * (*it);
                childBattle.s = t.s;
                childBattle.remainingMandragora = copyMinusIndex(t.remainingMandragora, std::distance(t.remainingMandragora.cbegin(), it));
                //printArray(childBattle.remainingMandragora);

                node childEat;
                childEat.p = t.p;
                childEat.s = t.s + 1;
                childEat.remainingMandragora = copyMinusIndex(t.remainingMandragora, std::distance(t.remainingMandragora.cbegin(), it));
                //printArray(childBattle.remainingMandragora);

                qNode.push(childBattle);
                qNode.push(childEat);
            }
        }

        cout << maxP << endl;
    }

    return 0;
}