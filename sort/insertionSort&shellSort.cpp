#include <iostream>
#include <vector>
#include <list>

using namespace std;

/****************************** insertsort ******************************/
// O(n^2), stable
// actually O(n+I), I is the number of inverted sequence, input-sensitive 
void insertionSort(vector<int> &v, int beg, int end){
    int i = beg;
    while(i < end){
        int temp = i + 1;
        int j = i;
        while(j >= beg && v[temp] < v[j]){  // < 而不是 <= 保证稳定性
            swap(v[temp], v[j]);
            --temp;
            --j;
        }         
        ++i;
    }
}

void insertionSort2(vector<int> &v, int beg, int end){
    int i = beg;
    while(i < end){
        int val = v[i+1];
        int j = i;
        while(j >= beg && val < v[j]){
            v[j+1] = v[j];
            --j;
        } 
        v[j+1] = val;
        ++i;
    }
}

/****************************** shellsort ******************************/
// time complexity depends on the incremental sequence, unstable
int findIncre(const vector<int>& seq, int length){
    int s = 0;
    for(int i = 0; i < seq.size(); ++i){
        if(seq[i] < length){
            s = i;
        }
    }
    return s;
}

void insertionSortOrder(vector<int> &v, int beg, int end, int incre){
    for(int i = incre; i < (end - beg + 1); ++i){
        int val = v[i];
        int j = i - incre;
        while(j >= 0 && val < v[j]){
            v[j+incre] = v[j];
            j -= incre;
        }
        v[j+incre] = val;
    }
}

void shellSort(vector<int> &v, int beg, int end){
    // vector of increment
    vector<int> H{1,2,3,4,6,8,9,12,16};  // pratt sequence for n(log(n))^2, assume that end-beg+1 < 16
    int s = findIncre(H, end-beg+1);
    for(int i = s; i >= 0; --i){
        int incre = H[i];
        // cout << "incre " << incre << endl;
        insertionSortOrder(v, beg, end, incre);
    }
}


/****************************** main ******************************/
int main(){
    vector<int> vec;
    int num;
    while(cin >> num){
        vec.push_back(num);
    }
    
    // insertionSort(vec, 0, vec.size()-1);
    // insertionSort2(vec, 0, vec.size()-1);
    shellSort(vec, 0, vec.size()-1);

    for(auto a : vec){
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}