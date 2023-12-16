class Solution {
public:    
  int evaluate(string s, unordered_map<string,int> dict = unordered_map<string,int>()) 
  {        
      if (s[0] != '(') return isalpha(s[0])? dict[s] : stoi(s);
      int i = 1; s.pop_back();
      string op = next(s, i);
      if (op == "let") {
        string var;
        do {
          var = next(s, i);
          if (i <= s.size()) dict[var] = evaluate(next(s, i), dict);
        }
        while (i <= s.size());
        
        return evaluate(var, dict);
      }                      
      else {
          int x1 = evaluate(next(s, i), dict), x2 = evaluate(next(s, i), dict);
          return op == "add"? x1+x2 : x1*x2;
      }
  }
private:  
  string next(const string& s,int& i) 
  {
      size_t ii = i;
      if (s[i++] == '(') {
        for (int dif=1; dif; ++i)
          if (s[i] == '(') dif++;
          else if (s[i] == ')') dif--;
      }
      else i = min(s.find(" ", ii), s.size()); 
      return s.substr(ii, i++ -ii);
  }
};
