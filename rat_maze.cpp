#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int isSafe(vector<vector<int>> &a,int x,int y){
    if(a[x][y]==0) return 0;
    else return 1;
}

void printMatrix(vector<vector<int>> &a){
    int i,j;
    for(i=0;i<a.size();i++){
        for(j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\n\n";
}
int findPath(vector<vector<int>> &a,int x,int y,vector<vector<int>> &b)
{
    
    if(x==a.size()-1 && y==a.size()-1) {   
       return 1;
    }
    int x1=x+1,y1=y,x2=x,y2=y+1;
   if(x1<a.size()&& y2<a.size()){
        if( a[x1][y1]==1) {
        b[x1][y1]=1;
        if(findPath(a,x1,y1,b)==0){
            b[x1][y1]=0;
        } 
    }
     if(a[x2][y2]==1 && b[x1][y1]==0){
        b[x2][y2]=1;
     
        if(findPath(a,x2,y2,b)==0){
            b[x2][y2]=0;
       
        }
    }
    if(b[x1][y1]==0 && b[x2][y2]==0){
        
        return 0;
    }
    else{
        
        return 1;
    }

   }
   else if(x1<a.size() && y2==a.size()){
        if( a[x1][y1]==1) {
        b[x1][y1]=1;


        if(findPath(a,x1,y1,b)==0){
            b[x1][y1]=0;

        }
    }
    if(b[x1][y1]==1){ return 1; }

    return 0;

    }
    else if(x1==a.size() && y2<a.size()){
        if( a[x2][y2]==1) {
        b[x2][y2]=1;

        if(findPath(a,x2,y2,b)==0){
            b[x2][y2]=0;

        }
    }
    if(b[x2][y2]==1) { return 1;}
  
    return 0;

    }
    
}
int main(){
    vector <vector<int>> a= 
                    {  { 1, 1, 1, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 1, 0, 1, 0 }, 
                       { 0, 1, 1, 1 } },


                       b={ { 1, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } };

if(findPath(a,0,0,b)==1){
printMatrix(b);
}
else cout<<"no path has been found!!!";
return 0;

}