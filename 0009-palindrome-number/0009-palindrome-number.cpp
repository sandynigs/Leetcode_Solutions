class Solution {
public:
    long long int reverse(long long int x){
        //123
        long long int temp=x;
        long long int fin=0;
        while(temp>0){
            long long int last=temp%10; //last=3, 2, 1
            temp=temp/10; //temp=12, 1, 0
            fin=fin*10+last; //fin=3, 32, 321
        }
        cout<<"reverse is:"<<fin<<endl;
        return fin;
    }
    
    bool isPalindrome(long long int x) {
        if(x<0){
            return false;
        }
        if(x==reverse(x)){
            return true;
        }
        return false;
    }
};