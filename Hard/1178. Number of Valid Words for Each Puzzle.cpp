class Solution {
public:
    int maskWord(string word) {  
        int mask = 0;
        for(auto ch : word) mask |= 1 << (ch-'a');
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        for(auto word : words) freq[(maskWord(word))]++;
		
        vector<int> ans;
        for (auto puzzle : puzzles) {
            int mask = maskWord(puzzle), submask = mask, first = (1 << puzzle[0]-'a'), count = 0;
            
            while(submask) {
                if(submask&first) count+=freq[submask];
                
                submask = mask&(submask-1);
            }
            ans.push_back(count);
        }
        return ans;
    }
};
