set(target constexpr_lambda)
set(src constexpr_lambda.cpp)

add_executable(${target} ${src})

target_compile_options(${target} PUBLIC ${DEFAULT_COMPILE_OPTIONS})