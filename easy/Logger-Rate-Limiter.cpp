class Logger {
   public:
    /** Initialize your data structure here. */
    unordered_map<string, int> lastTimePrintedMap;
    Logger() {}

    /** Returns true if the message should be printed in the given timestamp,
       otherwise returns false. If this method returns false, the message will
       not be printed. The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        bool should = false;
        if (lastTimePrintedMap.count(message) != 0) {
            should = timestamp >= lastTimePrintedMap[message] + 10;
        } else {
            should = true;
        }
        if (should) {
            lastTimePrintedMap[message] = timestamp;
        }
        return should;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */