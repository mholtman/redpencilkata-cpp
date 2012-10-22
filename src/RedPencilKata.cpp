#include <RedPencilKata.h>

#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;

RedPencilItem::RedPencilItem(int price){
    priceInCents = new int;
    *priceInCents = price;
    modifiedPriceInCents = new int;
    *modifiedPriceInCents = price;
   *promoEndDate = date (not_a_date_time);
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
  date_duration ddEndPromo(30);
  date stableDate = today + ddEndPromo;
  date_duration stableInterval = stableDate - *promoEndDate;
  
  if (promoEndDate->is_not_a_date())
  {
    return true;
  }
  else if (stableInterval.days() >= 30)
  {
    return true;
  }
  
  return false;
  
 
}
 
void RedPencilItem::ChangePrice(int newPrice) {
  if(IsStable())
  {
    *modifiedPriceInCents = newPrice;

  }
}
