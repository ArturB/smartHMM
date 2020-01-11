add_library( smarthmm smart-hmm.cc )
target_link_libraries(smarthmm PUBLIC armadillo)
target_include_directories( smarthmm
                            INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include> )
install(TARGETS smarthmm
        DESTINATION lib64)
install(FILES smart-hmm.h
        DESTINATION include)
