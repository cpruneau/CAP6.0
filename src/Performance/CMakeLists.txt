################################################################################################
# Project CAP/Performance
################################################################################################
#include(${ROOT_USE_FILE})
#include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
#add_definitions(${ROOT_CXX_FLAGS})

ROOT_GENERATE_DICTIONARY(G__Performance MeasurementSimulator.hpp ParticleSimulator.hpp PerformanceAnalyzer.hpp ParticlePerformanceHistos.hpp ClosureCalculator.hpp ClosureIterator.hpp  EventPlaneRandomizerTask.hpp EventVertexRandomizerTask.hpp ResolutionFunction.hpp EfficiencyFunction.hpp LINKDEF PerformanceLinkDef.h)
#  PidFunction.hpp

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(Performance SHARED MeasurementSimulator.cpp  ParticleSimulator.cpp PerformanceAnalyzer.cpp ParticlePerformanceHistos.cpp ClosureCalculator.cpp ClosureIterator.cpp
EventPlaneRandomizerTask.cpp EventVertexRandomizerTask.cpp ResolutionFunction.cpp EfficiencyFunction.hpp  G__Performance.cxx)
# PidFunction.cpp

target_link_libraries(Performance Base  Particles  ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(Performance  PUBLIC Performance Base  Particles   ${EXTRA_INCLUDES} )

# optimization for big histogram access within the pair inner loop
add_definitions(-DOPTIMIZEADDBINCONTENT)

install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libPerformance.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libPerformance_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS Performance  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

