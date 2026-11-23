
add_executable(drdo_client
    main.cpp
    mainwindow.cpp
    mainwindow.h
    clientmanager.cpp
    clientmanager.h
    MessageProtocol.cpp
    messageprotocol.h
)

target_link_libraries(drdo_client
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)
