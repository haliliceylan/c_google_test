COPTS = [
    "-Isimulink_example/bacteria-simulink/our_model_grt_rtw",
    "-Isimulink_example/R2021b/extern/include",
    "-Isimulink_example/R2021b/rtw/c/src",
    "-Isimulink_example/R2021b/rtw/c/src/ext_mode/common",
    "-Isimulink_example/R2021b/simulink/include"
]
cc_library(
    name = "simulink_libraries",
    srcs = glob(
        ["**/*.c"],
    ),
    hdrs = glob([
        "**/*.h",
    ]),
    linkopts = ["-pthread"],
    defines = [
        "MODEL=our_model", "NUMST=2", "NCSTATES=1", "HAVESTDIO", "RT", "USE_RTMODEL","CLASSIC_INTERFACE=0", "ALLOCATIONFCN=0", "MAT_FILE=1", "ONESTEPFCN=1", "TERMFCN=1", "MULTI_INSTANCE_CODE=0", "INTEGER_CODE=0", "MT=0", "TID01EQ=1"
    ],
    copts = COPTS,
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "our_model",
    srcs = ["bacteria-simulink/our_model_grt_rtw/our_model.c"],
    copts = COPTS,
    deps = [
        "//simulink_example:simulink_libraries",
    ],
)

cc_test(
  name = "our_model_unittest",
  size = "small",
  srcs = ["bacteria-simulink/our_model_grt_rtw/our_model_unittest.cc"],
  copts = COPTS,
  deps = ["@com_google_googletest//:gtest_main", "//simulink_example:our_model"],
)