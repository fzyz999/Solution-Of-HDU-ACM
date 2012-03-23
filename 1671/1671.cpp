#include <iostream>
#include <cstring>

using namespace std;

class trie
{
     struct trie_node
     {
	  bool is_end;
	  trie_node *next[10];
	  trie_node()
	       {
		    is_end=false;
		    for(int i=0;i<10;i++)
			 next[i]=NULL;
	       }
	  void clear()
	       {
		    for(int i=0;i<10;i++)
			 if(next[i]!=NULL)
			 {
			      next[i]->clear();
			      delete next[i];
			 }
	       }
     };

     trie_node *root;
public:
     trie(){root=new trie_node;}
     bool insert(char str[]);
     void clear();
};

bool trie::insert(char str[])
{
     trie_node *tmp=root;
     int i,l=strlen(str);

     for(i=0;i<l;i++)
	  if(tmp->next[str[i]-'0']==NULL)
	  {
	       tmp->next[str[i]-'0']=new trie_node;
	       tmp=tmp->next[str[i]-'0'];
	  }
	  else
	  {
	       tmp=tmp->next[str[i]-'0'];
	       if(i==l-1)//若此字符串结束时，所在的节点已被建立，则说明有以此字符串为前缀的字符串存在于字典中
		    return false;
	       if(tmp->is_end)
		    return false;
	  }

     tmp->is_end=true;

     return true;
}

void trie::clear()
{
     root->clear();
     root->is_end=false;
     for(int i=0;i<10;i++)
	  root->next[i]=NULL;
}


int main()
{
     int t,n;
     char str[11];
     bool ans;
     trie adt; 

     cin>>t;
     while(t--)
     {
	  adt.clear();
	  ans=true;
	  cin>>n;
	  while(n--)
	  {
	       cin>>str;
	       if(ans)
		    ans=adt.insert(str);
	  }

	  if(ans)
	       cout<<"YES"<<endl;
	  else
	       cout<<"NO"<<endl;

	  adt.clear();
     }

     return 0;
}
