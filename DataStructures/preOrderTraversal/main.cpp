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
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

        /*void preOrder(Node *root) {
        if(root == NULL)
        {
            return;
        }
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
        return;
    }*/

    void preOrder(Node *root) {
        
        auto s = stack<Node*>();
        s.push(root);
        while(s.size() != 0)
        {
            auto cur = s.top();
            s.pop();
            cout << cur->data << " ";
            if(cur->right != NULL)
            {
                s.push(cur->right);
            }
            if(cur->left != NULL)
            {
                s.push(cur->left);
            }
        }
    }
};

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}