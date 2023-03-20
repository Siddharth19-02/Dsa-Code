class Cashier {
    int n;
    int discount;
    unordered_map<int,int>mp;
    vector<int>prices;
    int count;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        count = 0;
        this->discount = discount;
        this->n = n;
        this->prices = prices;
        for(int i=0;i<products.size();i++)
        {
            mp[products[i]] = i;
        }
    }
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        long double total = 0.0;
        for(int i=0;i<product.size();i++)
        {
            total += (prices[mp[product[i]]]*amount[i]);
        }
        
        if(count == n)
        {
            total = total*(double(100-discount)/100);
            count = 0;
        }
        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
