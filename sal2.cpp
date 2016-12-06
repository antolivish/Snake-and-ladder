#include<iostream>
#include <queue>
using namespace std;
 
struct queueEntry
{
    int v;     
    int dist; 
};

int getMinDiceThrows(int move[], int N)
{

    //mark all cells as not visited
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
 

    queue<queueEntry> q;
  
    //initial position is 1 so mark it as visited
    visited[0] = true;
    queueEntry s = {0, 0};
    q.push(s);
 
    queueEntry qe; 
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v;
    
        // if it reaches destination break the loop
        if (v == N-1)
            break;
 
        q.pop();


        // looking next 6 position
        for (int j=v+1; j<=(v+6) && j<N; ++j)
        {
            //checking whether the cell is visited or not
            if (!visited[j])
            {
                
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;
 
                // checking whether there is snake or ladder
                if (move[j] != j)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
 
    return qe.dist;
}

int sort(int b[])
{
    int g,r;
    g=b[0];
    for(r=0;r<4;r++)
    {
      if(g>b[r])
        g=b[r];
    }
   cout<<"Value "<<g;
    return g;
}

int getMinDiceThrowsSnake(int sn[], int m)
{
    int small;
    int n=0;
    int b[10];
    int moves[50];
    
     for (int i = 0; i<sn[m]; i++)
        moves[i] = i;

    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // marking all cells as not visited and this functions for each snake
    bool *visited = new bool[sn[m]];
    for (int i = 0; i < sn[m]; i++)
        visited[i] = false;
 
    queue<queueEntry> q;
    
    // marking the first cell as visited
    visited[0] = true;
    queueEntry s = {0, 0};
    q.push(s); 
    
    queueEntry qf;
    while (!q.empty())
    {
        qf = q.front();
        int v = qf.v;
 
        if (v == sn[m]-1)
            break;
 
        q.pop();

        //checking minimum steps to reach snakebite
        for (int j=v+1; j<=(v+6) && j<sn[m]; ++j)
        {
            if (!visited[j])
            {
                queueEntry a;
                a.dist = (qf.dist + 1);
                visited[j] = true;
 
                if (moves[j]!=j)   
                     a.v = moves[j];
		else
                     a.v = j;
                q.push(a);
            }
        }
    }
    cout<<" "<<qf.dist;  
    return qf.dist;
}

int main()
{
   int  N = 30;
//    int m=3;
    int s=0,l=0;
    int moves[N],sn[10],b[20],small;
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
   
    sn[0]=27;
    sn[1]=21;
    sn[2]=19;
    sn[3]=17;
	
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
   for(int m=3;m>=0;m--)
   {
    b[m]=getMinDiceThrowsSnake(sn, m);
    cout<<"b[m] "<<b[m];
   }
    small = sort(b);
    cout <<"\n\nThe no. of snakes and ladder is "<< s <<" and "<< l ;
 
    cout << "\n\nMin Dice throws required is " << getMinDiceThrows(moves, N)<<"\n";
    p = small + getMinDiceThrows(moves, N);
    cout << "\n\nMin Dice throws given that it encountered snake atleast one is " <<p<<"\n";

    return 0;
}
