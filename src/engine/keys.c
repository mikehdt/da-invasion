#include "keys.h"
#include "../engine/global_variables.h"
#include "../libs/SMSlib.h"
#include "../scenes/_scenes.h"
#include "scenes.h"
#include <stdint.h>

void check_keys(void)
{
    if (SMS_getKeysHeld() & PORT_A_KEY_1)
    {
        uint8_t next_scene;

        // "Debounce" the button press as it were... this is a bit hacky
        while (SMS_getKeysHeld() != 0x0000)
            SMS_waitForVBlank();

        next_scene = current_scene + 1;

        if (next_scene >= MAX_SCENES)
            transition_to_scene(1);
        else
            transition_to_scene(next_scene);
    }
}
