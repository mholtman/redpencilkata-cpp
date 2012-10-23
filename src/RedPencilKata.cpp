#include <RedPencilKata.h>

#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;



RedPencilItem::RedPencilItem(int price){
    priceInCents = price;
    modifiedPriceInCents = price;
    promoEndDate = date (not_a_date_time);
    promoStartDate = date (not_a_date_time);

}

RedPencilItem::~RedPencilItem(){
 
}

int RedPencilItem::GetOriginalPrice() {
  return priceInCents;
}

int RedPencilItem::GetModifiedPrice() {
  return modifiedPriceInCents;
}

date RedPencilItem::GetPromoStartDate() {
  return promoStartDate;
}

date RedPencilItem::GetPromoEndDate() {
  return promoEndDate;
}

bool RedPencilItem::IsStable() {
  using namespace boost::posix_time;
  using namespace boost::gregorian;

  ptime now = second_clock::local_time();
  date today = now.date();
  date_duration ddEndPromo(30);
  date stableDate = today + ddEndPromo;
  date_duration stableInterval = stableDate - promoEndDate;
  
  if (promoEndDate.is_not_a_date())
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
  if(IsStable() && maxPercentageHonored(newPrice) && minPercentageHonored(newPrice) )
  {
    modifiedPriceInCents = newPrice;
    promoStartDate = date(day_clock::local_day());
    date_duration ddThirty(30);
    promoEndDate = promoStartDate + ddThirty;

  } else if (IsBeingPromoted()) {
    if (newPrice > modifiedPriceInCents || !maxPercentageHonored(newPrice))
      {
	promoEndDate = date(day_clock::local_day());
	modifiedPriceInCents = priceInCents;
      }
  }
}

bool RedPencilItem::minPercentageHonored(int newPrice) {
  double tempPrice = priceInCents  * 0.95;

  return newPrice <= tempPrice;

}

bool RedPencilItem::maxPercentageHonored(int newPrice) {
  double tempPrice = priceInCents * 0.70;

  return newPrice >= tempPrice;
}

bool RedPencilItem::IsBeingPromoted(){
  return modifiedPriceInCents !=  priceInCents;

}
