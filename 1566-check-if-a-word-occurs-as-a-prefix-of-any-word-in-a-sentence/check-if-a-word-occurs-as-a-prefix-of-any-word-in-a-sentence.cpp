class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
         std::istringstream ss(sentence);
    std::string word;
    int index = 1;

    while (ss >> word) {
        if (word.rfind(searchWord, 0) == 0) { // Check prefix
            return index;
        }
        index++;
    }
    return -1;
    }
};