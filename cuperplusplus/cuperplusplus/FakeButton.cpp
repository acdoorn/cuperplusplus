#include "stdafx.h"
#include "FakeButton.h"
#include "Player.h"

static const char * discoveredTrapString = "You find a button that says free cake and decide to look what it leads to before you press it. You find out it was a trap and that the cake was a lie.";
static const char * trapString = "You see a button that says free cake and immedietly press it, suddenly you smell a weird scent. You wake up with a slight headache and blurred sight. AttackPower-2";


FakeButton::FakeButton()
{
	dismantled = false;
	discoverChance = 80;
}


FakeButton::~FakeButton()
{
}

void FakeButton::activate(Player * p)
{
	if (!dismantled) {
		p->increasePwr(-2);
		dismantled = true;
	}
}

const char * FakeButton::getText()
{
	if (discoverTrap()) {
		return discoveredTrapString;
	}
	else {
		return trapString;
	}
}
