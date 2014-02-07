#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d",&t);
	
	char str[101];
	for(int i=1;i<=t;i++)
	{
		scanf("%s",str);
		
		printf("Case #%d: ",i);
		int l=strlen(str);
		if(strcmp(&str[l-4],"desu")==0)
		{
			str[l-4]=0;
		}
		
		printf("%snanodesu\n",str);
	}

	return 0;
}