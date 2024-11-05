################################################################################################
# Project CAP/Plotting
################################################################################################
ROOT_GENERATE_DICTIONARY(G__Plotting CanvasGroup.hpp CanvasConfiguration.hpp DataGraph.hpp FunctionGroup.hpp GraphConfiguration.hpp  Plotter.hpp  LegendConfiguration.hpp LINKDEF PlottingLinkDef.h)
#BalFctPlotter.hpp

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(Plotting SHARED CanvasGroup.cpp CanvasConfiguration.cpp  DataGraph.cpp   FunctionGroup.cpp  GraphConfiguration.cpp Plotter.cpp LegendConfiguration.cpp
 G__Plotting.cxx)
 
 # BalFctPlotter.cpp

target_link_libraries(Plotting Base ParticleDb ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(Plotting  PUBLIC Plotting Base ParticleDb ${EXTRA_INCLUDES} )

# optimization for big histogram access within the pair inner loop
# WARNING: the sumw2 structure is not used -> estimate uncertainties using sub-samples
add_definitions(-DOPTIMIZEADDBINCONTENT)


install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libPlotting.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libPlotting_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS Plotting  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

