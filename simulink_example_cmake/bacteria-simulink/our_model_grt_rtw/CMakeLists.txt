######################################################################
# CMakeLists.txt generated for component our_model
# Product type: executable
######################################################################
cmake_minimum_required(VERSION 3.12)
project(our_model)
enable_testing()


######################################################################
## Path variables
######################################################################
get_filename_component(START_DIR .. ABSOLUTE)
set(MATLAB_ROOT /workspaces/c_google_test/simulink_example_cmake/R2021b CACHE PATH "Root of MATLAB installation")

######################################################################
## Target definition and commands
######################################################################
add_executable(our_model  ${MATLAB_ROOT}/rtw/c/src/rt_logging.c ${START_DIR}/our_model_grt_rtw/our_model.cpp ${START_DIR}/our_model_grt_rtw/our_model_data.cpp ${START_DIR}/our_model_grt_rtw/rtGetInf.cpp ${START_DIR}/our_model_grt_rtw/rtGetNaN.cpp ${START_DIR}/our_model_grt_rtw/rt_nonfinite.cpp ${MATLAB_ROOT}/rtw/c/src/common/rt_cppclass_main.cpp)
set_target_properties(our_model PROPERTIES PREFIX "" RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../$<0:>" LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../$<0:>" ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../$<0:>" POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(our_model PRIVATE -DMODEL=our_model -DNUMST=2 -DNCSTATES=1 -DHAVESTDIO -DRT -DUSE_RTMODEL -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=1 -DMAT_FILE=1 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=1 -DINTEGER_CODE=0 -DMT=0)
target_include_directories(our_model PRIVATE ${START_DIR} ${START_DIR}/our_model_grt_rtw ${MATLAB_ROOT}/extern/include ${MATLAB_ROOT}/simulink/include ${MATLAB_ROOT}/rtw/c/src ${MATLAB_ROOT}/rtw/c/src/ext_mode/common)
if(NOT MSVC)
   target_link_libraries(our_model PRIVATE m)
endif()


######################################################################
## Tests
######################################################################
set(TEST_SRC
   "/workspaces/c_google_test/simulink_example_cmake/bacteria-simulink/test/halil_function_test.cpp"
)

add_library(gtest ${GTEST_DIR}/gmock-gtest-all.cc ${GTEST_DIR}/main.cc)
target_include_directories(gtest PUBLIC ${GTEST_DIR})
target_link_libraries(gtest pthread)

add_executable(rl_test ${TEST_SRC} ${SRC} ${MATLAB_ROOT}/rtw/c/src/rt_logging.c ${START_DIR}/our_model_grt_rtw/our_model.cpp ${START_DIR}/our_model_grt_rtw/our_model_data.cpp ${START_DIR}/our_model_grt_rtw/rtGetInf.cpp ${START_DIR}/our_model_grt_rtw/rtGetNaN.cpp ${START_DIR}/our_model_grt_rtw/rt_nonfinite.cpp)
add_test(rl_test rl_test)
target_link_libraries(rl_test gtest m)
target_compile_options(rl_test PRIVATE "-std=c++14" "-O3")
target_compile_definitions(rl_test PRIVATE -DMODEL=our_model -DNUMST=2 -DNCSTATES=1 -DHAVESTDIO -DRT -DUSE_RTMODEL -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=1 -DMAT_FILE=1 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=1 -DINTEGER_CODE=0 -DMT=0)
target_include_directories(rl_test PRIVATE ${START_DIR} ${START_DIR}/our_model_grt_rtw ${MATLAB_ROOT}/extern/include ${MATLAB_ROOT}/simulink/include ${MATLAB_ROOT}/rtw/c/src ${MATLAB_ROOT}/rtw/c/src/ext_mode/common)


######################################################################
## Build success message
######################################################################
add_custom_command(TARGET our_model POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:our_model>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
   toolchain_target_hook(our_model)
endif()
