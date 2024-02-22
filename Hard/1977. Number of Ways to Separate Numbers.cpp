#define ll long long 
ll mod = 1e9 + 7 ; 
ll ad(ll a , ll b )
{
    return ( a+b+mod)%mod;
}

class Solution {
int compare(int i , int j , int len , vector<vector<int>> &same , string &s)
{
    int common = same[i][j];
    if( common >= len ) return 1 ;
    if( s[i+common] < s[j+common]) return 1 ;
    else return 0;
}



public:
    int numberOfCombinations(string num) {

      int n = num.size();

      if( num[0] == '0') return 0 ;

      vector<vector<int>> same(n+1,vector<int>(n+1,0));
      for( int i = n-1 ; i >= 0 ; --i)
      {
          for( int j = n-1 ; j >=0 ; --j )
          {
              if(num[i]==num[j])
              {
                  same[i][j] = 1 + same[i+1][j+1];
             }
          }
      }

      vector<vector<int>> pref(n,vector<int>(n,0));
       for( int j =0 ; j < n ; ++j ) pref[0][j] = 1 ;


      for(int i = 1 ;i < n ; ++i )
      {
          if(num[i]=='0') { pref[i] = pref[i-1]; continue;}

          for( int j = i ; j < n ; ++j )
          {
              int len = j-i+1, prevStart = i-1-(len-1),count = 0 ; 

              if( prevStart < 0 ) count = pref[i-1][i-1];
              else 
              {
                  count = ad(pref[i-1][i-1],-pref[prevStart][i-1]);

                  if(compare(prevStart,i,len,same,num))
                  {
                      int cnt = (prevStart==0 ? pref[prevStart][i-1] : ad(pref[prevStart][i-1],-pref[prevStart-1][i-1]));
                      count = ad(count,cnt);
                  }
              }

              pref[i][j] = ad(pref[i-1][j] , count);
          }

      }

        return pref[n-1][n-1];
    }
};  
