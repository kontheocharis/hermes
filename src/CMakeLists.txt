set(hermes_srcs 
        "tun.h" 
        "hermes_tcp.c"
        )

add_subdirectory(${TARGET_PLATFORM})

add_library(hermes_tcp STATIC ${hermes_srcs})
target_link_libraries(hermes_tcp hermes_platform_specific)
set_target_properties(hermes_tcp PROPERTIES PUBLIC_HEADER "include/hermes_tcp.h")

install(TARGETS hermes_tcp 
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)
