
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int left = 0; int right = 0;
        int max = 0;
        while(right < s.length()){
            char letter = s.charAt(right);


            while(set.contains(letter)){
                set.remove(s.charAt(left));
                left++;
            }

            if(right - left + 1 > max){
                max = right -left + 1;
            }

            set.add(letter);
            right++;

        }
        return max;

    }
}
