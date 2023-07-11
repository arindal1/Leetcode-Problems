class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int count = 0;
        for(List<String> s : items) {
            switch(ruleKey) {
                case "type" -> {
                    count += s.get(0).equals(ruleValue) ? 1 : 0;
                }
                case "color" -> {
                    count += s.get(1).equals(ruleValue) ? 1 : 0;
                }
                case "name" -> {
                    count += s.get(2).equals(ruleValue) ? 1 : 0;
                }
            }
        }
        return count;
    }
}
