#include<iostream>
using namespace std;

class TrieNode {

    public : 
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            this -> data = ch;
            for(int i=0 ; i<26 ; i++ ) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    
    public : 
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root , string word) {

            if(word.length() == 0) {
                root -> isTerminal = true;
                return;
            }

            //assuming all in lower
            int index = word[0] - 'a';
            TrieNode* child; //you can name it temp also but child is relatable

            if(root -> children[index] != NULL) {
                child = root -> children[index] ; // child is pointing to current root Node's child
            }
            else {
                child = new TrieNode(word[0]); // create new node and store it's address into child pointer
                root -> children[index] = child; // now root is pointing to that node
            }

            insertUtil(child,word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root,word);
        }

        bool searchUtil(TrieNode* root,string word) {

            if(word.length() == 0) {
                return root -> isTerminal; //return the isTerminal value of that node
            }

            int index = word[0] - 'a';
            TrieNode* child;

            if(root ->children[index] != NULL) {
                //present
                child = root -> children[index];
            } 
            else {
                //absent
                return false;
            }
            return searchUtil(child,word.substr(1));
        }

        bool searchWord(string word) {
            return searchUtil(root,word);
        }

        bool prefixUtil(TrieNode* root , string prefix) {

            if(prefix.length() == 0) {
                return true;
            }

            int index = prefix[0] - 'a';
            TrieNode* child;

            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }
            else {
                return false;
            }

            return prefixUtil(child,prefix.substr(1));
        }

        bool prefix(string prefix) {
            prefixUtil(root,prefix);
        }

        void deleteUtil(TrieNode* root,string word) {

            if(word.length() == 0) {
                root -> isTerminal = false;
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }
            else {
                return;
            }

            deleteUtil(child,word.substr(1));
        }

        void deleteWord(string word) {
            deleteUtil(root,word);
        }
};

int main() {

    Trie* t = new Trie();

    t -> insertWord("arm");
    t -> insertWord("do");
    t -> insertWord("time");

    cout << " time : Present or Not " << t -> searchWord("time") << endl; 
    cout << " ti : Present or Not " << t -> searchWord("ti") << endl;

    t -> deleteWord("time");

    cout << "After Deletion of word time" << endl;
    cout << " time : Present or Not " << t -> searchWord("time") << endl; 

    // cout << " Prefix ar : Present or Not " << t -> prefix("ar") << endl;
    // cout << " Prefix  arm : Present or Not " << t -> prefix("arm") << endl;
    // cout << " Prefix  no : Present or Not " << t -> prefix("no") << endl;

    return 0;
}