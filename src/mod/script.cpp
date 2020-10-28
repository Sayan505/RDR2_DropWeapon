#include "../../inc/script.h"

#include "../../inc/keyboard.h"


#define KEY 0x47	//G

void mod_entry(void) {
	if (IsKeyJustUp(KEY)) {
		char wp_melee[15] = "WEAPON_UNARMED";

		Ped player = PLAYER::PLAYER_PED_ID();
		Hash unarmed = GAMEPLAY::GET_HASH_KEY(wp_melee);
		Hash cur;

		if (WEAPON::GET_CURRENT_PED_WEAPON(player, &cur, 0, 0, 0) && WEAPON::IS_WEAPON_VALID(cur) && cur != unarmed)
			WEAPON::SET_PED_DROPS_INVENTORY_WEAPON(player, cur, 0.0, 0.0, 0.0, 1);
	}
}

void start_script(void) {
	while (true) {
		mod_entry();

		WAIT(0);
	}
}

void ScriptMain(void) {
	srand(GetTickCount());

	start_script();
}