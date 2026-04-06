class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if(s2.length() < s1.length()) return false;
        int strLen = s1.length();
        Integer[] occuranceS1 = new Integer[26];
        Arrays.fill(occuranceS1, 0);
        for(int i = 0; i < s1.length(); i ++){
            occuranceS1[s1.charAt(i) - 'a']++;
        }
        for(int l = 0; l +strLen <= s2.length(); l++){
            Integer[] occuranceS2 = new Integer[26];
            Arrays.fill(occuranceS2, 0);
            for(int r = l; r < l + strLen; r++){
                occuranceS2[s2.charAt(r) - 'a']++;
            }
            if(Arrays.deepEquals(occuranceS1, occuranceS2)){
                return true;
            }
        }

        return false;        
    }
}
