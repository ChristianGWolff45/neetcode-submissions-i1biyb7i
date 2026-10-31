class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        int l = 0; 
        int r = x;
        int root = 0;
        while(l <= r){
            root = r + (l-r)/2;
            std::cout << root << std::endl;
            if(x / root < root){
                r = root - 1;
            }else if(x / root > root){
                l = root + 1;
            }else{
                return root;
            }
        }
        std::cout << root << std::endl;
        return x / root < root ? root - 1 : root;
    }
};