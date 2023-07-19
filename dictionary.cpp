#include<bits/stdtr1c++.h>
using namespace std;
class TrieNode{
    public :
    char data;
    TrieNode ** children;
    bool isTerminal; 
    TrieNode(char data) {
        this->data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode * root;
    public :
    int count;
    Trie() {
        root = new TrieNode ('\0');
        this->count = 0;
    }
    private :
    void insertWord(TrieNode * root, string word) {
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode * child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child, word.substr(1));
    }
    public :
    void insertWord(string word) {
        insertWord(root, word);
        count++;
    }

    private :

     bool search(TrieNode * root, string word) {
        if(word.size() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if(root->children[index] == NULL){
            return false;
        }
        return search(root->children[index], word.substr(1));

    }

    public :
    
    bool search(string word) {
        return search(root, word);
    }
    private :
    void removeWord(TrieNode* root, string word) {
        if(word.size() == 0) {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode * child = root->children[index];
        if(child == NULL) {
            return;
        }
        removeWord(child, word.substr(1));
        if(child -> isTerminal == false) {
            for(int i = 0; i < 26; i++) {
                if(child->children[i] != NULL) {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    public :
    void removeWord(string word) {
        removeWord(root, word);
        
    }
     // patternMatching 
    private :
     bool searchkkk(TrieNode * root, string word) {
        if(word.size() == 0) {
            return true;
        }
        int index = word[0] - 'a';
        if(root->children[index] == NULL){
            return false;
        }
        return searchkkk(root->children[index], word.substr(1));

    }
    
    bool searchkkk(string word) {
        return searchkkk(root, word);
    }
    public :
    bool patternMatching(vector<string> vect, string pattern) {
        int n = vect.size();
        for(int  i = 0; i < n; i++) {
            int k = vect[i].length();
            for(int j = 0; j < k; j++) {
                insertWord(vect[i].substr(j));
            }
        }
        return searchkkk(pattern);
    }
};

// Adding test comment
int main() {
    Trie t;
    vector<string> vect;
    vect.push_back("abcd");
    cout << " count = " << t.count << endl;
    cout << t.patternMatching(vect, "ad") << endl;
    t.removeWord("bcd");
    cout << "count = " << t.count << endl;
    cout << "search = " << t.search("bcd") << endl;
    cout << t.patternMatching(vect, "bcd") << endl;
    cout << " count = " << t.count << endl;

}