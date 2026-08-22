class MyQueue {
public:
stack<int>s;
    MyQueue() {}
    
    void push(int x) {
        if(s.empty()) s.push(x);
        else{
            stack<int>s1;

            while(!s.empty()){
                s1.push(s.top());
                s.pop();
            }
            s.push(x);
            while(!s1.empty()){
                s.push(s1.top());
                s1.pop();
            }
        }
    }
    
    int pop() {
        if(s.empty()) return -1;
        int x = s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        if(s.empty()) return -1;
        int x = s.top();
        return x;
    }
    
    bool empty() {
        if(s.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */