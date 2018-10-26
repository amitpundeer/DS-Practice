// Design a stack that supports getMin() in O(1) time and O(1) extra space

#include <bits/stdc++.h>

using namespace std;

class SpecialStack
{
    private:
    
     stack<int> s;
     int min;
    
    public:
    
    int getMin()
    {
        return min;
    }
    void push(int x)
    {
        if(s.empty()) {  s.push(x); min = x; }
        else if(x >= min){
            s.push(x);
        } else {
            s.push(2*x-min);
            min = x;
        }
        cout<<"push-> min: "<<min<<endl;
    }
    
    int pop()
    {
        if(s.empty())
        {
            cout<<"stack is empty"<<endl;
            min=INT_MAX;
            return INT_MAX;
        }
        
        int top = s.top();
        
        if(top < min) 
        {
            min = 2 * min - top;
        }
        
        s.pop();
        if(!s.empty())   cout<<"pop-> min: "<<min<<endl;
        
        return top;
    }
};


int main()
{
    SpecialStack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(-1);
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    
    
    return 0;
}
