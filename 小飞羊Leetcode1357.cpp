class Cashier {
private:
    int n;
    int discount;
    int nth_customer;
    unordered_map<int, int> prices;
public:
    Cashier(int n_, int discount_, vector<int>& products_, vector<int>& prices_) {
        n = n_;
        discount = discount_;
        nth_customer = 0;
        for (int i = 0; i < products_.size(); ++i) {
            prices[products_[i]] = prices_[i];
        }        
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double cost = 0;
        for (int i = 0; i < product.size(); ++i) {
            cost += prices[product[i]] * amount[i];
        }
        
        nth_customer++;
        if (nth_customer % n == 0) {
            // lucky customer
            cost = cost - (discount * cost) / 100;
        }
        return cost;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */