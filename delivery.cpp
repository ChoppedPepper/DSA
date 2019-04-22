#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> getMinCost(int _num, vector<vector<vector<int>>> _inf3, vector<int> _maxLeftTimeVec){       
    vector<int> minCostVec(_num, 0);

    for(int i = 0; i < _num; ++i){        
        vector<vector<int>> vec2 = _inf3[i];
        int accumCost = 0;
        vector<int> vecCost(_maxLeftTimeVec[i]+1, 0);  // note that vecCost[0] is not used
        int posLeft = INT_MAX, posRight = INT_MIN;        
        // for different person
        for(int j = 0; j < vec2.size(); ++j){  
            accumCost += vec2[j][2];
            posLeft = min(posLeft, vec2[j][0]);
            posRight = max(posRight, vec2[j][1]);
            // for the cost in differnt time
            for(int k = posLeft; k <= posRight; ++k){
                if(vecCost[k] == 0){
                    vecCost[k] = accumCost;
                }else if(vec2[j][0] <= k && k <= vec2[j][1]){
                    vecCost[k] = max(vecCost[k], vec2[j][2]);
                }else{                    
                    vecCost[k] += vec2[j][2];;
                }                
            }            
        }
        cout << "posLeft " <<  posLeft << " posRight " <<  posRight << " maxLeftTime " 
             << _maxLeftTimeVec[i] << endl;
        
        int minCost = INT_MAX;
        for(int j = posLeft; j <= posRight; ++j){ 
            minCost = min(minCost, vecCost[j]);
            cout << vecCost[j] << endl;
        }
        minCostVec[i] = minCost;
        cout << "min cost " << minCost << endl;
    }

    return minCostVec;
}

int main(){
    // get the input
    int num = 0;
    cin >> num;
    vector<int> maxLeftTimeVec;
    vector<vector<vector<int>>> inf3;
    for(int i = 0; i < num; ++i){
        int numPerson = 0;
        cin >> numPerson;
        vector<vector<int>> inf2;
        int maxLeftTime = 0;
        for(int j = 0; j < numPerson; ++j){
            vector<int> inf1;
            for(int k = 0; k < 3; ++k){
                int temp;
                cin >> temp;
                if(k == 1){
                    maxLeftTime = max(maxLeftTime, temp);
                }
                inf1.push_back(temp);
            }
            inf2.push_back(inf1);
        }
        maxLeftTimeVec.push_back(maxLeftTime);
        inf3.push_back(inf2);
    }
    
    // get the min Cost
    vector<int> minCostVec = getMinCost(num, inf3, maxLeftTimeVec);
    for(int minCost : minCostVec){
        cout << minCost << endl;
    }
    return 0;
}