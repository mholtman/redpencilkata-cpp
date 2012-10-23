#include "gtest/gtest.h"
#include "../src/RedPencilKata.h"

namespace {

  class TestRedPencilKata : public ::testing::Test{
  protected:
    TestRedPencilKata() {

    }
    virtual ~TestRedPencilKata() {


    }

    virtual void SetUp() {
    
    }

    virtual void TearDown() {

    }
  };

  TEST(RedPencilItem, ConstructorWorks) {
    RedPencilItem i (100);
    ASSERT_EQ(100, i.GetOriginalPrice());
  }

  TEST(RedPencilItem, OriginalPriceShouldEqualModifiedPriceForNewObject){
    RedPencilItem i (100);
    ASSERT_EQ(i.GetOriginalPrice(), i.GetModifiedPrice());
}

  TEST(RedPencilItem, NewlyCreatedItemIsStable) {
    RedPencilItem i (100);
    ASSERT_TRUE(i.IsStable());
  }

  TEST(RedPencilItem, CanChangePriceOnNewItem) {
    RedPencilItem i (100);
    i.ChangePrice(90);
    ASSERT_EQ(90, i.GetModifiedPrice());
  }

  TEST(RedPencilItem, PriceChangeSetsStartAndEndDates){
    RedPencilItem i (100);
    i.ChangePrice(90);
    ASSERT_TRUE(!i.GetPromoStartDate().is_special());
    ASSERT_TRUE(!i.GetPromoEndDate().is_special());
  }

  TEST(RedPencilItem, PriceChangeMustBeMoreThan5Percent){
    RedPencilItem i (10000);
    i.ChangePrice(9900);
    ASSERT_NE(9900, i.GetModifiedPrice());
    i.ChangePrice(9500);
    ASSERT_EQ(9500, i.GetModifiedPrice());
  }

  TEST(RedPencilItem, PriceChangeMustBeLessThan30Percent) {
    RedPencilItem i (10000);
    i.ChangePrice(6999);
    ASSERT_NE(6999, i.GetModifiedPrice());

    RedPencilItem j (10000);
    j.ChangePrice(7000);
    ASSERT_EQ(7000, j.GetModifiedPrice());
  }

  TEST(RedPencilItem, CurrentlyPromotedItemUnstable){
    RedPencilItem i (10000);
    i.ChangePrice(9000);
    ASSERT_FALSE(i.IsStable());
  }

  TEST(RedPencilItem, PriceIncreaseEndsPromotion){
    RedPencilItem i (10000);
    i.ChangePrice(9000);
    ASSERT_EQ(9000, i.GetModifiedPrice());
    ASSERT_TRUE(i.IsBeingPromoted());
    i.ChangePrice(9001);
    ASSERT_FALSE(i.IsBeingPromoted());
    
  }

  TEST(RedPencilItem, IllegalPriceDecreaseEndsPromotion){
    RedPencilItem i (10000);
    i.ChangePrice(9000);
    ASSERT_TRUE(i.IsBeingPromoted());
    i.ChangePrice(6999);
    ASSERT_FALSE(i.IsBeingPromoted());
  }
}
