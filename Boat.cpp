#include <iostream>
#include <limits>
#include "Boat.h"

using namespace std;

Boat::Boat(int valuable_item_qty, int boat_item_capacity, int starting_weight)
{
   unique_qty = valuable_item_qty;
   capacity = boat_item_capacity;
   current_weight = starting_weight;
}

Boat::Boat()
{
}

const int Boat::get_capacity()
{
   return capacity;
}

const int Boat::get_unique_qty()
{
   return unique_qty;
}

const int Boat::get_current_weight()
{
   return current_weight;
}

const int Boat::get_total_value()
{
   return total_value;
}

void Boat::increase_weight(int amt)
{
   current_weight += amt;
}

void Boat::increase_total_value(int amt)
{
   total_value += amt;
}

void Boat::add_item(Item newItem)
{
   inventory.push_back(newItem);
}