################################################################################################
# Project CAP/Performance
################################################################################################

ROOT_GENERATE_DICTIONARY(G__Performance MeasurementSimulator.hpp ParticleSimulator.hpp PerformanceAnalyzer.hpp ParticlePerformanceHistos.hpp ClosureCalculator.hpp ClosureIterator.hpp  EventPlaneRandomizerTask.hpp EventVertexRandomizerTask.hpp
LINKDEF PerformanceLinkDef.h)  


################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(Performance SHARED MeasurementSimulator.cpp  ParticleSimulator.cpp PerformanceAnalyzer.cpp ParticlePerformanceHistos.cpp ClosureCalculator.cpp ClosureIterator.cpp 
EventPlaneRandomizerTask.cpp EventVertexRandomizerTask.cpp G__Performance.cxx)

target_link_libraries(Performance Base  Particles  ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(Performance  PUBLIC Base  Particles Performance ${EXTRA_INCLUDES} ) 

# optimization for big histogram access within the pair inner loop
add_definitions(-DOPTIMIZEADDBINCONTENT)

install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libPerformance.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libPerformance_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS Performance  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

