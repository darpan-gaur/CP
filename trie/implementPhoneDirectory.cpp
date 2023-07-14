/*
https://www.codingninjas.com/studio/problems/implement-a-phone-directory_1062666
*/

// Solution 1 (Trie)
class TrieNode {
    public:
        char data;
        TrieNode *children[26];
        bool isEndOfWord;
    TrieNode(char data) {
        this->data = data;
        for (int i=0;i<26;i++) {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

class Trie {
    public:
        TrieNode *root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word) {
        if (word.size()==0) {
            root->isEndOfWord = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode *child;
        if (root->children[idx]!=NULL) {
            // present
            child = root->children[idx];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }
    
    void insrtWord(string word) {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string>& currAns, string prefix) {
        if (curr->isEndOfWord) {
            currAns.push_back(prefix);
        }
        for (char ch='a';ch<='z';ch++) {
            TrieNode *next = curr->children[ch-'a'];

            if (next!=NULL) {
                prefix.push_back(ch);
                printSuggestions(next, currAns, prefix);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> getSuggestions(string s) {
        vector<vector<string>> ans;
        TrieNode *prev = root;
        string prefix = "";

        for (int i=0;i<s.size();i++) {
            char temp = s[i];
            prefix.push_back(temp);

            // check for temp
            TrieNode *curr = prev->children[temp - 'a'];

            if (curr == NULL) break;

            vector<string> currAns;
            printSuggestions(curr, currAns, prefix);

            ans.push_back(currAns);
            currAns.clear();
            prev = curr;
        }
        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t = new Trie();
    for (string s:contactList) {
        t->insrtWord(s);
    }
    return t->getSuggestions(queryStr);
}