#include<iostream>
using namespace std;

void towerOfHanoi(int n, char beg, char aux, char end){
    if(n==0){
        return;
    }
    towerOfHanoi(n-1,beg,end,aux);
    cout<<" move disc "<<n<<" from "<<beg<<" to "<<end<<endl;
    towerOfHanoi(n-1,aux,beg,end);
}

int main(){
    int n;
    cout<<"number of discs: ";
    cin>>n;
    towerOfHanoi(n,'A','B','C');
    return 0;
}
