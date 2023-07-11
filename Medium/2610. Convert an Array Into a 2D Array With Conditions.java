class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        Set<Integer> set = new HashSet<>();
        for (int i : nums) {
            map.put(i, 1 + map.getOrDefault(i, 0));
            set.add(i);
        }
        
        List<List<Integer>> ans = new ArrayList<>();
        while (!map.isEmpty()) {
            List<Integer> row = new ArrayList<>();
            for (int key : set) {
                if (map.containsKey(key)) {
                    int cnt = map.get(key); 
                    row.add(key);   
                    if (cnt == 1) {
                        map.remove(key);   
                    } else {
                        map.put(key, --cnt);
                    } 
                }  
            }
            ans.add(row);
        }
        
        return ans;
    }
}
