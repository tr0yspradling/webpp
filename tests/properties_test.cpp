#include "../core/include/webpp/utils/property.hpp"

#include <gtest/gtest.h>
#include <string>

using namespace webpp;
using namespace std;

TEST(PropertiesTest, SimpleUsage) {
    EXPECT_EQ(property(10), 10);
    EXPECT_TRUE(property("hello"s) == "hello"s);
}
