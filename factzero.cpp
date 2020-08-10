#include <bits/stdc++.h>
using namespace std;


void zeroes(long long int n){
    long long int total=0;
    while(n>=5){
        total+=(n/5);
        n/=5;
    }
    cout<<total<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t-->0){
	    long long int n;
	    cin>>n;
	    zeroes(n);
	}
	return 0;
}
