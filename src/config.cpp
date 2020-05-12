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

#include <iostream>
#include <string>
#include <unordered_map>
#include <boost/program_options.hpp>

namespace
{
    // This function is called to register all sub-modules options.
    //
    // If a new sub-module is added that requires options, then a call
    // to that sub-module should be added.
    //
    // TODO: Add documentation for this function
    void register_options()
    {
        // TODO: log::register_options();
        // TODO: net::register_options();
    }
}

// //////////////////////////////////////////////////////////////////
// Below here no code should need to be modified

namespace ptmud::config
{
    namespace
    {
        namespace po = boost::program_options;

        // The actual run-time configuration map
        configuration_map_type configuration;

        // Registry of configuration options, used to set up argument,
        // configuration file parsing and the default values
        std::vector<registry::option> value_registry;

        void set_default_values()
        {
            for (auto const& option : value_registry)
            {
                if (!option.name.empty() && !option.default_value.empty())
                {
                    configuration.emplace(option.name, option.default_value);
                }
            }
        }

        void add_option_to_descr(po::options_description& descr, registry::option const& opt)
        {
            // TODO: Need a way to map back from the description to the option (or at least the name)

            std::string option;

            if (!opt.long_option.empty())
            {
                option = opt.long_option;
            }

            if (opt.short_option != 0)
            {
                option += ',';
                option += opt.short_option;
            }

            if (opt.is_switch)
            {
                if (opt.default_value.empty())
                {
                    descr.add_options()(option.c_str(), po::bool_switch(), opt.info_text.c_str());
                }
                else
                {
                    descr.add_options()(option.c_str(), po::bool_switch()->default_value(true), opt.info_text.c_str());
                }
            }
            else
            {
                if (opt.default_value.empty())
                {
                    descr.add_options()(option.c_str(), po::value<std::string>(), opt.info_text.c_str());
                }
                else
                {
                    descr.add_options()(option.c_str(), po::value<std::string>()->default_value(opt.default_value), opt.info_text.c_str());
                }
            }
        }

        po::options_description create_argument_options()
        {
            po::options_description general("General options");
            general.add_options()
                       ("help,h", "produce help message and exit")
                       ("version,v", "print version information and exit");

            // If the option name is "sectioned" (contains at least one dot, as in "net.telnet.port") then they will
            // be added to the "sectioned" options, where the name of the "section" is the first dot-separated name
            // All other options are added to the "other" option list
            std::unordered_map<std::string, po::options_description> sectioned_options;
            po::options_description other("Other options");

            // TODO: Use the new ranges to filter?
            for (auto const& opt : value_registry)
            {
                if (opt.scope == registry::option::file_only || (opt.long_option.empty() && opt.short_option == 0))
                {
                    continue;
                }

                if (auto pos = opt.name.find('.'); pos != std::string::npos)
                {
                    auto section = opt.name.substr(0, pos);
                    section[0] = std::toupper(section[0]);

                    auto descr_pair = sectioned_options.emplace(section, po::options_description(section));
                    add_option_to_descr(descr_pair.first->second, opt);
                }
                else
                {
                    add_option_to_descr(other, opt);
                }
            }

            // Create a single option list for all the accumulated options
            po::options_description options;
            options.add(general);
            for (auto const& [_, o] : sectioned_options)
            {
                options.add(o);
            }
            options.add(other);

            std::cout << options;

            return options;
        }

        po::variables_map parse_arguments(int argc [[maybe_unused]], char* argv[] [[maybe_unused]])
        {
            [[maybe_unused]] auto options = create_argument_options();

            // TODO: Check for "help" and "version" arguments

            // TODO: Check for "config" option to get the configuration file name
            // TODO: If none, create a default entry for it

            po::variables_map vm;

            return vm;
        }
    }

    void init(int argc, char* argv[])
    {
        // Call each sub-module to register configuration keys
        register_options();

        set_default_values();

        [[maybe_unused]] auto arguments_vm = parse_arguments(argc, argv);

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
        void register_values(std::vector<option> const& values)
        {
            value_registry.insert(end(value_registry), begin(values), end(values));
        }
    }
}
