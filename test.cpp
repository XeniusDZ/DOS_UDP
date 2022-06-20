#include "doctest.h"
#include "udp.h"

TEST_CASE("Correct IP"){
    REQUIRE(isIPv4("192.168.0.0") == true);
}
TEST_CASE("Incorrect IP"){
    REQUIRE(isIPv4("1956.10.10.159") == false);
}
TEST_CASE("Incorrect IP"){
    REQUIRE(isIPv4("lol") == false);
}
TEST_CASE("test winsocket") {
    REQUIRE(create_winsocket() == 1);
}