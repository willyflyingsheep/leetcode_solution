class ProductOfNumbers {
private:
    vector<int> products;
public:
    ProductOfNumbers() {
        products.clear();
        products.reserve(40000);
        products.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            products.clear();
            products.push_back(1);
        } else {
            products.push_back(products.back() * num);
        }
    }
    
    int getProduct(size_t k) {
        int n = products.size();
        if (n <= k) {
            return 0;
        }
        return products[n - 1] / products[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */