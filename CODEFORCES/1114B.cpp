B. Yet Another Array Partitioning Task
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
An array b is called to be a subarray of a if it forms a continuous subsequence of a, that is, if it is equal to al, al+1, …, ar for some l,r.

Suppose m is some known constant. For any array, having m or more elements, let's define it's beauty as the sum of m largest elements of that array. For example:

For array x=[4,3,1,5,2] and m=3, the 3 largest elements of x are 5, 4 and 3, so the beauty of x is 5+4+3=12.
For array x=[10,10,10] and m=2, the beauty of x is 10+10=20.
You are given an array a1,a2,…,an, the value of the said constant m and an integer k. Your need to split the array a into exactly k subarrays such that:

Each element from a belongs to exactly one subarray.
Each subarray has at least m elements.
The sum of all beauties of k subarrays is maximum possible.
Input
The first line contains three integers n, m and k (2≤n≤2⋅105, 1≤m, 2≤k, m⋅k≤n) — the number of elements in a, the constant m in the definition of beauty and the number of subarrays to split to.

The second line contains n integers a1,a2,…,an (−109≤ai≤109).

Output
In the first line, print the maximum possible sum of the beauties of the subarrays in the optimal partition.

In the second line, print k−1 integers p1,p2,…,pk−1 (1≤p1<p2<…<pk−1<n) representing the partition of the array, in which:

All elements with indices from 1 to p1 belong to the first subarray.
All elements with indices from p1+1 to p2 belong to the second subarray.
….
All elements with indices from pk−1+1 to n belong to the last, k-th subarray.
If there are several optimal partitions, print any of them.

Examples
inputCopy
9 2 3
5 2 5 2 4 1 1 3 2
outputCopy
21
3 5 
inputCopy
6 1 4
4 1 3 2 2 3
outputCopy
12
1 3 5 
inputCopy
2 1 2
-1000000000 1000000000
outputCopy
0
1 
Note
In the first example, one of the optimal partitions is [5,2,5], [2,4], [1,1,3,2].

The beauty of the subarray [5,2,5] is 5+5=10.
The beauty of the subarray [2,4] is 2+4=6.
The beauty of the subarray [1,1,3,2] is 3+2=5.
The sum of their beauties is 10+6+5=21.

In the second example, one optimal partition is [4], [1,3], [2,2], [3]
-----------------------------------------------------Solution-----------------------
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end(), greater<pii>());

    vector<int> ind(m*k);
    ll sumBeauty = 0;
    for(int i = 0; i < m*k; ++i) {
        sumBeauty += a[i].first;
        ind[i] = a[i].second;
    }

    sort(ind.begin(), ind.end());

    vector<int> division(k-1);
    for(int i = 0; i < k-1; ++i)
        division[i] = ind[(i+1)*m - 1];

    cout << sumBeauty << endl;
    for(int p: division)
        cout << p + 1 << " ";

    return 0;
}
