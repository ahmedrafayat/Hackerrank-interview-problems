#include <bits/stdc++.h>

using namespace std;


// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int move_i[7] = {0,0,0,1,2,2,2};
    int move_j[7] = {0,1,2,1,0,1,2};
    int max = -INT_MAX;

    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            int sum = 0;
            for(int k=0;k<7;k++){
                sum+=arr[i+move_i[k]][j+move_j[k]];
            }
            if(sum>max) {
                max=sum;
            }
            cout<<sum<<endl;
        }
    }

    return max;
}

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    return 0;
}