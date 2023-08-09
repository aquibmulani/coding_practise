//Leetcode question : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
//   utility function to traverse over all the strings and search for combinations
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ret_str;
        string get_str;
        // string to match 
        string total_combntn[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
  
        //check for empty input string
        if(!digits.length())
        {return ret_str;}

        //call the utlitiy function to get all the letter combinations 
         return_combination(ret_str,total_combntn,get_str,digits,0,digits.length());
        return ret_str;
    }
    void return_combination(vector<string> &res,string ip[],string &ret,string &digits,int i,int digit_str_size)
    {
        //push the string in the return string vector once all the strings are traversed 
        if(i == digit_str_size)
        {
            res.push_back(ret);
            //cout<<"here";
            return;
        }
//      get each digit during every recursive call  
        int digit_iterator = (digits[i] - 48);
        
        for(int k =0; k < ip[digit_iterator].size();k++)
        {
//          fill in the string one character at a time using recursion
            ret.push_back(ip[digit_iterator][k]);
            return_combination(res,ip,ret,digits,i+1,digit_str_size);
//          back track             
            ret.pop_back();
        }
        return;  
    }
        

};