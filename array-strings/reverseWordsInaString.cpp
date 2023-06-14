/*
https://leetcode.com/problems/reverse-words-in-a-string/
*/

// Time: - O(n),    Space: - O(n). &  O(1) if extra spaces not there
class Solution {
public:
    void reverse(string &s, int i, int j) {
        while (i<=j) swap(s[i++], s[j--]);
    }
    string reverseWords(string s) {
        int i,j=-1,n=s.size(),t=0;
        string ans="";
        for (i=0;i<n;i++) {
            if (s[i]==' ') {
                if (j==-1) continue;
                reverse(s,j,i-1);
                if (t) ans += " ";
                if (!t) t = !t;
                for (int k=j;k<i;k++) ans += s[k];
                j = -1;
            } 
            else if (j==-1) j=i;
        }
        if (j!=-1) {
            reverse(s,j,n-1);
            if (t) ans += " ";
            for (int k=j;k<n;k++) ans += s[k];
        }
        // reverse(s,0,n-1);
        reverse(ans,0,ans.size()-1);
        return ans;
    }
};