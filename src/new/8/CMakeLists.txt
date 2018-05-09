set(target init_if_sw)
set(src init_if_sw.cpp)

add_executable(${target} ${src})

target_compile_options(${target} PUBLIC ${DEFAULT_COMPILE_OPTIONS})