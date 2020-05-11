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
#include "config.h"

namespace ptmud
{
    namespace
    {
        void init(int argc, char* argv[])
        {
            config::init(argc, argv);

            // TODO: 1. Logging setup
            // TODO: 2. Read "database"
            // TODO: 3. Network setup
        }

        void cleanup()
        {
            config::cleanup();
        }
    }

    int main(int argc, char* argv[])
    {
        std::cout << "Hello world!\n";

        using config::registry::make_argument_option;
        std::vector<config::registry::option> options = {
            make_argument_option("o1.option1", "long-option-1", 's', "the first option", "default value 1"),
            make_argument_option("o1.option2", 'x', "the first option", "default value 2"),
            make_argument_option("o2.option3", "long-option-3", "the third option"),
            make_argument_option("option4", "long-option-4", '4', "the fourth option")
        };

        config::registry::register_values(options);

        init(argc, argv);

        if (config::exist("foo"))
        {
            std::cout << "\"foo\" exists!\n";
        }
        else
        {
            std::cout << "\"foo\" doesn't exist yet\n";
        }

        config::get<std::string>("foo") = "bar";

        if (config::exist("foo"))
        {
            std::cout << R"("foo" exists and have the value ")" << config::get<std::string>("foo") << "\"\n";
        }
        else
        {
            std::cout << "\"foo\" doesn't exist!\n";
        }




        // TODO: Enter main loop

        cleanup();

#if defined(CLION_IDE)
        {
            std::cout << std::endl << "Press Enter to continue... ";
            std::string line;
            std::getline(std::cin, line);
        }
#endif

        return 0;
    }
}
