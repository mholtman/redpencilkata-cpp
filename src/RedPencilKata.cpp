#include <RedPencilKata.h>

#include "boost/date_time/posix_time/posix_time.hpp"

RedPencilItem::RedPencilItem(int price){
    priceInCents = new int;
    *priceInCents = price;
    modifiedPriceInCents = new int;
    *modifiedPriceInCents = price;
}

RedPencilItem::~RedPencilItem(){
  delete priceInCents; 
  delete modifiedPriceInCents;
}

int RedPencilItem::GetOriginalPrice() {
  return *priceInCents;
}

int RedPencilItem::GetModifiedPrice() {
  return *modifiedPriceInCents;
}

bool RedPencilItem::IsStable() {
  using namespace boost::posix_time;
  using namespace boost::gregorian;

  ptime now = second_clock::local_time();
  date today = now.date();
  
  
 return true;
}
