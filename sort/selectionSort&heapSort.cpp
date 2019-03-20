#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*************** selectionSort ***************/
int findMax(vector<int> &v, int beg, int end){
    int pos = beg;
    for(int i = beg + 1; i <= end; ++i){
        if(v[pos] < v[i]){
            pos = i;
        }
    }
    return pos;
}

void selectionSort(vector<int> &v, int beg, int end){
    while(beg < end){
        int posMax = findMax(v, beg, end);
        swap(v[posMax], v[end]);
        --end;     
    }
}

/*************** heapSort ***************/
void heapSort(vector<int> &v, int beg, int end){
    priority_queue<int> que(v.begin()+beg, v.begin()+end+1);
    while(beg <= end){
        int max = que.top();
        que.pop();
        v[end] = max;
        --end;     
    }
}

void goDown(vector<int> &v, int beg, int end){
    int dad = beg;
    int son = beg * 2 + 1;
    while(son <= end){ 
        // 找出大孩子 
        if(son + 1 <= end && v[son] < v[son+1]){ 
            ++son;
        }
        // 孩子大于父亲则交换，父亲大于等于孩子则结束
        if(v[dad] < v[son]){
            swap(v[dad], v[son]);
            dad = son;
            son = son * 2 + 1;
        }else{
            return;
        }
    }
    return;
}
void heapify(vector<int> &v, int beg, int end){
    int posFirstInNode = (end - beg - 1) >> 1; // 自下往上第一个内部节点（非叶节点）
    for(int i = posFirstInNode; i >= beg; --i){
        goDown(v, i, end);
    }
}
int popMax(vector<int> &v, int beg, int end){
    int max = v[beg];
    v[beg] = v[end];
    goDown(v, beg , end-1);
    return max;
}

void heapSort2(vector<int> &v, int beg, int end){
    heapify(v, beg, end);
    while(beg < end){
        int max = popMax(v, beg, end);
        v[end] = max;
        --end;
    }
}

void heapSort3(vector<int> &v, int beg, int end){
    heapify(v, beg, end);
    while(beg < end){        
        swap(v[beg], v[end]);
        --end;
        goDown(v, beg, end);
    }
}

/*************** main ***************/
int main(){
    vector<int> vec;
    int num;
    while(cin >> num){
        vec.push_back(num);
    }
    
    // selectionSort(vec, 0, vec.size()-1);
    // heapSort(vec, 0, vec.size()-1);
    // heapSort2(vec, 0, vec.size()-1);
    heapSort3(vec, 0, vec.size()-1);

    for(auto a : vec){
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}