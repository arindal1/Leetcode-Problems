class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int totalLength = s.size();
        int numWords = words.size();
        int wordLength = words[0].size();
        
        if (totalLength < (wordLength * numWords)) {
            return {};
        }
        
        vector<int> resultIndices;
        unordered_map<string, int> wordFrequencyMap;
        for (string word : words) {
            wordFrequencyMap[word]++;
        }

        for (int startPos = 0; startPos <= totalLength - (numWords * wordLength); startPos++) {
            unordered_map<string, int> currentWordFrequencyMap;
            int wordCount = 0;

            for (int j = startPos; j < startPos + (numWords * wordLength); j += wordLength) {
                string currentWord = s.substr(j, wordLength);
                currentWordFrequencyMap[currentWord]++;
                if (currentWordFrequencyMap[currentWord] <= wordFrequencyMap[currentWord]) {
                    wordCount++;
                } else {
                    break;
                }
            }
            if (wordCount == numWords) {
                resultIndices.push_back(startPos);
            }
        }
        return resultIndices;
    }
};
