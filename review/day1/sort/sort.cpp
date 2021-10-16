#include<iostream>
#include<vector>
using namespace std;
void Swap(int &a, int &b);
void bubbleSort(vector<int> &array);
void InsertionSort(vector<int> &array);
void output(vector<int> &array);
int main(void){
    cout<<"please input your data!"<<endl;
    int num;
    cin>>num;
    vector<int>array(num);
    for(int i = 0;i<num;i++){
        cin>>array[i];
    }
    InsertionSort(array);
    output(array);
    return 0;
}
void Swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}
/*
    bubbleSort is a kind of stable sort
    特点是每一轮会有确定一个最大元素
    min = O(n)
    max = O(n^2)
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
/*
    insertionSort is a kind of stable sort
    Swap times of InsertionSort is equal to BubbleSort

*/
void InsertionSort(vector<int> &array){
    int len = array.size();
    int times = 0;
    int temp;
    int j;
    for(int i = 1;i < len;i++){
        temp = array[i];
        for(j = i;j > 0 && array[j - 1]>temp;j--){
            array[j] = array[j - 1];
            times++;
        }
        array[j] = temp;
    }
    cout<<times<<endl;
}
void output(vector<int> &array){
    int len = array.size();
    for(int i = 0;i<len;i++){
        cout<<array[i]<<" ";
    }

}