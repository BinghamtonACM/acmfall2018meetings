import java.util.*;

class Loc {
    public int x;
    public int y;
    public int pos;
    
    Loc(int mx, int my, int mp) {
        this.x = mx;
        this.y = my;
        this.pos = mp;
    }
};

class code {
    public static void main(String[] args) {
        String[] maze = new String[8];
        int[][] bestq = new int[8][8];
        int[][] bests = new int[8][8];
        
        int start_x=0;
        int start_y=0;
        int end_x=0;
        int end_y=0;
        
        Scanner scan = new Scanner(System.in);
        
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                bestq[i][j] = -1;
                bests[i][j] = -1;
            }
        }
        
        for (int i=0; i<8; i++) {
            String hold = scan.next();
            
            maze[i] = hold;
            
            for (int j=0; j<8; j++) {
                if (hold.charAt(j)=='s') {
                    start_x=i;
                    start_y=j;
                }
                if (hold.charAt(j)=='e') {
                    end_x=i;
                    end_y=j;
                }
            }
        }
        
        /*BFS using a queue in Java*/
        
        Queue<Loc> posq = new LinkedList<Loc>();

        posq.add(new Loc(start_x,start_y,0));
        
        while (!posq.isEmpty()) {
            Loc top = posq.poll();

            if (maze[top.x].charAt(top.y) != 'x' && (bestq[top.x][top.y] == -1 || bestq[top.x][top.y]>top.pos)) {
                bestq[top.x][top.y] = top.pos;
            
                if (top.x > 0) posq.add(new Loc(top.x-1,top.y,top.pos+1));
                if (top.x < 7) posq.add(new Loc(top.x+1,top.y,top.pos+1));
                if (top.y > 0) posq.add(new Loc(top.x,top.y-1,top.pos+1));
                if (top.y < 7) posq.add(new Loc(top.x,top.y+1,top.pos+1));
            }
        }
        
        System.out.println(bestq[end_x][end_y]);
        
        /*DFS using a stack in Java*/
        
        Stack<Loc> poss = new Stack<Loc>();

        poss.push(new Loc(start_x,start_y,0));
        
        while (!poss.isEmpty()) {
            Loc top = poss.pop();

            if (maze[top.x].charAt(top.y) != 'x' && (bests[top.x][top.y] == -1 || bests[top.x][top.y]>top.pos)) {
                bests[top.x][top.y] = top.pos;
            
                if (top.x > 0) poss.push(new Loc(top.x-1,top.y,top.pos+1));
                if (top.x < 7) poss.push(new Loc(top.x+1,top.y,top.pos+1));
                if (top.y > 0) poss.push(new Loc(top.x,top.y-1,top.pos+1));
                if (top.y < 7) poss.push(new Loc(top.x,top.y+1,top.pos+1));
            }
        }
        
        System.out.println(bests[end_x][end_y]);
    }
}

















