#include <limits.h>
#include "our_model_prev.h"
#include "gtest/gtest.h"

TEST(our_model_prevModelClass, Deneme) {
  EXPECT_EQ(2, halil(1));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}