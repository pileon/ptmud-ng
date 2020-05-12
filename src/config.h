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

#pragma once
#ifndef PTMUD_NG_SRC_CONFIG_H
#define PTMUD_NG_SRC_CONFIG_H

#include <unordered_map>
#include <string>
#include <vector>
#include <type_traits>

namespace ptmud::config
{
    // TODO: Add namespace for compile-time default values, for easier customization

    //region Initialization and cleanup

    void init(int argc, char* argv[]);

    void cleanup();

    //endregion

    //! \brief Configuration per-module setup and value registration
    namespace registry
    {
        //! \brief This structure describes a configuration option
        struct option
        {
            // TODO: Need to add a boolean toggle for true/false switches
            std::string name;                   //!< Name of the option
            std::string long_option;            //!< Possible long option name for the command-line option
            char        short_option;           //!< Possible one-character abbreviation of the command-line option
            std::string info_text;              //!< Informative text displayed for help
            bool        is_switch;              //!< True if option is a boolean "switch" or "toggle"
            enum
            {
                file_only,
                argument_only,
                both
            }           scope;                  //!< Can the option be in the configuration file only, can be command-line argument only, or both
            std::string default_value = "";     //!< Default value, if any
        };

        inline option make_argument_option(std::string const& name, std::string const& long_option, char const short_option, std::string const& info_text, std::string const& value = "")
        {
            return option{
                .name = name,
                .long_option = long_option,
                .short_option = short_option,
                .info_text = info_text,
                .is_switch = false,
                .scope = option::argument_only,
                .default_value = value
            };
        }

        inline option make_argument_option(std::string const& name, std::string const& long_option, std::string const& info_text, std::string const& value = "")
        {
            return option{
                .name = name,
                .long_option = long_option,
                .short_option = 0,
                .info_text = info_text,
                .is_switch = false,
                .scope = option::argument_only,
                .default_value = value
            };
        }

        inline option make_argument_option(std::string const& name, char const short_option, std::string const& info_text, std::string const& value = "")
        {
            return option{
                .name = name,
                .long_option = "",
                .short_option = short_option,
                .info_text = info_text,
                .is_switch = false,
                .scope = option::argument_only,
                .default_value = value
            };
        }

        inline option make_argument_switch(std::string const& name, std::string const& long_option, char const short_option, std::string const& info_text, bool default_on = false)
        {
            return option{
                .name = name,
                .long_option = long_option,
                .short_option = short_option,
                .info_text = info_text,
                .is_switch = true,
                .scope = option::argument_only,
                .default_value = default_on ? "true" : ""
            };
        }

        inline option make_argument_switch(std::string const& name, std::string const& long_option, std::string const& info_text, bool default_on = false)
        {
            return option{
                .name = name,
                .long_option = long_option,
                .short_option = 0,
                .info_text = info_text,
                .is_switch = true,
                .scope = option::argument_only,
                .default_value = default_on ? "true" : ""
            };
        }

        inline option make_argument_switch(std::string const& name, char const short_option, std::string const& info_text, bool default_on = false)
        {
            return option{
                .name = name,
                .long_option = "",
                .short_option = short_option,
                .info_text = info_text,
                .is_switch = true,
                .scope = option::argument_only,
                .default_value = default_on ? "true" : ""
            };
        }

        void register_values(std::vector<option> const& values);
    }

    //region Values

    //! \brief The configuration is stored as a mapping from name to value
    //!
    //! All values are stored as strings.
    using configuration_map_type = std::unordered_map<std::string, std::string>;

    //! \brief Get the configuration map
    configuration_map_type& get_configuration();

    template <typename T>
    struct value;

    //! \brief Represents a single configuration value
    template <typename T>
    class base_value
    {
    public:
        base_value() = delete;

        base_value& operator=(T const& new_value)
        {
            actual_->second = std::to_string(new_value);
            return *this;
        }

        base_value& operator=(char const* new_value)
        {
            actual_->second = new_value;
            return *this;
        }

        base_value& operator=(std::string new_value)
        {
            actual_->second = std::move(new_value);
            return *this;
        }

        template<typename..., typename U = T>
        bool operator==(U const& other) const
        {
            return actual_->second == std::to_string(other);
        }

        template<typename..., typename U = T>
        std::enable_if_t<!std::is_same_v<U, std::string>, bool>
        operator==(std::string const& other) const
        {
            return actual_->second == other;
        }

        friend std::ostream& operator<<(std::ostream& os, base_value const& value)
        {
            return os << value.actual_->second;
        }

    protected:
        configuration_map_type::iterator actual_;   //!< Iterator to the actual configuration pair

    private:
        explicit base_value(configuration_map_type::iterator actual)
            : actual_{ actual }
        {
        }

        template <typename U>
        friend value<U> get(std::string const&);

    };

    //! \brief Default value structure
    template <typename T>
    struct value : public base_value<T>
    {
        using base_value<T>::base_value;
        using base_value<T>::operator=;

        explicit operator T() const
        {
            return T(this->actual_->second);
        }
    };

    // //! \brief Specialization of the value structure
    // template <>
    // struct value<int> : public base_value<int>
    // {
    //     using base_value<int>::base_value;
    //     using base_value<int>::operator=;
    //
    //     explicit operator int() const
    //     {
    //         return std::stoi(actual_->second);
    //     }
    // };

    //! \brief Specialization of the value structure
    template <>
    struct value<std::string> : public base_value<std::string>
    {
        using base_value<std::string>::base_value;
        using base_value<std::string>::operator=;

        explicit operator std::string() const
        {
            return actual_->second;
        }
    };

    //! \brief Specialization of the value structure
    template <>
    struct value<char const*> : public base_value<char const*>
    {
        using base_value<const char*>::base_value;
        using base_value<char const*>::operator=;

        explicit operator char const*() const
        {
            return actual_->second.c_str();
        }
    };


    //! \brief Get the named configuration value
    template <typename T>
    value<T> get(std::string const& name)
    {
        if (auto config = get_configuration().find(name); config != get_configuration().end())
        {
            return value<T>(config);
        }
        else
        {
            // Insert new value into the map and return iterator to it
            auto pair = get_configuration().emplace(name, "");
            return value<T>(pair.first);
        }
    }

    //! \brief Check if a configuration key exists
    bool exist(std::string const& name);

    //endregion
}

#endif // PTMUD_NG_SRC_CONFIG_H
