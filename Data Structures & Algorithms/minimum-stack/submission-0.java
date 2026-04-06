class MinStack {
    private int[] stack;
    private int index;
    public MinStack() {
        stack = new int[8];
        index = 0;
    }
    
    public void push(int val) {
        if(index >= stack.length){
            stack = Arrays.copyOf(stack, stack.length * 2);
        }
        stack[index] = val;
        index++;
    }
    
    public void pop() {
        index--;
    }
    
    public int top() {
        return stack[index - 1];
    }
    
    public int getMin() {
        int min = stack[index - 1];
        for(int i = index - 1; i >= 0; i--){
            if(stack[i] < min){
                min = stack[i];
            }
        }
        return min;
    }
}
