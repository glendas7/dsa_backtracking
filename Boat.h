#include <iostream>
#include <vector>

using namespace std;

struct Item{
   int weight;
   int value;
   int quantity;
};

class Boat{
public:
   vector<Item> inventory;
   Boat(int valuable_item_qty, int boat_item_capacity, int starting_weight);
   Boat();
   const int get_capacity();
   const int get_unique_qty();
   void add_item(Item);
   const int get_weight();
   void increase_weight(int);

private:
   int capacity;
   int unique_qty;
   int current_weight;
};