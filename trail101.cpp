#include <bits/stdc++.h>
#include<math.h>
#include<iostream>

using namespace std;


int main(){
    vector <long double> ans,q;
    unsigned long long int l,s1,s2,temp,nq;
    scanf("%llu %llu %llu",&l,&s1,&s2);
    temp=s2;
    if(s1>s2) {
        s2=s1;
        s1=temp;
    }
    scanf("%llu",&nq);
    while(nq--){
        long double q1;
        scanf("%Lf",&q1);
        q.push_back(q1);
    }
    long long i=0;
    for(i=0;i<q.size();i++){
        long double ans1= pow(2,0.5)*((l-pow(q[i],0.5))/(s2-s1));
        //long double ans1= sqrt(2);
        cout<<pow(2,0.5);
        ans.push_back(ans1);
    }
    for(i=0;i<ans.size();i++){
        printf("%.12Lf\n",ans[i]);
    }


}
