#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s) {
    int length = s.length();
    if(length%2!=0)
        return "NO";
    stack<char> c;
    int count = 0;
    int i;
    for(i=0;i<length;i++) {
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            c.push(s[i]);
            count++;
        }
        else if(s[i]==')') {
            if(c.empty()) return "NO";
            char temp = c.top();
            c.pop();
            count--;
            if(temp!='(')
                return "NO";
        }
        else if(s[i]=='}') {
            if(c.empty()) return "NO";
            char temp = c.top();
            c.pop();
            count--;
            if(temp!='{')
                return "NO";
        }
        else if(s[i]==']') {
            if(c.empty()) return "NO";
            char temp = c.top();
            c.pop();
            count--;
            if(temp!='[')
                return "NO";
        }
    }

    if(count==0){
        return "YES";
    }
    else return "NO";
}

int main() {
    int t;
    cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin,s);

        string result = isBalanced(s);
        cout<< result<<"\n";
    }

}