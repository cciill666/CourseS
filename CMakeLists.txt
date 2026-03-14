cmake_minimum_required(VERSION 4.1.1)

#https://github.com/Kitware/CMake/blob/v4.1.1/Help/dev/experimental.rst


set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)

project(selectsystem LANGUAGES CXX)

# set(MODULE_LIB_DIR1 /opt/utils/modules)  # 模块库的目录的设置
add_executable(sc
    #math.cpp                              # 模块实现单元
    main.cpp


)

set(DOMAIN_PRITION
    #${MODULE_LIB_DIR1}/utils.cppm         #添加模块库的模块接口单元
    #math.cppm                             # 模块接口单元
    domain.user.cppm
    domain.teacher.cppm
    domain.student.cppm
    domain.secretary.cppm
    domain.enrollment.cppm
    domain.course.cppm
)

set(SERVICE_PRITION
    courseservice.cppm
)

set(REPOSITORY_PRITION
    repository.cppm
)

set(UI_PRITION
    ui.cppm
)

source_group("Domain Files" FILES ${DOMAIN_PRITION})
source_group("Service Files" FILES ${SERVICE_PRITION})
source_group("Repository Files" FILES ${REPOSITORY_PRITION})
source_group("Ui Files" FILES ${UI_PRITION})

target_sources(sc  PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS                              # 配置BASE_DIRS，用于组织构建输出目录，以便构建不同目录中(同名的)模块文件.
        #${MODULE_LIB_DIR1}
        ${CMAKE_CURRENT_SOURCE_DIR}
    FILES ${DOMAIN_PRITION} ${SERVICE_PRITION} ${REPOSITORY_PRITION} ${UI_PRITION}
)
target_compile_features(sc PRIVATE cxx_std_23)












































<<<<<<< HEAD

# target_link_directories(sc PRIVATE /opt/utils/lib)  # -L /opt/utils/lib 设置链接路径
# target_link_libraries(sc PRIVATE utils)             # -lutils           设置链接库名

# set_target_properties(sc PROPERTIES
#     INSTALL_RPATH_USE_LINK_PATH  True                           # 使用链接路径作为安装文件的RPath，等价于"-Wl,-rpath=/opt/utils/lib"
# )

#add_library(sc SHARED
#  utils.cpp
#)

#set_target_properties( sc PROPERTIES
=======
# target_link_directories(sc1 PRIVATE /opt/utils/lib)  # -L /opt/utils/lib 设置链接路径
# target_link_libraries(sc1 PRIVATE utils)             # -lutils           设置链接库名

# set_target_properties(sc1 PROPERTIES
#     INSTALL_RPATH_USE_LINK_PATH  True                           # 使用链接路径作为安装文件的RPath，等价于"-Wl,-rpath=/opt/utils/lib"
# )

#add_library(sc1 SHARED
#  utils.cpp
#)

#set_target_properties( sc1 PROPERTIES
>>>>>>> origin/dev
#    PUBLIC_HEADER utils.cppm
#    VERSION   2.5.1
#    SOVERSION 2
#    LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib"
#)

<<<<<<< HEAD
#install(TARGETS sc
=======
#install(TARGETS sc1
>>>>>>> origin/dev
#    LIBRARY DESTINATION /opt/utils/lib
#    PUBLIC_HEADER DESTINATION  /opt/utils/modules
#)

<<<<<<< HEAD
#add_custom_command(TARGET sc
=======
#add_custom_command(TARGET sc1
>>>>>>> origin/dev
#    POST_BUILD
#    COMMAND cmake --install "${CMAKE_CURRENT_BINARY_DIR}"
#)
