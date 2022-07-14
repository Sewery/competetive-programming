#include <iostream>
 
using namespace std;
 
int main()
{
 long a;
 cin>>a;
	while(a!=1){
		cout<<a<<" ";
		a = a%2?a*3+1:a/2;
	}
	cout<<1;
}
