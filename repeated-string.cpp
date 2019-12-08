#include <bits/stdc++.h>

using namespace std;

long repeatedString(string s, long n){
    int count = 0;
    long result = 0;
    int length = s.length();
    int pos[length]={0};

    for(int i=0;i<length;i++){
        if(s[i]=='a'){
            count++;
            pos[i]=1;
        }
    }

    result = count * (n/length);
    long count2=0;
    if(n%length>0) {
        int temp = n%length;
        for(int i=0;i<temp;i++){
            if(pos[i]==1)
                count2++;
        }
    }

    cout<<result<<' '<<count2<<' '<<count;
    return result+count2;
}

int main () {
    string s;
    getline(cin,s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s,n);
    
    cout<<result;
}