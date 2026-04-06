class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int start = 0;
        int end = s.length() -1;
        while(start < end){
            if(!alphanumeric(s.charAt(start))){
                start += 1;
                continue;
            }
            if(!alphanumeric(s.charAt(end))){
                end -= 1;
                continue;
            }
            if(s.charAt(start) == s.charAt(end)){
                start +=1;
                end -=1;
                continue;
            }
            return false;
        }
        return true;
    }
    public boolean alphanumeric(char letter){
        return (letter >= 'a' && letter <= 'z') ||
               (letter >= 'A' && letter <= 'Z') ||
               (letter >= '0' && letter <= '9');
    }
}
