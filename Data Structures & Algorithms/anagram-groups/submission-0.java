class Solution {
    private List<Integer> freqMap(String s){
        int[] freq = new int[26];
        for(int i=0;i<s.length();i++){
            freq[s.charAt(i) - 'a']++;
        }
        List<Integer> ans = new ArrayList<>();
        for(int i=0;i<26;i++){
            ans.add(freq[i]);
        }
        return ans;
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<List<Integer>, List<String>> mp = new HashMap<>();
        
        
        for(String s : strs){
            List<Integer> key = freqMap(s);
            
            // 2. If the key doesn't exist, put a new ArrayList in the map
            if (!mp.containsKey(key)) {
                mp.put(key, new ArrayList<>());
            }
            // 3. Add the string to the corresponding anagram group
            mp.get(key).add(s);
        }

        List<List<String>> ans = new ArrayList<>();

        for (Map.Entry<List<Integer>, List<String>> entry : mp.entrySet()) {
            ans.add(entry.getValue());
        }
        return ans;
    }
}
