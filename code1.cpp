#include<bits/stdc++.h>
#include<fstream>
using namespace std;
using ll=long long ;
using ch=char32_t;
typedef deque<ll>de;
typedef stack<ll>st;
typedef set<ll> se;
typedef vector<ll>vi;
typedef map<ll,ll> ml;
typedef vector<char> vc;
typedef queue<ll> Q;
typedef vector<pair<ll,ll>> vp;
typedef vector<tuple<ll,ll,ll>> vt;
typedef pair<ll,ll> pi;  
typedef map<char,ll> mc; 
 struct trie{
	struct trie *child[26];
	bool isend;
	trie(){
		memset(child,0,sizeof(child));
		isend=false;}
};
struct trie2{
	bool isend;
	unordered_map<char,trie2*> mp;
	trie2()	{
		isend=false;
	}
};
struct trie *root;
struct trie2* root1;
void insert2(string str)
{
	struct trie2* cur=root1;
	for(char ch:str)
	{
		if(!cur->mp.count(ch))
			cur->mp[ch]=new trie2;
		cur=cur->mp[ch];}
	cur->isend=true;
}
bool search2(string str)
{
	struct trie2* cur=root1;
	for(char ch:str)
	{
		if(!cur->mp.count(ch))
			return false;
		cur=cur->mp[ch];
	}
	return cur->isend;
}
void insert(string str)
{
	struct trie *cur=root;
	for(char ch:str)	{
		int idx=ch-'a';
		if(cur->child[idx]==NULL){
			cur->child[idx]=new trie;	}
		cur=cur->child[idx];
	}
	cur->isend=true;
}
bool search(string str)
{
	struct trie *cur=root;
	for(char ch:str)
	{
		int idx=ch-'a';
		if(cur->child[idx]==NULL)	return false;
        	cur=cur->child[idx];
	}
	return cur->isend;
}
int main()
{
    ifstream  ip("testcase.csv");
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
	root=new trie;
	root1=new trie2;
    ll n;
    cin>>n;
    string s,s2;
    while (n--)
    {
        cin>>s;
        insert2(s);
    }
    cin>>s2;
    if(search(s2))
        cout<<"YES"<<endl;
        else cout<<"N0"<<endl;
 return 0;
}