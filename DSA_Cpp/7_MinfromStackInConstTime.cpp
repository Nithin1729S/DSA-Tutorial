#include <iostream>
#include <stack>

using namespace std;
class MinStack {
public:
    stack<int>stk;
    int minEle;
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(empty(stk))
        {
            minEle=val;
            stk.push(val);
            
        }
        else
        {
            if(val>=minEle) stk.push(val);
            else
            {
                
                stk.push(2*val-minEle);
                minEle=val;
            }
        }
    }
    
    void pop() {
        int t=stk.top();
        stk.pop();
        if(t<minEle)
        {
            minEle=2*minEle-t;
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */