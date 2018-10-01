#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <stack>
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

class Node {
    public:
        int data;
        Node *next;
};

class Solution {
    public:
bool has_cycle(Node* head) {
    auto visited = std::unordered_set<Node*>();
    
    auto cur = head;
    while(cur != NULL)
    {
        visited.insert(cur);
        cur = cur->next;
        if(visited.find(cur) != visited.cend())
        {
            return true;
        }
    }
    return false;
}
};

int main() {

    return 0;
}