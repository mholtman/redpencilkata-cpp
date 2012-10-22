#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;

class RedPencilItem {

  using namespace boost::posix_time;
  using namespace boost::gregorian;
  int *priceInCents;
  int *modifiedPriceInCents;
  date *promoEndDate;
public:
  RedPencilItem(int);
  ~RedPencilItem();
  int GetOriginalPrice();
  int GetModifiedPrice();
  bool IsStable();
};
