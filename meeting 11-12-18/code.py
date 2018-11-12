class Loc:
    def __init__(self, x, y, pos):
        self.x = x
        self.y = y
        self.pos = pos
    
maze = ["" for x in range(8)]
bestq = [[-1 for x in range(8)] for y in range(8)] 
bests = [[-1 for x in range(8)] for y in range(8)] 

for i in range(8):
    maze[i] = input()
    
    for j in range(8):
        if maze[i][j]=='s':
            start_x=i
            start_y=j
        if maze[i][j]=='e':
            end_x=i
            end_y=j
            
#BFS using a queue in python

from collections import deque

posq = deque([])

posq.append(Loc(start_x,start_y,0));

while len(posq) > 0:
    top = posq[0]
    posq.popleft()

    if maze[top.x][top.y] != 'x' and (bestq[top.x][top.y] == -1 or bestq[top.x][top.y]>top.pos):
        bestq[top.x][top.y] = top.pos;
    
        if top.x > 0:
            posq.append(Loc(top.x-1,top.y,top.pos+1))
        if top.x < 7: 
            posq.append(Loc(top.x+1,top.y,top.pos+1))
        if top.y > 0: 
            posq.append(Loc(top.x,top.y-1,top.pos+1))
        if top.y < 7: 
            posq.append(Loc(top.x,top.y+1,top.pos+1))

print(bestq[end_x][end_y])

#DFS using a stack in python

poss = []

poss.append(Loc(start_x,start_y,0))

while len(poss) > 0:
    top = poss[-1]
    poss.pop()

    if maze[top.x][top.y] != 'x' and (bests[top.x][top.y] == -1 or bests[top.x][top.y]>top.pos):
        bests[top.x][top.y] = top.pos;
    
        if top.x > 0:
            poss.append(Loc(top.x-1,top.y,top.pos+1))
        if top.x < 7: 
            poss.append(Loc(top.x+1,top.y,top.pos+1))
        if top.y > 0: 
            poss.append(Loc(top.x,top.y-1,top.pos+1))
        if top.y < 7: 
            poss.append(Loc(top.x,top.y+1,top.pos+1))

print(bests[end_x][end_y])

















