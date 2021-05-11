#define SC_INCLUDE_FX
#include<iostream>
#include<vector>
#include<systemc>


typedef sc_dt::sc_int<50> num;
typedef std::vector<num> arr;
typedef sc_dt::sc_ufix_fast fixx;

using namespace std;

num  fib(int n)
{
	arr a;
	a.push_back(0);
	a.push_back(1);

	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	
	int i;
	for(i = 2; i <= n; i++)
	{
		a.push_back(a[i-1]+a[i-2]);
	}
	return a[i-1];

}

int bits(int n)
{
	int bit = 1;
	
	while(1)
	{
		fixx fix_point(bit,bit);

		fix_point = n;
		if(!fix_point.overflow_flag())
		break;

		bit++;
	}

	return bit;
}
int sc_main(int argc, char* argv[])
{
	int n;

	cout<<"Unesite koji clan fibonacijevog niza zelite:"<<endl;
	cin >> n;
	cout<<"Odgovor:"<< fib(n)<<endl;
	cout<<bits(n)<<endl;
	return 0;
}
