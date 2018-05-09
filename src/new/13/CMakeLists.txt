set(target tuple_pack)
set(src tuple_pack.cpp)

add_executable(${target} ${src})

target_compile_options(${target} PUBLIC ${DEFAULT_COMPILE_OPTIONS})