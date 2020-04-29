# Copyright 2020 Joachim Pileborg
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.16)
project(ptmud-ng
        VERSION 0.0.1
        DESCRIPTION "A simple DikuMUD variant created from scratch in C++."
        HOMEPAGE_URL "https://github.com/pileon/ptmud-ng"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_CXX_STANDARD 20)

find_package(Threads)

include(cmake/build-flags.cmake)
include(cmake/boost.cmake)
include(cmake/stdc++fs.cmake)
include(cmake/rs_add_library.cmake)

add_compile_options(${COMPILER_OPTIONS})
#include_directories(${CMAKE_SOURCE_DIR}/include)

if(CLION_IDE)
    add_compile_definitions(CLION_IDE)
endif()

check_cxx_compiler_flag(-Werror HAVE_FLAG_WERROR)
if(HAVE_FLAG_WERROR)
    add_compile_options(-Werror)
endif()

#configure_file(${CMAKE_SOURCE_DIR}/include/ptmud-ng/version.h.in ${CMAKE_SOURCE_DIR}/include/ptmud-ng/version.h)

option(ENABLE_COVERAGE "enable code-coverage targets and builds" OFF)

add_subdirectory(src)
