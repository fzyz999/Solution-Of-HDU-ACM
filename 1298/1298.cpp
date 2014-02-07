#include <iostream>

using namespace std;

class trie
{
     struct trie_node
     {
          int probability;
          int p_str;
          bool is_end;
          trie_node *next[10];
          trie_node()
               {
                    probability=0;
                    p_str=0;                        
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
                              next[i]=NULL;
                         }
               }
     };

     trie_node *root;
public:
     trie();
     void insert(char str[],const int &v);
     void find(char input[]);
     void clear();
};

inline trie::trie()
{
     root=new trie_node;
}

inline void trie::clear()
{
     root->clear();
}

inline void trie::insert(char *str, const int &v)
{
     char *tmp;
     trie_node *p=root;
     
     for(tmp=str;*tmp!=0;tmp++)
     {
          if(p->next[(*tmp-'a')/3+2]==NULL)
               p->next[(*tmp-'a')/3+2]=new trie_node;
          p=p->next[(*tmp-'a')/3+2];
          if(v>p->probability)
               p->p_str=(*tmp-'a')/3+2;
     }
     p->is_end=true;
     
     return ;
}

inline void trie::find(char *input)
{
     char *str=input,ans[101];
     trie_node *tmp=root;

     for(;*str!=0;str++)
     {
          if(tmp)
     }
     
     return ;
}

int main()
{
     int t,i;

     cin>>t;
     while(t--)
     {
          
     }
          
     return 0;
}






