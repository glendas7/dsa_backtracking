//Glenda Salas

#include <algorithm>
#include <iostream>
#include <limits>
#include "Boat.h"
#include <vector>

using namespace std;

void maximize_payment(Boat);
bool desc_value(const Item &, const Item &);

int main(){
   Item item;
   int qty, capacity, weight, value;

   cout << "Please enter the maximum weight capacity of your boat:  ";
   cin >> capacity;

   cout <<"Please enter the number of valuable items that you have:  ";
   cin >> qty;

   Boat boat(qty, capacity, 0);

//print for testing
   for (int i = 0; i < qty; i++){
      cout << "\nPlease enter the weight of item " << i << endl;
      cin >> weight;
      cout << "Please enter the value of item " << i << endl;
      cin >> value;

      item = {weight, value, 0};
      boat.add_item(item);
   }
   sort(boat.inventory.begin(), boat.inventory.end(), desc_value);
   cout << "Sorted\n\n";
   for (int i = 0; i < qty; i++){
      cout << "weight : " << boat.inventory[i].weight << "\n";
   }

      maximize_payment(boat);
}

//sort by desc value
bool desc_value(const Item &a, const Item &b){
   if(a.value == b.value){
      if(a.weight > b.weight){
         return b.weight > a.value;
      }
   }
   else{
      return a.value > b.value;
   }
}

void maximize_payment(Boat b) {
      int weight, capacity, unique_items, diff;
      weight = b.get_weight();
      capacity = b.get_capacity();
      unique_items = b.get_unique_qty();
      diff = capacity - weight;

      if (weight <= capacity && diff < b.inventory[unique_items - 1].weight){
         cout << "\nMaximized our Payment to its Fullest Potential! " << weight << "\n";
      for (int i = 0; i < b.get_unique_qty(); i++){
         cout << "Weight: " << b.inventory[i].weight << " Value: " << b.inventory[i].value << " Qty: " << b.inventory[i].quantity << "\n";
      }
         return;
      }
      for (int i = 0; i < b.get_unique_qty(); i++){
         if((weight + b.inventory[i].weight) <= capacity){
            b.increase_weight(b.inventory[i].weight);
            b.inventory[i].quantity++;
            cout << "Total Weight: " << weight << " \n";
            cout << "Weight: " << b.inventory[i].weight << " Value: " << b.inventory[i].value << " Qty: " << b.inventory[i].quantity << "\n";
            maximize_payment(b);
            return;
         }
      }
}
