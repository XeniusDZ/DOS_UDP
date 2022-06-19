/**#include "doctest.h"
#include "udp.hpp"

TEST_CASE("Correct IP"){
    CHECK(isIPv4("192.168.0.0") == true);
}
TEST_CASE("Incorrect IP"){
    CHECK(isIPv4("1956.10.10.159") == false);
}
TEST_CASE("Incorrect IP"){
    CHECK(isIPv4("lol") == false);
}
TEST_CASE("test winsocket") {
    CHECK(create_winsocket() == 1);
}
TEST_CASE("test socket") {
    CHECK(create_socket() == 1);
}**/