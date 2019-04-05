#include <vector>
#include <list>
#include <iostream>
#include <climits>

using namespace std;

/****************************** countingsort ******************************/
void findMinMax(const vector<int>& num,  int& valMin, int& valMax){
    valMin = INT_MAX;
    valMax = INT_MIN;
    for(int a : num){
        valMin = min(valMin, a);
        valMax = max(valMax, a);
    }
    return;
}

void countNum(const vector<int>& num, vector<int>& temp, int& valMin){
    // count, O(n)
    for(int a : num){
        ++temp[a-valMin];  // hash(num[i]) = num[i] - valMin (rank of temp)
    }
    // accumulate, O(valMax - valMin + 1)
    for(int i = 1; i < temp.size(); ++i){
        temp[i] += temp[i-1];
    }
    return;
}

void refillNum(vector<int>& num, vector<int>& temp, int& valMin){
    // O(n)
    // num[i] = i+valMin 位于区间 [temp[i-1], temp[i]) 中
    vector<int> temp2(num.size(), 0);  // 定义临时数组保存排序后的数组
    for(int i = num.size() - 1; i >= 0; --i){  // 为保证稳定性，从后向前遍历num
        temp2[temp[num[i]-valMin]-1] = num[i];
        --temp[num[i]-valMin];      
    }

    int j = 0;
    for(int a : temp2){
        num[j] = a;
        ++j;
    }

    return;
}

void countingSort(vector<int> &num){
    int valMin = 0, valMax = 0;
    findMinMax(num, valMin, valMax);
    
    // 构造一个桶数组, 其中hash(key) = key - valMin，桶单元vector[hash(key)]中存放key出现的次数
    vector<int> temp(valMax - valMin + 1, 0);
    countNum(num, temp, valMin);

    refillNum(num, temp, valMin);

    return;
}


/****************************** bucketsort ******************************/
void countNum2(const vector<int>& num, vector<list<int>>& temp, int& valMin){
    // count, O(n)
    for(int a : num){        
        temp[a-valMin].push_back(a);  // hash(num[i]) = num[i] - valMin (rank of temp)      
    }    
    return;
}

void refillNum2(vector<int>& num, const vector<list<int>>& temp){
    // O(valMax - valMin + 1)
    // 遍历所有链表，依次取出节点值
    int j = 0;
    for(int i = 0; i < temp.size(); ++i){
        list<int> lis = temp[i];
        while(!lis.empty()){
            num[j] = lis.front();
            lis.pop_front();
            ++j;            
        }        
    }
    return;
}

void bucketSort(vector<int> &num){
    int valMin = 0, valMax = 0;
    findMinMax(num, valMin, valMax);

    // 构造一个桶数组, 其中hash(key) = key - valMin，桶单元vector[hash(key)]中存放key
    //                                             (为应对可能存在相同的key，实际存放一个链表)
    vector<list<int>> temp(valMax - valMin + 1);
    countNum2(num, temp, valMin);

    refillNum2(num, temp);

    return;
}

/****************************** main ******************************/
int main(){
    vector<int> vec;
    int num;
    while(cin >> num){
        vec.push_back(num);
    }

    countingSort(vec);
    // bucketSort(vec);

    for(auto a : vec){
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}