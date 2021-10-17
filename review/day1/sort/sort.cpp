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
void mergeSort(vector<int> &array);
void mSort(vector<int> &arr,vector<int> &temp,int left, int rightEnd);
void merge(vector<int> &array, vector<int> &temp, int left, int right, int mid);
void quickSort(vector<int>&array);
int media3(vector<int> &array,int left,int right);
void quick_Sort(vector<int>&array,int left, int right);
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
    quickSort(array);
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
    heapSort is a kind of uunstable Sort
    O(N*logN)
    实际平均时间复杂度可能不如ShellSort of Sedgewick sequence
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
void mergeSort(vector<int> &array){
    int len = array.size();
    vector<int>temp(len);
    mSort(array,temp,0,len-1);
}
/*
    mergeSort is a kind of stable sort
    适用于外排序而不是内排序 数据量较大时,消耗内存较大 并且复制元素消耗过多
    平均最坏最好复杂度都为N*logN
*/
void mSort(vector<int> &arr,vector<int> &temp,int left, int rightEnd){
    int center;
    if(left<rightEnd){
        center = (left+rightEnd)/2;
        mSort(arr,temp,left,center);
        mSort(arr,temp,center+1,rightEnd);
        merge(arr,temp,left,center+1,rightEnd);

    }
}
void merge(vector<int> &array, vector<int> &temp, int left, int right, int rightEnd){
    int leftEnd = right - 1;
    int numEle = rightEnd - left + 1;
    int point = left;
    for(;left<=leftEnd&&right<=rightEnd;){
        if(array[left]<array[right]){
            temp[point++] = array[left++];
        }else{
            temp[point++] = array[right++];
        }
    }
    while(left<=leftEnd){
        temp[point++] = array[left++];
    }
    while(right<=rightEnd){
        temp[point++] = array[right++];
    }
    for(int i = 0;i<numEle;i++,rightEnd--){
        array[rightEnd] = temp[rightEnd];
    }
}
/*
    quickSort is a kind of unstable sort
    min = O(N*logN) max = O(N^2)
    算法复杂度取决于主元的选取,如果取得不好很可能会直接变成O(N^2)
    对于较小的范围的是排序其效率可能不如插入排序等算法 可以设置一个阈值切换排序方法以加速排序效率
    
    基于比较的排序算法的时间复杂度的下界为N*logN
*/

void quickSort(vector<int>&array){
    int len = array.size();
    quick_Sort(array,0,len - 1);

}
void quick_Sort(vector<int>&array,int left, int right){
    if(left == right){
        return;
    }
    int piovt = media3(array,left,right);
    if(left+1 == right){
        return;
    }
    
    int len = array.size();
    int low = left + 1;
    int high = right - 2;
    while(1){
        while(array[low]<piovt){
            low++;
        }
        while(array[high]>piovt){
            high--;
        }
        if(low>=high){
            break;
        }else{
            Swap(array[low],array[high]);
        }
        
    }
    //output(array);
    Swap(array[low],array[right - 1]);
    quick_Sort(array,left,low - 1);
    quick_Sort(array,low+1,right);
}
int media3(vector<int> &array,int left,int right){
    int mid = (left+right)/2;
    if(array[left]>array[mid]){
        Swap(array[left],array[mid]);
    }
    if(array[left]>array[right]){
        Swap(array[left],array[right]);
    }
    if(array[mid]>array[right]){
        Swap(array[mid],array[right]);
    }
    Swap(array[mid],array[right - 1]);
    return array[right - 1];
}
void output(vector<int> &array){
    int len = array.size();
    for(int i = 0;i<len;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

}