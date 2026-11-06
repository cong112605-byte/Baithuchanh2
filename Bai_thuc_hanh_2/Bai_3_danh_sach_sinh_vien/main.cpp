#include <iostream>
#include <string>
using namespace std;
struct SV
{
    string hoten;
    int ma;
    float d1,d2,d3;
};
int main(){
    int n;
    cout<<"So SV";
    cin>>n;
    cin.ignore();
    SV *p =new SV[n];
    for(int i=0 ;i<n ;i++){
        cout<<"sinh vien thu "<<i+1<<endl;
        getline(cin,p[i].hoten);
        cin>>p[i].ma;
        cin>>p[i].d1;
        cin>>p[i].d2;
        cin>>p[i].d3;
        cin.ignore();
    }
    for(int i=0 ;i<n ;i++){
        cout<<"Ho ten :"<< p[i].hoten<<endl
        cout<<"Ma sv :"<<p[i].ma<<endl;
        cout<<"Diem1 :"<<p[i].d1<<endl;
        cout<<"Diem2 :"<<p[i].d2<<endl;
        cout<<"Diem3 :"<<p[i].d3;

    }
    delete[] p;
}