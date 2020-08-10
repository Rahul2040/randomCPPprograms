#include<iostream>
#include<vector>
using namespace std;
int main(){
    int num;
    cin>>num;
    vector<int> v1;
    for(int i=0;i<num;i++){
        int num2;
        cin>>num2;
        v1.push_back(num2);
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";

    }
    return 0;
}