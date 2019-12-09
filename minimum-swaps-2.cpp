#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
// 4 3 1 2 5
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int count = 0;
    int n = arr.size();
    pair<int,int> edge[n];

    for(int i=0;i<n;i++) {
        edge[i].first = arr[i];
        edge[i].second = i;
    }

    sort(edge,edge+n);

    vector<bool> vis(n,false);

    for(int i=0;i<n;i++) {
        if(vis[i]==true||edge[i].second==i){
            continue;
        }

        int cycle_size = 0;
        int j = i;
        while(!vis[j]){
            vis[j]=true;
            j = edge[j].second;
            cycle_size++;
        }

        if(cycle_size>0) {
            count += (cycle_size -1);
        }
    }



    return count;

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    cout << res << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
