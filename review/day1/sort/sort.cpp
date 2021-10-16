#include<iostream>
#include<vector>
using namespace std;
class heap{
    private:
        vector<int> *array;
        int size;
        int capacity;
    public:
        void setSize(int SIZE){
            size = SIZE;
        }
        int getSize(){
            return size;
        }
        void setcapacity(int CAPACITY){
            capacity = CAPACITY;
        }
        int getCapacity(){
            return capacity;
        }
        void setHeap(vector<int> * ARRAY){
            array = ARRAY;
        }
        vector<int> * getHeap(){
            return array;
        }
};
class heapFunction{
    public:
        void perDown(vector<int> &array, int root){
            int parent,child;
            int size = array.size() - 1;
            int temp = array[root];
            for(parent = root;parent*2 <= size;parent = child){
                child = parent*2;
                if(child!=size&&array[child]<array[child+1]){
                    child++;
                }
                if(temp>=array[child]){
                    break;
                }else{
                    array[parent] = array[child];
                }
            }
            array[parent] = temp;
        }
        void perDown(vector<int> &array,int root, int end){
            //int size = array.size();
            int parent,child;
            int temp = array[root];
            for(parent = root;parent*2 + 1<end;parent = child){
                child = parent*2 + 1;
                if(child<end - 1&&array[child]<array[child+1]){
                    child++;
                }
                if(temp>=array[child]){
                    break;
                }else{
                    array[parent] = array[child];
                }
            }
            array[parent] = temp;
        }
        void buildHeap(vector<int> &array, int size){
            for(int i = size/2;i>0;i--){
                perDown(array,i);
            }
        }
        void buildHeap(vector<int>&array){
            int size = array.size() - 1;
            for(int i = (size - 1)/2;i>=0;i--){
                perDown(array,i,size -1);
            }
        }
};
void Swap(int &a, int &b);
void bubbleSort(vector<int> &array);
void InsertionSort(vector<int> &array);
void shellSort(vector<int> &array);
void selectionSort(vector<int> &array);
void heapSort(vector<int> &array);
void output(vector<int> &array);

int main(void){
    cout<<"please input your data!"<<endl;
    int num;
    cin>>num;
    vector<int>array(num);
    for(int i = 0;i<num;i++){
        cin>>array[i];
    }
    //heapFunction H = heapFunction();
    //H.buildHeap(array,num - 1);
    heapSort(array);
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
/*
    SelectionSort is a kind of stable sort
    每次找到扫描序列最小/最大值
    从而直接一次性找到合适的最小最大值
    无所谓最好最坏情况, 它的时间复杂度都为O(N^2)
*/
void selectionSort(vector<int> &array){
    int len = array.size();
    int times = 0;
    int minEle;
    int index;
    for(int i = 0;i < len - 1;i++){
        minEle = array[i];
        index = i;
        for(int j = i;j < len;j++){
            if(array[j] < minEle){
                index = j;
                minEle = array[j];
                times++;
            }
        }
        Swap(array[i],array[index]);
    }
    cout<<times<<endl;
}
/*
    heapSort 
    O(N*logN)
*/
void heapSort(vector<int> &array){
    int len = array.size();
    int times = 0;
    int temp;
    heapFunction H = heapFunction();
    H.buildHeap(array);
    output(array);
    for(int i = len - 1;i>0;i--){
        Swap(array[i],array[0]);
        H.perDown(array,0,i);
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