class MyStack {
public: 
queue<int>q;
    MyStack() {}
    
    void push(int x) {
        if(q.empty()) q.push(x);
        else{
            queue<int>q1;
            while(!q.empty()){
                q1.push(q.front());
                q.pop();
            }
            q.push(x);
            while(!q1.empty()){
                q.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
         if(q.empty()) return -1;
        int x = q.front();
        return x;
    }
    
    bool empty() {
        if(q.empty())  return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */