#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int hash[n+1]={0};
	int i;
	int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	    hash[a[i]]++;
	}
	for(i=0;i<=n;i++)
	{
	    if(hash[i]==0)
	    {
	        cout<<i<<" ";
	    }
	}
	return 0;
}
