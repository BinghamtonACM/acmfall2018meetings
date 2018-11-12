#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct Loc {
    int x;
    int y;
    int pos;
    
    Loc(int mx, int my, int mp): x(mx), y(my), pos(mp) {}
};

int main() {
    vector<string> maze;
    vector< vector<int> > best;
    vector< vector<int> > bestq;
    vector< vector<int> > bests;
    vector<int> empty_vec;
    
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    
    for (int i=0; i<8; i++) empty_vec.push_back(-1);
    
    for (int i=0; i<8; i++) {
        string hold;
        
        cin >> hold;
        
        maze.push_back(hold);
        best.push_back(empty_vec);
        
        for (int j=0; j<8; j++) {
            if (hold[j]=='s') {
                start_x=i;
                start_y=j;
            }
            if (hold[j]=='e') {
                end_x=i;
                end_y=j;
            }
        }
    }
    
    /*BFS using a queue in C++*/
    
    queue<Loc> posq;
    
    bestq = best;
    
    posq.push(Loc(start_x,start_y,0));
    
    while (!posq.empty()) {
        Loc top = posq.front();
        posq.pop();

        if (maze[top.x][top.y] != 'x' && (bestq[top.x][top.y] == -1 || bestq[top.x][top.y]>top.pos)) {
            bestq[top.x][top.y] = top.pos;
        
            if (top.x > 0) posq.push(Loc(top.x-1,top.y,top.pos+1));
            if (top.x < 7) posq.push(Loc(top.x+1,top.y,top.pos+1));
            if (top.y > 0) posq.push(Loc(top.x,top.y-1,top.pos+1));
            if (top.y < 7) posq.push(Loc(top.x,top.y+1,top.pos+1));
        }
    }
    
    cout << bestq[end_x][end_y] << "\n";
    
    /*DFS using a stack in C++*/
    
    stack<Loc> poss;
    
    bests = best;
    
    poss.push(Loc(start_x,start_y,0));
    
    while (!poss.empty()) {
        Loc top = poss.top();
        poss.pop();

        if (maze[top.x][top.y] != 'x' && (bests[top.x][top.y] == -1 || bests[top.x][top.y]>top.pos)) {
            bests[top.x][top.y] = top.pos;
        
            if (top.x > 0) poss.push(Loc(top.x-1,top.y,top.pos+1));
            if (top.x < 7) poss.push(Loc(top.x+1,top.y,top.pos+1));
            if (top.y > 0) poss.push(Loc(top.x,top.y-1,top.pos+1));
            if (top.y < 7) poss.push(Loc(top.x,top.y+1,top.pos+1));
        }
    }
    
    cout << bests[end_x][end_y] << "\n";
}


















