rit_add_executable(app_object
    SOURCES
        app_object.cpp
)

target_link_libraries(app_object
    PUBLIC
    PRIVATE
    rit::ipcv_object_rpa
)