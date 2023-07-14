/*
https://leetcode.com/problems/implement-trie-prefix-tree/
*/
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Solution 1 -> iterative
class TrieNode {
    public:
        TrieNode *children[26] = {NULL};
        bool isEndOfWord = false;
    
    bool containsKey(char ch) {
        return children[ch-'a'] != NULL;
    } 
    void put(char ch, TrieNode *child) {
        children[ch-'a'] = child;
    }

    TrieNode* moveAhead(char ch) {
        return children[ch-'a'];
    }

    void setEnd() {
        isEndOfWord = true;
    }

    bool isEnd() {
        return isEndOfWord;
    }

};

class Trie {
public:
    TrieNode *root; 
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        for (int i=0; i<word.size(); i++) {
            if (!(temp->containsKey(word[i]))) {
                temp->put(word[i], new TrieNode());
            }
            temp = temp->moveAhead(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        for (int i=0;i<word.size();i++) {
            if (!(temp->containsKey(word[i]))) {
                return false;
            }
            temp = temp->moveAhead(word[i]);
        }
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for (int i=0;i<prefix.size();i++) {
            if (!(temp->containsKey(prefix[i]))) {
                return false;
            }
            temp = temp->moveAhead(prefix[i]);
        }
        return true;
    }
};

// Solution 2 -> recursive
class TrieNode {
    public:
        char data;
        TrieNode *children[26];
        bool isEndOfWord;
    TrieNode (char data) {
        this->data = data;
        for (int i=0;i<26;i++) {
            this->children[i] = NULL;
        }
        this->isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil (TrieNode *root, string word) {
        if (word.size() == 0) {
            root->isEndOfWord = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode *child;
        if (root->children[idx] != NULL) {
            child = root->children[idx];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }
    
    bool searchUtil (TrieNode *root, string word) {
        if (word.size() == 0) {
            return root->isEndOfWord;
        }

        int idx = word[0] - 'a';
        TrieNode *child;
        if (root->children[idx] != NULL) {
            child = root->children[idx];
        }
        else return false;

        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool startsWithUtil(TrieNode *root, string word) {
        if (word.size() == 0) {
            return true;
        }

        int idx = word[0] - 'a';
        TrieNode *child;
        if (root->children[idx] != NULL) {
            child = root->children[idx];
        }
        else return false;

        return startsWithUtil(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};