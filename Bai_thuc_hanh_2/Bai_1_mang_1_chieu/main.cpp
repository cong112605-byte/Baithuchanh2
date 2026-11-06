#include <iostream>
using namespace std;
    int main(){
        int n;
        float *p;
        cin>>n;
        p=new float[n];
        for(int i =0;i<n;i++){
            cin >>*(p+i);
        }
        for(int i=0;i<n ;i++){
            cout << *(p+i)<< " ";
        }
        delete[] p;
        return 0;
    }