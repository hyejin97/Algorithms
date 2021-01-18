class Solution {
    public String decodeString(String s) {
        Stack<String> vstk = new Stack<String>();
        int i = 0;
        
        while(i < s.length()){
            if(s.charAt(i) == ']'){
                String tmp = "";
                while(vstk.peek().charAt(0) != '['){
                    tmp = vstk.pop() + tmp;
                }
                vstk.pop(); //pop out open bricket
                String snum = "";
                while(!vstk.isEmpty() && (vstk.peek().charAt(0) >='0' && vstk.peek().charAt(0) <= '9')){
                    snum = vstk.pop() + snum;
                }
                int num = Integer.valueOf(snum);
                
                String iter = tmp;
                for(int k = 0; k < num-1; k++){
                    tmp += iter;
                }
                vstk.push(tmp);
            }
            else{
                vstk.push(Character.toString(s.charAt(i)));
            }
            i++;
        }
        
        String res = "";
        while(!vstk.empty()){
            res = vstk.pop() + res;
        }
        return res;
    }

}

