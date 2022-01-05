//https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/

class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& a) {
        //code here
        unordered_map<string,vector<string>>m;
        int n=a.size();
        for(int i=0;i<n;i++){
            string s=a[i];
            sort(s.begin(),s.end());
            m[s].push_back(a[i]);
        }
        vector<vector<string>>ans(m.size());
        int idx=0;
        for(auto i:m){
            auto j=i.second;
            for(int i=0;i<j.size();i++) ans[idx].push_back(j[i]);
            idx++;
        }
        return ans;
    }
};