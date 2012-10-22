#include "boost/date_time/posix_time/posix_time.hpp"

class RedPencilItem {
  int *priceInCents;
  int *modifiedPriceInCents;
public:
  RedPencilItem(int);
  ~RedPencilItem();
  int GetOriginalPrice();
  int GetModifiedPrice();
  bool IsStable();
};
