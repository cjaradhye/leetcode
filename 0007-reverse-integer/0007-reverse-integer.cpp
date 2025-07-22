class Solution {
public:
    int length(int x){
        int count = 0;
        do{
            x/=10;
            count++;
        }while(x!=0);
        return count;
    }
    int reverse(int x) {
        int temp = x;
        long final = 0;
        int count = 0;
        int len = length(x);
        do {
            int dig = temp % 10;
            final += pow(10,len-count-1) * dig;
            if(final > pow(2,31) || final < (-1)*pow(2,31)){
                return 0;
            }
            count++;
            temp /= 10;
        } while (temp != 0); 
        return long(final);
    }

};