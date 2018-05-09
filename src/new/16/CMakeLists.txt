set(target temp_arg_deduc)
set(src temp_arg_deduc.cpp)

add_executable(${target} ${src})

target_compile_options(${target} PUBLIC ${DEFAULT_COMPILE_OPTIONS})