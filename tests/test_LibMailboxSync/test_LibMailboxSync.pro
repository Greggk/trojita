QT += core network
lessThan(QT_MAJOR_VERSION, 5) {
    CONFIG += qtestlib
} else {
    QT += testlib
}
DEFINES -= QT3_SUPPORT
DEPENDPATH += ../../src/ ../
INCLUDEPATH += ../../src/ ../
CONFIG += staticlib
TEMPLATE = lib
TARGET = test_LibMailboxSync

#trojita_libs = Imap Streams
#myprefix = ../../src/
#include(../../src/linking.pri)

HEADERS += TagGenerator.h \
    FakeCapabilitiesInjector.h
HEADERS += test_LibMailboxSync.h
SOURCES += test_LibMailboxSync.cpp
