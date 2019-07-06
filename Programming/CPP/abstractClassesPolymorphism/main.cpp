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

typedef struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val): prev(p),next(n),key(k),value(val){};
    Node(int k, int val): prev(NULL),next(NULL),key(k),value(val){};
} Node;

class Cache{
protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp; //capacity
    Node* tail; //double linked list tail pointer
    Node* head; //double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function
};

class LRUCache: public Cache {
private:
    bool contains(int key) {
        //cout << "Hello 9" << endl;
        return mp.find(key) != mp.cend();
    }
    int current_cap;

public:
    LRUCache(int capacity): current_cap(0){
        mp = map<int, Node*>();
        cp = capacity;
        tail = NULL;
        head = NULL;
    }
    ~LRUCache() {
        head = NULL; tail = NULL;
        for(auto&& [first, second]: mp) {
            delete second;
        }
    }

    void set(int key, int val) override {
        //cout << "Hello 1" << endl;
        if (contains(key)) {
            //cout << "Hello 8" << endl;
            // hit: update existing value
            auto cur = mp[key];
            cur->value = val;
            head->prev = cur;

            if(cur->prev != NULL) {
                cur->prev->next = cur->next;
            }
            if(cur->next != NULL) {
                cur->next->prev = cur->prev;
            }

            cur->prev = NULL;
            cur->next = head;
            head = cur;
        }
        else {
            //cout << "Hello 2" << endl;
            // miss add value to cache and delete LRU entry if over capacity
            auto cur = new Node(NULL, head, key, val);
            if(head == NULL && tail == NULL) {
                //cout << "Hello 3" << endl;
                head = cur; tail = cur;
            }
            else if (head == NULL || tail == NULL) {
                //cout << "Hello 4" << endl;
                head = NULL; tail = NULL;
                for(auto&& [first, second] : mp) {
                    delete second;
                }
                delete cur;
                exit(-1);
            }
            else {
                //cout << "Hello 5" << endl;
                head->prev = cur;
                head = cur;
            }

            mp[key] = cur;
            //cout << "mp: ";
            for(auto&& [first, second]: mp) {
                //cout << first << "->" << second->value << " ";
            }
            //cout << endl;

            if(current_cap == cp) {
                //cout << "Hello 6" << endl;
                auto to_be_deleted = tail;
                mp.erase(to_be_deleted->key);
                tail->prev->next = NULL;
                tail = to_be_deleted->prev;
                delete to_be_deleted;
            }
            else {
                //cout << "Hello 7" << endl;
                ++current_cap;
            }
        }
    }

    int get(int key) override {
        if(contains(key)) {
            // hit and return the value
            return mp[key]->value;
        }
        else {
            // miss return -1:wa
            return -1;
        }
    }
};

inline char fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar_unlocked();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;

    return c;
}

inline void fastscan_vector(vector<int> &vector)
{
    int i;
    while(fastscan(i) != '\n') {
        vector.push_back(i);
    }
}

int main()
{
    int n, capacity;
    fastscan(n);
    fastscan(capacity);

    LRUCache l = LRUCache(capacity);

    for(auto i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if(cmd == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if(cmd == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
