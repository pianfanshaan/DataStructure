#include<iostream>
#include<vector>
using namespace std;
void Swap(int &a, int &b);
void bubbleSort(vector<int> &array);
void output(vector<int> &array);
int main(void){
    cout<<"please input your data!"<<endl;
    int num;
    cin>>num;
    vector<int>array(num);
    for(int i = 0;i<num;i++){
        cin>>array[i];
    }
    bubbleSort(array);
    output(array);
    return 0;
}
void Swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}
/*
    bubbleSort 是稳定的排序算法
    特点是每一轮会有确定一个最大元素
    min = O(n)
    max = O(n^2)
    {
        for(P = N - 1;;P--)

    }

*/
void bubbleSort(vector<int> &array){
    int len = array.size();
    int flag = 0;
    int times = 0;
    for(int i = len - 1;i >= 0;i--){
        for(int j = 0;j < i;j++){
            flag = 0;
            if(array[j]>array[j+1]){
                Swap(array[j],array[j+1]);
                times++;
                flag = 1;
            }
        }
        if(!flag){
            break;
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