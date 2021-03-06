#include <iostream>
#include <vector>

using namespace std;

/****************************** mergesort ******************************/
// O(nlog(n)), stable
void merge(vector<int> &v, int i, int m, int j){
    // 将v中前半段（即要用于归并的第一部分）复制到一个临时数组中以免被覆盖
    vector<int> temp(v.begin()+i, v.begin()+m+1); 
    int a = 0;
    // 直到temp中的数全排入v中结束
    while(a < temp.size()){
        if(m+1 > j  || temp[a] <= v[m+1]){ // <= 而不是 <, 保证稳定性
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

// void merge2(vector<int> &v, int i, int m, int j){
//     vector<int> temp1(v.begin()+i, v.begin()+m+1); 
//     vector<int> temp2(v.begin()+m+1, v.begin()+j+1); 
//     int a = 0;
//     int b = 0;
//     while(a < temp1.size() || b < temp2.size() ){
//         if(a < temp1.size() && (b >= temp2.size() || temp1[a] <= temp2[b]) ){  
//             v[i] = temp1[a];
//             ++a;
//             ++i;
//         }
//         if(b < temp2.size() && (a >= temp1.size() || temp1[a] > temp2[b]) ){
//             v[i] = temp1[b];
//             ++b;
//             ++i;
//         }
//     }
//     return;
// }

void mergeSort(vector<int> &v, int i, int j){
    if(i >= j){
        return;
    }
    int m = (j + i) / 2;
    mergeSort(v, i, m);
    mergeSort(v, m+1, j);
    // 二路归并
    merge(v, i, m ,j);
}


/****************************** quicksort ******************************/
// O(nlog(n)), unstable
int setPivot(vector<int> &v, int i, int j){
    // 用数组第一个数初始化轴点值
    int Pivot = v[i];
    // 从数组两端开始搜索轴点应当处于的位置
    while(i < j){
        while((i < j) && (v[j] >= Pivot)){ 
            --j;
        }
        v[i] = v[j];

        while((i < j) && (v[i] <= Pivot)){
            ++i;
        }
        v[j] = v[i];
    }
    // 注意将轴点值设置在轴点位置， 并返回轴点位置
    v[i] = Pivot;
    return i;
}

void quickSort(vector<int> &v, int i, int j){
    if(i >= j){
        return;
    }
    int m = 0;
    // 构造一个轴点，并返回轴点位置
    m = setPivot(v, i, j);
    quickSort(v, i, m-1);
    quickSort(v, m+1, j);
}


/****************************** main ******************************/
int main(){
    vector<int> vec;
    int num;
    while(cin >> num){
        vec.push_back(num);
    }
    
    // mergeSort(vec, 0, vec.size()-1);
    quickSort(vec, 0, vec.size()-1);

    for(auto a : vec){
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}