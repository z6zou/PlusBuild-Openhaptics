
#ifndef OPENIGTLINKIO_CONVERTER_EXPORT_H
#define OPENIGTLINKIO_CONVERTER_EXPORT_H

#ifdef IGTLIOCONVERTER_STATIC_DEFINE
#  define OPENIGTLINKIO_CONVERTER_EXPORT
#  define IGTLIOCONVERTER_NO_EXPORT
#else
#  ifndef OPENIGTLINKIO_CONVERTER_EXPORT
#    ifdef igtlioConverter_EXPORTS
        /* We are building this library */
#      define OPENIGTLINKIO_CONVERTER_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define OPENIGTLINKIO_CONVERTER_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef IGTLIOCONVERTER_NO_EXPORT
#    define IGTLIOCONVERTER_NO_EXPORT 
#  endif
#endif

#ifndef IGTLIOCONVERTER_DEPRECATED
#  define IGTLIOCONVERTER_DEPRECATED __declspec(deprecated)
#endif

#ifndef IGTLIOCONVERTER_DEPRECATED_EXPORT
#  define IGTLIOCONVERTER_DEPRECATED_EXPORT OPENIGTLINKIO_CONVERTER_EXPORT IGTLIOCONVERTER_DEPRECATED
#endif

#ifndef IGTLIOCONVERTER_DEPRECATED_NO_EXPORT
#  define IGTLIOCONVERTER_DEPRECATED_NO_EXPORT IGTLIOCONVERTER_NO_EXPORT IGTLIOCONVERTER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef IGTLIOCONVERTER_NO_DEPRECATED
#    define IGTLIOCONVERTER_NO_DEPRECATED
#  endif
#endif

#endif /* OPENIGTLINKIO_CONVERTER_EXPORT_H */
