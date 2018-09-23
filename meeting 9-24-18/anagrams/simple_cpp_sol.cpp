#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    vector<string> substrs;
    map<string, int> instances;
    
    int counter=0;
    
    for (int i=0; i<s.length(); i++) {
        substrs.push_back("");
    }

    for (int i=0; i<s.length(); i++) {
        instances.clear();
        
        for (int j=0; j<(s.length()-i); j++) {
            substrs[j] += s[j+i];
            
            sort(substrs[j].begin(), substrs[j].end());
            
            if (instances.find(substrs[j]) == instances.end()) {
                instances[substrs[j]] = 1;
            } else {
                instances[substrs[j]]++;
            }
        }
        
        for (auto it : instances) {
            //cout << it.first << " " << it.second << "\n";
            
            if (it.second >= 2) {
                counter += ((it.second)*(it.second-1))/2;
            }
        }
    }
    
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

