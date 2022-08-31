class MinStack {
public:
    stack<int>inc;
    stack<int>st;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        stack<int>temp;
        while(!inc.empty() && inc.top()<val){
            temp.push(inc.top());inc.pop();
        }
        inc.push(val);
        //pour back the temp to inc
        while(!temp.empty()){
            inc.push(temp.top());
            temp.pop();
        }
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        stack<int>temp;
        while(!inc.empty() && inc.top()<val){
            temp.push(inc.top());inc.pop();
        }
        inc.pop();
        //pour back the temp to inc
        while(!temp.empty()){
            inc.push(temp.top());
            temp.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return inc.top();
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