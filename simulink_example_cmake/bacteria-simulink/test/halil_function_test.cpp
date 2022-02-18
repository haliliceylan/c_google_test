#include <limits.h>
#include <our_model.h>
#include "gtest/gtest.h"

TEST(our_model_prevModelClass, halil_function_test) {
  EXPECT_EQ(2, halil(1));
}

TEST(our_model_prevModelClass, halil_function_test_a) {
  EXPECT_EQ(6, halil(4));
}