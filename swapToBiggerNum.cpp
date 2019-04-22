#include <iostream>
#include <vector>

using namespace std;

void swapArr(const vector<int>& kVec, vector<vector<int>>& arrVec){
    if(kVec.empty()) return;

    for(int i = 0; i < kVec.size(); ++i){
        int k = kVec[i];
        vector<int>& arr = arrVec[i];
        
        int count = 0;
        int countHelper = 0;
        int posForSwap = 0;
        for(int j = 0; j < arr.size(); ++j){
            // find pos to swap  
            int valTemp = arr[j];
            countHelper = count;
            for(int m = j+1; m < arr.size(); ++m){
                ++countHelper;
                // cout << "j " << j << " arr[m] " << arr[m] <<  " valTemp "  << valTemp << endl;
                if(arr[m] > valTemp){
                    count = countHelper;
                    posForSwap = m;
                    valTemp = arr[m];

                    if(count == k){                        
                        break;
                    }
                }
            }
               
            // swap
            if(posForSwap != 0){
                int temp = arr[posForSwap];
                for(int n = posForSwap-1; n >= j; --n){;
                    arr[n+1] = arr[n];
                }
                arr[j] = temp;
                if(count == k){
                    // cout << "breakout" << endl;
                    break;
                }
            }        
        }
    }
    return;
}

int main(){
    // get input
    int numExample = 0;    
    cin >> numExample;
    vector<int> kVec;
    vector<vector<int>> arrVec;
    for(int i = 0; i < numExample; ++i){
        int k = 0;
        cin >>  k;
        kVec.push_back(k);
        int sizeTemp = 0;
        cin >> sizeTemp;
        vector<int> arrTemp;
        for(int j = 0; j < sizeTemp; ++j){
            int numTemp = 0;
            cin >> numTemp;
            arrTemp.push_back(numTemp);
        }
        arrVec.push_back(arrTemp);
    }

    // get solved
    swapArr(kVec, arrVec);

    // output
    for(auto& a : arrVec){
        for(auto b : a){
            cout << b << " ";
        }
        cout << endl;        
    }

    return 0;
}