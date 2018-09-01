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

/* Node is defined as : */
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

node* rotateLeft(node* n) {
    auto l = n->left;
    
    n->left = l->right;
    l->right = n;
    
    return l;
}

node* rotateRight(node* n) {
    auto r = n->right;
    
    n->right = r->left;
    r->left = n;
    
    return r;
}

int computeHeight(node* r)
{
    auto right_ht = r->right != NULL ? r->right->ht : -1;
    auto left_ht = r->left != NULL ? r->left->ht : -1;
    return max(right_ht, left_ht) + 1;
}

void do_insert(node* r, int val, stack<node*>& s)
{   
    auto cur = r;
    auto inserted = false;
    while(cur != NULL && !inserted)
    {
        s.push(cur);
        if(val <= cur->val)
        {
            if(cur->left != NULL)
            {
                cur = cur->left;
            }
            else
            {
                node* n = new node();
                n->right = NULL;
                n->left = NULL;
                n->ht = 0;
                n->val = val;
                cur->left = n;
                inserted = true;
            }
        }
        else
        {
            if(cur->right != NULL)
            {
                cur = cur->right;
            }
            else
            {
                node* n = new node();
                n->right = NULL;
                n->left = NULL;
                n->ht = 0;
                n->val = val;
                cur->right = n;
                inserted = true;
            }
        } 
    }
    cur->ht = computeHeight(cur);
}

node* balance(node* r)
{
    auto ht_diff = (r->left != NULL ? r->left->ht : -1) - (r->right != NULL ? r->right->ht : -1);
    auto left = r->left;
    auto right = r->right;
    auto new_r = r;
    
    if(ht_diff > 1)
    {
        auto ht_l_diff = (left->left != NULL ? left->left->ht : -1) - (left->right != NULL ? left->right->ht : -1);
                
        if(ht_l_diff < 0)
        {
            r->left = rotateRight(left);
            r->left->left->ht = computeHeight(r->left->left);
        }
        
        new_r = rotateLeft(r);
        new_r->right->ht = computeHeight(new_r->right);
    }
    else if(ht_diff < -1)
    {
        
        auto ht_r_diff = (right->left != NULL ? right->left->ht : -1) - (right->right != NULL ? right->right->ht : -1);
                
        if(ht_r_diff > 0)
        {
            r->right = rotateLeft(right);
            r->right->right->ht = computeHeight(r->right->right);
        }
        new_r = rotateRight(r);
        new_r->left->ht = computeHeight(new_r->left);
    }
    new_r->ht = computeHeight(new_r);
    
    return new_r;
}

node * insert(node * root,int val)
{
    auto s = stack<node*>();
    node* dummy = new node;
    dummy->left = root;
    dummy->right = NULL;
    dummy->val = -1;
    s.push(dummy);
    
	do_insert(root,val, s);
    s.pop();
    while(s.size() != 0)
    {
        auto cur = s.top();
        s.pop();
        
        auto left = cur->left;
        auto right = cur->right;
        
        if(left != NULL)
        {
            cur->left = balance(left);
        }
        
        if(right != NULL)
        {
            cur->right = balance(right);
        }
        
    }
    auto tmp = dummy->left;
    delete(dummy);
    
    return tmp;
}