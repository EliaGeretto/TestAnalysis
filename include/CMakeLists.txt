# Given that this is an analysis pass, it is necessary to include its headers in
# all the passes that depend on it. However, it is not necessary to link the
# pass itself. For this reason, the header is installed as a header-only library
# that the passes using the analysis can link against. The users of this
# analysis will need to take care of loading the pass manually in opt or clang.

install(DIRECTORY TestAnalysis DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_library(Headers INTERFACE)
target_include_directories(
  Headers INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
add_library(TestAnalysis::Headers ALIAS Headers)

# It is necessary to use LLVMExports so that the pass and the headers will end
# up in the same export set which can then be installed in one file.
install(TARGETS Headers EXPORT LLVMExports)
