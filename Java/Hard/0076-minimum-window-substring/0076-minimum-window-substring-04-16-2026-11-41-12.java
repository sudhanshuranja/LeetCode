class Solution {
    public String minWindow(String s, String t) {
       if(t.length()==1&&s.contains(t))return t;
        int minLen=Integer.MAX_VALUE,sindex=-1,left=0,right=0,n=s.length(),m=t.length(),count=0;
        int[]hash=new int[256];
        for(int i=0;i<m;i++)hash[t.charAt(i)]++;
        while(right<n){
            if(hash[s.charAt(right)]>0){
                count++;
            }
            hash[s.charAt(right)]--;
            while(count==m){
                if((right-left+1)<minLen){
                    minLen=right-left+1;
                    sindex=left;
                }
                hash[s.charAt(left)]++;
                if(hash[s.charAt(left)]>0)count--;
                left++;
            }
            right++;
        }
        return sindex==-1?"":s.substring(sindex,sindex+minLen);
    }
}