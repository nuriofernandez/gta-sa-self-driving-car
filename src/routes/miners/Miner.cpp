#pragma once

#include "../../drivers/Checkpoint.cpp"

namespace Miner {

    namespace Checkpoints {

        static Checkpoint *DELIVERY_POINT = new Checkpoint(-550, 2337);
        static Checkpoint *START_RAMP = new Checkpoint(-565, 2338);

        static Checkpoint *OUTSIDE_PATH_RAMP_CORNER = new Checkpoint(-587, 2339);
        static Checkpoint *OUTSIDE_PATH_DOOR_BRIDGE = new Checkpoint(-597, 2331);
        static Checkpoint *OUTSIDE_PATH_DOOR_CORNER = new Checkpoint(-605, 2330);

        static Checkpoint *ENTER_DOOR = new Checkpoint(-611, 2325);
        static Checkpoint *EXIT_DOOR = new Checkpoint(-718, 2462);

        static Checkpoint *RAIL_END = new Checkpoint(-717, 2424);
        static Checkpoint *RAIL_MID = new Checkpoint(-717, 2443);

        static Checkpoint *IRON_STONE = new Checkpoint(-740, 2392);
        static Checkpoint *IRON_PATH_MID = new Checkpoint(-726, 2408);

        static Checkpoint *COPPER_STONE = new Checkpoint(-744, 2410);
        static Checkpoint *COPPER_PATH = new Checkpoint(-726, 2418);

        static Checkpoint *TITANIUM_STONE = new Checkpoint(-729, 2409);
        static Checkpoint *TITANIUM_PATH = new Checkpoint(-723, 2410);

        static Checkpoint *MERCURY_STONE = new Checkpoint(-728, 2421);

    }

}