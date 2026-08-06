class MinStack {
public:
stack<long long>st;
long long min ;
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int value) {
        long long x = (long long) value;
        if(st.empty()){
            st.push(x);
            min = x;
        }
        else if(x>=min)st.push(x);
        else {
            st.push(2*x - min);
            min = value;
        }
    }
    
    void pop() {
        if(st.top() < min){
            min = 2*min - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < min){
            return min;
        }
        else return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */