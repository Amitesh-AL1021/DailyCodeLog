#include <iostream>   // For input/output
#include <stack>      // For stack data structure
#include <vector>     // For storing test inputs
using namespace std;

// Class to calculate the Stock Span
class StockSpanner {
private:
    stack<pair<int,int>> st;  // Stack stores (price, span)
public:
    StockSpanner() {}

    // Function to process the next stock price and return its span
    int next(int price) {
        int span = 1; // Minimum span is 1 (the day itself)

        // Merge consecutive days where stock price <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add previous day's span
            st.pop(); // Remove that day's data (merged into current)
        }

        // Push current day's price and its computed span
        st.emplace(price, span);

        return span; // Return computed span for current day
    }
};

int main() {
    StockSpanner spanner;

    // Sample test prices
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    cout << "Stock Prices: ";
    for (int price : prices) cout << price << " ";
    cout << "\nSpans: ";

    for (int price : prices) {
        cout << spanner.next(price) << " ";
    }

    cout << endl;
    return 0;
}

/*
======================== DRY RUN ========================

Input Prices: [100, 80, 60, 70, 60, 75, 85]

Day 1: Price = 100
  Stack: empty → push (100, 1)
  Output span = 1

Day 2: Price = 80
  Top (100,1) > 80 → stop
  Push (80, 1)
  Output span = 1

Day 3: Price = 60
  Top (80,1) > 60 → stop
  Push (60, 1)
  Output span = 1

Day 4: Price = 70
  Top (60,1) <= 70 → pop, span = 1 + 1 = 2
  Next top (80,1) > 70 → stop
  Push (70, 2)
  Output span = 2

Day 5: Price = 60
  Top (70,2) > 60 → stop
  Push (60, 1)
  Output span = 1

Day 6: Price = 75
  Top (60,1) <= 75 → pop, span = 1 + 1 = 2
  Top (70,2) <= 75 → pop, span = 2 + 2 = 4
  Next top (80,1) > 75 → stop
  Push (75, 4)
  Output span = 4

Day 7: Price = 85
  Top (75,4) <= 85 → pop, span = 1 + 4 = 5
  Top (80,1) <= 85 → pop, span = 5 + 1 = 6
  Next top (100,1) > 85 → stop
  Push (85, 6)
  Output span = 6

Final Output Spans: [1, 1, 1, 2, 1, 4, 6]
==========================================================
*/
