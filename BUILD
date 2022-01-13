cc_library(
    name = "sample1",
    srcs = ["sample1.cc"],
    hdrs = ["sample1.h"],
)

cc_test(
  name = "sample1_unittest",
  size = "small",
  srcs = ["sample1_unittest.cc"],
  deps = ["@com_google_googletest//:gtest_main", ":sample1"],
)