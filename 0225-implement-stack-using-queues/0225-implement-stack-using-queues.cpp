class MyStack {
public:
queue<int>q;
queue<int>q2;
    MyStack() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty()) return -1;

        while(q.size()>1){
            q2.push(q.front());
            q.pop();
        }

        int x = q.front();
        q.pop();

        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }
        return x;

    }
    
    int top() {
        if(q.empty()) return -1;

        while(q.size()>1){
            q2.push(q.front());
            q.pop();
        }
        int x = q.front();
        q2.push(x);   // important fix
        q.pop();

        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }
        return x;
    }
    
    bool empty() {
        if(q.empty())return true;
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