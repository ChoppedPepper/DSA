#include <iostream>
#include <queue>

using namespace std;

    int LastRemaining_Solution(int n, int m){
        if(n <= 0) return -1;
        if(n == 1) return 0;
        
        // 用两个队列来连成一个圈
        queue<int> que1, que2;
        for(int i = 0; i < n; ++i){
            que1.push(i);
        }
        // 模拟游戏过程
        int mTemp = 0; 
        int queFlag = 0; // 0 for que1, 1 for que2
        while(que1.size() + que2.size() > 1){          
            if(!queFlag){
                //为空时转向下一个队列
                if(que1.empty()){
                    queFlag = 1;
                    continue;
                }
                int nTemp = que1.front();
                que1.pop();
                // 到编号为 m-1 的小朋友，开始下一圈， 且不再将他放在下一队列
                if(mTemp == m - 1){
                    mTemp = 0;
                    continue;
                }
                ++mTemp;
                que2.push(nTemp);

            }else{
                if(que2.empty()){
                    queFlag = 0;
                    continue;
                }
                int nTemp = que2.front();
                que2.pop();
                if(mTemp == m - 1){
                    mTemp = 0;
                    continue;
                }
                ++mTemp;
                que1.push(nTemp);
            }
        }
        if(que1.empty()){
            return que2.front();
        }else{
            return que1.front();
        }
    }
    
    struct ListNode{
        int val;
        ListNode* next;
        ListNode() = default;
        ListNode(int x) : val(x), next(nullptr) {}    
    };
    
    int LastRemaining_Solution2(int n, int m){
        if(n <= 0) return -1;
        if(n == 1) return 0;
        
        // 闭环链表
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        for(int i = 1; i <= n-1; ++i){
            temp->next =  new ListNode(i);
            temp = temp->next;
        }
        temp->next = head;
        // 模拟游戏过程
        ListNode* pre = nullptr;
        temp = head;
        int mtemp = 0;
        while(temp != temp->next){
            if(mtemp == m - 1){
                pre->next = temp->next;
                pre = pre;
                temp = temp->next;
                mtemp = 0;
                continue;
            }
            pre = temp;
            temp = temp->next;
            ++mtemp;
        }
        return temp->val;
    }

    int main(){
        int a, b;
        cin >> a;
        cin >> b;
        int result = LastRemaining_Solution2(a, b);
        cout << result << endl;
    }