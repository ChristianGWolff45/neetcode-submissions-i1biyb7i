class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if(s2.length() < s1.length()) return false;
        int strLen = s1.length();
        int[] occuranceS1 = new int[26];
        int[] occuranceS2 = new int[26];
        int matches = 26;
        for(int i = 0; i < strLen; i++){
            if(++occuranceS1[s1.charAt(i) - 'a'] == 1){
                matches -= 1;
            }
        }
        for(int i = 0; i < strLen; i++){
            if(occuranceS2[s2.charAt(i) - 'a']++ == occuranceS1[s2.charAt(i) - 'a']){
                matches -= 1;
            }
            if(occuranceS2[s2.charAt(i) - 'a'] == occuranceS1[s2.charAt(i) - 'a']){
                matches += 1;
            }
        }
        int r = strLen - 1; int l = 0;
        if(matches == 26){
            return true;
        }
        while(r < s2.length() -  1){
            if(occuranceS2[s2.charAt(l) - 'a']-- == occuranceS1[s2.charAt(l) - 'a']){
                matches -= 1;
                System.out.println(matches);
            }
            if(occuranceS2[s2.charAt(l) - 'a'] == occuranceS1[s2.charAt(l) - 'a']){
                matches += 1;
                System.out.println(matches);
            }
            l++;
            r++;
            if(occuranceS2[s2.charAt(r) - 'a']++ == occuranceS1[s2.charAt(r) - 'a']){
                matches -= 1;
                System.out.println(matches);
            }
            if(occuranceS2[s2.charAt(r) - 'a'] == occuranceS1[s2.charAt(r) - 'a']){
                matches += 1;
                System.out.println(matches);
            }
            if(matches == 26){
                return true;
            }

        }

        

        return false;        
    }
}
