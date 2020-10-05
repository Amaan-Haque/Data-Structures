// heap if its sorted in array
// T: n*k*logk

#define pb push_back
#define ele first
#define array second.first
#define arrayIndex second.second
#define couple pair<int, int>

int* mergeKArrays(int arr[][N], int k)
{
    vector<int> ans;

    priority_queue <pair <int, pair<int, int> > > pq;

    for (int i = 0 ; i < k ; i++)
        pq.push({arr[i][0], {i, 0}});

    while (pq.size())
    {
        auto top = pq.top(); pq.pop();
        ans.pb(top.ele);

        int i = top.array;
        int j = top.arrayIndex + 1;

        if (i < k and j < k)
            pq.push({arr[i][j], {i, j}});
    }

    int *sorted = new int[ans.size()];

    for (int i = 0 ; i < ans.size() ; i++)
        sorted[i] = ans[i];

    return sorted;
}
