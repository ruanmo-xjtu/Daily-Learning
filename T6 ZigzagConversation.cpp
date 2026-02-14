class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()){
            return s;
        }//特判 当行数小大于字符串长度或行数为1时 输出即为输入
        int n = s.size();
        string res;
        int cycle = 2 * (numRows - 1);
        for(int i = 0; i < numRows; ++i){
            for (int j = i; j < n; j += cycle) {
                res += s[j];
                if (i != 0 && i != numRows - 1) {
                    int secondIdx = j + cycle - 2 * i;
                    if (secondIdx < n) {
                        res += s[secondIdx];
                    }
                }
            }
        }
        return res;
    }
};
