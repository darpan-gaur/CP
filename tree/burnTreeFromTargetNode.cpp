/*
https://practice.geeksforgeeks.org/problems/burning-tree/1
*/

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Solution 1
// Time Complexity: O(nlogn), Space Complexity: O(n)
class Solution {
  public:
    map<Node*, Node*> nodeToParent;
    int ans=0;
    // create map and return target node
    Node* createMap(Node* root, int target) {
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (temp->data == target) res = temp;
            if (temp->left) {
                nodeToParent[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                nodeToParent[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return res;
        
    }
    
    // do bfs to find burning time
    void burnTree(Node* target) {
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(target);
        visited[target] = true;
        while (!q.empty()) {
            int n = q.size();
            bool chk = 0;
            for (int i=0;i<n;i++) {
                Node* temp = q.front();
                q.pop();
                if (temp->left && !visited[temp->left]) {
                    visited[temp->left] = true;
                    q.push(temp->left);
                    chk =1 ;
                }
                
                if (temp->right && !visited[temp->right]) {
                    visited[temp->right] = true;
                    q.push(temp->right);
                    chk = 1;
                }
                
                if (nodeToParent[temp] && !visited[nodeToParent[temp]]) {
                    visited[nodeToParent[temp]] = true;
                    q.push(nodeToParent[temp]);
                    chk = 1;
                }
            }
            if (chk) ans++;
        }
    }
    
    int minTime(Node* root, int target) 
    {
        // convert to graph and bfs from target
        Node* targetNode = createMap(root, target);
        burnTree(targetNode);
        return ans;
    }
};