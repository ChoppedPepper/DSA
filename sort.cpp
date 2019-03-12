#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int i, int m, int j){
    vector<int> temp(v.begin()+i, v.begin()+m+1); // 前半段（即要用于归并的第一部分）复制到一个临时数组中以免被覆盖
    int a = 0;
    //直到temp中的数全排入v中结束
    while(a < temp.size()){
        if(m+1 > j  || temp[a] <= v[m+1]){
            v[i] = temp[a];
            ++a;
            ++i;
        }else{
            v[i] = v[m+1];
            ++m;
            ++i;
        }
    }
    return;
}

void mergeSort(vector<int> &v, int i, int j){
    if(i >= j){
        return;
    }
    int m = (j + i) / 2;
    mergeSort(v, i, m);
    mergeSort(v, m+1, j);
    merge(v, i, m ,j);
}

int setPivot(vector<int> &v, int i, int j){
    // 用数组第一个数初始化轴点值
    int Pivot = v[i];
    while(i < j){
        while((i < j) && (v[j] >= Pivot)){  // while(v[j] >= Pivot){
            --j;
        }
        v[i] = v[j];

        while((i < j) && (v[i] <= Pivot)){
            ++i;
        }
        v[j] = v[i];
    }
    // 将轴点值设置在轴点位置， 并返回轴点位置
    v[i] = Pivot;
    return i;
}

void quickSort(vector<int> &v, int i, int j){
    if(i >= j){
        return;
    }
    int m = 0;
    m = setPivot(v, i , j);
    quickSort(v, i, m);
    quickSort(v, m+1, j);
}

int main(){
    vector<int> vec;
    int num;
    while(cin >> num){
        vec.push_back(num);
    }

    // quickSort(vec, 0, vec.size()-1);
    mergeSort(vec, 0, vec.size()-1);

    for(auto a : vec){
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}