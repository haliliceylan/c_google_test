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
    copts = [
        "-Isimulink_example/bacteria-simulink/our_model_grt_rtw",
        "-Isimulink_example/R2021b/extern/include",
        "-Isimulink_example/R2021b/rtw/c/src",
        "-Isimulink_example/R2021b/rtw/c/src/ext_mode/common",
        "-Isimulink_example/R2021b/simulink/include"
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "our_model",
    srcs = ["bacteria-simulink/our_model_grt_rtw/our_model.c"],
    copts = [
        "-Isimulink_example/bacteria-simulink/our_model_grt_rtw",
        "-Isimulink_example/R2021b/extern/include",
        "-Isimulink_example/R2021b/rtw/c/src",
        "-Isimulink_example/R2021b/rtw/c/src/ext_mode/common",
        "-Isimulink_example/R2021b/simulink/include"
    ],
    deps = [
        "//simulink_example:simulink_libraries",
    ],
)