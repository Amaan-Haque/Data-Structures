#include<bits/stdc++.h>
using namespace std;

struct node
{
    int maxi;
    int smax;
};

void buildTree(int arr[], node tree[], int start, int end, int treeNode)
{
    if(start == end )
    {
        tree[treeNode].maxi = arr[start];
        tree[treeNode].smax = INT_MIN;
        return;
    }
    
    int mid = (start + end )/2;
    
    buildTree(arr,tree,start, mid, 2*treeNode);
    buildTree(arr,tree,mid+1,end, 2*treeNode+1);
    
    node ans1 = tree[2*treeNode];
    node ans2 = tree[2*treeNode+1];
    
    tree[treeNode].maxi = max(ans1.maxi, ans2.maxi);
    
    if(ans1.maxi>= ans2.maxi)
    {
        tree[treeNode].smax = max(ans1.smax, ans2.maxi);
    }
    else   
    {
        tree[treeNode].smax = max(ans2.smax, ans1.maxi);
    }
    
    return;
}

void update(int arr[], node tree[], int start, int end, int treeNode, int index, int val)
{
    if(start == end )
    {
        tree[treeNode].maxi= val;
        tree[treeNode].smax = INT_MIN;
        arr[index] = val;
        return;
    }
    
    int mid = (start + end )/2;
    
    if(index > mid)
    {
        update(arr, tree, mid+1, end, 2*treeNode+1, index, val);
    }
    else 
    {
        update(arr,tree,start,mid,2*treeNode,index,val);
    }
    
    node ans1 = tree[2*treeNode];
    node ans2 = tree[2*treeNode+1];
    
    tree[treeNode].maxi = max(ans1.maxi, ans2.maxi);
    
    if(ans1.maxi>= ans2.maxi)
    {
        tree[treeNode].smax = max(ans1.smax, ans2.maxi);
    }
    else   
    {
        tree[treeNode].smax = max(ans2.smax, ans1.maxi);
    }
    
}

node query(node tree[], int start, int end, int treeNode, int left, int right)
{
    // cout << "treeNode= "<< treeNode<< endl;
    // cout << "start = "<< start << " end= "<< end << endl;
    //No Overlap 
    if(start > right || end < left)
    {
        node temp;
        temp.maxi = INT_MIN;
        temp.smax = INT_MIN;
        return temp;
    }
    
    // Complete Overlap 
    if(start >=left && end <= right)
    {
        return tree[treeNode];
    }
    
    // Pratial Overlap 
    
    int mid = (start+end )/2;
    
    node ans1;
    ans1= query(tree,start,mid ,2*treeNode,left, right);
    // cout << "ans 1 = "<< ans1.maxi << " "<< ans1.smax << endl;

    node ans2;
    ans2 = query(tree,mid+1,end,2*treeNode+1,left, right);
    // cout << "ans 2 = "<< ans2.maxi << " "<< ans2.smax <<endl;
    node temp;
    temp.maxi = max(ans1.maxi, ans2.maxi);
    
    if(ans1.maxi>= ans2.maxi)
    {
        temp.smax = max(ans1.smax, ans2.maxi);
    }
    else   
    {
        temp.smax = max(ans2.smax, ans1.maxi);
    }
    // cout << "tree[treeNode]= "<< tree[treeNode].maxi << " "<< tree[treeNode].smax << endl;

    return temp;
    

}

int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    node tree[4*n];
    buildTree(arr, tree, 0, n-1, 1);
    
    // for(int i=0;i<4*n;i++)
    // {
    //     cout << tree[i].maxi << " " << tree[i].smax << endl;
    // }
    // cout << endl;
        
    int q;
    cin >> q;
    
    for(int i=0;i<q;i++)
    {
        char inpt;
        cin >> inpt;
        
        if(inpt == 'U')
        {
            int x;
            cin >> x;
            int y;
            cin >> y;
            
            update(arr, tree,0, n-1, 1, x-1, y);
        }
        
        if(inpt == 'Q')
        {
            int x;
            cin >> x;
            int y ;
            cin >> y;
            
            node temp;
            
            temp =query(tree, 0, n-1, 1, x-1, y-1);
            if(i!=0)
            cout << temp.maxi+temp.smax<< endl;
            else 
            cout << temp.maxi+temp.smax << endl;   
            
        }
        
    }
}
