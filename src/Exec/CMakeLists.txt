################################################################################################
# Project CAP/Exec
################################################################################################
ROOT_GENERATE_DICTIONARY(G__Exec TaskCreator.hpp RunAnalysis.hpp RunSubSampleSum.hpp  LINKDEF ExecLinkDef.h)

################################################################################################
# Create a shared library with generated dictionary
################################################################################################
add_library(Exec SHARED TaskCreator.cpp  RunAnalysis.cpp  RunSubSampleSum.cpp  G__Exec.cxx)

target_link_libraries(Exec Base ParticleDb Particles Global Spherocity ParticleSingle ParticlePair ParticlePair3D  Jets  NuDyn PtPt Performance SubSample CAPPythia Therminator ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(Exec PUBLIC Base  ParticleDb Particles  Exec Global Spherocity ParticleSingle  ParticlePair ParticlePair3D Jets NuDyn PtPt Performance SubSample CAPPythia   Therminator ${EXTRA_INCLUDES})

install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libExec.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libExec_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS Exec  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}") 

