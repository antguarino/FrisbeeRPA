rit_add_library(ipcv_object_rpa
    SOURCES
        VideoProcess.cpp
        GraphGen.cpp
    HEADERS
        ObjectRPA.h
        VideoProcess.h
        GraphGen.h
)

target_link_libraries(ipcv_object_rpa
    PUBLIC
        matplot
        opencv_core
        opencv_highgui
        
)