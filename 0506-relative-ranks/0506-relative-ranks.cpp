class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        std::unordered_map<int,int> mp;
        std::vector<string> meds(score.size());
        int n = score.size();
        
        for(int i = 0; i < score.size(); i++){
            mp[score[i]]=i;
        }
        sort(score.begin(),score.end(),greater<int>());
        for(int i = 0; i < n; i++){
            if(i == 0){
                meds[mp[score[i]]]= "Gold Medal";
            }else if(i == 1){
                meds[mp[score[i]]]= "Silver Medal";
            }else if(i == 2){
                meds[mp[score[i]]]= "Bronze Medal";
            }else{
                meds[mp[score[i]]] = std::to_string(i + 1);
            }
        }
        return meds;
    }
};