#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int traverseQueens(int n, int px, int py, int dx, int dy, unordered_map<int, unordered_set<int> > & obsticleMap) {
    int steps=0;
    
    px += dx;
    py += dy;
    
    while (px>0 && py>0 && px<=n && py<=n && (obsticleMap[px].find(py) == obsticleMap[px].end())) {
        cout << px << " " << py << "\n";
        px += dx;
        py += dy;
        steps++;
    }
    
    cout << dx << " " << dy << " " << steps << "\n";
    
    return steps;
}

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    unordered_map<int, unordered_set<int> > obsticleMap;
    
    for (int i=0; i<obstacles.size(); i++) {
        cout << obstacles[i][0] << " " << obstacles[i][1] << "\n";

        obsticleMap[obstacles[i][0]].insert(obstacles[i][1]);
    }
    
    cout << "runs\n";
    
    int total=0;
    
    total += traverseQueens(n, r_q, c_q, 1, 0, obsticleMap);
    total += traverseQueens(n, r_q, c_q, 1, 1, obsticleMap);
    total += traverseQueens(n, r_q, c_q, 0, 1, obsticleMap);
    total += traverseQueens(n, r_q, c_q,-1, 1, obsticleMap);
    total += traverseQueens(n, r_q, c_q,-1, 0, obsticleMap);
    total += traverseQueens(n, r_q, c_q,-1,-1, obsticleMap);
    total += traverseQueens(n, r_q, c_q, 0,-1, obsticleMap);
    total += traverseQueens(n, r_q, c_q, 1,-1, obsticleMap);
    
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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

