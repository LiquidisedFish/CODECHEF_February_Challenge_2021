def distinct(l1,l2):
    s=len(set(l1+l2))
    return s
for t in range(int(input())):
    n=int(input())
    l=input().split()
    body={}
    for i in l:
        p=i[1:]
        if p in body:
            body[p].append(i[0])
        else:
            body[p]=[i[0]]
    body1=list(body.keys())
    s=0
    for i in range (len(body)):
        for j in range(i+1,len(body)):
            temp=distinct(body[body1[i]],body[body1[j]])
            s+=(temp-len(body[body1[i]]))*(temp-len(body[body1[j]]))
    print(2*s)


'''

Сhef has assembled a football team! Now he needs to choose a name for his team. There are N words in English that Chef considers funny. These words are s1,s2,…,sN.

Chef thinks that a good team name should consist of two words such that they are not funny, but if we swap the first letters in them, the resulting words are funny. Note that under the given constraints, this means that a word is a non-empty string containing only lowercase English letters.

Can you tell Chef how many good team names there are?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated strings s1,s2,…,sN.
Output
For each test case, print a single line containing one integer — the number of ways to choose a good team name.

Constraints
1≤T≤100
2≤N≤2⋅104
2≤|si|≤20 for each valid i
s1,s2,…,sN contain only lowercase English letters
s1,s2,…,sN are pairwise distinct
the sum of N over all test cases does not exceed 2⋅104
Subtasks
Subtask #1 (20 points): s1,s2,…,sN contain only letters 'a' and 'b'

Subtask #2 (80 points): original constraints

Example Input
3
2
suf mas
3
good game guys
4
hell bell best test
Example Output
2
0
2
Explanation
Example case 1: The good team names are ("muf", "sas") and ("sas", "muf").

Example case 2: There are no good team names because all funny words start with 'g'.

Example case 3: The good team names are ("hest", "tell") and ("tell", "hest").

'''