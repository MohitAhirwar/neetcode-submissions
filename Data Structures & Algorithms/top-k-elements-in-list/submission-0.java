class Pair{
    int p1;
    int p2;

    Pair(int p1, int p2) {
        this.p1 = p1;
        this.p2 = p2;
    }
};

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<Pair> pq = new PriorityQueue<>(
            (ele1, ele2) -> ele2.p2 - ele1.p2
        );
        

        HashMap<Integer,Integer> mp = new HashMap<>();

        for(int i=0;i<nums.length;i++){
            int key = nums[i];
            int val = 1;
            if(mp.containsKey(key) == false){
                mp.put(key,val);
            }else{
                val = mp.get(key);
                mp.put(key,val+1);
            }
        }

        for(Map.Entry<Integer,Integer> ele : mp.entrySet()){
            System.out.println(ele.getKey() +  "-" + ele.getValue());
            Pair p = new Pair(ele.getKey(),ele.getValue());
            pq.add(p);
        }

        int[] ans = new int[k];
        int j = 0;
        while(k > 0){
            ans[j] = pq.poll().p1;
            j++;
            k--;
        }
        return ans;
    }
}
