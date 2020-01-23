#ifndef BCTTT_GLOBAL_H
#define BCTTT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BCTTT_LIBRARY)
#  define BCTTT_EXPORT Q_DECL_EXPORT
#else
#  define BCTTT_EXPORT Q_DECL_IMPORT
#endif

#endif // BCTTT_GLOBAL_H
