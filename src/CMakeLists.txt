rit_add_library(ipcv_frisbee_rpa
    SOURCES
        VideoProcess.cpp
        GraphGen.cpp
    HEADERS
        FrisbeeRPA.h
        VideoProcess.h
        GraphGen.h
)

target_link_libraries(ipcv_frisbee_rpa
    PUBLIC
        matplot
        opencv_core
        opencv_highgui
        
)