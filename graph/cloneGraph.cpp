/*
https://leetcode.com/problems/clone-graph/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Solution 1, DFS
// Time complexity: O(V+E), Space complexity: O(V)
class Solution {
public:
    map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        if (mp.find(node)==mp.end()) {
            mp[node] = new Node(node->val);
            for (Node* x:node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(x));
            }
        }
        return mp[node];
    }
};

// Solution 2, BFS
// Time complexity: O(V+E), Space complexity: O(V)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* res = new Node(node->val);
        map<Node*, Node*> mp;
        mp[node] = res;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            for (Node* x:temp->neighbors) {
                if (mp.find(x)==mp.end()) {
                    mp[x] = new Node(x->val);
                    q.push(x);
                }
                mp[temp]->neighbors.push_back(mp[x]);
            }
        }
        return res;
    }
};