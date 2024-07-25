################################################################################################
# Project CAP/NuDyn
################################################################################################
ROOT_GENERATE_DICTIONARY(G__NuDyn NuDynHistos.hpp NuDynDerivedHistos.hpp  NuDynAnalyzer.hpp NuDynCalculator.hpp LINKDEF NuDynLinkDef.h)

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(NuDyn SHARED NuDynHistos.cpp NuDynDerivedHistos.cpp NuDynAnalyzer.cpp NuDynCalculator.cpp G__NuDyn.cxx)

target_link_libraries(NuDyn Base  Particles  ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(NuDyn  PUBLIC Base  Particles  NuDyn ${EXTRA_INCLUDES} ) 

install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libNuDyn.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libNuDyn_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS NuDyn  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

