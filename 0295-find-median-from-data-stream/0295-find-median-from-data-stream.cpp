class MedianFinder {
public:
    priority_queue<int>pqMax;
    priority_queue<int , vector<int> , greater<int> >pqMin;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqMax.size() == 0 ) pqMax.push(num);
        
        else if(num <= pqMax.top()) pqMax.push(num);
        else pqMin.push(num);

        if(pqMax.size() > pqMin.size() + 1){
            pqMin.push(pqMax.top());
            pqMax.pop();
        }
        else if(pqMin.size() > pqMax.size() + 1){
            pqMax.push(pqMin.top());
            pqMin.pop();
        }
    }
    
    double findMedian() {
        
        if(pqMax.size() == pqMin.size()){
            return (pqMax.top()+pqMin.top())/2.0;
        }
        else if(pqMax.size() > pqMin.size()){
            return pqMax.top();
        }
        else{
            return pqMin.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */