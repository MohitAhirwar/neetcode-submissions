class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        left.push(num);
        int leftMax = left.top(); left.pop();
        right.push(leftMax);

        if(right.size() > left.size()){
            left.push(right.top()); right.pop();
        }
    }
    
    double findMedian() {
        int sz1 = left.size();
        int sz2 = right.size();
        int sz = sz1 + sz2;

        if(sz & 1){
            return left.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};
