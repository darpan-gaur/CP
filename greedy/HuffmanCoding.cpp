/*
Huffman Coding
https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

Time Complexity: O(NlogN)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
		Node *left, *right;
		Node(int data) {
			this->data = data;
			left = right = NULL;
		}
};

class compare {
	public:
		bool operator()(Node* l, Node* r) {
			return (l->data > r->data);
		}
};

class Solution
{
	public:
		void getCodes(Node *root, vector<string> &ans, string str) {
			if (root->left == NULL && root->right == NULL) {
				ans.push_back(str);
				return;
			}
			getCodes(root->left, ans, str + "0");
			getCodes(root->right, ans, str + "1");
		}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>, compare> minHeap;
			for (int i = 0; i < N; ++i) minHeap.push(new Node(f[i]));
			while (minHeap.size() > 1) {
				Node *left = minHeap.top();
				minHeap.pop();

				Node *right = minHeap.top();
				minHeap.pop();

				Node *top = new Node(left->data + right->data);
				top->left = left;
				top->right = right;
				minHeap.push(top);
			}
			vector<string> ans;
			getCodes(minHeap.top(), ans, "");
			return ans;	
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}