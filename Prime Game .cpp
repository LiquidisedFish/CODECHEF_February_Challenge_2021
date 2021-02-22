#include<bits/stdc++.h>
#define int long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

const int N = 1e6+5;
int res[N];

void valentine()
{
    vector<int>vect;
    bool prime[N];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p < N; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i < N; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = 2; p < N; p++)
        if (prime[p])
            vect.push_back(p);

    auto it = vect.begin();
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if(*it <= i)
        {
            ++cnt;
            ++it;
        }
        res[i] = cnt;
    }
}

signed main()
{
    fastio;
    valentine();
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(res[x] <= y)
            printf("Chef\n");
        else
            printf("Divyam\n");
    }
    return 0;
}

/*

Chef and Divyam are playing a game with the following rules:

First, an integer X! is written on a board.
Chef and Divyam alternate turns; Chef plays first.
In each move, the current player should choose a positive integer D which is divisible by up to Y distinct primes and does not exceed the integer currently written on the board. Note that 1 is not a prime.
D is then subtracted from the integer on the board, i.e. if the integer written on the board before this move was A, it is erased and replaced by A−D.
When one player writes 0 on the board, the game ends and this player wins.
Given X and Y, determine the winner of the game.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers X and Y.
Output
For each test case, print a single line containing the string "Chef" if Chef wins the game or "Divyam" if Divyam wins (without quotes).

Constraints
1≤T≤106
1≤X,Y≤106
Subtasks
Subtask #1 (5 points): Y=1
Subtask #2 (10 points):

1≤T≤102
1≤X≤6
Subtask #3 (85 points): original constraints

Example Input
3
1 2
3 1
2021 42
Example Output
Chef
Divyam 
Divyam
Explanation
Example case 1: Since D=1 is divisible by 0 primes, Chef will write 0 and win the game in the first move.

Example case 2: Chef must choose D between 1 and 5 inclusive, since D=6 is divisible by more than one prime. Then, Divyam can always choose 6−D, write 0 on the board and win the game.  

*/