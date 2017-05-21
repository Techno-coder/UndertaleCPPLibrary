#include "../catch.hpp"
#include <encounter/components/FightBar.h>

TEST_CASE("FightBar component remains in valid state", "[fightBar]") {
	SECTION("Calling hit function even after no more target lines left") {
		ug::FightBar fightBar(1, false);
		fightBar.update(20.0f);
		REQUIRE(!std::isnan(fightBar.hit(true)));
		REQUIRE(std::isnan(fightBar.hit(true)));
	}

	SECTION("Starting a target line even after no more left") {
		ug::FightBar fightBar(1, false);
		fightBar.startNextTargetLine();
		REQUIRE_NOTHROW(fightBar.startNextTargetLine());
	}

	SECTION("Updating a line past the end of the bar should pop line") {
		ug::FightBar fightBar(1, false);
		fightBar.startNextTargetLine();
		fightBar.update(1000.0f);
		REQUIRE(std::isnan(fightBar.hit(false)));
	}

	SECTION("Updating a line past the end of the bar should not create invalid state") {
		ug::FightBar fightBar(1, false);
		fightBar.startNextTargetLine();
		fightBar.update(1000.0f);
		REQUIRE_NOTHROW(fightBar.hit(true));
		REQUIRE_NOTHROW(fightBar.startNextTargetLine());
	}

	SECTION("Updating with no lines moving") {
		ug::FightBar fightBar(3, false);
		REQUIRE_NOTHROW(fightBar.update(30.0f));
	}

	SECTION("Example usage should not fail") {
		ug::FightBar fightBar(3, false);
		REQUIRE_NOTHROW(fightBar.startNextTargetLine());
		REQUIRE_NOTHROW(fightBar.update(100.0f));
		REQUIRE_NOTHROW(fightBar.startNextTargetLine());
		REQUIRE_NOTHROW(fightBar.update(50.0f));
		REQUIRE_NOTHROW(fightBar.hit(true));
		REQUIRE_NOTHROW(fightBar.update(50.0f));
		REQUIRE_NOTHROW(fightBar.hit(true));
		REQUIRE_NOTHROW(fightBar.startNextTargetLine());
		REQUIRE_NOTHROW(fightBar.update(100.0f));
		REQUIRE_NOTHROW(fightBar.hit(true));
		REQUIRE(std::isnan(fightBar.hit(true)));
	}

	SECTION("Second example usage should not fail") {
		ug::FightBar fightBar(3, false);
		REQUIRE_NOTHROW(fightBar.hit(true));
		REQUIRE_NOTHROW(fightBar.hit(true));
		REQUIRE_NOTHROW(fightBar.hit(true));
		REQUIRE(std::isnan(fightBar.hit(false)));
		REQUIRE_NOTHROW(fightBar.update(1000.0f));
	}
}
