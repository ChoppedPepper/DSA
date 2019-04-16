#include <iostream>
#include <vector>

using namespace std;

int getMaxValue(int num, const vector<int>& vecW, const vector<int>& vecV, int vol){
    if(num <= 0){        
        return 0;
    }

    if(vol >= vecW[num-1]){
        return max(getMaxValue(num-1, vecW, vecV, vol), 
                   getMaxValue(num-1, vecW, vecV, vol-vecW[num-1])+vecV[num-1]);
    }else{
        return getMaxValue(num-1, vecW, vecV, vol);
    }
}

int getMaxValue2(int num, const vector<int>& vecW, const vector<int>& vecV, int vol){
    vector<vector<int>> ValDP(num+1, vector<int>(vol+1, 0));
    for(int i = 1; i <= num; ++i){
        for(int j = 1; j <= vol; ++j){
            if(j >= vecW[i-1]){
                ValDP[i][j] = max(ValDP[i-1][j], ValDP[i-1][j-vecW[i-1]]+vecV[i-1]);
            }else{
                ValDP[i][j] = ValDP[i-1][j];
            }
            cout << ValDP[i][j] << " ";
        }
        cout << endl;
    }
    return ValDP[num][vol];
}

int getMaxValue3(int num, const vector<int>& vecW, const vector<int>& vecV, int vol){
    vector<int> ValDP(vol+1, 0);
    for(int i = 1; i <= num; ++i){
        for(int j = vol; j >= 1; --j){  // 注意此处的顺序 
            if(j >= vecW[i-1]){
                ValDP[j] = max(ValDP[j], ValDP[j-vecW[i-1]]+vecV[i-1]);
            }else{
                ValDP[j] = ValDP[j];
            }
            cout << ValDP[j] << " ";
        }
        cout << endl;
    }
    return ValDP[vol];
}

int getMaxValue4(int num, const vector<int>& vecW, const vector<int>& vecV, int vol){
    vector<int> ValDP(vol+1, 0);
    for(int i = 1; i <= num; ++i){
        for(int j = vol; j >= vecW[i-1]; --j){  // 注意此处的顺序 
            ValDP[j] = max(ValDP[j], ValDP[j-vecW[i-1]]+vecV[i-1]);
            cout << ValDP[j] << " ";
        }
        cout << endl;
    }
    return ValDP[vol];
}

int main(){
    int N = 6, vol = 50;
    vector<int> vecWei = {12,6,9,23,34,7};
    vector<int> vecVal = {6,8,4,5,12,4};
    int maxValue = getMaxValue(N, vecWei, vecVal, vol);
    int maxValue2 = getMaxValue2(N, vecWei, vecVal, vol);
    int maxValue3 = getMaxValue3(N, vecWei, vecVal, vol);
    int maxValue4 = getMaxValue4(N, vecWei, vecVal, vol);
    cout << "the maxValue is: " << maxValue << " " << maxValue2 << " " << maxValue3 << " " << maxValue4 << endl;
    return 0;
}