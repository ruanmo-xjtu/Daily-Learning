class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 1;
        int start = 0;
        for (int i = 0; i < n;) {
            if (n - i <= len / 2) break;//显然当剩余长度小于最大回文子串长度时 最大字串长度确定
            int x = i;
            int y = i;
            while (y + 1 < n && s[y] == s[y+1]) ++y;
            for(--x, ++y, i = y; x >= 0 && y < n && s[x] == s[y]; --x, ++y)；//扩张两端 改变初始位置 判断越界与相等性
            if(y - x - 1 > len){
                len = y - x - 1;
                start = x + 1;
            }
        }
        return s.substr(start, len);
    }
};
