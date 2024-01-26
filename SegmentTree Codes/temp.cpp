#include<iostream>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int posx = 0;
        int negx = 0;
        int posy = 0;
        int negy = 0;
        while(n--){
            int x, y;
            cin >> x >> y;
            if(x<0){
                negx++;
            }
            if(x>0){
                posx++;
            }
            if(y<0){
                negy++;
            }
            if(y>0){
                posy++;
            }
        }
        if(posy && negy && negx && posx){//yeh line btarhi ki har ek direction mein elements hai toh chaaro button dabane hi pdenge 
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }

    }
}