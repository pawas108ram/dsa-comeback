#include<bits/stdc++.h>
using namespace std;
int main(){
 

        int n;
        cin >> n;
        vector<int> positions(n+1, 0);
        for (int i = 1; i <= n;i++){
            int x;
            cin >> x;
            positions[x] = i;// corresponding to number uska index store kara hai 
        }
    
    int m;
    cin >> m;
    long long int startcount = 0;//start se comparsion
    long long int endcount = 0;//end se comparison
    while(m--){
        int b;
        cin >> b;
        startcount += positions[b];// i comparisons for b 
        endcount += (n  - positions[b]+1);//end se comparisons for b
    }
    cout << startcount << " " << endcount << endl;
}