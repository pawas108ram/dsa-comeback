#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int mindiff = INT_MAX;
    for (int i = 1; i < n;i++){
        mindiff = min(mindiff, arr[i] - arr[i - 1]);
    }
    cout << mindiff << endl;
}