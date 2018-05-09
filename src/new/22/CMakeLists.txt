set(target lambda_this)
set(src lambda_this.cpp)

add_executable(${target} ${src})

target_compile_options(${target} PUBLIC ${DEFAULT_COMPILE_OPTIONS})