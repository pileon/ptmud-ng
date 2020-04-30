// Copyright 2020 Joachim Pileborg
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>

#include "ptmud-ng.h"

namespace ptmud
{
    namespace
    {
        void init(int argc [[maybe_unused]], char* argv[] [[maybe_unused]])
        {
            // TODO: 1. Configuration defaults
            // TODO: 2. Read configuration file
            // TODO: 3. Parse arguments
            // TODO: 4. Logging setup
            // TODO: 5. Read "database"
            // TODO: 6. Network setup
        }

        void cleanup()
        {
        }
    }

    int main(int argc, char* argv[])
    {
        std::cout << "Hello world!\n";

        // TODO: Initialization
        init(argc, argv);

        // TODO: Enter main loop

        // TODO: Clean up
        cleanup();

        return 0;
    }
}
