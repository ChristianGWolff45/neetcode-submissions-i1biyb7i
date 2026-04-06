class Solution {
    public int characterReplacement(String s, int k) {
        if(s.length() == 0) return 0;
        int left = 0;
        int maxSubstring = 0;
        int[] occurance = new int[26];
        for(int right = 0; right < s.length(); right++){
            char letter = s.charAt(right);
            occurance[letter - 'A']++;
            if(k + getMaxOccurance(occurance) >= right - left + 1){
                if(right - left + 1 > maxSubstring){
                    maxSubstring = right - left + 1;
                }
            }else{
                occurance[s.charAt(left) - 'A']--;
                left++;
            }
        }
        return maxSubstring;
    }

    public int getMaxOccurance(int[] letters){
        int max = 0;
        for(int i = 0; i < letters.length; i++){
            if(letters[i] > max){
                max = letters[i];
            }
        }
        return max;
    }
}
