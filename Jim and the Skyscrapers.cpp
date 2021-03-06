#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long solve(vector<int> arr) {
    long count=0;
    stack<vector<int>> s;
    for(int x:arr)
    {
        //Delete all items till top of stack is equal to new element or till empty
        while(!s.empty() and s.top()[0]<x)
            s.pop();
        //If it is equal to top element post increment top's 1st index while adding it to count
        if(!s.empty() and s.top()[0]==x)
        {
            count+=s.top()[1]++;
        }
        // If it is not equal then push it as a vector with {x,1}
        else s.push({x,1});
    }
    return count*2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    long result = solve(arr);

    fout << result << "\n";

    fout.close();

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

