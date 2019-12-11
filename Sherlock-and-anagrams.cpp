#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s)
{
    int length = s.length();
    map<array<int, 26>, int> hash_map;

    for (int i = 0; i < length; i++)
    {
        array<int, 26> freq = {0};
        for (int j = i; j < length; j++)
        {
            freq[s[j] - 'a']++;
            hash_map[freq]++;
        }
    }
    int result = 0;
    for (auto i = hash_map.begin(); i != hash_map.end(); i++)
    {
        int temp = i->second;
        result += (temp * (temp - 1)) / 2;
    }

    return result;
}

int main()
{

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
    }

    return 0;
}
