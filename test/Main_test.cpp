// This can be done in any of the test files but then we will have multiple executables
// in one Eclipse project which is impossible in a non-makefile project

// See http://www.boost.org/doc/libs/1_68_0/libs/test/doc/html/boost_test/adv_scenarios/shared_lib_customizations/entry_point.html
#define BOOST_TEST_MODULE MatrixTestModule
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN

#include <boost/test/unit_test.hpp>

int main(int argc, char **argv) {
  // @suppress("Symbol is not resolved") // @suppress("Invalid arguments")
  return boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}
