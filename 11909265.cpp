//project Meeting Scheduling
#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<int> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ",";
   }
   cout << "]"<<endl;
}
using namespace std;
bool cmp(vector <int> a, vector <int> b){
   return a[0]<b[0];
}
class Solution {
   public:
   vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
      int i =0;
      int j = 0;
      vector <int> ans;
      sort(slots1.begin(),slots1.end(),cmp);
      sort(slots2.begin(),slots2.end(),cmp);
      while(i<slots1.size() && j<slots2.size()){
         int end = min(slots1[i][1],slots2[j][1]);
         int start = max(slots1[i][0],slots2[j][0]);
         if(end-start>=duration){
            ans.push_back(start);
            ans.push_back(start+duration);
            return ans;
         } else if(slots1[i][1]<slots2[j][1]) {
            i++;
         } else {
         j++;}
      }
      return ans;
   }
};
int main(){
    cout << "Eneter the employee :"<<endl;
   vector<vector<int>> v = {{10,50},{60,120},{140,210}};
   vector<vector<int>> v1 = {{0,15},{60,70}};
   Solution ob;
   print_vector(ob.minAvailableDuration(v, v1, 9));
}