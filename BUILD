SIMULINK_COPS = [
    "-Isimulink_example/bacteria-simulink/our_model_grt_rtw",
    "-Isimulink_example/R2021b/extern/include",
    "-Isimulink_example/R2021b/rtw/c/src",
    "-Isimulink_example/R2021b/rtw/c/src/ext_mode/common",
    "-Isimulink_example/R2021b/simulink/include",
]

cc_library(
    name = "simulink_libraries",
    srcs = glob(
        ["simulink_example/**/*.c"],
    ),
    hdrs = glob([
        "simulink_example/**/*.h",
    ]),
    linkopts = ["-pthread"],
    defines = [
        "MODEL=our_model", "NUMST=2", "NCSTATES=1", "HAVESTDIO", "RT", "USE_RTMODEL","CLASSIC_INTERFACE=0", "ALLOCATIONFCN=0", "MAT_FILE=1", "ONESTEPFCN=1", "TERMFCN=1", "MULTI_INSTANCE_CODE=0", "INTEGER_CODE=0", "MT=0", "TID01EQ=1"
    ],
    copts = SIMULINK_COPS,
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "our_model",
    srcs = ["our_model.c"],
    copts = SIMULINK_COPS,
    deps = [
        ":simulink_libraries",
    ],
)

cc_test(
  name = "our_model_unittest",
  size = "small",
  srcs = ["our_model_unittest.cc"],
  copts = SIMULINK_COPS,
  deps = ["@com_google_googletest//:gtest_main", ":our_model"],
)

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