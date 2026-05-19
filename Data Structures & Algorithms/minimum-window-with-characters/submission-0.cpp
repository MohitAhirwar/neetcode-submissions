class Solution {
private:
    int k = -1;
    int ik = - 1;

    bool ok(int mid, string &s, string &t){
        vector<int> sf(128,0);
        vector<int> tf(128,0);

        for(auto &ch : t) tf[ch]++;
        
        for(int i=0;i<mid;i++){
            sf[s[i]]++;
        }
        int c = 0;
        for(int i=0;i<128;i++){
            if(tf[i] <= sf[i]) c++;
        }
        bool ok = false;
        if(c == 128){
            ok = true;
            ik = 0;
            k = mid;
        }

        for(int i=mid;i<s.size();i++){
            sf[s[i-mid]]--;
            sf[s[i]]++;
            int c = 0;
            for(int j=0;j<128;j++){
                if(tf[j] <= sf[j]) c++;
            }
            if(c == 128){
                ok = true;
                ik = i - mid + 1;
                k = mid;
            }
        }
        return ok;
    }
public:
    string minWindow(string s, string t) {
        int lo = t.size();
        int hi = s.size();

        if(lo > hi) return "";

        while(lo <= hi){
            int mid = (lo + hi) / 2;

            if(ok(mid,s,t)){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }


        return k == -1 ? "" : s.substr(ik, k);
    }
};
