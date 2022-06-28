vector<int> findAnagrams(string s, string p) {
        
        if(p.size() > s.size())
            return {};
        int k = p.size();
        unordered_map<char, int> temp;
        for(auto c : p)
        {
            if(temp.find(c) != temp.end())
            {
                temp[c] ++;
            }
            else
                temp[c] = 1;
        }
        
        int totalCharacters = temp.size();
        
        for(int r =0; r < k; r++)
        {
            char c = s[r];
            if(temp.find(c) != temp.end())
            {
                temp[c] --;
                if (temp[c] == 0)
                    totalCharacters --;
            }
        }
        
        vector<int> result;
        if(totalCharacters == 0)
            result.push_back(0);
        int r = k;
        int l = 0;
        while(r < s.size()){
            char c = s[l];
            if(temp.find(c) != temp.end())
            {
                temp[c] ++;
                if(temp[c] == 1)
                    totalCharacters ++;
            }
            c = s[r];
            if(temp.find(c) != temp.end())
            {
               temp[c]--;
                if(temp[c] == 0)
                    totalCharacters --;
            }
            
            l++;
            if(totalCharacters == 0)
                result.push_back(l);
            r++;
        }
        return result;   
            
        
    }