#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    double sum_actual=0,sum_attended=0;
    while(n--){
        int actual,attend;
        cout<<"actual: ";
        cin>>actual ;
        cout<<"attended: ";
        cin>>attend;
        cout<<"\n";
        sum_attended+=attend;
        sum_actual+=actual;
    }
    cout<<"Total Period: "<<sum_actual<<" Attended: "<<sum_attended<<endl;
    cout<<"attendance percentage: ";
    double perc=(sum_attended/sum_actual)*100;
    printf("%.7lf",perc);
    return 0;
}