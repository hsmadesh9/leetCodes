class Solution {// TC : O(N×4ᴺ) & SC : O(N)
public:// N = digits.size()

    vector<string> result;// SC : O(N×4ᴺ) ---> Output Space

    vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};// SC : O(10) = O(1)

    void helper(string &digits,int index,string &current){// SC : O(N) ---> Auxiliary Space, Space due to recurtion stack

        if(index == digits.size()){// TC : O(4ᴺ)
            result.push_back(current);// TC : O(N×4ᴺ)
            return;
        }

        string chars = letters[digits[index] - '0'];//SC : O(4) = O(1) & TC : O(4) = O(1)

        for(char ch : chars){// TC : O(4) = O(1)

            current.push_back(ch);

            helper(digits,index+1,current);// TC : O(4ᴺ)

            current.pop_back();

        }
    }



    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()){
            return {};
        }

        string current = "";
        helper(digits,0,current);

        return result;
       
    }

};