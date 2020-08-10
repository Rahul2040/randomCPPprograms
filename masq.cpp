#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
void printVector(vector <int> &a){
    for(int j=0;j<a.size();j++){
            cout<<a[j]<<" ";
        }
    cout<<endl;
}
void printMatrix(vector <vector <int>> &a){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
vector<int> findEmpty(vector <vector <int>> &a,int row,int col){
    vector <int> v1;
    int flag=0,n=a.size();
    while(flag==0){
        if(col<n-1) col++;
        else if(col==n-1 && row<n-1)  { row++; col=0;}
        else return v1;
        if(a[row][col]==0) flag=1;
    }
    v1.push_back(row);
    v1.push_back(col);
    return v1;
}
int findMax(int a,int b,int c,int d){
    vector <int> v1;
    v1.push_back(a);
    v1.push_back(b);
    v1.push_back(c);
    v1.push_back(d);
    auto i=max_element(v1.begin(),v1.end());
    int max=*i;
    return max;
}
vector<int> possibleVal(vector <vector <int>> &a,int row,int col){
    vector <int> v1,v2;
    int n=a.size(),flag1=0,flag2=0;
    int n1=(n*(pow(n,2)+1))/2;
    vector <int> r,c,s;
    int row_sum=0,col_sum=0,d1_sum=0,d2_sum=0;
    if(row==col) flag1=1;

    for(int i=0;i<a.size();i++){
        if(a[i][col]!=0){ col_sum+=a[i][col]; cout<<a[i][col]<<endl;}
        if(a[row][i]!=0) row_sum+=a[row][i];
        if(flag1==1) d1_sum+=a[i][i];
        if((a.size()-1-i)==row && col==i) flag2=1;
        
    }
    if(flag2==1)
    {
         for(int i=0;i<a.size();i++){
             if(a[n-1-i][i]!=0) d2_sum+=a[n-1-i][i];
         }
    }
    for(int i=1;i<pow(n,2)+1;i++){
        int flag=0;
        for(int j=0;j<a.size();j++){  
            if(find(a[j].begin(),a[j].end(),i)!=a[j].end()){  flag=1; break;}   
        }  
        if(flag==0) v1.push_back(i);
    }
    
    int max=findMax(row_sum,col_sum,d1_sum,d2_sum);
    n1=n1-max;
    if(row==(n-1)&& col==(n-1)){
        if(row_sum!=col_sum||col_sum!=d1_sum) {v1.push_back(0); return v1;};
    }
    if(row==(n-1)|| col==(n-1)){
        for(int i=0;i<v1.size();i++){
        if(v1[i]==n1) v2.push_back(v1[i]);
        
    }
    return v2;
    }
    for(int i=0;i<v1.size();i++){
        if(v1[i]<=n1) v2.push_back(v1[i]);
        else break;
    }
    return v2;

}
int createMagic(vector <vector <int>> &a,int row,int col){
   printMatrix(a);
    vector <int> v1=possibleVal(a,row,col);
    if(v1.size()==1 &&v1[0]==0 ){ a[row][col]=0; return 0;}
    printVector(v1);
    if(v1.size()==0) return 0;
    for(int i=0;i<v1.size();i++){
        a[row][col]=v1[i];
        vector <int> v2=findEmpty(a,row,col);
        
        if(v2.size()==0) {  return 1;}
        if(createMagic(a,v2[0],v2[1])==0)
            a[row][col]=0;
        else return 1;

    }
    return 0;

}

int main(){
    int n;
    vector <vector <int>> m1;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        vector <int> v;
        for(int j=0;j<n;j++)
            v.push_back(0);
        m1.push_back(v);
    }
    printMatrix(m1);
    createMagic(m1,0,0);
    printMatrix(m1);




}
