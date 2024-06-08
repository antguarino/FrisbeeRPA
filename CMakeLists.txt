rit_add_executable(app_frisbee
    SOURCES
        app_frisbee.cpp
)

target_link_libraries(app_frisbee
    PUBLIC
    PRIVATE
    rit::ipcv_frisbee_rpa
)