#pragma once

#if defined(_WIN32) && defined(_MSVC)
# if defined(TGALoader_EXPORTS)
#  define TGALOADER_EXPORT __declspec(dllexport)
# else
#  define TGALOADER_EXPORT __declspec(dllimport)
# endif // TGALoader_EXPORTS
#else // _WIN32
# define TGALOADER_EXPORT
#endif

TGALOADER_EXPORT char * LoadTGA( const char * szFileName, int * width, int * height, int * bpp );
