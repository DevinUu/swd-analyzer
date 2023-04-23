cmake_minimum_required (VERSION 3.11)
project(riscswdio_analyzer)

add_definitions( -DLOGIC2 )

# enable generation of compile_commands.json, helpful for IDEs to locate include files.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# custom CMake Modules are located in the cmake directory.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(ExternalAnalyzerSDK)

set(SOURCES 
src/RiscSWDIOAnalyzer.cpp
src/RiscSWDIOAnalyzer.h
src/RiscSWDIOAnalyzerResults.cpp
src/RiscSWDIOAnalyzerResults.h
src/RiscSWDIOAnalyzerSettings.cpp
src/RiscSWDIOAnalyzerSettings.h
src/RiscSWDIOSimulationDataGenerator.cpp
src/RiscSWDIOSimulationDataGenerator.h
src/RiscSWDIOTypes.cpp
src/RiscSWDIOTypes.h
src/RiscSWDIOUtils.cpp
src/RiscSWDIOUtils.h
)

add_analyzer_plugin(riscswdio_analyzer SOURCES ${SOURCES})
