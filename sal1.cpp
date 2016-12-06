#include<iostream>
#include <queue>
using namespace std;
 
struct queueEntry
{
    int v;     // Vertex number
    int dist;  // Distance of this vertex from source
};

int getMinDiceThrows(int move[], int N)
{
    // The graph has N vertices. Mark all the vertices as
    // not visited
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    queue<queueEntry> q;
 
    // Mark the node 0 as visited and enqueue it.
    visited[0] = true;
    queueEntry s = {0, 0};  // distance of 0't vertex is also 0
    q.push(s);  // Enqueue 0'th vertex
 
    // Do a BFS starting from vertex at index 0
    queueEntry qe;  // A queue entry (qe)
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v; // vertex no. of queue entry
 
        // If front vertex is the destination vertex,
        // we are done
        if (v == N-1)
            break;
 
        // Otherwise dequeue the front vertex and enqueue
        // its adjacent vertices (or cell numbers reachable
        // through a dice throw)
        q.pop();
        for (int j=v+1; j<=(v+6) && j<N; ++j)
        {
            // If this cell is already visited, then ignore
            if (!visited[j])
            {
                // Otherwise calculate its distance and mark it
                // as visited
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;
 
                // Check if there a snake or ladder at 'j'
                // then tail of snake or top of ladder
                // become the adjacent of 'i'
                if (move[j] != j)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
 
    // We reach here when 'qe' has last vertex
    // return the distance of vertex in 'qe'
    return qe.dist;
}



int getMinDiceThrowsSnakebite(int move[], int N)
{
    // The graph has N vertices. Mark all the vertices as
    // not visited
    int small;
    int m=0;
    int n=0;
    int b[10],sn[10];
    sn[0]=27;
    sn[1]=21;
    sn[2]=19;
    sn[3]=17;
    bool *visited = new bool[27];
    for (int i = 0; i < 27; i++)
        visited[i] = false;

    // Create a queue for BFS
    queue<queueEntry> q1;

    // Mark the node 0 as visited and enqueue it.
    visited[0] = true;
    queueEntry s = {0, 0};  // distance of 0't vertex is also 0
    q1.push(s);  // Enqueue 0'th vertex

    // Do a BFS starting from vertex at index 0
    queueEntry qf;  // A queue entry (qe)
    while (!q1.empty())
    {
        qf = q1.front();
        int v = qf.v; // vertex no. of queue entry

        // If front vertex is the destination vertex,
        // we are done
        if (v == 27-1)
            break;

        // Otherwise dequeue the front vertex and enqueue
        // its adjacent vertices (or cell numbers reachable
        // through a dice throw)
        q1.pop();
	for (int j=v+1; j<=(v+6) && j<27; ++j)
        {
            // If this cell is already visited, then ignore
            if (!visited[j])
            {
                // Otherwise calculate its distance and mark it
                // as visited
                queueEntry a;
                a.dist = (qf.dist + 1);
                visited[j] = true;

                // Check if there a snake or ladder at 'j'
                // then tail of snake or top of ladder
                // become the adjacent of 'i'
                if (move[j] != j)
                    a.v = move[j];
                else
                    a.v = j;
                q1.push(a);
            }
       }
//   cout<<"qf"<<qf.dist;
  
//    b[m]=(qf.dist + 1);
//  cout<<"b[m]"<<b[m];
//   m++;
   
    }
 b[0]=(qf.dist + 1);
   // m++;;
//m++;
small = b[0] + getMinDiceThrows(move, N);

    //small=b[0];
   // for(n=0;n<4;n++)
   // { cout<<"\t"<<b[n];
   // if(small>(b[n] + getMinDiceThrows(move, N)))
   // {
   // small=b[n] + getMinDiceThrows(move, N);
   // }
   // }
    qf.dist = small;
   // cout<<"qf\t"<<qf.dist;
    // We reach here when 'qe' has last vertex
    // return the distance of vertex in 'qe'
    return small;
}




 
// Driver program to test methods of graph class
int main()
{
    // Let us construct the board given in above diagram
    int N = 30;
    int s=0,l=0;
    int moves[N];
    int p;
    for (int i = 0; i<N; i++)
        moves[i] = i;
 
    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
   
	
    for(int i=0;i<N;i++)
    {
        if(moves[i]>i)
        {
                l++;
        }
        else if(moves[i]<i)
        {
                s++;
        }
    }
    cout <<"\n\nThe no. of snakes and ladder is "<< s <<" and "<< l ;
 
    cout << "\n\nMin Dice throws required is " << getMinDiceThrows(moves, N)<<"\n";
 //   p = getMinDiceThrowsSnakebite(moves, N) + getMinDiceThrows(moves, N);
    cout << "\n\nMin Dice throws given that it encountered snake atleast one is " << getMinDiceThrowsSnakebite(moves, N)<<"\n";

    return 0;
}
