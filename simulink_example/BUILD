COPTS = [
    "-Isimulink_example/our_model_prev_grt_rtw",
    "-Isimulink_example/MATLAB_R2021a.app/extern/include",
    "-Isimulink_example/MATLAB_R2021a.app/rtw/c/src",
    "-Isimulink_example/MATLAB_R2021a.app/rtw/c/src/ext_mode/common",
    "-Isimulink_example/MATLAB_R2021a.app/simulink/include"
]

cc_library(
    name = "simulink_libraries",
    srcs = glob(
        [
            "MATLAB_R2021a.app/**/*.c",
            #"MATLAB_R2021a.app/**/*.cpp",
            "our_model_prev_grt_rtw/**/*.c",
            "our_model_prev_grt_rtw/**/*.cpp"
        ],
    ),
    hdrs = glob([
        "MATLAB_R2021a.app/**/*.h","our_model_prev_grt_rtw/**/*.h"
    ]),
    linkopts = ["-pthread"],
    defines = [
        "MODEL=our_model_prev","NUMST=2","NCSTATES=1","HAVESTDIO","RT","USE_RTMODEL","CLASSIC_INTERFACE=0","ALLOCATIONFCN=0","TID01EQ=1","MAT_FILE=1","ONESTEPFCN=1","TERMFCN=1","MULTI_INSTANCE_CODE=1","INTEGER_CODE=0","MT=0"
    ],
    copts = COPTS,
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "our_model",
    srcs = [
        "MATLAB_R2021a.app/rtw/c/src/common/rt_cppclass_main.cpp",
        "our_model_prev_grt_rtw/our_model_prev.cpp"
    ],

    copts = COPTS,
    deps = [
        "//simulink_example:simulink_libraries",
    ],
)

cc_test(
  name = "our_model_test",
  size = "small",
  srcs = ["test/halil_function_test.cpp"],
  copts = COPTS,
  deps = ["@com_google_googletest//:gtest_main", "//simulink_example:simulink_libraries"],
)