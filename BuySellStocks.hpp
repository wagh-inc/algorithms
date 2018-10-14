#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

namespace waghamit {
namespace bbg {
    namespace bestbuysellstock {
        using namespace std;
        class Solution {
            using PRICES = vector<int>;
            const PRICES prices_;
            size_t size = 0;
        public:
              explicit Solution(const PRICES & prices) noexcept:prices_(prices) {
                size = prices_.size();
              }

              auto maxProfit1Trans() {

              int pSize = prices_.size();
              if(pSize <= 1)
                return 0;

              int profit = 0;
              int minPrice = prices_[0];
              for( auto j=1;j < pSize;++j ) {
                profit = max(profit,prices_[j]-minPrice);
                minPrice = prices_[j] < minPrice ? prices_[j]:minPrice;
              }
              return profit;
            }

            int maxProfit2Trans() {
                vector<int> profit (size,0);
                int maxPrice = prices_[size-1];

                for(int i=size-2;i>=0;i--) {
                  if(maxPrice < prices_[i])
                    maxPrice = prices_[i];
                    profit[i] = max(profit[i+1],maxPrice - prices_[i]);
                }

                int minPrice = prices_[0];
                for(int i=1;i<size;i++) {
                  if( minPrice > prices_[i] ) {
                    minPrice = prices_[i];
                  }

                  profit[i] = max(profit[i-1],profit[i] + prices_[i] - minPrice);
                }

                return profit[size-1];
              }
        };
    }
}
}