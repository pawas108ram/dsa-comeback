// Brute Force Code

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         string ans = "";
//         int carry = 0;

//         for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry; i--, j--) {
//             int ac = (i >= 0) ? a[i] - '0' : 0;
//             int bc = (j >= 0) ? b[j] - '0' : 0;
//             int sum = ac + bc + carry;
            
//             char chardigit = (sum % 2) + '0';
//             ans += chardigit;
//             carry = sum / 2;
//         }

//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };


// Time Complexity : O(n)
// Space Complexity : O(n)
