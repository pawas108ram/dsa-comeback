#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector < int >arr(n, 0);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(),greater<int>());
    long long int sum = 0;
    for (int i = 0; i < n;i++){
        sum += arr[i]*pow(2,i);
    }
    cout << sum << endl;
}