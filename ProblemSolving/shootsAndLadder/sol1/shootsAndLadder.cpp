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

struct Ladder{
    int begin;
    int end;

    Ladder(int b, int e) : begin(b), end(e) {}
    Ladder(): begin(0), end(0) {}

    bool operator < (const Ladder& other)
    {
        return begin < other.begin;
    }

    bool operator == (const Ladder& other) const
    {
        return begin == other.begin;
    }
};

struct ladderComp{
    inline bool operator() (const Ladder& l, const Ladder& r) {
        return l.begin < r.begin;
    }
};

vector<Ladder> readLadderOrSnakes();
void printBoard(const vector<Ladder>, const vector<Ladder>);
bool populatePossibilities(queue<int>&, int, const vector<Ladder>, const vector<Ladder>, unordered_set<int>&);
bool contains(const unordered_set<int>, int);
bool checkIfPossible(const vector<Ladder>);
int treeBfs(const vector<Ladder>, const vector<Ladder>);
void printQueue(queue<int>);

int main() {

    int T = 0;

    cin >> T;

    for(int i = 0; i < T ; ++i)
    {
        vector<Ladder> ladders = readLadderOrSnakes();
        vector<Ladder> snakes = readLadderOrSnakes();
        //sort(ladders.begin(), ladders.end(), [](Ladder l, Ladder r) -> bool {
        //            return l.begin >= r.begin;
        //        });
        sort(ladders.begin(), ladders.end(), ladderComp());
        sort(snakes.begin(), snakes.end(), ladderComp());

        if(!checkIfPossible(snakes)) 
        {
            cout << -1 << endl;     
        }
        else
        {
            cout << treeBfs(ladders, snakes) << endl;
        }

//        printBoard(ladders, snakes);
    }

}

vector<Ladder> readLadderOrSnakes() {
    int n = 0;

    cin >> n;
    vector<Ladder> res(n);

    for(int i = 0; i < n; ++i)
    {
        Ladder l;
        cin >> l.begin >> l.end;
        res[i] = l;
    }

    return res;
}

int treeBfs(const vector<Ladder> ladders, const vector<Ladder> snakes) 
{
    unordered_set<int> visited(100);
    queue<int>* q = new queue<int>; 
    queue<int>* nextLevelQueue;
    int numberOfAction = 1;

    if(populatePossibilities(*q, 1, ladders, snakes, visited))
    {
        delete q;
        return numberOfAction;
    }
    ++numberOfAction;
    nextLevelQueue = new queue<int>;

    while(q->size() > 0) 
    {
        int curr = q->front();
//        cout << curr << endl;
        q->pop();
        if(populatePossibilities(*nextLevelQueue, curr, ladders, snakes, visited))
        {
            delete q;
            delete nextLevelQueue;
            return numberOfAction;
        }

        if(q->size() == 0 && nextLevelQueue->size() > 0)
        {
//            cout << "Swap" <<endl;
            queue<int>* swap = q;
            q = nextLevelQueue;
            nextLevelQueue = swap;
            ++numberOfAction;
        }
    }

    delete q;
    delete nextLevelQueue;
    return -1;
}

bool populatePossibilities(queue<int>& q, int start, const vector<Ladder> ladders, const vector<Ladder> snakes, unordered_set<int>& visited)
{
    bool finished = false;

    for(int i = 1 ; i <= 6 ; ++i)
    {
        int curr = start + i;
        if(curr == 100)
            finished = true;

        bool snakeOrLadderFound = false;
        vector<Ladder>::const_iterator lad = find(ladders.begin(), ladders.end(), Ladder(curr, curr));
        if(lad != ladders.end())
        {
            snakeOrLadderFound = true;
            if(lad->end == 100)
                finished = true;

            if(!contains(visited, lad->end))
            {
                q.push(lad->end);
                visited.insert(lad->end);
            }
        }

        vector<Ladder>::const_iterator sn = find(snakes.begin(), snakes.end(), Ladder(curr, curr));
        if(sn != snakes.end())
        {
            snakeOrLadderFound = true;
            if(!contains(visited, sn->end))
            { 
                q.push(sn->end);
                visited.insert(sn->end);
            }
        }

        if(!snakeOrLadderFound && !contains(visited, curr))
        {
            q.push(curr);
            visited.insert(curr);
        }
    }
    return finished;
}

bool checkIfPossible(const vector<Ladder> snakes)
{
    return find(snakes.cbegin(), snakes.cend(), Ladder(94, 94)) == snakes.cend() ||
        find(snakes.cbegin(), snakes.cend(), Ladder(95, 95)) == snakes.cend() ||
        find(snakes.cbegin(), snakes.cend(), Ladder(96, 96)) == snakes.cend() ||
        find(snakes.cbegin(), snakes.cend(), Ladder(97, 97)) == snakes.cend() ||
        find(snakes.cbegin(), snakes.cend(), Ladder(98, 98)) == snakes.cend() ||
        find(snakes.cbegin(), snakes.cend(), Ladder(99, 99)) == snakes.cend();;
}

bool contains(const unordered_set<int> set, int item)
{
    return set.find(item) != set.end();
}

void printBoard(const vector<Ladder> ladders, const vector<Ladder> snakes)
{
    vector<Ladder>::const_iterator iter = ladders.cbegin();
    cout << "Ladders:" << endl;
    while(iter != ladders.cend())
    {
        cout << "Starts: " << iter->begin << ", Ends: " << iter->end << endl;
        ++iter;
    }

    cout << "Snakes:" << endl;
    iter = snakes.cbegin();
    while(iter != snakes.cend())
    {
        cout << "Starts: " << iter->begin << ", Ends: " << iter->end << endl;
        ++iter;
    }
}

void printQueue(queue<int> q)
{
    while(q.size() > 0)
    {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
    }
    cout << endl;
}
