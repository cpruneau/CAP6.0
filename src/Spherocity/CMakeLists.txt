################################################################################################
# Project CAP/Spherocity
################################################################################################

ROOT_GENERATE_DICTIONARY(G__Spherocity SpherocityHistos.hpp  SpherocityAnalyzer.hpp SpherocityCalculator.hpp LINKDEF SpherocityLinkDef.h)


################################################################################################
# Create a shared library with generated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(Spherocity SHARED  SpherocityExceptions.cpp SpherocityHistos.cpp SpherocityAnalyzer.cpp SpherocityCalculator.cpp G__Spherocity.cxx)

target_link_libraries(Spherocity Base  Particles  ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(Spherocity  PUBLIC Spherocity Base  Particles  ${EXTRA_INCLUDES} )

# optimization for big histogram access within the pair inner loop
# WARNING: the sumw2 structure is not used -> estimate uncertainties using sub-samples
add_definitions(-DOPTIMIZEADDBINCONTENT)


install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libSpherocity.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libSpherocity_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS Spherocity  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

