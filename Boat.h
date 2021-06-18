#include <iostream>
#include <vector>

using namespace std;

struct Item
{
   int weight;
   int value;
   int quantity;
   int num_id;
};

class Boat
{
public:
   vector<Item> inventory;
   Boat(int valuable_item_qty, int boat_item_capacity, int starting_weight);
   Boat();
   const int get_capacity();
   const int get_unique_qty();
   void add_item(Item);
   const int get_current_weight();
   const int get_total_value();
   void increase_weight(int);
   void increase_total_value(int);

private:
   int capacity;
   int unique_qty;
   int current_weight;
   int total_value;
};