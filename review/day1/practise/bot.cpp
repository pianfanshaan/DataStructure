#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int Next[100];
int num;
void getNext(string s, int length) {
    int j = -1;
    Next[0] = j;
    for (int i = 1; i < length; i++) {
        while (j != -1 && s[i] != s[j + 1]) {//不停回退，直到找到或者等于j = -1 
            j = Next[j];
        }
        if (s[i] == s[j + 1])//找到
            j++;
        Next[i] = j;
    }
}
int main(void){
    string s;
    int len;
    cin >> s;
    len = s.length();
    cout<<len<<endl;
    getNext(s,len);
    for(int i = 0;i<len;i++){
        cout<<Next[i]<<" ";
    }
    //a();
    return 0;
}