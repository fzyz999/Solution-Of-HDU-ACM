#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

struct Task
{
    int time;
    int level;
    Task(){}
    Task(int _time,int _level):
	time(_time),
	level(_level){}
};

bool operator < (const Task& a, const Task& b)
{
    if(a.time!=b.time)
    {
        return a.time > b.time;
    }
    else
    {
        return a.level>b.level;
    }
}
Task task[100001],machine[100001];

int main()
{
    int n,m;

    while(scanf("%d%d", &n,&m)!=EOF)
    {
        int i;
        for (i = 0; i < n; i++)
	{
	    scanf("%d%d", &machine[i].time,&machine[i].level);
        }

        for(i = 0; i< m; i++)
        {
            scanf("%d%d", &task[i].time, &task[i].level);
        }
        sort(task, task+m);
        sort(machine, machine+n);

        long long int ans=0;
        int count=0,j=0;
	map<int,int> _map;
        for(i = 0; i < m; i++)
        {
            while(j<n && machine[j].time>=task[i].time)
	    {
		_map[machine[j].level]++;
		j++;
	    }
	    map<int,int>::iterator it=_map.lower_bound(task[i].level);
	    if(it!=_map.end())
            {
                count++;
                ans+=500*task[i].time+2*task[i].level;
		_map[it->first]--;
		if(_map[it->first]==0){
		    _map.erase(it);
		}
            }
        }

	printf("%d %I64d\n", count, ans);
    }
    
    return 0;
}
