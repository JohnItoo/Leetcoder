/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     
     */
    int start = 0;
    queue<char> order;

    
    int read(char *buf, int n) {
        char arr[4]; //{ , , , }
      while(order.size() < n) {
        
        int readNextCount = read4(arr);
        if(!readNextCount) break;
          
        for(int i = 0; i < readNextCount; i++) {
           order.push(arr[i]);
       }
     }

    int ans = 0;
    start = 0;

    while(!order.empty() && n > 0) {
        buf[start++] = order.front();
        order.pop();
        n--;
        ans++;
    }
        
        return ans;
    }
};