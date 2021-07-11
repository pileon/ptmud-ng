# Copyright 2021 Joachim Pileborg
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

# Function to add a library target, with optional coverage target
function(rs_add_library target type)
    add_library(${target} ${type} ${ARGN})
    set_target_properties(${target}
            PROPERTIES LINKER_LANGUAGE CXX)

    if(ENABLE_COVERAGE)
        add_library(${target}_coverage ${type} ${ARGN})
        target_compile_options(${target}_coverage PRIVATE --coverage)
        set_target_properties(${target}_coverage
                PROPERTIES LINKER_LANGUAGE CXX)
    endif()
endfunction()
