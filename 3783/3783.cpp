#include <iostream>
#include <cstring>

using namespace std;

int main()
{
     int i,z,o,j;
     char str[101];

     while(cin>>str && str[0]!='E')
     {
          z=o=j=0;
          i=strlen(str);
          
          while(i--)
               switch(str[i])
               {
               case 'Z':
                    z++;
                    break;
               case 'O':
                    o++;
                    break;
               default:
                    j++;
               }

          while(z!=0||o!=0||j!=0)
          {
               if(z>0)
               {
                    cout<<'Z';
                    z--;
               }
               if(o>0)
               {
                    cout<<'O';
                    o--;
               }
               if(j>0)
               {
                    cout<<'J';
                    j--;
               }
          }
          cout<<endl;
               
     }
     
     return 0;
}
