#include <limits.h>
#include "our_model_prev.h"
#include "gtest/gtest.h"

TEST(our_model_prevModelClass, halil_function_test) {
  EXPECT_EQ(2, halil(1));
}