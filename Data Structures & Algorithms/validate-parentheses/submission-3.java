class Solution {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        Map<Character, Character> pairs = Map.of(')', '(', ']', '[', '}', '{');

        for(char letter : s.toCharArray()){
            if(pairs.containsValue(letter)){
                stack.push(letter);
            }
            else if(pairs.containsKey(letter)){
                if(stack.isEmpty() || stack.peek() != pairs.get(letter)){
                    return false;
                }
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
}
