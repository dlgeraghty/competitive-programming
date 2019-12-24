#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){


        string s;
        while(cin >> s && s != "#"){
                bool val = next_permutation(s.begin(), s.end());

                if(!val) cout << "No Successor";
                else cout << s;
                cout << endl;
        }

        return 0;
}
