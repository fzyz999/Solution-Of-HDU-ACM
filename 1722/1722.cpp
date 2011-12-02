/*
  设有一块方形蛋糕，被切为lcm(p,q)块。先将其切为p块，再分为q块，然后将重复部分去除，即使最小值。
  例：p=2,q=3
  若来p个人： 2,4,6
  若来q个人： 3,6
  总共为5块，出现一块重复，所以最少切为5-1块。

  p=6,q=9
  若来p个人： 3 6 9 12 15 18
  若来q个人： 2 4 6 8 10 12 14 16 18
  总共为15块，出现3块重复，所以最少切为15-3块。

 解：重复块数=lcm(p,q)/lcm(p/gcd(p,q),q/gcd(p,q))
 lcm(p,q)=p*q/gcd(p,q)
 所以，
原式=p*q/gcd(p,q)/lcm(p/gcd(p,q),q/gcd(p,q))
   =p*q/gcd(p,q)/((p/gcd(p,q))*(q/gcd(p,q))/gcd(p,q))
   =p*q/gcd(p,q)/(p*q)   [若m=gcd(a,b),则gcd(a/m,b/m)=1]
   =gcd(p,q)

 所以，ans=p+q-gcd(p,q)
 */

#include <iostream>

using namespace std;

int gcd(int a,int b)
{
  while(b>0)
  {
       a%=b;
       a^=b;
       b^=a;
       a^=b;
  }

  return a;
}

int main()
{
  int p,q;

  while(cin>>p>>q)
    cout<<p+q-gcd(p,q)<<endl;

  return 0;
}
