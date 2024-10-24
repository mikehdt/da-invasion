#include "config_scenes.h"
#include "scenes/city.h"
#include "scenes/credits.h"
#include "scenes/default.h"
#include "scenes/eye.h"
#include "scenes/fire.h"
#include "scenes/lady.h"
#include "scenes/logo.h"
#include "scenes/plasma.h"
#include "scenes/sineline.h"
#include "scenes/skull.h"
#include "scenes/type.h"

Scenes scenes[MAX_SCENES];

void empty_fn(void) {}

// Idea: can I use a struct that's defined by the effects themselves to simplify this?
// IMPORTANT: All scenes must implement an init, update and end function.
void scenes_init(void)
{
    // Default
    scenes[DEFAULT].init = empty_fn;
    scenes[DEFAULT].update = default_init; // Technically init, but kicks over in update
    scenes[DEFAULT].end = empty_fn;

    scenes[CITY_A].init = city_init;
    scenes[CITY_A].update = city_update;
    scenes[CITY_A].end = city_end;

    scenes[CITY_B].init = city_init;
    scenes[CITY_B].update = city_update;
    scenes[CITY_B].end = city_end;

    scenes[CITY_C].init = city_init;
    scenes[CITY_C].update = city_update;
    scenes[CITY_C].end = city_end;

    scenes[CREDITS_A].init = credits_init;
    scenes[CREDITS_A].update = credits_update;
    scenes[CREDITS_A].end = empty_fn;

    scenes[CREDITS_B].init = credits_init;
    scenes[CREDITS_B].update = credits_update;
    scenes[CREDITS_B].end = empty_fn;

    scenes[CREDITS_C].init = credits_init;
    scenes[CREDITS_C].update = credits_update;
    scenes[CREDITS_C].end = empty_fn;

    scenes[EYE].init = eye_init;
    scenes[EYE].update = eye_update;
    scenes[EYE].end = eye_end;

    scenes[FIRE].init = fire_init;
    scenes[FIRE].update = fire_update;
    scenes[FIRE].end = fire_end;

    scenes[LADY].init = lady_init;
    scenes[LADY].update = lady_update;
    scenes[LADY].end = lady_end;

    scenes[LOGO].init = logo_init;
    scenes[LOGO].update = logo_update;
    scenes[LOGO].end = empty_fn;

    scenes[PLASMA].init = plasma_init;
    scenes[PLASMA].update = plasma_update;
    scenes[PLASMA].end = plasma_end;

    scenes[SINELINE].init = sineline_init;
    scenes[SINELINE].update = sineline_update;
    scenes[SINELINE].end = sineline_end;

    scenes[SKULL].init = skull_init;
    scenes[SKULL].update = skull_update;
    scenes[SKULL].end = skull_end;

    scenes[TYPE].init = type_init;
    scenes[TYPE].update = type_update;
    scenes[TYPE].end = type_end;
}
