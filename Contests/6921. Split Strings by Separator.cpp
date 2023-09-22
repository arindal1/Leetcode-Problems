class Solution {
public:
std::vector<std::string> splitWordsBySeparator(std::vector<std::string>& words, char separator) {
    std::vector<std::string> result;
    for (const std::string& word : words) {
        std::stringstream ss(word);
        std::string temp;
        while (std::getline(ss, temp, separator)) {
            if (!temp.empty()) {
                result.push_back(temp);
            }
        }
    }
    return result; 
}
};
