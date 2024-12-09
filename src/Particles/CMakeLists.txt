################################################################################################
# Project CAP/Particles
################################################################################################

#include(${ROOT_USE_FILE})
#include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
#add_definitions(${ROOT_CXX_FLAGS})

ROOT_GENERATE_DICTIONARY(G__Particles  Event.hpp EventAccountant.hpp  EventFilter.hpp EventCountHistos.hpp  EventTask.hpp  EventIterator.hpp  Particle.hpp  ParticleDecayer.hpp ParticleDecayerTask.hpp   ParticleFilter.hpp   ParticlePairFilter.hpp JetFilter.hpp EfficiencyFilter.hpp RootChainManager.hpp FilterCreator.hpp
LINKDEF ParticlesLinkDef.h)

#ParticleDigit.hpp

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(Particles SHARED  ParticlesExceptions.cpp Event.cpp EventAccountant.cpp EventTask.cpp EventIterator.cpp EventFilter.cpp EventCountHistos.cpp   EventTask.cpp Particle.cpp ParticleDecayer.cpp ParticleDecayerTask.cpp   ParticleFilter.cpp   ParticlePairFilter.cpp  JetFilter.cpp EfficiencyFilter.cpp  FilterCreator.cpp
    RootChainManager.cpp  G__Particles.cxx)

target_link_libraries(Particles ParticleDb Base FASTJET_LIB   ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(Particles  PUBLIC Base Particles ParticleDb ${FASTJET_INCLUDE_PATH} ${EXTRA_INCLUDES} )



# optimization for big histogram access within the pair inner loop
# WARNING: the sumw2 structure is not used -> estimate uncertainties using sub-samples
add_definitions(-DOPTIMIZEADDBINCONTENT)


install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libParticles.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libParticles_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS Particles  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

