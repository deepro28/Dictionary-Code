#include <bits/stdc++.h>
using namespace std;
const int ALPHA_SIZE = 26;

struct Trie {
   struct Trie *child[ALPHA_SIZE];
   bool endofstring;
   int val;
};
struct Trie *createNode(void) {
   struct Trie *t = new Trie;
   t->endofstring = false;
   t->val = NULL;
   for (int i = 0; i < ALPHA_SIZE; i++)
      t->child[i] = NULL;
   return t;
}
void insert(struct Trie *root, string sentence,int val,vector<string> &v) {
   struct Trie *c = root;
   for (int i = 0; i < sentence.length(); i++) {
      int index = sentence[i] - 'A';
      if (!c->child[index])
         c->child[index] = createNode();
         c = c->child[index];
   }
   c->endofstring= true;
   c->val = val;
   v[val] = sentence;
}
void search(struct Trie *root, int num,vector<string> v) {
   cout << v[num];
}
int main() {
   string sentence[100000];
   string sent;
   int k = 0;
   int number;
   cin >> number;
   while(cin >> sent){
       sentence[k] = sent;
       k++;
   }
   int n = sizeof(sentence)/sizeof(sentence[0]);
   struct Trie *root = createNode();
   vector<string> v(n);
   for (int i = 0; i < n; i++){
        insert(root, sentence[i],i,v);
   }
   search(root,number,v);
}