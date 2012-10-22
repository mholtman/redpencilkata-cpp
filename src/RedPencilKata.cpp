#include <RedPencilKata.h>

#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;

int *priceInCents = new int;
int *modifiedPriceInCents = new int;
date *promoEndDate;
date *promoStartDate;

RedPencilItem::RedPencilItem(int price){
    *priceInCents = price;
    //*priceInCents = price;
    *modifiedPriceInCents = price;
    //*modifiedPriceInCents = price;
    *promoEndDate = date (not_a_date_time);
    *promoStartDate = date (not_a_date_time);

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

date RedPencilItem::GetPromoStartDate() {
  return *promoStartDate;
}

date RedPencilItem::GetPromoEndDate() {
  return *promoEndDate;
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
    *promoStartDate = date(day_clock::local_day());
    date_duration ddThirty(30);
    *promoEndDate = *promoStartDate + ddThirty;

  }
}
