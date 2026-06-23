class MyCircularDeque {
public:

int K , front , rear , curr_c;
vector<int>dq;

    MyCircularDeque(int k) {
        K = k;
        front = 0;
        rear = k-1;
        curr_c =0;
        dq = vector<int>(K, 0);
    }
    
    bool insertFront(int value) {
        if(curr_c == K)return false;

        curr_c++;
        front = (front-1+K)%K;
        dq[front] = value;

        return true;
    }
    
    bool insertLast(int value) {
        if(curr_c == K)return false;

        curr_c++;
        rear = (rear+1)%K;
        dq[rear] = value;

        return true;
    }
    
    bool deleteFront() {
        if(curr_c == 0)return false;

        curr_c--;
        front = (front+1)%K;

        return true;
    }
    
    bool deleteLast() {
        if(curr_c == 0)return false;

        curr_c--;
        rear = (rear-1+K)%K;

        return true;
    }
    
    int getFront() {
        if(curr_c == 0) return -1;
        return dq[front];
    }
    
    int getRear() {
        if(curr_c == 0) return -1;
        return dq[rear];
    }
    
    bool isEmpty() {
        if(curr_c == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(curr_c == K) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */