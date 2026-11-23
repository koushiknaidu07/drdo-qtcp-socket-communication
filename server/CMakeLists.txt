
add_executable(drdo_server
    main.cpp
    mainwindow.cpp
    mainwindow.h
    clientmanager.cpp
    clientmanager.h
    clientchatwidget.cpp
    clientchatwidget.h
    servermanager.cpp
    servermanager.h
    messageprotocol.cpp
    messageprotocol.h
)

target_link_libraries(drdo_server
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)
