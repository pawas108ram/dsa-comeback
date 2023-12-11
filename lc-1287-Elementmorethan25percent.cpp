// Brute Force Code 

// class Solution {
// public:
//     int findSpecialInteger(vector<int>& arr) {
//         int minfreq=arr.size()/4;
//         unordered_map<int,int>umap;
//         for(int i=0;i<arr.size();i++){
//             umap[arr[i]]++;
//         }
//         for(auto ele:umap){
//             if(ele.second>minfreq){
//                 return ele.first;
//             }
//         }
//         return -1;
//     }
// };

// Time Complexity : O(n)
// Space Complexity : O(n)

// Optimal Code 

// class Solution {
// public:
//     int findSpecialInteger(vector<int>& arr) {
//         int n=arr.size();
//         for(int i=0;i<=n-n/4;i++){
//             cout<<i<<" "<<i+(n/4)<<endl;
//             if(arr[i]==arr[(i+(n/4))]){
//                 return arr[i];
//             }
//         }
//         return -1;
//     }

// };

// Time Complexity : O(n)
// Space Complexity : O(1)