class Solution {
private:
    vector<string> ans;
    int N;
    void generate(int open, int close, string &s){
        if(close < open) return;

        if(s.size() == 2*N){
            if(open == 0 && close == 0)
                ans.push_back(s);
            return;
        }

        s.push_back('(');
        generate(open-1,close,s);
        s.pop_back();


        s.push_back(')');
        generate(open,close-1,s);
        s.pop_back();

    }
public:
    vector<string> generateParenthesis(int n) {
        string state = "";
        N = n;
        generate(n,n,state);
        return ans;
    }
};
