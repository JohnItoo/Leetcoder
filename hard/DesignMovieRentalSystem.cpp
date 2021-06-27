class MovieRentingSystem {
public:
    map<int, set<pair<int, int> > > graph; // movies -> <{price, shop}>
    set<tuple<int, int, int> > rented; // movies -> shops that dont have movie currently price, shop, movie
    map<pair<int, int> , int> movieShopPrice;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto entry : entries) {
            int movie = entry[1];
            int price = entry[2];
            int shop = entry[0];
            
            graph[movie].insert({price, shop});
            movieShopPrice[{movie, shop}] = price;
        }
    }
    
    vector<int> search(int movie) {
      set<pair<int, int> > shopsWithMovie = graph[movie];
     vector<int> ret;
        int i = 0;
      for(auto it = shopsWithMovie.begin(); it != shopsWithMovie.end(); ++it) {
          if(i >= 5) break;
          pair<int, int> priceShop = *it;
          tuple<int, int, int> toCheck = tie(priceShop.first, priceShop.second, movie);
         if(rented.find(toCheck) != rented.end()) continue;
          ret.push_back(priceShop.second);
          i++;
      }
        return ret;
    }
    
    void rent(int shop, int movie) {
        pair<int, int> toRent = {movie, shop};
        int price = movieShopPrice[toRent];
        rented.insert(tie(price,shop, movie));
    }
    
    void drop(int shop, int movie) {
        pair<int, int> toReturn = {movie, shop};
        int price = movieShopPrice[toReturn];
        rented.erase(tie(price, shop, movie));
    }
    
    vector<vector<int>> report() {
         vector<vector<int>> res;
        int i = 0;
    
        for(auto it = rented.begin(); i < 5 &&  it != rented.end(); i++, ++it) {
            vector<int> here;
            tuple<int, int, int> curr = *it;
            here.push_back(get<1>(curr));
            here.push_back(get<2>(curr));
            res.push_back(here);
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */