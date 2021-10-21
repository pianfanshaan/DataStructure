#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct node {
	int score;
	int force;
	int number;
};
void fight(struct node &a, struct node &b){
    if(a.force>b.force){
        a.score++;
    }else{
        b.score++;
    }
}
bool compare(struct node a, struct node b) {
	if (a.score > b.score) {
		return true;
	}
	else if (a.score == b.score && a.number < b.number) {
		return true;
	}
	else {
		return false;
	}
};
void swap(struct node &a, struct node &b) {
	struct node temp;
	temp = a;
	a = b;
	b = temp;


}
void media3(vector<struct node> &array, int left, int right) {
	int media = (left + right) / 2;
	if (!compare(array[left], array[media])) {
		swap(array[left], array[media]);
	}
	if (!compare(array[left], array[right])) {
		swap(array[left], array[right]);
	}
	if (!compare(array[media], array[right])) {
		swap(array[media], array[right]);
	}
	swap(array[media], array[right - 1]);
	//return array[right - 1];
}
void qSort(vector<struct node> &array, int left, int right) {
	if (left == right) {
		return;
	}
	else if (left + 1 == right) {
		if (!compare(array[left], array[right])) {
			swap(array[left], array[right]);
		}
		return;
	}
	media3(array, left, right);
	struct node pivot = array[right - 1];

	int len = array.size();
	int low = left + 1;
	int high = right - 2;
	while (1) {
		for (; compare(array[low], pivot);) {
			low++;
		}
		for (; !compare(array[high], pivot);) {
			high--;
		}
		if (low < high) {
			swap(array[high], array[low]);
		}
		else if (low >= high) {
			break;
		}
	}
	swap(array[low], array[right - 1]);
	qSort(array, left, low - 1);
	qSort(array, low + 1, right);


}
void quickSort(vector<struct node> &array) {
	int len = array.size();
	qSort(array, 1, len - 1);
}
int main(void) {
	int num, times, q;
	cin >> num >> times >> q;
	vector<struct node> array(num * 2 + 1);
    int len = array.size();
	for (int i = 1; i <= num * 2; i++) {
		cin >> array[i].score;
		array[i].number = i;
	}
	for (int i = 1; i <= num * 2; i++) {
		cin >> array[i].force;
	}
	for (int i = 0; i < times; i++) {
		quickSort(array);
        for(int i = 1;i<len;i+=2){
            fight(array[i],array[i+1]);
        }
	}
	cout << array[q].number;
	return 0;
}
