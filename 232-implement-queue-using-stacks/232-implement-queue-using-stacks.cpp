class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {
        
    }

    void transfer() {
        while(!input.empty()) {
            int temp = input.top();
            output.push(temp);
            input.pop();
        }
    }
    
    void push(int x) {
        input.push(x); // O(1)
    }
    
    int pop() {
        if(output.empty()) transfer(); // O(N)
        int top = output.top();
        output.pop(); // O(1)
        return top;
    }
    
    int peek() {
        if(output.empty()) transfer(); // O(N)
        return output.top(); // O(1)
    }
    
    bool empty() {
        return input.empty() && output.empty(); // O(1)
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