class MedianFinder {
public:


    priority_queue<int>max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;


    MedianFinder() {}
    
    void addNum(int num) {
        
        if(max_heap.empty() || max_heap.top() >= num ) max_heap.push(num);
        else min_heap.push(num);

        if(min_heap.size() > max_heap.size() ){
            int x = min_heap.top();
            min_heap.pop();
            max_heap.push(x);
        }
        else if(max_heap.size() >  min_heap.size()+1){
            int x = max_heap.top();
            max_heap.pop();
            min_heap.push(x);
        }

    }
    
    double findMedian() {
       
       if(max_heap.size()>min_heap.size())return max_heap.top();

       return (double)(max_heap.top() + min_heap.top())/2.0;

    }


};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

