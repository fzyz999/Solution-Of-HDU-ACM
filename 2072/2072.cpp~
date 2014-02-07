#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class dic_tree
{
     struct dic_tree_node
     {
	  bool is_end;
	  dic_tree_node *next[26];
	  dic_tree_node()
	       {
		    is_end=false;
		    for(int i=0;i<26;i++)
			 next[i]=NULL;
	       }
	  void clear()
	       {
		    for(int i=0;i<26;i++)
			 if(next[i]!=NULL)
			 {
			      next[i]->clear();
			      delete next[i];
			 }
	       }
     };

     dic_tree_node *root;
public:
     dic_tree(){root=new dic_tree_node;}
     bool insert(char str[]);
     void clear();
};

bool dic_tree::insert(char str[])
{
     dic_tree_node *tmp=root;
     int i,l=strlen(str);
     
     if(l==0)
        return false;

     for(i=0;i<l;i++)
     {
	     if(tmp->next[str[i]-'a']==NULL)
	     {
	          tmp->next[str[i]-'a']=new dic_tree_node;
	     }
	     tmp=tmp->next[str[i]-'a'];
	 }

     if(tmp->is_end==true)
	     return false;
     tmp->is_end=true;

     return true;
}

void dic_tree::clear()
{
     root->clear();
     root->is_end=false;
     for(int i=0;i<26;i++)
	  root->next[i]=NULL;
}

int main()
{
     dic_tree dic;
     char line[1000],*word,*p;
     int s;

     for(;;)
     {
	      s=0;
	      dic.clear();
          gets(line);
          word=line;
          p=line;
	      if(strcmp(line,"#")==0)
	          break;
	      while(p!=NULL)
	      {
	           while(*p!=' ' && *p!=0) p++;
	           if(*p==0)
	               p=NULL;
	           else
	           {	          
	               while(*p!=0 && *p==' ')
	               {
	                   *p=0;
	                   p++;
	               }
	           }
	           s+=(int)dic.insert(word);
	           word=p;
	      }
	      printf("%d\n",s);
     }

     return 0;
}
