#include <bits/stdc++.h>

using namespace std;

string biggerIsGreater(string w) {
    unsigned long int index = w.length();
    while(--index>0)
    {
        if(w[index-1]<w[index])
            break;
    }
    if(index==0)    return "no answer";
    else
    {
        unsigned long int i=w.length();
        while(w[--i]<=w[index-1]);        
        swap(w[i],w[index-1]);
        reverse(w.begin()+index,w.end());
        return w;
    }
    
    /*
    Another solution :
	bool isPerm=next_permutation(w.begin(),w.end());
    if(isPerm)  return w;
    else    return "no answer";*/

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

