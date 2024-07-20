# CMake generated Testfile for 
# Source directory: /home/matin/Videos/gtest-cmake-example
# Build directory: /home/matin/Videos/gtest-cmake-example/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(that-test-I-made "/home/matin/Videos/gtest-cmake-example/build/runUnitTests")
set_tests_properties(that-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "/home/matin/Videos/gtest-cmake-example/CMakeLists.txt;73;add_test;/home/matin/Videos/gtest-cmake-example/CMakeLists.txt;0;")
add_test(that-other-test-I-made "runUnitTests")
set_tests_properties(that-other-test-I-made PROPERTIES  _BACKTRACE_TRIPLES "/home/matin/Videos/gtest-cmake-example/CMakeLists.txt;77;add_test;/home/matin/Videos/gtest-cmake-example/CMakeLists.txt;0;")
subdirs("lib/gtest-1.6.0")
