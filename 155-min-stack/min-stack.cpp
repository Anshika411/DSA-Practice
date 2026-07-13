class MinStack {
public:
    stack<long long> s;
    long long minVal;
    MinStack() {
    }
    void push(int value) {
        if (s.empty()) {
            s.push(value);
            minVal = value;
        } else {
            if (value < minVal) {
                s.push(2LL * value - minVal);
                minVal = value;
            } else {
                s.push(value);
            }
        }
    }
    void pop() {
        if (s.empty()) return;
        if (s.top() < minVal) {
            minVal = 2LL * minVal - s.top();
        }
        s.pop();
    }
    int top() {
        if (s.top() < minVal)
            return minVal;

        return s.top();
    }
    int getMin() {
        return minVal;
    }
};