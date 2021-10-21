#include<iostream>
#include<cmath>
using namespace std;
int main(void){
    double threeStar = 0.4;
    double fourStar = 0.5;
    double fiveStar = 0.08;
    double siveStar = 0.02;
    int initTimes = 24;
    double possibility = pow(0.98,50);
    double tempSixStar = 0.02;
    for(int i = 0;i<20;i++){
        tempSixStar+=0.02;
        possibility *= (1 - tempSixStar);
        if(possibility<=0.01){
            cout<<possibility<<endl;
            cout<<50+i+1<<endl;
            break;    
        }
    }
    possibility = 1;
    for(int i = 0;i<50;i++){
        possibility *= (1 - threeStar);
        //cout<<possibility<<endl;
        if(possibility<=0.01){
            cout<<possibility<<endl;
            cout<<i+1<<endl;
            break;    
        }
    }
    possibility = 1;
    for(int i = 0;i<50;i++){
        possibility *= (1 - fourStar);
        if(possibility<=0.01){
            cout<<possibility<<endl;
            cout<<i+1<<endl;
            break;    
        }
    }
    possibility = pow(0.92,51);
    //cout<<possibility<<endl;
    double tempFiveStar = 0.08;
    for(int i = 0;i<50;i++){
        possibility *= (1 - tempFiveStar);
        if(possibility<=0.01){
            cout<<possibility<<endl;
            cout<<50+i+1<<endl;
            break;    
        }
    }
    return 0;
}