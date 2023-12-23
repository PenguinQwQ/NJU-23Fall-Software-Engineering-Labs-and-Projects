# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (gtest_frame)

# add googletest subdirectory
add_subdirectory(googletest-main)

# this is so we can #include <gtest/gtest.h> 
include_directories(googletest/include)

# add header files in the lib
include_directories(lib) 

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    main.cpp
    src/address.cpp
    src/ambulance.cpp
    src/doctor.cpp
    src/appointment.cpp
    src/driver.cpp
    src/global.cpp
    src/hospital.cpp
    src/nurse.cpp
    src/patient.cpp
    src/person.cpp
)

# Add an executable with the above sources
add_executable(run_opt ${SOURCES})


# Set the directories that should be included in the build command for this target

target_include_directories(run_opt
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/lib
)

enable_testing()
add_executable(run_opt_test
    src/global.cpp tests/unittest.cpp
)

target_link_libraries(run_opt_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_opt_test )
