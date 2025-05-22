#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "services/lead_service.hpp"

TEST_CASE("Add and list leads") {
    REQUIRE_NOTHROW(add_lead("John Doe", "john@example.com", "web"));
    REQUIRE_NOTHROW(add_lead("Jane Roe", "jane@example.com", "ads"));
    auto leads = fetch_all_leads();
    REQUIRE(leads.size() >= 2);
}

TEST_CASE("Duplicate email handling") {
    add_lead("User One", "duplicate@example.com", "form");
    REQUIRE_THROWS(add_lead("User Two", "duplicate@example.com", "form"));
}
