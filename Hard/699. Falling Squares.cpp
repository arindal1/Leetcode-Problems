class Solution {
public:
    const static int N = 1e5 + 2;
int INF = 1e9;
int tree[4 * N], lazy[4 * N];
void push(int node)
{
    if(lazy[node]!=-1)
    {
       tree[2*node] =tree[2*node+1]=lazy[node];
       lazy[2*node] = lazy[2*node+1]=lazy[node];
       lazy[node]=-1;
    }
}
void update(int node, int tl, int tr, int l, int r, int updatedVal)
{
    if (tl > tr)return;
    else if (l<=tl && tr <=r)
    {
        tree[node] = updatedVal;
        lazy[node] = updatedVal; // ye value update krni hai tl to tr segment of segment tree.
    }
    else if(tl==tr && (tl<l||tr>r)) return;
    else
    {
        push(node);
        int tm = (tl + tr) / 2;
        update(2*node, tl, tm, l,r, updatedVal);
        update(2*node + 1, tm + 1, tr,l, r, updatedVal);
        tree[node] = max(tree[2*node], tree[2*node+ 1]);
    }
}
int query(int node, int tl, int tr, int l, int r)
{
    if (tl >tr)return -INF;
    if (l <= tl && tr <= r)return tree[node];
    if(tl==tr) return -INF;
    push(node);
    int tm = (tl + tr) / 2;
    int q1=query(2*node, tl, tm, l,r);
    int q2=query(2*node + 1, tm + 1, tr,l, r);
    return max(q1,q2);
}

 vector<int> fallingSquares(vector<vector<int>>& positions) 
  {
      memset(tree,0,sizeof(tree));
      memset(lazy,0,sizeof(lazy));
      memset(a,0,sizeof(a));

      unordered_map<int, int> index;
      set<int> sortedCoords;
      for (const auto& pos : positions) 
      {
          sortedCoords.insert(pos[0]);
          sortedCoords.insert(pos[0] + pos[1] - 1);
      }
      int compressedIdx = 1;
      for (auto it:sortedCoords) 
      {
          index[it] = compressedIdx;
          compressedIdx++;
      }  
      int n= compressedIdx;
      int best = 0;
      vector<int> ans;  
      for (const auto& pos : positions) 
      {
          int l = index[pos[0]];
          int r = index[pos[0] + pos[1] - 1];
          int mxinlr=query(1,1,n,l,r);
          update(1,1,n,l,r,mxinlr+pos[1]);
          int temp=query(1,1,n,1,n);
          ans.push_back(temp);
      }
      return ans;
  }
};
