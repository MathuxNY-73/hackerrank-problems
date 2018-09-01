#ifndef MAIN_H
#define MAIN_H

using namespace std;

template<class T1, class T2 = vector<T1>, class T3 = less<T1>> 
    priority_queue<T1,T2,T3> removeItem(priority_queue<T1, T2, T3> q, T1 item)
{
    priority_queue<T1, T2, T3> res;
    bool occurence_rm = false;
    while(!q.empty())
    {
        T1 t = q.top();

        if(!occurence_rm && t == item)
        {
            occurence_rm = true;
        }
        else
        {
            res.push(t);
        }
        q.pop();
    }
    return res;
};

template<class T1, class T2 = less<T1>>
    struct hacked_priority_queue: priority_queue<T1, vector<T1>, T2> {
        public:
        void remove(int item) {
            vector<int>::iterator it = std::find(
                priority_queue<T1, vector<T1>, T2>::c.begin(),
                priority_queue<T1, vector<T1>, T2>::c.end(),
                item);
            cout << "Hello 1: " << *it << endl;
            if(it != priority_queue<T1, vector<T1>, T2>::c.end())
            {
                priority_queue<T1, vector<T1>, T2>::c.erase(it);
            }
        }
    };

template<typename T1, class T2 = vector<T1>, class T3 = less<T1>>
void print_queue(priority_queue<T1,T2,T3> q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
};

#endif