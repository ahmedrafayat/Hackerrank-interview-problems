#include <bits/stdc++.h>

using namespace std;

int alternatingCharacters(string s) {
    char curr = s[0];
    int length = s.length();
    int count = 0;
    if(length>1) {
        for(int i=1;i<length;i++) {
            if(curr==s[i]){
                count++;
            }
            else curr=s[i];
        }
    }
    return count;

}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        cout << result << "\n";
    }


    return 0;
}
