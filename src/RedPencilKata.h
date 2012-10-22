#ifndef REDPENCILKATA_H
#define REDPENCILKATA_H

#include "boost/date_time/posix_time/posix_time.hpp"
using namespace boost::posix_time;
using namespace boost::gregorian;

class RedPencilItem {
 private:
  int priceInCents;
  int modifiedPriceInCents;
  date promoEndDate;
  date promoStartDate;
  bool MinPercentageHonored(int);
  bool MaxPercentageHonored(int);
 public:
  RedPencilItem(int);
  ~RedPencilItem();
  int GetOriginalPrice();
  int GetModifiedPrice();
  date GetPromoStartDate();
  date GetPromoEndDate();
  bool IsStable();
  void ChangePrice(int);
};

#endif
