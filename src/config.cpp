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

#include "config.h"

namespace ptmud::config
{
    namespace
    {
        // The actual configuration
        configuration_map_type configuration;

        // Registry of configuration keys, use to set up argument and file parsing
        // and the default values
        std::vector<registry::value> value_registry;
    }

    void init(int argc [[maybe_unused]], char* argv[] [[maybe_unused]])
    {
        // TODO: Call each sub-module to register configuration keys

        // TODO: Set default values for configuration

        // TODO: Parse arguments

        // TODO: Check for "help" and "version" arguments

        // TODO: Check for "config" argument to see what configuration file to load

        // TODO: Load configuration file

        // TODO: Modify configuration according to the remaining arguments
    }

    void cleanup()
    {

    }

    configuration_map_type& get_configuration()
    {
        return configuration;
    }

    bool exist(std::string const& name)
    {
        return configuration.find(name)  != configuration.end();
    }

    namespace registry
    {
        void register_values(std::vector<value> const& values)
        {
            value_registry.insert(end(value_registry), begin(values), end(values));
        }
    }
}
