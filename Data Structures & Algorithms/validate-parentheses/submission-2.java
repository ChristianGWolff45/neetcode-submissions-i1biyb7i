class Solution {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        for(char letter : s.toCharArray()){
            if(letter == '(') stack.push(letter);
            else if(letter == '[') stack.push(letter);
            else if(letter == '{') stack.push(letter);
            else if(stack.isEmpty()){
                return false;
            }
            else if(letter == ')' && stack.peek() == '(') stack.pop();
            else if(letter == ']' && stack.peek() == '[') stack.pop();
            else if(letter == '}' && stack.peek() == '{') stack.pop();
            else{
                return false;
            }
        }
        return stack.isEmpty();
    }
}
