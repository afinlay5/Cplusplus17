# New Language Features & Language Changes in C++17
CMake source code repository for C++17 source code examples posted on personal blog (http://bit.ly/Cplusplus17Ft).
Built and tested on Linux Mint, SUSE Linux. The executables included have been compiled against Clang v6 on SUSE linux.
Many thanks to Parra Deadlock for getting around cMake.

![alt text](https://raw.githubusercontent.com/afinlay5/Cplusplus17/master/blog.png)

# Platform 
- Any Microsoft Windows platform that supports the succceding environments.
- \*Nix platforms that support the succceding environments.

# Requirements
- cmake version 3.11.1
- clang++ (LLVM/Clang) v.6.0.0 or g++-7 (GCC) v.7.3.1 (ISO C++17)

# Tasks
- To Build navigate to $root/build and execute "cmake .." then "make".
- To Run navigate to $root/build/src and run the main executable.

# Known Problems
- Source Example #16 (Class template argument deduction) will not work with GCCv.7.3.1(only works with v.8, which is currently a preview release) (05/09/2018).
- Source Example #31 (Template-Template Parameters match compatible arguments) will only with clangv.6 with the flag "-frelaxed-template-template-args" (05/09/2018).
- Source Examples #29, #32, #33 are also not compiled.
- For this reason, these examples are not compiled by default (You may change this in the CMakeLists.txt). 
  See https://gcc.gnu.org/projects/cxx-status.html#cxx17, https://clang.llvm.org/cxx_status.html#p0522 for more information.

# Execution Screenshot
![alt text](https://raw.githubusercontent.com/afinlay5/Cplusplus17/master/build.png)
![alt text](https://raw.githubusercontent.com/afinlay5/Cplusplus17/master/run.png)

