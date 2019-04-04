#include <vector>
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

void refillNum(vector<int>& num, const vector<int>& temp, int& valMin){
    // O(valMax - valMin + 1)
    // i+valMin 位于区间 [temp[i-1], temp[i]) 中
    for(int i = 0; i < temp[1]; ++i){
        num[i] = valMin;
    }
    for(int i = 1; i < temp.size(); ++i){
        for(int j = temp[i-1]; j < temp[i]; ++j){
            num[j] = i + valMin;
        }       
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
struct Node{
    int val;
    Node* next;
    Node() = default;
    Node(int a) : val(a), next(nullptr) { }
};

void countNum2(const vector<int>& num, vector<Node*>& temp, int& valMin){
    // count, O(n)
    for(int a : num){
        Node* nodePtr = temp[a-valMin];  // hash(num[i]) = num[i] - valMin (rank of temp)        
        if(nodePtr){
            while(nodePtr->next){
                nodePtr = nodePtr->next;
            }        
            Node* nodeTemp = new Node(a);
            nodePtr->next = nodeTemp;            
        }else{
            temp[a-valMin] = new Node(a);
        }        
    }    
    return;
}

void refillNum2(vector<int>& num, const vector<Node*>& temp){
    // O(valMax - valMin + 1)
    // 遍历链表，依次取出节点值
    int j = 0;
    for(int i = 0; i < temp.size(); ++i){
        Node* nodePtr = temp[i];
        while(nodePtr){
            num[j] = nodePtr->val;
            ++j;
            nodePtr = nodePtr->next;
        }        
    }
    return;
}

void bucketSort(vector<int> &num){
    int valMin = 0, valMax = 0;
    findMinMax(num, valMin, valMax);

    // 构造一个桶数组, 其中hash(key) = key - valMin，桶单元vector[hash(key)]中存放key
    //                                             (为应对可能存在相同的key，实际存放一个链表)
    vector<Node*> temp(valMax - valMin + 1, 0);
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

    // countingSort(vec);
    bucketSort(vec);

    for(auto a : vec){
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}