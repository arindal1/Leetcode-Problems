class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> line;
        int lineLength = 0;

        for (const std::string& word : words) {
            if (lineLength + line.size() + word.length() <= maxWidth) {
                line.push_back(word);
                lineLength += word.length();
            } else {
                result.push_back(line);
                line.clear();
                line.push_back(word);
                lineLength = word.length();
            }
        }

        result.push_back(line);

        std::vector<std::string> justifiedLines;
        for (int i = 0; i < result.size() - 1; i++) {
            line = result[i];
            int numWords = line.size();
            int numSpaces = maxWidth;
            for (const std::string& word : line) {
                numSpaces -= word.length();
            }

            int spaceGaps = std::max(numWords - 1, 1);
            int spacesPerGap = numSpaces / spaceGaps;
            int extraSpaces = numSpaces % spaceGaps;

            std::string justifiedLine = "";
            for (const std::string& word : line) {
                justifiedLine += word;

                if (spaceGaps > 0) {
                    int spacesToAdd = spacesPerGap + (extraSpaces > 0 ? 1 : 0);
                    justifiedLine += std::string(spacesToAdd, ' ');
                    extraSpaces -= 1;
                    spaceGaps -= 1;
                }
            }

            justifiedLines.push_back(justifiedLine);
        }

        std::string lastLine = "";
        for (const std::string& word : result[result.size() - 1]) {
            lastLine += word + " ";
        }
        lastLine.pop_back();
        lastLine += std::string(maxWidth - lastLine.length(), ' ');
        justifiedLines.push_back(lastLine);

        return justifiedLines;      
    }
};
