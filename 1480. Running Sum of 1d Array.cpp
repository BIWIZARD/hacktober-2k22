class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>duplicates;
        unordered_map<int, int> map;
        for(auto it : nums){
            map[it]++;
        }
        for(auto it : map){
             if(it.second==2){
                duplicates.push_back(it.first);
             }
        }

        return duplicates;
    }
};