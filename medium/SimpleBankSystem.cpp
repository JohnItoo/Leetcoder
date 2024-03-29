class Bank {
public:
    vector<long long> balance;
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
       if(validateAccount(account1) || validateAccount(account2)) return false;
        if(balance[account1-1] < money) return false;
      //  cout << account1 << " " << balance[account1-1] <<endl;
        balance[account1-1] -= money;
        balance[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(validateAccount(account)) return false;
        balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(validateAccount(account)) return false;
        if(balance[account-1] < money) return false;
        balance[account-1] -= money;
        return true;
    }
    
    bool validateAccount(int account) {
        return account < 1 || account > balance.size();
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);