class Solution {
    public String lexPalindromicPermutation(String s, String t) {
        // smallest palindrom greater than target 
        // for a palindrom we fix two character's at a time 
        // so we only need to build half the string 
        int n = s.length(); 
        int half = s.length() / 2; 
        int f[] = new int[26]; 
        for(int i= 0; i < n; i++) f[s.charAt(i)-'a']++; 

        // Now let's first match the prefix 
        int odd = -1; // pos of odd char 
        for(int i = 0; i < 26; i++) {
            if(f[i] % 2 == 1) {
                if(odd != -1) return ""; 
                odd = i; 
            }
        }
        // for each character we decrease the freq by 2 
        // then backtrack for the last character 

        int pos = 0; 
        while(pos < half && f[t.charAt(pos) - 'a'] > 1) {
            f[t.charAt(pos) - 'a'] -= 2; // why because of palindrom 
            pos++; 
        }

        if(pos == half) {
            StringBuilder ans = new StringBuilder(); 
            // prepare the string and compare if already greataer or not
            ans.append(t.substring(0, half)); 
            StringBuilder str = new StringBuilder(ans); 
            if(n % 2 == 1) ans.append((char)('a' + odd)); 
            str.reverse(); 
            ans.append(str); 

            if(String.valueOf(ans).compareTo(t) > 0) return String.valueOf(ans); 
        }

        // Now the prefix position will be either equal to N / 2 or less than it, we can backtrack from here 
        int st = half == pos ? half - 1 : pos; 
        // System.out.println(pos); 
        for(int i = st; i >= 0; i--) {
            // return the current back 
            if(i < pos) f[t.charAt(i) - 'a']+= 2; 


            // find which is greater than current 
            for(int k = 0; k < 26; k++) {
                if(f[k] > 1 && (k > (t.charAt(i) - 'a'))) {

                    // System.out.println(k + " " + i); 
                    // we can construct the string here now. 

                    StringBuilder ans = new StringBuilder(); 
                    ans.append(t.substring(0, i)); 
                    ans.append((char)('a' + k)); // add the cur 
                    f[k] -= 2; // we used it. 
                    // till half append the rest in ascending order 
                    for(int x = 0; x < 26; x++) {
                        while(f[x] > 1) {
                            ans.append((char)('a' + x)); 
                            f[x] -= 2; 
                        }
                    }
                    // mirror first half 
                    StringBuilder str = new StringBuilder(ans); 
                    str.reverse(); 
                    ans.append(str); 
                    if(n % 2 == 1) ans.insert(n / 2, (char)('a' + odd)); 
                    return String.valueOf(ans); 
                }
            }
        }

        return ""; 
    }
}


// 4 / 2 = 2, break = 2 => 1
// 5 / 2 = 2, break = 2 => 1

// s = acca 
// t = abba 

// p = a
// 