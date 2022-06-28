vector<int> findSubstring(string s, vector<string>& words) {
        int word_count = words.size();
        int word_length = words[0].size();
        int totalChars = word_count * word_length;
        int n = s.size();
        
        if (totalChars > n)
            return {};
        
        unordered_map<string, int> temp;
        for(auto w:words)
            temp[w] ++;
        int left =0, right = 0;
        vector<int> result;
        
        while (left < n - totalChars + 1){
            int count = word_count;
            unordered_map<string, int> temp_word(temp);
            right = left;
            while (right < left + totalChars)
            {
                string w = s.substr(right, word_length);
                if(temp.find(w) == temp.end() || temp_word[w] == 0)
                    break;
                else{
                    temp_word[w] --;
                    count --;
                }
                right += word_length;
            }
            if (count == 0)
                result.push_back(left);
            left ++;
        }
        return result;
        
    }