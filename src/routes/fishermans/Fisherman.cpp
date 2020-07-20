#pragma once

#include "../../drivers/Checkpoint.cpp"

namespace Fisherman {

    namespace Checkpoints {

        static Checkpoint *DELIVERY_POINT = new Checkpoint(2793, -2599);
        static Checkpoint *DOCK_EXIT = new Checkpoint(2775, -2702);
        static Checkpoint *OCEAN_DOCS_CORNER = new Checkpoint(2417, -2859);
        static Checkpoint *AIRPORT_CORNER = new Checkpoint(0, 0);
        static Checkpoint *BEACH_CORNER = new Checkpoint(1267, -2911);

        static Checkpoint *VERONA_BEACH_LIGHTHOUSE = new Checkpoint(101, -1979);

        static Checkpoint *DOLPHIN_REORIENTATION_POINT = new Checkpoint(36, -1766);
        static Checkpoint *DOLPHIN_POINT = new Checkpoint(36, -1710);

        static Checkpoint *TURTLE_REORIENTATION_POINT = new Checkpoint(980, -2820);
        static Checkpoint *TURTLE_POINT = new Checkpoint(945, -2820);

    }

}
