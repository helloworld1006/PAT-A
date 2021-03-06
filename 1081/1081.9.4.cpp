#include<cstdio>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b){
	if (b==0)
	{
		return a;
	}else{
		return gcd(b,a%b);
	}
}
struct node
{
	long long up,down;
};
void init(node &f){
	if (f.down<0)
	{
		f.down=-f.down;
		f.up=-f.up;
	}
	if (f.up==0)
	{
		f.down=1;
	}else{
		long long d=gcd(abs(f.up),abs(f.down));
		f.up/=d;
		f.down/=d;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	node f1,f2;
	scanf("%lld/%lld",&f1.up,&f1.down);
	init(f1); node result;
	for (int i = 1; i < n; ++i)
	{
		scanf("%lld/%lld",&f2.up,&f2.down);
		init(f2);
		result.up=f1.up*f2.down+f1.down*f2.up;
		result.down=f1.down*f2.down;
		init(result);
		f1=result;
	}
	if (result.down==1)
	{
		printf("%lld\n",result.up);
	}else if (abs(result.up)>result.down)
	{
		printf("%lld %lld/%lld\n",result.up/result.down,abs(result.up)%result.down,result.down);
	}else{
		printf("%lld/%lld\n", result.up,result.down);
	}
	return 0;
}