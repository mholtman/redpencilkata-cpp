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

  TEST(TestRedPencilKata, CompletelyUnrelated) {
    ASSERT_EQ(1 ,1);

  }

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




}
