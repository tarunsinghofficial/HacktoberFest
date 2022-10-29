#include <iostream>
using namespace std;

int main(){
    int obtainedmarks;
    cout<<"Enter the obtainedmarks: ";
    cin>>obtainedmarks;
    if (obtainedmarks >= 85){
        cout<<"Your Grade is A";
    }
    else if (obtainedmarks >= 80){
        cout<<"Your Grade is A-";
    }
    else if (obtainedmarks >= 75){
        cout<<"Your Grade is B+";
    }
    else if (obtainedmarks >= 70){
        cout<<"Your Grade is B";
    }
    else if (obtainedmarks >= 65){
        cout<<"Your Grade is B-";
    }
    else if (obtainedmarks >= 60){
        cout<<"Your Grade is C+";
    }
    else if (obtainedmarks >= 55){
        cout<<"Your Grade is C";
    }
    else if (obtainedmarks >= 50){
        cout<<"Your Grade is D";
    }
	else if (obtainedmarks < 50){
        cout<<"Your Grade is F";
    }
    else{
        cout<<"Enter a valid number";
    }
    return 0;
}