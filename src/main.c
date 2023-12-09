#include "config_scenes.h"
#include "engine/console_init.h"
#include "engine/scenes.h"
#include "libs/SMSlib.h"
#include <stdbool.h>
#include <stdint.h>

void check_keys(void)
{
    if (SMS_getKeysHeld() & PORT_A_KEY_1)
    {
        // "Debounce" the button press as it were... this is a bit hacky
        while (SMS_getKeysHeld() != 0x0000)
            SMS_waitForVBlank();

        next_scene();
    }
}

void main(void)
{
    // The pause and reset buttons are given over to our code to handle however
    // we see fit. From what I understand, the pause button triggers an
    // interrupt, but reset is detected via a bitmask of keys currently pressed.
    uint16_t keys_pressed;

    while (true)
    {
        console_init();
        scenes_init();

        do
        {
            keys_pressed = SMS_getKeysPressed();

            check_keys();
            update_scene();
        } while (~(keys_pressed & RESET_KEY));
    }
}

// Maybe add back if feeling fancy
// if (SMS_queryPauseRequested())
// {
//     SMS_resetPauseRequest();
//     global_pause = !global_pause;

//     if (global_pause)
//         continue;
// }

// Stop VScode from fussing about these function calls
#ifndef __INTELLISENSE__
SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
SMS_EMBED_SDSC_HEADER_AUTO_DATE(1, 0, "Mike Hopkins", "SMS Demo",
                                "Mucking about with the Master System");
#endif
