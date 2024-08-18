class Solution{
  public:
    int max(int &a, int &b){
        if(a>b) {
            return a;
        }
        else{
            return b;
        }
    }    

    int findLongestConseqSubseq(int arr[], int N)
    {
        map<int,int>m;
        for(int i=0;i<N;i++){
            m[arr[i]]++;
        }
        
        pair<int,int>p;
        
        set<int>s;
        int longestSubs=1;
        
        for(const auto& p: m) {
            int currentKey = p.first; 
            if(m.find(currentKey + 1) == m.end()) {
                continue;
            } 
            else {
                s.insert(currentKey);
                while(m.find(currentKey + 1) != m.end()) {
                    s.insert(currentKey+1);
                    currentKey += 1;
                }
            }
            int setSize = s.size();
            longestSubs = max(longestSubs, setSize);
            s.clear();
        }
        return longestSubs;
    }
};
