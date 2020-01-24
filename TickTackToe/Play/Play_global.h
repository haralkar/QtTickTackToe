#ifndef PLAY_GLOBAL_H
#define PLAY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLAY_LIBRARY)
#  define PLAY_EXPORT Q_DECL_EXPORT
#else
#  define PLAY_EXPORT Q_DECL_IMPORT
#endif

#endif // PLAY_GLOBAL_H
