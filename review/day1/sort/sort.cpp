#include<iostream>
#include<vector>
using namespace std;
void Swap(int &a, int &b);
void bubbleSort1(vector<int> &array);
void bubbleSort2(vector<int> &array);
void output(vector<int> &array);
int main(void){
    cout<<"please input your data!"<<endl;
    int num;
    cin>>num;
    vector<int>array(num);
    for(int i = 0;i<num;i++){
        cin>>array[i];
    }
    bubbleSort2(array);
    output(array);
    return 0;
}
void Swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}
void bubbleSort1(vector<int> &array){
    int len = array.size();
    int times = 0;
    for(int i = 0;i<len;i++){
        for(int j = 0;j<len-1;j++){
            if(array[j]>array[j+1]){
                Swap(array[j],array[j+1]);
            }
            times++;
        }

    }
    cout<<times<<endl;

}
void bubbleSort2(vector<int> &array){
    int len = array.size();
    int times = 0;
    for(int i = 0;i<len - 1;i++){
        for(int j = i + 1;j<len;j++){
            if(array[i]>array[j]){
                Swap(array[i],array[j]);
            }
            times++;
        }

    }
    cout<<times<<endl;
}
void output(vector<int> &array){
    int len = array.size();
    for(int i = 0;i<len;i++){
        cout<<array[i]<<" ";
    }

}