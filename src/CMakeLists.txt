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

add_subdirectory(host)

add_executable(ptmud-ng ${ptmud_ng_host_files} ptmud-ng.cpp ptmud-ng.h config.cpp config.h)
target_link_libraries(ptmud-ng Threads::Threads Boost::program_options)
