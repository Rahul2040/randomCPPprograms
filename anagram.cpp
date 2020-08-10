#include<iostream>

#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    string s1="12345";
    string s2="421536";
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1.compare(s2)){
        cout<<"they are not equal";
    }
    else{
        cout<<"equal";
    }
    return 0;
    
}