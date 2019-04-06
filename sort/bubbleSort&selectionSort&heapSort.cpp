#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/****************************** bubblesort ******************************/
// O(n^2), stable
void bubbleSort(vector<int>& vec, int beg, int end){
    while(beg < end){
        for(int i = 0; i < end; ++i){
            if(vec[i] > vec[i+1]){  // > 而不是 >=, 保证稳定性
                swap(vec[i], vec[i+1]);
            }
        }
        --end;
    }
}

void bubbleSort2(vector<int>& vec, int beg, int end){
    bool isSorted = false;
    while(!isSorted){
        isSorted = true;
        for(int i = 0; i < end; ++i){
            if(vec[i] > vec[i+1]){ 
                swap(vec[i], vec[i+1]);
                isSorted = false;
            }
        }
        --end;
    }
}


/****************************** selectionSort ******************************/
// O(n^2), stable
int findMax(vector<int> &v, int beg, int end){
    int posMax = beg;
    for(int i = beg + 1; i <= end; ++i){
        if(v[posMax] <= v[i]){  // <= 而不是 <， 保证稳定性
            posMax = i;
        }
    }
    return posMax;
}

void selectionSort(vector<int> &v, int beg, int end){
    while(beg < end){
        int posMax = findMax(v, beg, end);
        swap(v[posMax], v[end]);
        --end;     
    }
}


/****************************** heapSort ******************************/
// O(nlog(n)), unstable
void heapSort(vector<int> &v, int beg, int end){
    priority_queue<int> que(v.begin()+beg, v.begin()+end+1);  // 默认降序（大顶堆）
    while(beg <= end){
        int valMax = que.top();
        que.pop();
        v[end] = valMax;
        --end;     
    }
}

void goDown(vector<int> &v, int beg, int end){  // 从 beg 处开始下滤
    int dad = beg;
    int son = beg * 2 + 1;  // left son = dad * 2 + 1, right son = dad * 2 + 1
    while(son <= end){ 
        // 找出大孩子 
        if(son + 1 <= end && v[son] < v[son+1]){ 
            ++son;
        }
        // 孩子大于父亲则交换，父亲大于等于孩子则结束
        if(v[son] > v[dad]){  
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
    int valMax = v[beg];
    v[beg] = v[end];
    goDown(v, beg , end-1);
    return valMax;
}

void heapSort2(vector<int> &v, int beg, int end){
    heapify(v, beg, end);
    while(beg < end){
        int valMax = popMax(v, beg, end);
        v[end] = valMax;
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


/****************************** main ******************************/
int main(){
    vector<int> vec;
    int num;
    while(cin >> num){
        vec.push_back(num);
    }
    
    // bubbleSort(vec, 0, vec.size()-1);
    // bubbleSort2(vec, 0, vec.size()-1);
    // selectionSort(vec, 0, vec.size()-1);
    heapSort(vec, 0, vec.size()-1);
    // heapSort2(vec, 0, vec.size()-1);
    // heapSort3(vec, 0, vec.size()-1);

    for(auto a : vec){
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}