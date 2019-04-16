#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class compare {
public:
    bool operator()(pair<int, int> pair1, pair<int, int> pair2){
        return pair1.second != pair2.second ? pair1.second > pair2.second
               : pair1.first > pair2.first;
    }
};

class compare2 {
public:
    bool operator()(pair<int, int> pair1, pair<int, int> pair2){
        return pair1.first != pair2.first ? pair1.first < pair2.first
               : pair1.second > pair2.second;
    }
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        // 前面大数少的数在堆顶，一样多则小的数在堆顶。第一个数一定是原队列最前的数 
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;
        for(auto a : people){
            que.push(a);
        }
        
        vector<pair<int, int>> vec;
        while(!que.empty()){
            pair<int, int> peo = que.top();
            que.pop();                            
            int count = 0;
            if(vec.empty()){
                vec.push_back(peo);
            }else{
                // 从前开始比较，在合适的地方插入
                for(auto iter = vec.begin(); iter < vec.end(); ++iter){
                    if(iter->first >= peo.first){
                        ++count;
                    }
                    if(count > peo.second){
                        vec.insert(iter, peo);
                        break;
                    } 
                    if(iter == vec.end() - 1){
                        vec.push_back(peo);
                        break;
                    }// end if
                } // end for
            } // end else                               
        } // end while
        return vec;
    }

    vector<pair<int, int>> reconstructQueue2(vector<pair<int, int>>& people) {
        // 大的数在堆顶，一样大则前面大数少的数在堆顶。
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare2> que;
        for(auto a : people){
            que.push(a);
        }
        
        vector<pair<int, int>> vec;
        while(!que.empty()){
            pair<int, int> peo = que.top();
            que.pop();
            vec.insert(vec.begin() + peo.second, peo);   
        } 
        return vec;
    }
};

int main(){
    vector<pair<int, int>> vecRaw = {{7,0},{4,4}, {7,1},{5,0},{6,1},{5,2}};
    vector<pair<int, int>> vecSlo;
    vector<pair<int, int>> vecSlo2;
    Solution sol;
    vecSlo = sol.reconstructQueue(vecRaw);
    for(auto a : vecSlo){
        cout << a.first << "*" << a.second << " ";
    }
    cout << endl;
    vecSlo2 = sol.reconstructQueue2(vecRaw);
    for(auto a : vecSlo2){
        cout << a.first << "*" << a.second << " ";
    }
    cout << endl;

    return 0;
}