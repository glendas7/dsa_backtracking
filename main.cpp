//Glenda Salas

#include <algorithm>
#include <iostream>
#include <limits>
#include "Boat.h"
#include <vector>

using namespace std;

void maximize_payment(Boat, int);
bool desc_value(const Item &, const Item &);
void print_result(Boat);
void remove_zeros(Boat);

int main()
{
   Item item;
   int qty, capacity, weight, value;

   cout << "Please enter the maximum weight capacity of your boat:  ";
   cin >> capacity;

   cout << "Please enter the number of valuable items that you have:  ";
   cin >> qty;

   Boat boat(qty, capacity, 0);

   for (int i = 0; i < qty; i++)
   {
      cout << "\nPlease enter the weight of item #" << i + 1 << ": ";
      cin >> weight;
      cout << "Please enter the value of item $" << i + 1 << ": ";
      cin >> value;

      item = {weight, value, 0, i + 1};
      boat.add_item(item);
      cout << item.quantity << "\n";
   }

   sort(boat.inventory.begin(), boat.inventory.end(), desc_value);
   int min_weight = boat.inventory[0].weight;

   for (int i = 1; i < boat.inventory.size(); i++)
   {
      if (boat.inventory[i].weight < min_weight)
      {
         min_weight = boat.inventory[i].weight;
      }
   }
   maximize_payment(boat, min_weight);
}

//sort by desc value
bool desc_value(const Item &a, const Item &b)
{
   if (a.value == b.value)
   {
      if (a.weight < b.weight)
      {
         return b.weight > a.value;
      }
   }
   else
   {
      return a.value > b.value;
   }
}

void maximize_payment(Boat b, int min_weight)
{
   int weight, capacity, unique_items, diff;
   weight = b.get_current_weight();
   capacity = b.get_capacity();
   unique_items = b.get_unique_qty();
   diff = capacity - weight;

   if (weight <= capacity && diff < min_weight)
   {
      cout << "\nMaximized our Payment to its Fullest Potential! " << weight << "\n";
      remove_zeros(b);
      return;
   }
   for (int i = 0; i < b.get_unique_qty(); i++)
   {
      if ((weight + b.inventory[i].weight) <= capacity)
      {
         b.increase_weight(b.inventory[i].weight);
         b.increase_total_value(b.inventory[i].value);
         b.inventory[i].quantity++;
         maximize_payment(b, min_weight);
         return;
      }
   }
}

void remove_zeros(Boat b)
{
   for (int i = 0; i < b.inventory.size(); i++)
   {
      if (b.inventory[i].quantity == 0)
      {
         b.inventory.erase(b.inventory.begin() + i);
         remove_zeros(b);
      }
   }
   cout << "test 1\n";
   print_result(b);
   return;
}

void print_result(Boat b)
{
   cout << "***The Solution Contains***\n";
   for (int i = 0; i < b.inventory.size(); i++)
   {
      cout << b.inventory[i].quantity << " of Item " << b.inventory[i].num_id << "\n";
   }

   cout << "Total Weight: ";
   for (int i = 0; i < b.inventory.size(); i++)
   {
      cout << b.inventory[i].quantity << " * " << b.inventory[i].weight << " ";
      if (i == b.inventory.size() - 1)
         cout << " = " << b.get_current_weight() << "\n";
      else
         cout << " + ";
   }

   cout << "Total Value: ";
   for (int i = 0; i < b.inventory.size(); i++)
   {
      cout << b.inventory[i].quantity << " * " << b.inventory[i].value << " ";
      if (i == b.inventory.size() - 1)
         cout << " = " << b.get_total_value() << "\n";
   }
   return;
}