/*
https://leetcode.com/problems/longest-common-prefix/
*/

// Solution 1: Vertical scanning
// Time complexity: O(S), where S is the sum of all characters in all strings.
// Space complexity: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int i,j;
        for (i=0;i<strs[0].size();i++) {
            char chk = strs[0][i];
            for (j=1;j<strs.size();j++) {
                if (i<strs[j].size() && (chk==strs[j][i])) continue;
                else break;
            }
            if (j!=strs.size()) break;
            ans += chk;
        }
        return ans;
    }
};

// Solution 2: Horizontal scanning
// Time complexity: O(S), where S is the sum of all characters in all strings.
// Space complexity: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        string ans = strs[0];
        for (int i=1;i<strs.size();i++) {
            while (strs[i].find(ans)!=0) {
                ans = ans.substr(0,ans.size()-1);
                if (ans=="") return "";
            }
        }
        return ans;
    }
};

// Solution 3: Divide and conquer
// Time complexity: O(S), where S is the sum of all characters in all strings.
// Space complexity: O(m*log(n)), n-> number of strings, m-> length of shortest string
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        return longestCommonPrefix(strs,0,strs.size()-1);
    }
    
    string longestCommonPrefix(vector<string>& strs, int l, int r) {
        if (l==r) return strs[l];
        else {
            int mid = (l+r)/2;
            string lcpLeft = longestCommonPrefix(strs,l,mid);
            string lcpRight = longestCommonPrefix(strs,mid+1,r);
            return commonPrefix(lcpLeft,lcpRight);
        }
    }
    
    string commonPrefix(string left, string right) {
        int minLen = min(left.size(),right.size());
        for (int i=0;i<minLen;i++) {
            if (left[i]!=right[i]) return left.substr(0,i);
        }
        return left.substr(0,minLen);
    }
};

// Solution 4: Binary search
// Time complexity: O(S*log(n)), where S is the sum of all characters in all strings.
// Space complexity: O(1)  
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        int minLen = INT_MAX;
        for (string str:strs) {
            minLen = min(minLen,(int)str.size());
        }
        int low=1,high=minLen;
        while (low<=high) {
            int mid = (low+high)/2;
            if (isCommonPrefix(strs,mid)) low = mid+1;
            else high = mid-1;
        }
        return strs[0].substr(0,(low+high)/2);
    }
    
    bool isCommonPrefix(vector<string>& strs, int len) {
        string str1 = strs[0].substr(0,len);
        for (int i=1;i<strs.size();i++) {
            if (strs[i].find(str1)!=0) return false;
        }
        return true;
    }
};

// Solution 5: Trie
// Time complexity: O(S), where S is the sum of all characters in all strings.
// Space complexity: O(S), where S is the sum of all characters in all strings.
class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isEndOfWord;
    TrieNode(char data) {
        this->data = data;
        for (int i=0;i<26;i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isEndOfWord = false;
    }
};

class Trie{
    public:
        TrieNode *root;
    
    Trie(char data) {
        root = new TrieNode(data);
    }

    void insertUtil(TrieNode *root, string word) {
        if (word.size()==0) {
            root->isEndOfWord = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode *child;
        if (root->children[idx]!=NULL) {
            child = root->children[idx];
        }
        else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        for (int i=0;i<str.size();i++) {
            char ch = str[i];

            if (root->childCount == 1) {
                ans.push_back(ch);
                int index = ch-'a';
                root = root->children[index];
            }
            else break;
            if (root->isEndOfWord) break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        Trie *t = new Trie('\0');

        for (string s:strs) {
            if (s.size()==0) return "";
            t->insertWord(s);
        }

        string first = strs[0];
        string ans = "";
        t->lcp(first, ans);
        return ans;
    }
};