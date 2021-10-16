#include<iostream>
#include<vector>
using namespace std;
void Swap(int &a, int &b);
void bubbleSort(vector<int> &array);
void InsertionSort(vector<int> &array);
void shellSort(vector<int> &array);
void output(vector<int> &array);
int main(void){
    cout<<"please input your data!"<<endl;
    int num;
    cin>>num;
    vector<int>array(num);
    for(int i = 0;i<num;i++){
        cin>>array[i];
    }
    shellSort(array);
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
    T(N,I) = O(N+I) N is number of inversion pair

*/
/*
    如果元素基本有序可以使用插入排序 因为时间复杂度与逆序对个数成正比
    theory 1:
        任意N个不同元素组成的序列平均具有
            N(N - 1)/4 个逆序对
    
    theory 2:
        任意仅以交换相邻两个元素的排序算法,平均时间复杂度为O(N^2)
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
/*
    shellSort is a kind of unstable sort
    执行某一间隔的shellSort之后 上一间隔的仍旧是有序的
    增量不互质可能会导致无效导致小增量不起作用
    可选择特殊的序列来加快速度
    
*/
void shellSort(vector<int> &array){
    int len = array.size();
    int times = 0;
    int temp;
    int k;
    for(int i = len/2;i>0;i/=2){
        cout<<"the gap is "<<i<<endl;
        for(int j = i;j<len;j++){
            temp = array[j];
            for(k = j;k>=i&&array[k - i]>temp;k-=i){
                array[k] = array[k - i] ;
                times++;
            }
            array[k] = temp;
            output(array);
        }
    }
    cout<<times<<endl;
}
void output(vector<int> &array){
    int len = array.size();
    for(int i = 0;i<len;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

}