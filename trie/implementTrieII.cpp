/*
https://www.codingninjas.com/studio/problems/implement-trie_1387095
*/

// Solution 1 
class TrieNode {
    public:
        TrieNode *children[26] = {NULL};
        int count_end = 0;
        int count_prefix = 0;
    
    bool constainsKey(char ch) {
        return (children[ch-'a'] != NULL);
    }

    TrieNode *get(char ch) {
        return children[ch-'a'];
    }

    void put(char ch, TrieNode *child) {
        children[ch-'a'] = child;
    }

};

class Trie{
    TrieNode *root;
    public:

    Trie(){
        root = new TrieNode;
    }

    void insert(string &word){
        TrieNode *temp = root;
        for (int i=0;i<word.size();i++) {
            if (!(temp->constainsKey(word[i]))) {
                temp->put(word[i], new TrieNode());
            }
            temp = temp->get(word[i]);
            temp->count_prefix++;
        }
        temp->count_end++;
    }

    int countWordsEqualTo(string &word){
        TrieNode *temp = root;
        for (int i=0;i<word.size();i++) {
            if (!(temp->constainsKey(word[i]))) return 0;
            temp = temp->get(word[i]);
        }
        return temp->count_end;
    }

    int countWordsStartingWith(string &word){
        TrieNode *temp = root;
        for (int i=0;i<word.size();i++) {
            if (!(temp->constainsKey(word[i]))) return 0;
            temp = temp->get(word[i]);
        }
        return temp->count_prefix;
    }

    void erase(string &word){
        TrieNode *temp = root;
        for (int i=0;i<word.size();i++) {
            if (temp->constainsKey(word[i])) {
                temp = temp->get(word[i]);
                temp->count_prefix--;
            }
            else return;
        }
        temp->count_end--;
    }
};
