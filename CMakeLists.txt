cmake_minimum_required(VERSION 2.8)
project(libfastpaxos_cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FASTPAXOS src/lib/acceptor.c
        src/lib/leader.c
        src/lib/learner.c
        src/lib/proposer.c
        src/common/paxos_udp.c)

#set(SOURCE_FILES
#    include/config.h
#    include/config_highspeed.h
#    include/config_slow_debug.h
#    include/libpaxos.h
#    include/libpaxos_priv.h
#    include/paxos_udp.h
#    src/common/paxos_udp.c
#    src/lib/acceptor.c
#    src/lib/acceptor_disk_helpers.c
#    src/lib/leader.c
#    src/lib/learner.c
#    src/lib/proposer.c
#    src/test/acceptor_main.c
#    src/test/leader_main.c
#    src/test/learner_main.c
#    src/test/proposer_main.c)
include_directories(./include)
add_library(fastpaxos ${SOURCE_FASTPAXOS})

add_executable(acceptor_main src/test/acceptor_main.c)
add_executable(leader_main src/test/leader_main.c)
add_executable(proposer_main src/test/proposer_main.c)
#add_executable(learner_main src/test/learner_main.c)

set(link_lib fastpaxos db event pthread)
target_link_libraries(acceptor_main ${link_lib})
target_link_libraries(leader_main ${link_lib})
target_link_libraries(proposer_main ${link_lib})
#target_link_libraries(learner_main ${link_lib})

