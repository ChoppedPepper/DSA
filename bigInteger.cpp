#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

string addBigInteger(string str1, string str2){
    // 用两个数组分别储存这两个数
    int size = max(str1.size(), str2.size());
    vector<int> vec1(size, 0), vec2(size, 0);
    for(int i = 0; i < str1.size(); ++i){
        vec1[i] = str1[str1.size() - 1 - i] - 48; // char to int
    }
    for(int i = 0; i < str2.size(); ++i){
        vec2[i] = str2[str2.size() - 1 - i] - 48; // char to int
    }
    
    // 将这两个数按位相加
    vector<int> vecSum;// 记录两个数之和
    int temp = 0; // 记录进位
    for(int i = 0; i < size; ++i){
        int sumTemp = vec1[i] + vec2[i] + temp;
        if(sumTemp < 10){
            vecSum.push_back(sumTemp);
            temp = 0;
        }else{
            vecSum.push_back(sumTemp - 10);
            temp = 1;
        }    
    }
    if(temp == 1) vecSum.push_back(1);

    // 将得到的数转化为string
    string strSum;
    for(auto iter = vecSum.end(); iter != vecSum.begin(); --iter){
        strSum += to_string(*(iter - 1));
    }
    return strSum;
}


int main(){
    string str1, str2, strSum;
    cin >> str1 >> str2;
    strSum = addBigInteger(str1, str2);
    cout << strSum << endl;
    return 0;
}

