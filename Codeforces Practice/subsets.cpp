#include<bits/stdc++.h>
using namespace std;
void generate(vector<int>& arr, vector<vector<vector<int>>>& subsets, vector<int>& a, vector<int>& b, int ind, int n) {
    if (ind == n) {
        subsets.push_back({a, b});
        return;
    }
    a.push_back(arr[ind]);
    generate(arr, subsets, a, b, ind + 1, n);
    a.pop_back();
    b.push_back(arr[ind]);
    generate(arr, subsets, a, b, ind + 1, n);
    b.pop_back();
}


int main(){
    vector<vector<vector<int>>> subsets;
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<int> a;
    vector<int> b;
    generate(arr, subsets, a, b, 0, n);
   for (int i = 0; i < subsets.size(); i++) {
       cout << "************************" << endl;
       cout << "Vector A" << endl;
       for (auto ele : subsets[i][0])
       {
           cout << ele << " ";
    }
    cout << endl;
    cout << "Vector B" << endl;
    for(auto ele:subsets[i][1]){
        cout << ele << " ";
    }
    cout << endl;
    cout << "****************************" << endl;
}

}