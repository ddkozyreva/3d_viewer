cmake_minimum_required(VERSION 3.5)

project(
  viewer
  VERSION 0.1
  LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)

set(PROJECT_SOURCES
    main.cpp
    viewport.cpp
    viewport.h
    parser/parser.h
    parser/parser.c
    ViewerInterface.ui
    mainwindow.cpp
    mainwindow.h
    options_window.h
    options_window.cpp
    aphins/aphins.h
    aphins/aphins.c
    options_window.ui)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(viewer MANUAL_FINALIZATION ${PROJECT_SOURCES})
  # Define target properties for Android with Qt 6 as: set_property(TARGET
  # viewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
  # ${CMAKE_CURRENT_SOURCE_DIR}/android) For more information, see
  # https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
  if(ANDROID)
    add_library(viewer SHARED ${PROJECT_SOURCES})
    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(viewer ${PROJECT_SOURCES})
  endif()
endif()

target_link_libraries(
  viewer
  PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGLWidgets
          Qt${QT_VERSION_MAJOR}::Gui)

set_target_properties(
  viewer
  PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
             MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
             MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
             MACOSX_BUNDLE TRUE
             WIN32_EXECUTABLE TRUE)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(viewer)
endif()
