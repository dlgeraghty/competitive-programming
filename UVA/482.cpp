#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

        int in;
        cin >> in;
        while(in--){
                int a;
                vector<int> v;
                int size = 0;
                char ch;
                while(cin >> a ){
                        v.push_back(a);
                        size++;
                        if(cin.get(ch) && ch == '\n') break;
                }
                string b;
                vector<string> w(size);
                int i = 0;
                while(cin >> b){
                        w[v[i]-1] = b;
                        i++;

                        if(cin.get(ch) && ch == '\n') break;
                }
                for(int x = 0; x < w.size(); x++){
                        cout << w[x];
                        cout << endl;
                }
                if(in > 0) cout << endl;
        }

        return 0;
}

