#include <bits/stdc++.h>

using namespace std;

long substrCount(int n, string s) {
    long count=n;
    for(float i=0.5; i<n; i+=0.5)
    {
        int left =(int)(i-0.5);
        int right=(int)(i+1);
        char ch=s[left];
        while(left>=0 and right<n)
        {
            if(s[left]==s[right] and s[right]==ch)
                count++;
            else break;
            --left;
            ++right;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
