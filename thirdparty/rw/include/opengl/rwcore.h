/******************************************/
/*                                        */
/*    RenderWare(TM) Graphics Library     */
/*                                        */
/******************************************/

/*
 * This file is a product of Criterion Software Ltd.
 *
 * This file is provided as is with no warranties of any kind and is
 * provided without any obligation on Criterion Software Ltd.
 * or Canon Inc. to assist in its use or modification.
 *
 * Criterion Software Ltd. and Canon Inc. will not, under any
 * circumstances, be liable for any lost revenue or other damages
 * arising from the use of this file.
 *
 * Copyright (c) 1999. Criterion Software Ltd.
 * All Rights Reserved.
 */

/*************************************************************************
 *
 * Filename: <C:/daily/rwsdk/include/opengl/rwcore.h>
 * Automatically Generated on: Thu Feb 12 12:57:55 2004
 *
 ************************************************************************/

#ifndef RWCORE_H
#define RWCORE_H

/*--- System Header Files ---*/
#include <rwplcore.h>


/*--- Automatically derived from: C:/daily/rwsdk/driver/common/barwasmm.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/glext.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/drvfns.h ---*/

/****************************************************************************
 Function prototypes
 */

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */


/* General useful functions */
extern RwUInt32
_rwOpenGLNextPowerOf2( RwUInt32 in );

extern RwBool
RwOpenGLIsExtensionSupported( const RwChar * const extString );

extern void
_rwOpenGLApplyRwMatrix( RwMatrix *matrix );

extern void
_rwOpenGLMatrixToRwMatrix( RwMatrix *outMatrix,
                           void *inMatrix );

extern RwInt32
_rwOpenGLGetMaxSupportedTextureSize( void );

extern RwInt32
_rwOpenGLGetMaxSupportedHardwareLights( void );

/* Win32 multiple display functionality and SSE support */
#if defined( _WIN32 )
extern RwBool
_rwOpenGLCameraAttachWindow(void *camera, void *window);

extern RwBool
_rwIntelSSEsupported(void);

extern RwBool
RwOpenGLChangeVideoMode( RwInt32 modeIndex );
#endif /* defined( _WIN32 ) */

/* Memory manager functions for the Vertex Array Range extension */
#define _rwOpenGLVertexHeapAvailable()  \
    (NULL != _rwOpenGLExt.VertexArrayRangeNV)

extern void
_rwOpenGLVertexHeapSetSize( const RwUInt32 size );

extern void *
_rwOpenGLVertexHeapDynamicMalloc( const RwUInt32 size,
                                  const RwBool generateFence );

extern void *
_rwOpenGLVertexHeapStaticMalloc( const RwUInt32 size );

extern void
_rwOpenGLVertexHeapDynamicFree( void *videoMemory );

extern void
_rwOpenGLVertexHeapStaticFree( void *videoMemory );

extern void
_rwOpenGLVertexHeapSetNVFence( void *videoMemory );

extern void
_rwOpenGLVertexHeapFinishNVFence( void *videoMemory );

extern void
_rwOpenGLVertexHeapDynamicDiscard( void *videoMemory );


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */


/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/drvmodel.h ---*/
#ifndef OPENGL_DRVMODEL_H
#define OPENGL_DRVMODEL_H

#if (defined(__ICL))
/* Avoid voluminous
 *   'warning #344: typedef name has already been declared (with same type)'
 * warnings from MS include files
 */
#pragma warning( disable : 344 )
#endif /* (defined(__ICL)) */

/****************************************************************************
 Defines
 */

/* Set true depth information (for fogging, eg) */
#define RwIm2DVertexSetCameraX(vert, camx)     /* Nothing */
#define RwIm2DVertexSetCameraY(vert, camy)     /* Nothing */
#define RwIm2DVertexSetCameraZ(vert, camz)     /* Nothing */
#define RwIm2DVertexSetRecipCameraZ(vert, recipz)    ((vert)->recpz = (recipz))

#define RwIm2DVertexGetCameraX(vert)           (cause an error)
#define RwIm2DVertexGetCameraY(vert)           (cause an error)
#define RwIm2DVertexGetCameraZ(vert)           (cause an error)
#define RwIm2DVertexGetRecipCameraZ(vert)            ((vert)->recpz)

/* Set screen space coordinates in a device vertex */
#define RwIm2DVertexSetScreenX(vert, scrnx)    ((vert)->x = (scrnx))
#define RwIm2DVertexSetScreenY(vert, scrny)    ((vert)->y = (scrny))
#define RwIm2DVertexSetScreenZ(vert, scrnz)    ((vert)->z = (scrnz))
#define RwIm2DVertexGetScreenX(vert)           ((vert)->x)
#define RwIm2DVertexGetScreenY(vert)           ((vert)->y)
#define RwIm2DVertexGetScreenZ(vert)           ((vert)->z)

/* Set texture coordinates in a device vertex */
#define RwIm2DVertexSetU(vert, u, recipz)       \
MACRO_START                                     \
{ ((vert)->oow = (recipz));                     \
  ((vert)->row = (RwReal)(0));                  \
  ((vert)->sow = ((u) * (recipz)));             \
}                                               \
MACRO_STOP
#define RwIm2DVertexSetV(vert, v, recipz)      ((vert)->tow = ((v) * (recipz)))
#define RwIm2DVertexGetU(vert)                 ((vert)->sow / ((vert)->oow))
#define RwIm2DVertexGetV(vert)                 ((vert)->tow / ((vert)->oow))

/* Modify the luminance stuff */
#define RwIm2DVertexSetRealRGBA(vert, red, green, blue, alpha)          \
MACRO_START                                                             \
{                                                                       \
    ((vert)->r = ((unsigned char)RwFastRealToUInt32(red)));             \
    ((vert)->g = ((unsigned char)RwFastRealToUInt32(green)));           \
    ((vert)->b = ((unsigned char)RwFastRealToUInt32(blue)));            \
    ((vert)->a = ((unsigned char)RwFastRealToUInt32(alpha)));           \
}                                                                       \
MACRO_STOP

#define RwIm2DVertexSetIntRGBA(vert, red, green, blue, alpha)           \
MACRO_START                                                             \
{                                                                       \
    ((vert)->r = ((unsigned char)(red)  ));                             \
    ((vert)->g = ((unsigned char)(green)));                             \
    ((vert)->b = ((unsigned char)(blue) ));                             \
    ((vert)->a = ((unsigned char)(alpha)));                             \
}                                                                       \
MACRO_STOP

#define RwIm2DVertexGetRed(vert)                ((vert)->r)
#define RwIm2DVertexGetGreen(vert)              ((vert)->g)
#define RwIm2DVertexGetBlue(vert)               ((vert)->b)
#define RwIm2DVertexGetAlpha(vert)              ((vert)->a)

#define RwIm2DVertexCopyRGBA(dst, src)                  \
MACRO_START                                             \
{                                                       \
    ((dst)->r = (src)->r);                              \
    ((dst)->g = (src)->g);                              \
    ((dst)->b = (src)->b);                              \
    ((dst)->a = (src)->a);                              \
}                                                       \
MACRO_STOP

/* Clipper stuff */
#define RwIm2DVertexClipRGBA(out, interp, near, far)    \
MACRO_START                                             \
{                                                       \
    (out)->r = (unsigned char)RwFastRealToUInt32(       \
        RWSHADCLIP((interp), (near)->r, (far)->r));     \
    (out)->g = (unsigned char)RwFastRealToUInt32(       \
        RWSHADCLIP((interp), (near)->g, (far)->g));     \
    (out)->b = (unsigned char)RwFastRealToUInt32(       \
        RWSHADCLIP((interp), (near)->b, (far)->b));     \
    (out)->a = (unsigned char)RwFastRealToUInt32(       \
        RWSHADCLIP((interp), (near)->a, (far)->a));     \
}                                                       \
MACRO_STOP

/****************************************************************************
 Global Types
 */

/* We use RwOpenGLVertex to drive the hardware */
/* The polygon index structure is 32 bit - see above */

typedef struct RwOpenGLVertex RwOpenGLVertex;
/**
 * \ingroup rwim3dopengl
 * \struct RwOpenGLVertex
 *
 * Structure describing a vertex in OpenGL
 */
struct RwOpenGLVertex
{
    float           x;      /**< X positional component */
    
    float           y;      /**< Y positional component */
    
    float           z;      /**< Z positional component */

    unsigned char   r;      /**< 8-bit red color component */
    
    unsigned char   g;      /**< 8-bit green color component */
    
    unsigned char   b;      /**< 8-bit blue color component */
    
    unsigned char   a;      /**< 8-bit alpha component */

    float           sow;    /**< Perspective-correct U texture coordinate */
    
    float           tow;    /**< Perspective-correct V texture coordinate */
    
    float           row;    /**< Internal use only */
    
    float           oow;    /**< Texture perspective correction */
    
    float           recpz;  /**< Reciprocal Z component */
};

/* Define types used */

/**
 * \ingroup rwim2dvertex
 * \ref RwIm2DVertex
 * Typedef for a RenderWare Graphics Immediate Mode 2D Vertex
 */

typedef RwOpenGLVertex      RwIm2DVertex;

/**
 * \ingroup rwcoregeneric
 * \ref RxVertexIndex
 * Typedef for a RenderWare Graphics PowerPipe 
 * Immediate Mode Vertex
 */
typedef RwUInt32        RxVertexIndex;

/**
 * \ingroup rwcoregeneric
 * \ref RwImVertexIndex
 * Typedef for a RenderWare Graphics Immediate Mode Vertex
 */

typedef RxVertexIndex   RwImVertexIndex;


/* OpenGL extension data and types - as defined in glext.h */

#ifdef WIN32
#ifndef APIENTRY
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#include <gl/gl.h>
#endif
#else
#define APIENTRY
#include "gl/gl.h"
#include "gl/glext.h"
#endif

#if !defined(GL_EXT_packed_pixels)
#define GL_UNSIGNED_BYTE_3_3_2_EXT          0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT       0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT       0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT         0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT      0x8036
#endif /* !defined(GL_EXT_packed_pixels) */

#if !defined(GL_EXT_compiled_vertex_array)
typedef void (APIENTRY * PFNGLLOCKARRAYSEXTPROC) (int first, int count);
typedef void (APIENTRY * PFNGLUNLOCKARRAYSEXTPROC) (void);
#endif /* !defined(GL_EXT_compiled_vertex_array) */

#if !defined(GL_NV_vertex_array_range)
#define GL_VERTEX_ARRAY_RANGE_NV            0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV     0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV      0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV    0x8521

typedef void (APIENTRY * PFNGLFLUSHVERTEXARRAYRANGENVPROC) (void);
typedef void (APIENTRY * PFNGLVERTEXARRAYRANGENVPROC) (int size,
                                                       const void *pointer);
typedef void* (APIENTRY * PFNWGLALLOCATEMEMORYNVPROC) (int size,
                                                       float readfreq,
                                                       float writefreq,
                                                       float priority);
typedef void (APIENTRY * PFNWGLFREEMEMORYNVPROC) (void *pointer);
#endif /* !defined(GL_NV_vertex_array_range) */

#if !defined(GL_NV_vertex_array_range2)
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533
#endif /* !defined(GL_NV_vertex_array_range2) */

#if !defined(GL_NV_fence)
#define GL_ALL_COMPLETED_NV               0x84F2

typedef void (APIENTRY * PFNGLDELETEFENCESNVPROC) (int n,
                                                   const void *fences);
typedef void (APIENTRY * PFNGLGENFENCESNVPROC) (int n,
                                                int *fences);
typedef void (APIENTRY * PFNGLSETFENCENVPROC) (int fence,
                                               int condition);
typedef void (APIENTRY * PFNGLFINISHFENCENVPROC) (int fence);
typedef int (APIENTRY * PFNGLISFENCENVPROC) (int fence);
typedef int (APIENTRY * PFNGLTESTFENCENVPROC) (int fence);
#endif /* !defined(GL_NV_fence) */

#if !defined(GL_EXT_paletted_texture)
#define GL_COLOR_INDEX1_EXT               0x80E2
#define GL_COLOR_INDEX2_EXT               0x80E3
#define GL_COLOR_INDEX4_EXT               0x80E4
#define GL_COLOR_INDEX8_EXT               0x80E5
#define GL_COLOR_INDEX12_EXT              0x80E6
#define GL_COLOR_INDEX16_EXT              0x80E7

typedef void 
(APIENTRY * PFNGLCOLORTABLEEXTPROC) (unsigned int target,
                                     unsigned int internalformat,
                                     int width,
                                     unsigned int format,
                                     unsigned int type,
                                     const void *table);
typedef void 
(APIENTRY * PFNGLGETCOLORTABLEEXTPROC) (unsigned int target, 
                                        unsigned int format, 
                                        unsigned int type, 
                                        void *data);
#endif /* !defined(GL_EXT_paletted_texture) */

#if !defined(GL_ARB_multitexture)
#define GL_TEXTURE0_ARB                   0x84C0
#define GL_TEXTURE1_ARB                   0x84C1
#define GL_TEXTURE2_ARB                   0x84C2
#define GL_TEXTURE3_ARB                   0x84C3
#define GL_TEXTURE4_ARB                   0x84C4
#define GL_TEXTURE5_ARB                   0x84C5
#define GL_TEXTURE6_ARB                   0x84C6
#define GL_TEXTURE7_ARB                   0x84C7
#define GL_TEXTURE8_ARB                   0x84C8
#define GL_TEXTURE9_ARB                   0x84C9
#define GL_TEXTURE10_ARB                  0x84CA
#define GL_TEXTURE11_ARB                  0x84CB
#define GL_TEXTURE12_ARB                  0x84CC
#define GL_TEXTURE13_ARB                  0x84CD
#define GL_TEXTURE14_ARB                  0x84CE
#define GL_TEXTURE15_ARB                  0x84CF
#define GL_TEXTURE16_ARB                  0x84D0
#define GL_TEXTURE17_ARB                  0x84D1
#define GL_TEXTURE18_ARB                  0x84D2
#define GL_TEXTURE19_ARB                  0x84D3
#define GL_TEXTURE20_ARB                  0x84D4
#define GL_TEXTURE21_ARB                  0x84D5
#define GL_TEXTURE22_ARB                  0x84D6
#define GL_TEXTURE23_ARB                  0x84D7
#define GL_TEXTURE24_ARB                  0x84D8
#define GL_TEXTURE25_ARB                  0x84D9
#define GL_TEXTURE26_ARB                  0x84DA
#define GL_TEXTURE27_ARB                  0x84DB
#define GL_TEXTURE28_ARB                  0x84DC
#define GL_TEXTURE29_ARB                  0x84DD
#define GL_TEXTURE30_ARB                  0x84DE
#define GL_TEXTURE31_ARB                  0x84DF
#define GL_ACTIVE_TEXTURE_ARB             0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB      0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB          0x84E2

typedef void (APIENTRY * PFNGLACTIVETEXTUREARBPROC) (unsigned int texture);
typedef void (APIENTRY * PFNGLCLIENTACTIVETEXTUREARBPROC) (unsigned int texture);
typedef void (APIENTRY * PFNGLMULTITEXCOORD2FVARBPROC) (unsigned int target,
                                                        const float *v);
#endif /* !defined(GL_ARB_multitexture) */

#if !defined(GL_ARB_texture_env_combine)
#define GL_COMBINE_ARB                    0x8570
#define GL_COMBINE_RGB_ARB                0x8571
#define GL_COMBINE_ALPHA_ARB              0x8572
#define GL_RGB_SCALE_ARB                  0x8573
#define GL_ADD_SIGNED_ARB                 0x8574
#define GL_INTERPOLATE_ARB                0x8575
#define GL_CONSTANT_ARB                   0x8576
#define GL_PRIMARY_COLOR_ARB              0x8577
#define GL_PREVIOUS_ARB                   0x8578
#define GL_SOURCE0_RGB_ARB                0x8580
#define GL_SOURCE1_RGB_ARB                0x8581
#define GL_SOURCE2_RGB_ARB                0x8582
#define GL_SOURCE0_ALPHA_ARB              0x8588
#define GL_SOURCE1_ALPHA_ARB              0x8589
#define GL_SOURCE2_ALPHA_ARB              0x858A
#define GL_OPERAND0_RGB_ARB               0x8590
#define GL_OPERAND1_RGB_ARB               0x8591
#define GL_OPERAND2_RGB_ARB               0x8592
#define GL_OPERAND0_ALPHA_ARB             0x8598
#define GL_OPERAND1_ALPHA_ARB             0x8599
#define GL_OPERAND2_ALPHA_ARB             0x859A
#define GL_SUBTRACT_ARB                   0x84E7
#endif /* !defined(GL_ARB_texture_env_combine) */

#if !defined(GL_ARB_texture_cube_map)
#define GL_NORMAL_MAP_ARB                  0x8511
#define GL_REFLECTION_MAP_ARB              0x8512
#define GL_TEXTURE_CUBE_MAP_ARB            0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB    0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB      0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB   0x851C
#endif /* !defined(GL_ARB_texture_cube_map) */

#if !defined(GL_EXT_texture_filter_anisotropic)
#define GL_TEXTURE_MAX_ANISOTROPY_EXT     0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
#endif /* !defined(GL_EXT_texture_filter_anisotropic) */

#if !defined(GL_ATI_vertex_array_object)
#define GL_STATIC_ATI                           0x8760
#define GL_DYNAMIC_ATI                          0x8761
#define GL_PRESERVE_ATI                         0x8762
#define GL_DISCARD_ATI                          0x8763

#define GL_OBJECT_BUFFER_SIZE_ATI               0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI              0x8765
#define GL_ARRAY_OBJECT_BUFFER_ATI              0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI              0x8767

typedef unsigned int (APIENTRY * PFNGLNEWOBJECTBUFFERATIPROC)(int size,
                                                              const void *pointer,
                                                              unsigned int usage);
typedef unsigned char (APIENTRY * PFNGLISOBJECTBUFFERATIPROC)(unsigned int buffer);
typedef void (APIENTRY * PFNGLUPDATEOBJECTBUFFERATIPROC)(unsigned int buffer,
                                                         unsigned int offset,
                                                         int size,
                                                         const void *pointer,
                                                         unsigned int preserve);
typedef void (APIENTRY * PFNGLFREEOBJECTBUFFERATIPROC)(unsigned int buffer);
typedef void (APIENTRY * PFNGLARRAYOBJECTATIPROC)(unsigned int array,
                                                  int size,
                                                  unsigned int type,
                                                  int stride,
                                                  unsigned int buffer,
                                                  unsigned int offset);
#endif /* !defined(GL_ATI_vertex_array_object) */

#if !defined(GL_ARB_texture_compression)

#define GL_COMPRESSED_ALPHA_ARB                 0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB             0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB       0x84EB
#define GL_COMPRESSED_INTENSITY_ARB             0x84EC
#define GL_COMPRESSED_RGB_ARB                   0x84ED
#define GL_COMPRESSED_RGBA_ARB                  0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB         0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB    0x86A0
#define GL_TEXTURE_COMPRESSED_ARB               0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB   0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB       0x86A3

typedef void (APIENTRY * PFNGLCOMPRESSEDTEXIMAGE3DARB)( unsigned int target,
                                                        int level,
                                                        unsigned int internalformat,
                                                        int width,
                                                        int height,
                                                        int depth,
                                                        int border,
                                                        int imageSize,
                                                        const void *data );

typedef void (APIENTRY * PFNGLCOMPRESSEDTEXIMAGE2DARB)( unsigned int target,
                                                        int level,
                                                        unsigned int internalformat,
                                                        int width,
                                                        int height,
                                                        int border, 
                                                        int imageSize,
                                                        const void *data );

typedef void (APIENTRY * PFNGLCOMPRESSEDTEXIMAGE1DARB)( unsigned int target,
                                                        int level,
                                                        unsigned int internalformat,
                                                        int width,
                                                        int border,
                                                        int imageSize,
                                                        const void *data );

typedef void (APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE3DARB)( unsigned int target,
                                                           int level, 
                                                           int xoffset,
                                                           int yoffset,
                                                           int zoffset,
                                                           int width,
                                                           int height,
                                                           int depth,
                                                           unsigned int format,
                                                           int imageSize,
                                                           const void *data );

typedef void (APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE2DARB)( unsigned int target,
                                                           int level,
                                                           int xoffset,
                                                           int yoffset,
                                                           int width,
                                                           int height,
                                                           unsigned int format,
                                                           int imageSize,
                                                           const void *data );

typedef void (APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE1DARB)( unsigned int target,
                                                           int level, 
                                                           int xoffset,
                                                           int width,
                                                           unsigned int format,
                                                           int imageSize,
                                                           const void *data );

typedef void (APIENTRY * PFNGLGETCOMPRESSEDTEXIMAGEARB)( unsigned int target,
                                                         int lod,
                                                         void *img );

#endif /* !defined(GL_ARB_texture_compression) */

#if !defined(GL_EXT_texture_compression_s3tc)
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT     0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT    0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT    0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT    0x83F3
#endif /* !defined(GL_EXT_texture_compression_s3tc) */

#if !defined(GL_ARB_texture_mirrored_repeat)
#define GL_MIRRORED_REPEAT_ARB			    0x8370
#endif /* !defined(GL_ARB_texture_mirrored_repeat) */

#if !defined(GL_SGIS_generate_mipmap)
#define GL_GENERATE_MIPMAP_SGIS             0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS        0x8192
#endif /* !defined(GL_SGIS_generate_mipmap) */

#if !defined(GL_EXT_texture_edge_clamp)
#define GL_CLAMP_TO_EDGE_EXT                0x812F
#endif /* !defined(GL_EXT_texture_edge_clamp) */

typedef struct RwOpenGLExtensions RwOpenGLExtensions;
/** 
 * \ingroup rwengineopengl
 * \struct RwOpenGLExtensions
 *
 * This type contains the necessary information to query whether
 * an OpenGL extension (and the functions they provide) that RenderWare
 * Graphics requires is supported by the video card drivers on
 * the host computer, and any additional extension-centric data.
 *
 * Function pointers are NULL if the function is not supported.
 * \ref RwBool values are FALSE if the extension is not supported.
 * Other values are dependent on the extension that they refer to.
 */
struct RwOpenGLExtensions
{
    PFNGLLOCKARRAYSEXTPROC                  LockArrays;
        /**< Function pointer to glLockArraysEXT (or glLockArraysSGI).
          *  (Extension \e GL_EXT_compiled_vertex_array
          *  (or \e GL_SGI_compiled_vertex_array).) */

    PFNGLUNLOCKARRAYSEXTPROC                UnlockArrays;
        /**< Function pointer to glUnlockArraysEXT (or glUnlockArraysSGI).
          *  (Extension \e GL_EXT_compiled_vertex_array
          *  (or \e GL_SGI_compiled_vertex_array).) */

    PFNGLFLUSHVERTEXARRAYRANGENVPROC        FlushVertexArrayRangeNV;
        /**< Function pointer to glFlushVertexArrayRangeNV.
          *  (Extension \e GL_NV_vertex_array_range.) */

    PFNGLVERTEXARRAYRANGENVPROC             VertexArrayRangeNV;
        /**< Function pointer to glVertexArrayRangeNV.
          *  (Extension \e GL_NV_vertex_array_range.) */

    PFNWGLALLOCATEMEMORYNVPROC              AllocateMemoryNV;
        /**< Function pointer to wglAllocateMemoryNV.
          *  (Extension \e GL_NV_vertex_array_range.) */

    PFNWGLFREEMEMORYNVPROC                  FreeMemoryNV;
        /**< Function pointer to wglFreeMemoryNV.
          *  (Extension \e GL_NV_vertex_array_range.) */

    PFNGLGENFENCESNVPROC                    GenFencesNV;
        /**< Function pointer to glGenFencesNV.
          *  (Extension \e GL_NV_fence.) */

    PFNGLDELETEFENCESNVPROC                 DeleteFencesNV;
        /**< Function pointer to glDeleteFencesNV.
          *  (Extension \e GL_NV_fence.) */

    PFNGLSETFENCENVPROC                     SetFenceNV;
        /**< Function pointer to glSetFenceNV.
          *  (Extension \e GL_NV_fence.) */

    PFNGLFINISHFENCENVPROC                  FinishFenceNV;
        /**< Function pointer to glFinishFenceNV.
          *  (Extension \e GL_NV_fence.) */

    PFNGLISFENCENVPROC                      IsFenceNV;
        /**< Function pointer to glIsFenceNV.
          *  (Extension \e GL_NV_fence.) */

    PFNGLTESTFENCENVPROC                    TestFenceNV;
        /**< Function pointer to glTestFenceNV.
          *  (Extension \e GL_NV_fence.) */

    RwUInt32                                MaxTextureUnits;
        /**< \ref RwUInt32 containing the value of \c GL_MAX_TEXTURE_UNITS_ARB.
          *  (Extension \e GL_ARB_multitexture.) */

    PFNGLACTIVETEXTUREARBPROC               ActiveTextureARB;
        /**< Function pointer to glActiveTextureARB.
          *  (Extension \e GL_ARB_multitexture.) */

    PFNGLCLIENTACTIVETEXTUREARBPROC         ClientActiveTextureARB;
        /**< Function pointer to glClientActiveTextureARB.
          *  (Extension \e GL_ARB_multitexture.) */

    PFNGLMULTITEXCOORD2FVARBPROC            MultiTexCoord2fvARB;
        /**< Function pointer to glMultiTexCoord2fvARB.
          *  (Extension \e GL_ARB_multitexture.) */

    RwBool                                  TextureEnvCombineARB;
        /**< \ref RwBool, TRUE if the \e GL_ARB_texture_env_combine
          *  extension is supported, FALSE if not. */

    RwBool                                  TextureEnvAddARB;
        /**< \ref RwBool, TRUE if the \e GL_ARB_texture_env_add
          *  extension is supported, FALSE if not. */

    RwBool                                  TextureCubeMapARB;
        /**< \ref RwBool, TRUE if the \e GL_ARB_texture_cube_map
          *  extension is supported, FALSE if not. */

    RwUInt32                                MaxCubeMapSize;
        /**< \ref RwUInt32 containing the maximum cube map size allowed.
          *  The width and height of the cube map must be the same. */

    RwBool                                  VertexArrayRange2NV;
        /**< \ref RwBool, TRUE if the \e GL_NV_vertex_array_range2
          *  extension is supported, FALSE if not. */

    RwInt8                                  MaxTextureAnisotropy;
        /**< \ref RwInt8 containing the maximum texture anisotropy, or 0
          *  if the \e GL_EXT_texture_filter_anisotropic is not supported. */

    PFNGLNEWOBJECTBUFFERATIPROC             NewObjectBufferATI;
        /**< Function pointer to glNewObjectBufferATI.
          *  (Extension \e GL_ATI_vertex_array_object.) */

    PFNGLISOBJECTBUFFERATIPROC              IsObjectBufferATI;
        /**< Function pointer to glIsObjectBufferATI.
          *  (Extension \e GL_ATI_vertex_array_object.) */
    
    PFNGLUPDATEOBJECTBUFFERATIPROC          UpdateObjectBufferATI;
        /**< Function pointer to glUpdateObjectBufferATI.
          *  (Extension \e GL_ATI_vertex_array_object.) */

    
    PFNGLFREEOBJECTBUFFERATIPROC            FreeObjectBufferATI;
        /**< Function pointer to glFreeObjectBufferATI.
          *  (Extension \e GL_ATI_vertex_array_object.) */
    
    PFNGLARRAYOBJECTATIPROC                 ArrayObjectATI;
        /**< Function pointer to glArrayObjectATI.
          *  (Extension \e GL_ATI_vertex_array_object.) */

    PFNGLCOMPRESSEDTEXIMAGE3DARB            CompressedTexImage3DARB;
        /**< Function pointer to glCompressedTexImage3DARB.
          *  (Extension \e GL_ARB_texture_compression.) */

    PFNGLCOMPRESSEDTEXIMAGE2DARB            CompressedTexImage2DARB;
        /**< Function pointer to glCompressedTexImage2DARB.
          *  (Extension \e GL_ARB_texture_compression.) */

    PFNGLCOMPRESSEDTEXIMAGE1DARB            CompressedTexImage1DARB;
        /**< Function pointer to glCompressedTexImage1DARB.
          *  (Extension \e GL_ARB_texture_compression.) */

    PFNGLCOMPRESSEDTEXSUBIMAGE3DARB         CompressedTexSubImage3DARB;
        /**< Function pointer to glCompressedTexSubImage3DARB.
          *  (Extension \e GL_ARB_texture_compression.) */

    PFNGLCOMPRESSEDTEXSUBIMAGE2DARB         CompressedTexSubImage2DARB;
        /**< Function pointer to glCompressedTexSubImage2DARB.
          *  (Extension \e GL_ARB_texture_compression.) */

    PFNGLCOMPRESSEDTEXSUBIMAGE1DARB         CompressedTexSubImage1DARB;
        /**< Function pointer to glCompressedTexSubImage1DARB.
          *  (Extension \e GL_ARB_texture_compression.) */

    PFNGLGETCOMPRESSEDTEXIMAGEARB           GetCompressedTexImageARB;
        /**< Function pointer to glGetCompressedTexImageARB.
          *  (Extension \e GL_ARB_texture_compression.) */

    RwBool                                  TextureCompressionS3TCEXT;
        /**< \ref RwBool, TRUE if the \e GL_EXT_texture_compression_s3tc
          *  extension is supported, FALSE if not. */

    RwBool                                  TextureMirroredRepeatARB;
        /**< \ref RwBool, TRUE if the \e GL_ARB_texture_mirrored_repeat
          *  extension is supported, FALSE if not. */

    RwBool                                  GenerateMipmapSGIS;
        /**< \ref RwBool, TRUE if the \e GL_SGIS_generate_mipmap
          *  extension is supported, FALSE if not. */

    RwBool                                  TextureEdgeClampEXT;
        /**< \ref RwBool, TRUE if the \e GL_EXT_texture_edge_clamp
          *  extension is supported, FALSE if not. */

    RwBool                                  BlendSquareNV;
        /**< \ref RwBool, TRUE if the \e GL_NV_blend_square
          *  extension is supported, FALSE if not. */
};


typedef struct RwXWindowInfo RwXWindowInfo;
#if (!defined(DOXYGEN))
struct RwXWindowInfo
{
    void    *display;
    void    *window;
    void    *visualInfo;
};
#endif /* (!defined(DOXYGEN)) */

/* make the Win32 OpenGL pixel format descriptor accessible */
#if defined( _WIN32 )

extern PIXELFORMATDESCRIPTOR _rwOpenGLPixelFormatDesc;

#endif /* defined( _WIN32 ) */


#endif /* OPENGL_DRVMODEL_H */

/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/opengl/pip2model.h ---*/

/* =====================================================================
 *  Defines
 * ===================================================================== */

#define RXHEAPPLATFORMDEFAULTSIZE  (1 << 12) /* 4k */

/* --- MISCELLANEOUS --- */
#define RwIm3DVertexGetNext(_vert)  ((_vert) + 1)

/* --- POSITION --- */
#define RxObjSpace3DVertexGetPos(_vert,_pos)    \
    RwV3dAssign( (RwV3d *)(_pos),               \
                 (const RwV3d *)(&((_vert)->position)) )

#define RxObjSpace3DLitVertexGetPos(_vert,_pos)     \
    RxObjSpace3DVertexGetPos(_vert,_pos)

#define RwIm3DVertexGetPos(_vert)   \
    (&((_vert)->position))

#define RxObjSpace3DVertexSetPos(_vert,_pos)        \
    RwV3dAssign( (RwV3d *)(&((_vert)->position)),   \
                 (const RwV3d *)(_pos) )

#define RxObjSpace3DLitVertexSetPos(_vert,_pos)     \
    RxObjSpace3DVertexSetPos(_vert,_pos)

#define RwIm3DVertexSetPos(_vert,_imx,_imy,_imz)    \
MACRO_START                                         \
{                                                   \
    RwV3d   tempV3d;                                \
    tempV3d.x = (_imx);                             \
    tempV3d.y = (_imy);                             \
    tempV3d.z = (_imz);                             \
    RxObjSpace3DLitVertexSetPos((_vert),&tempV3d);  \
}                                                   \
MACRO_STOP

/* --- PRELIGHT --- */
#define RxObjSpace3DVertexGetPreLitColor(_vert,_col)    \
    RwRGBAAssign( (RwRGBA *)(_col),                     \
                  (const RwRGBA *)(&((_vert)->color)) )

#define RxObjSpace3DVertexSetPreLitColor(_vert,_col)    \
    RwRGBAAssign( (RwRGBA *)(&((_vert)->color)),        \
                  (const RwRGBA *)(_col) )

/* --- COLOR --- */
#define RxObjSpace3DVertexGetColor  \
    RxObjSpace3DVertexGetPreLitColor

#define RxObjSpace3DLitVertexSetColor   \
    RxObjSpace3DVertexSetPreLitColor

#define RwIm3DVertexSetRGBA(_vert,_imr,_img,_imb,_ima)  \
MACRO_START                                             \
{                                                       \
    RwRGBA tempRGBA;                                    \
    tempRGBA.red   = (_imr);                            \
    tempRGBA.green = (_img);                            \
    tempRGBA.blue  = (_imb);                            \
    tempRGBA.alpha = (_ima);                            \
    RxObjSpace3DLitVertexSetColor(_vert, &tempRGBA);    \
}                                                       \
MACRO_STOP

/* --- NORMALS --- */
#define RxObjSpace3DVertexGetNormal(_vert,_normal)  \
    RwV3dAssign( (RwV3d *)(_normal),                \
                 (const RwV3d *)(&((_vert)->normal)) )

#define RwIm3DVertexGetNormal(_vert)   \
    (RwV3d *)( &((_vert)->normal) )

#define RxObjSpace3DVertexSetNormal(_vert,_normal)  \
    RwV3dAssign( (RwV3d *)(&((_vert)->normal)),     \
                 (const RwV3d *)(_normal) )

#define RwIm3DVertexSetNormal(_vert,_imnx,_imny,_imnz)  \
MACRO_START                                             \
{                                                       \
    RwV3d   tempV3d;                                    \
    tempV3d.x = (_imnx);                                \
    tempV3d.y = (_imny);                                \
    tempV3d.z = (_imnz);                                \
    RxObjSpace3DVertexSetNormal((_vert),&tempV3d);      \
}                                                       \
MACRO_STOP

/* --- TEXTURE COORDINATES --- */
#define RxObjSpace3DVertexGetU(_vert)   \
    ((_vert)->texCoords.u)

#define RxObjSpace3DVertexGetV(_vert)    \
    ((_vert)->texCoords.v)

#define RxObjSpace3DVertexSetU(_vert,_imu)   \
    ((_vert)->texCoords.u = (_imu))

#define RxObjSpace3DLitVertexSetU(_vert,_imu)   \
    RxObjSpace3DVertexSetU(_vert,_imu)

#define RwIm3DVertexSetU    \
    RxObjSpace3DLitVertexSetU

#define RxObjSpace3DVertexSetV(_vert,_imv)   \
    ((_vert)->texCoords.v = (_imv))

#define RxObjSpace3DLitVertexSetV(_vert,_imv)   \
    RxObjSpace3DVertexSetV(_vert,_imv)

#define RwIm3DVertexSetV    \
    RxObjSpace3DLitVertexSetV


/* =====================================================================
 *  Module specific type definitions
 * ===================================================================== */

/**
 * \ingroup rwcoregeneric
 * \struct RxObjSpace3DVertex
 * Typedef for an RxObjSpace3DVertex.
 */
typedef struct RxObjSpace3DVertex RxObjSpace3DVertex;

/*
 * Structure representing object space vertex.
 */
#if (!defined(DOXYGEN))
struct RxObjSpace3DVertex
{
    RwV3d       position;   /* RwV3d containing the position of the vertex */

    RwV3d       normal;     /* RwV3d containing the vertex normal */

    RwRGBA      color;      /* RwRGBA containing the vertex color */

    RwTexCoords texCoords;  /* RwTexCoords containing one set of texture coordinates for the vertex */
};
#endif /* (!defined(DOXYGEN)) */

/* this vertex should not be truncated */
#define RxObjSpace3DVertexNoUVsNoNormalsSize    (sizeof(RxObjSpace3DVertex))
#define RxObjSpace3DVertexNoUVsSize             (sizeof(RxObjSpace3DVertex))
#define RxObjSpace3DVertexFullSize              (sizeof(RxObjSpace3DVertex))

/**
 * \ingroup rwcoregeneric
 * \ref RxObjSpace3DLitVertex
 * Typedef for an RxObjSpace3DLitVertex
 */
typedef RxObjSpace3DVertex RxObjSpace3DLitVertex;

/**
 * \ingroup rwim3dvertex
 * \ref RwIm3DVertex
 * Typedef for an RwIm3DVertex
 */
typedef RxObjSpace3DLitVertex RwIm3DVertex;

/**
 * \ingroup rwcoregeneric
 * \ref RxScrSpace2DVertex
 * Typedef for an RxScrSpace2DVertex structure
 */
typedef RwIm2DVertex RxScrSpace2DVertex;


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2resort.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2macros.h ---*/

#define RxClusterDecCursorByStride(_cluster, _stride)                           \
    ((_cluster)->currentData =                                                  \
      (void *)(((RwUInt8 *)(_cluster)->currentData) -                           \
         (_stride)))

#define RxClusterDecCursor(_cluster) \
    RxClusterDecCursorByStride(_cluster, (_cluster)->stride)

#define RxClusterIncCursorByStride(_cluster, _stride)                           \
    ((_cluster)->currentData =                                                  \
     (void *)(((RwUInt8 *)(_cluster)->currentData) +                            \
              (_stride)))

#define RxClusterIncCursor(_cluster) \
    RxClusterIncCursorByStride(_cluster, (_cluster)->stride)

#define RxClusterResetCursor(_cluster) \
    ((_cluster)->currentData = (_cluster)->data)

#define RxClusterGetCursorData(_cluster, _type) \
    ((_type *)(_cluster)->currentData)

#define RxClusterGetIndexedData(_cluster, _type, _index)                        \
    ((_type *)(((RwUInt8 *)(_cluster)->data) + (_cluster)->stride*(_index)))

#define RxClusterGetFreeIndex(_cluster) ( (_cluster)->numUsed++ )

#define RxPipelineClusterAssertAttributeSet(_cluster, _attributeSet)    \
    RWASSERT( (_cluster)->clusterRef->attributeSet != NULL &&           \
              rwstrcmp((_cluster)->clusterRef->attributeSet,              \
                     (_attributeSet)) == 0 )

#define RxPipelineNodeParamGetData(_param) \
    ( (_param)->dataParam )

#define RxPipelineNodeParamGetHeap(_param) \
    ( (_param)->heap )



/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2heap.h ---*/

#if (defined(RWDEBUG) && (defined(RWMEMDEBUG)))

#if (!defined(DISABLERWHEAP))
#define DISABLERWHEAP
#endif /* (!defined(DISABLERWHEAP)) */

#endif /* (defined(RWDEBUG) && (defined(RWMEMDEBUG))) */

typedef struct rxHeapFreeBlock rxHeapFreeBlock;
typedef struct rxHeapSuperBlockDescriptor rxHeapSuperBlockDescriptor;
typedef struct RxHeap RxHeap;
typedef struct rxHeapBlockHeader rxHeapBlockHeader;

#if (!defined(DOXYGEN))
struct rxHeapFreeBlock
{
    RwUInt32            size;
    rxHeapBlockHeader  *ptr;
};

struct rxHeapSuperBlockDescriptor
{
    void *start;
    RwUInt32 size;
    rxHeapSuperBlockDescriptor *next;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwcoregeneric
 * \struct RxHeap 
 * structure describing a pipeline execution heap 
 */
struct RxHeap
{
    RwUInt32            superBlockSize; /**< Granularity of heap growth */
    rxHeapSuperBlockDescriptor *head;   /**< Internally used superblock pointer */
    rxHeapBlockHeader  *headBlock;      /**< Internally used block pointer */
    rxHeapFreeBlock    *freeBlocks;     /**< Internally used free blocks pointer */
    RwUInt32            entriesAlloced; /**< Number of entries allocated */
    RwUInt32            entriesUsed;    /**< Number of entries used */
    RwBool              dirty;          /**< Internally used boolean, flags whether
                                         *   the heap needs resetting or not. */
};

#if (!defined(DOXYGEN))
struct rxHeapBlockHeader
{
    /* present in all blocks (used & unused) */
    rxHeapBlockHeader  *prev, *next;
    RwUInt32            size;
    rxHeapFreeBlock    *freeEntry; /* (or null) */
    RwUInt32            pad[4]; /* alignment padding to 32 bytes */
};
#endif /* (!defined(DOXYGEN)) */

/* This wrapper cheaply early-outs when a heap doesn't *need* resetting */
#define RxHeapReset(heap) \
    ((FALSE == (heap)->dirty) ? (TRUE) : (_rxHeapReset(heap)))

#ifdef __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

extern RxHeap      *RxHeapCreate(RwUInt32 size);
extern void         RxHeapDestroy(RxHeap * heap);
extern RwBool       _rxHeapReset(RxHeap * heap);
extern void        *RxHeapAlloc(RxHeap * heap, RwUInt32 size);
extern void         RxHeapFree(RxHeap * heap, void *block);
extern void        *RxHeapRealloc(RxHeap * heap, void *block,
                                  RwUInt32 newSize, RwBool allowCopy);

#ifdef __cplusplus
}
#endif                          /* __cplusplus */

#if (defined(DISABLERWHEAP))

typedef struct rxHeapMallocTrace rxHeapMallocTrace;
struct rxHeapMallocTrace
{
    rxHeapMallocTrace *next;
    rxHeapBlockHeader *block;
};

#endif                          /* (defined(DISABLERWHEAP)) */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2dep.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2core.h ---*/

extern RwInt32 _rxPipelineMaxNodes;
extern RwInt32 _rxHeapInitialSize;
/* LEGACY-SUPPORT MACRO */
#define _rwRxHeapInitialSize _rxHeapInitialSize

/* Beneficial padding of PowerPipe types is still being worked out... */
#define PADCLUSTERSx


/*************************************************************
 * Global Defines
 */

#define RWBOOLTOGGLE(bVar) ((bVar == FALSE)?(bVar = TRUE):(bVar = FALSE))

/* Both these currently limited due to the use of RwUInt32 bit-fields */
#define RXNODEMAXCLUSTERSOFINTEREST 32
#define RXNODEMAXOUTPUTS            32

/* Useful (for memory alloc) to limit this during pipeline construction */
#define RXPIPELINEDEFAULTMAXNODES   64

/*
 * Cluster flags
 */

#define rxCLFLAGS_NULL          ((RwUInt16) 0x0000U)
#define rxCLFLAGS_CLUSTERVALID  ((RwUInt16) 0x0001U)
#define rxCLFLAGS_EXTERNAL ((RwUInt16) 0x0002U)
#define rxCLFLAGS_EXTERNALMODIFIABLE ((RwUInt16) 0x0004U | 0x0002U)
#define rxCLFLAGS_MODIFIED ((RwUInt16) 0x0008U)

/*
 * Packet flags
 */

#define rxPKFLAGS_NULL        ((RwUInt16) 0x0000U)

/*
 * used in input specification
 */

/**
 * \ingroup rwcoregeneric
 * \ref RxClusterValidityReq
 * Flags specifying the state requirements for
 * a \ref RxCluster on entry to a node */
enum RxClusterValidityReq
{
    rxCLREQ_DONTWANT = 0, /**<The cluster is required but any data within it is
                           * not wanted and will be overwritten */
    rxCLREQ_REQUIRED = 1, /**<The cluster is required and it must contain
                           * valid data */
    rxCLREQ_OPTIONAL = 2, /**<The cluster will be used if it is present and
                           * contains valid data, otherwise the node will
                           * make do without it. */
    rxCLUSTERVALIDITYREQFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};


/**
 * \ingroup rwcoregeneric
 * \ref RxClusterValid
 * Flags specifying the state requirements for
 * a \ref RxCluster on exit from a node */
enum RxClusterValid
{
    rxCLVALID_NOCHANGE = 0, /**<The cluster and its data will not change in
                             * validity on passing through this node */
    rxCLVALID_VALID = 1,    /**<The cluster and its data will be valid on
                             * exit from this node */
    rxCLVALID_INVALID = 2,  /**<The cluster's data will be invalid on
                             * exit from this node */
    rxCLUSTERVALIDFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};

/****************************************************************************
 Global Types
 */

typedef struct RxClusterDefinition RxClusterDefinition;

typedef struct rxReq rxReq;

typedef enum RxClusterValidityReq RxClusterValidityReq;
typedef enum RxClusterValid RxClusterValid;
typedef struct RxOutputSpec RxOutputSpec;
typedef struct RxClusterRef RxClusterRef;
typedef struct RxIoSpec RxIoSpec;

typedef struct RxNodeMethods RxNodeMethods;
typedef struct RxNodeDefinition RxNodeDefinition;

typedef struct RxCluster RxCluster;
typedef struct RxPipelineCluster RxPipelineCluster;
typedef struct RxPacket RxPacket;
typedef struct RxPipelineNode RxPipelineNode;
typedef struct RxPipelineNodeTopSortData RxPipelineNodeTopSortData;
typedef struct RxPipelineNode RxPipelineNodeInstance;
typedef struct RxPipelineNodeParam RxPipelineNodeParam;
typedef struct RxExecutionContext RxExecutionContext;
typedef struct RxPipelineRequiresCluster RxPipelineRequiresCluster;
typedef struct RxPipeline RxPipeline;

/***************************************************************************
 *
 * C L U S T E R   D E F I N I T I O N
 *
 ***************************************************************************/

/**
 * \ingroup rwcoregeneric
 * \struct RxClusterDefinition
 * Structure describing a cluster */
struct RxClusterDefinition
{
    RwChar             *name;                  /**< Name */
    RwUInt32            defaultStride;         /**< Default stride */
    RwUInt32            defaultAttributes;     /**< Default attributes */
    const RwChar         *attributeSet;           /**< Attribute set */
};


/***************************************************************************
 *
 * N O D E   D E F I N I T I O N   S T R U C T S
 *
 ***************************************************************************/

/**
 * \ingroup rwcoregeneric
 * \struct RxOutputSpec
 * Structure describing an output specification of a node */
struct RxOutputSpec
{
     RwChar             *name;                  /**< Name */
     RxClusterValid     *outputClusters;        /**< States of clusters of interest on output */
     RxClusterValid      allOtherClusters;      /**< States of clusters not of interest on output */
};



/**
 * \ingroup rwcoregeneric
 * \ref RxClusterForcePresent
 *  Flags specifying whether an \ref RxCluster
 * should be forced to be present in an \ref RxPipelineNode */
enum RxClusterForcePresent
{
    rxCLALLOWABSENT = FALSE, /**<The cluster is allowed to be absent if no prior
                              *  nodes create it and no subsequent nodes require it */
    rxCLFORCEPRESENT = TRUE, /**<The cluster must be present even if no prior
                              *  nodes create it and no subsequent nodes require it */

    rxCLUSTERFORCEPRESENTFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxClusterForcePresent RxClusterForcePresent;

/**
 * \ingroup rwcoregeneric
 * \struct RxClusterRef
 * Structure describing a cluster reference */
struct RxClusterRef
{
    RxClusterDefinition  *clusterDef;           /**< Cluster definition */
    RxClusterForcePresent forcePresent;         /**< Specifies whether the cluster should be forced present */
    RwUInt32              reserved;             /**< Omit or initialize to zero */
};

#define rxCLRESERVED       ((RwUInt32)0)

/**
 * \ingroup rwcoregeneric
 * \struct RxIoSpec
 * Structure describing an input/output specification of a node */
struct RxIoSpec
{
    RwUInt32              numClustersOfInterest;/**< Number of Clusters of interest */
    RxClusterRef         *clustersOfInterest;   /**< Clusters of interest array */
    RxClusterValidityReq *inputRequirements;    /**< Requirements of the clusters of interest on input to the node */
    RwUInt32              numOutputs;           /**< Number of outputs from the node */
    RxOutputSpec         *outputs;              /**< Output specification array */
};

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeBodyFn is the callback to be
 * called during pipeline execution -- and, typically, process
 * \ref RxPacket's -- for the owning pipeline node.
 *
 * \param  self   A pointer to the pipeline node being executed
 * \param  params   A pointer to a parameter structure
 *
 * \return TRUE on success, FALSE otherwise.
 *
 * \see RxNodeMethods
 */
typedef RwBool (*RxNodeBodyFn) (RxPipelineNode * self,
                                const RxPipelineNodeParam *params);

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeInitFn
 * is the callback to be called,
 * for the owning node definition, the first time an \ref RxPipeline
 * referencing that node definition is unlocked.
 *
 * \param  self   A pointer to the node definition
 *
 * \return TRUE on success, FALSE otherwise.
 *
 * \see RxNodeMethods
 */
typedef RwBool (*RxNodeInitFn) (RxNodeDefinition * self);

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeTermFn
 * is the callback to be called,
 * for the owning node definition, the last time an \ref RxPipeline
 * referencing that node definition is destroyed or locked.
 *
 * \param  self   A pointer to the node definition
 *
 * \return None
 *
 * \see RxNodeMethods
 */
typedef void   (*RxNodeTermFn) (RxNodeDefinition * self);

/**
 * \ingroup rwcoregeneric
 * \ref RxPipelineNodeInitFn
 * is the callback to be called, for the owning pipeline node, whenever a
 * \ref RxPipeline containing that that pipeline node is unlocked.
 *
 * \param  self   A pointer to the pipeline node
 *
 * \return TRUE on success, FALSE otherwise.
 *
 * \see RxNodeMethods
 */
typedef RwBool (*RxPipelineNodeInitFn) (RxPipelineNode * self);

/**
 * \ingroup rwcoregeneric
 * \ref RxPipelineNodeTermFn
 * is the callback to be called, for the owning pipeline node, whenever a
 * \ref RxPipeline containing that that pipeline node is locked or
 * destroyed.
 *
 * \param  self   A pointer to the pipeline node
 *
 * \return None
 *
 * \see RxNodeMethods
 */
typedef void   (*RxPipelineNodeTermFn) (RxPipelineNode * self);

/**
 * \ingroup rwcoregeneric
 * \ref RxPipelineNodeConfigFn
 * is the callback to be called, for the owning pipeline node, whenever a
 * \ref RxPipeline containing that that pipeline node is unlocked,
 * *after* all \ref RxPipelineNodeInitFn's have been called for the
 * pipeline in question. This func is to be used as described in
 * RxPipelineNodeSendConfigMsg.
 *
 * \param  self       A pointer to the pipeline node
 * \param  pipeline   A pointer to the containing pipeline
 *
 * \return TRUE on success, FALSE otherwise.
 *
 * \see RxNodeMethods
 */
typedef RwBool (*RxPipelineNodeConfigFn) (RxPipelineNode * self,
                                          RxPipeline * pipeline);

/**
 * \ingroup rwcoregeneric
 * \ref RxConfigMsgHandlerFn
 * is the callback to be called, for the owning pipeline node, whenever
 * a message is sent to it by the \ref RxPipelineNodeConfigFn of another
 * pipeline node in the same pipeline. See \ref RxPipelineNodeSendConfigMsg.
 * 
 * \param  self   A pointer to the pipeline node
 * \param  msg   Message ID
 * \param  intparam   Meaning is message-specific
 * \param  ptrparam   Meaning is message-specific
 *
 * \return A RwInt32 value, 0: unserviced; -ve: error; +ve: informative success
 * 
 * \see RxNodeMethods
 */
typedef RwUInt32 (*RxConfigMsgHandlerFn) (RxPipelineNode * self,
                                          RwUInt32 msg,
                                          RwUInt32 intparam,
                                          void *ptrparam);

/**
 * \ingroup rwcoregeneric
 * \struct RxNodeMethods
 * A structure describing a set
 * of node methods
 *
 * \see RxNodeBodyFn
 * \see RxNodeInitFn
 * \see RxNodeTermFn
 * \see RxPipelineNodeInitFn
 * \see RxPipelineNodeTermFn
 * \see RxPipelineNodeConfigFn
 * \see RxConfigMsgHandlerFn
 */
struct RxNodeMethods
{
    RxNodeBodyFn         nodeBody;              /**< Node body function */
    RxNodeInitFn         nodeInit;              /**< Node initialization function */
    RxNodeTermFn         nodeTerm;              /**< Node termination function */
    RxPipelineNodeInitFn pipelineNodeInit;      /**< Pipeline node initialization function */
    RxPipelineNodeTermFn pipelineNodeTerm;      /**< Pipeline node termination function */
    RxPipelineNodeConfigFn pipelineNodeConfig;  /**< Pipleline node configuation function */
    RxConfigMsgHandlerFn configMsgHandler;      /**< Configuaraton message handler function */
};

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeDefEditable
 * Flags specifying whether an \ref RxNodeDefinition
 * is editable or not (\ref RxPipelineNodeCloneDefinition,
 * \ref RxPipelineNodeReplaceCluster and \ref RxPipelineNodeRequestCluster
 * create editable copies of node definitions as the originals may be
 * static definitions). */
enum RxNodeDefEditable
{
    /**<This node definition should not be freed */
    rxNODEDEFCONST = FALSE,
    /**< This node definition is a temporary,
     * modified copy of another and can be freed */
    rxNODEDEFEDITABLE = TRUE,
    rxNODEDEFEDITABLEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxNodeDefEditable RxNodeDefEditable;

/**
 * \ingroup rwcoregeneric
 * \struct RxNodeDefinition
 * A structure describing a node definition */
struct RxNodeDefinition
{
    RwChar             *name;                   /**< Name */
    RxNodeMethods       nodeMethods;            /**< Node methods */
    RxIoSpec            io;                     /**< Input/output specification */
    RwUInt32            pipelineNodePrivateDataSize; /**< Size in bytes of node's private data  */
    RxNodeDefEditable   editable;               /**< Flags whether a node is editable */
    RwInt32             InputPipesCnt;          /**< Count of the unlocked pipelines containing this node */
};

/***************************************************************************
 *
 * P I P E L I N E - E X E C U T I O N - T I M E   S T R U C T S
 *
 ***************************************************************************/

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineCluster
 * A structure describing a pipeline cluster;
 * that is, an \ref RxClusterDefinition in the context of a specific \ref RxPipeline
 * (in the same way as an \ref RxPipelineNode is an \ref RxNodeDefinition in the
 * context of a specific \ref RxPipeline). The \ref RxCluster is the structure
 * representing this and the \ref RxClusterDefinition within \ref RxPacket's at
 * pipeline-execution-time */
struct RxPipelineCluster
{
    RxClusterDefinition *clusterRef;            /**< Cluster refererence */
    RwUInt32             creationAttributes;    /**< Creation Attributes */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxCluster
 * A structure describing a cluster; this is
 * the representative of an \ref RxClusterDefinition and \ref RxPipelineCluster
 * within \ref RxPacket's at pipeline-execution-time. */
struct RxCluster
{
    RwUInt16            flags;                  /**< Bitfield of flags e.g. modification permissions */
    RwUInt16            stride;                 /**< Stride in bytes of the cluster's data */
    void               *data;                   /**< The Cluster's data */
    void               *currentData;            /**< A 'cursor', referencing the current element in the data */
    RwUInt32            numAlloced;             /**< Allocated count */
    RwUInt32            numUsed;                /**< Used count */
    RxPipelineCluster  *clusterRef;             /**< Valid after a cluster has been locked for writing,
                                                 *   otherwise NULL. Analog of \ref RxPipelineNode and
                                                 *   its 'nodeDef' member. */
    RwUInt32            attributes;             /**< Attributes */
#ifdef PADCLUSTERS
    RwUInt32 pad[1];                            /**< Alignment padding */
#endif
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPacket
 * A structure describing a packet header */
struct RxPacket
{
    RwUInt16            flags;                  /**< Flags to guide pipeline execution */
    RwUInt16            numClusters;            /**< Maximum number of clusters simultanesouly present in the current pipeline */
    RxPipeline         *pipeline;               /**< The pipeline in which this packet is embedded (the current pipeline) */
    RwUInt32           *inputToClusterSlot;     /**< LUT to locate clusters of interest in the packet */
    RwUInt32           *slotsContinue;          /**< Bitfields specifying clusters persisting to output node */
    RxPipelineCluster **slotClusterRefs;        /**< Internal Use */
#ifdef PADCLUSTERS
    RwUInt32 pad[3];                            /**< Alignment padding */
#endif
    RxCluster           clusters[1];            /**< Cluster array large enough for widest part of the pipeline */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineNode
 * Structure describing a pipeline Node;
 * that is an \ref RxNodeDefinition in the context 
 * of a specific \ref RxPipeline. 
 */
struct RxPipelineNode
{
    RxNodeDefinition   *nodeDef;            /**< Node definition reference */
    RwUInt32            numOutputs;         /**< Output count */
    RwUInt32           *outputs;            /**< Output array, indexing the pipeline's array of pipeline nodes */
    RxPipelineCluster **slotClusterRefs;    /**< For packets passing through this node, SlotClusterRefs[n]
                                             * identifies the cluster to be found at index n in the packet's
                                             * Clusters[] array. These assignments are determined at pipeline
                                             * Unlock() time and are good for the life of the pipeline. */
    RwUInt32           *slotsContinue;      /**< Cluster persistence table for the node's outputs */
    void               *privateData;        /**< Pointer to the pipeline Node's private data */
    RwUInt32           *inputToClusterSlot; /**< LUT to locate clusters of interest in packets passing through this pipeline Node */
    RxPipelineNodeTopSortData *topSortData; /**< Internal Use */
    void               *initializationData; /**< Used by the pipeline node initialisation
                                             * function in setting up the Private data. */
    RwUInt32        initializationDataSize; /**< Present so that if the node is cloned
                                             * we can copy the initialisation data. */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineNodeTopSortData
 * Structure describing data used during topological sorting 
 * during \ref RxLockedPipeUnlock ; 
 * RenderWare users do not need to understand this */
struct RxPipelineNodeTopSortData
{
    RwUInt32            numIns;                 /**< Input count */
    RwUInt32            numInsVisited;          /**< Count of inputs visited during dependencies
                                                 * propagation/cluster slot allocation */
    rxReq              *req;                    /**< Req used in dependencies propagation/cluster
                                                 * slot allocation */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineNodeParam
 * Structure holding parameters
 * to pass to node body functions */
struct RxPipelineNodeParam
{
    void   *dataParam;   /**< The data pointer passed in to \ref RxPipelineExecute */
    RxHeap *heap;        /**< The heap associated with the current pipeline exeuction */
};

enum rxEmbeddedPacketState
{
    rxPKST_PACKETLESS = 0, /* Packet not created */
    rxPKST_UNUSED     = 1, /* Packet created and then destroyed */
    rxPKST_INUSE      = 2, /* Packet created but not yet destroyed and fetched but not yet dispatched */
    rxPKST_PENDING    = 3, /* Packet created but not destroyed and dispatched but not yet fetched */
    rxEMBEDDEDPACKETSTATEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum rxEmbeddedPacketState rxEmbeddedPacketState;

/**
 * \ingroup rwcoregeneric
 * \struct RxExecutionContext
 * Structure describing an execution context */
struct RxExecutionContext
{
    RxPipeline           *pipeline;     /**< Currently executing pipeline */
    RxPipelineNode       *currentNode;  /**< Currently executing node */
    RwInt32               exitCode;     /**< Used internally for nodes returning error codes on exit */
    RwUInt32              pad;          /**< Alignment padding */
    RxPipelineNodeParam   params;       /**< The parameters passed to node bodies */
    /*RwUInt32              pad[2];*/
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipelineRequiresCluster
 * Structure describing a pipeline requirement of a cluster */
struct RxPipelineRequiresCluster
{
    RxClusterDefinition *clusterDef;    /**< Reference to a Cluster definition */
    RxClusterValidityReq rqdOrOpt;      /**< Cluster validity requirement (rxCLREQ_DONTWANT, rxCLREQ_REQUIRED or rxCLREQ_OPTIONAL) */
    RwUInt32             slotIndex;     /**< Index into the packet's cluster array within this pipeline */
};

/**
 * \ingroup rwcoregeneric
 * \struct RxPipeline
 * Structure describing a pipeline */
struct RxPipeline
{
    RwBool                     locked;                /**< Flags whether the pipeline is locked for editing */
    RwUInt32                   numNodes;              /**< Node count */
    RxPipelineNode            *nodes;                 /**< Topologically sorted array of pipeline nodes */
    RwUInt32                   packetNumClusterSlots; /**< Number of slots allocated for clusters */
    rxEmbeddedPacketState      embeddedPacketState;   /**< The state of this pipeline's embedded packet */
    RxPacket                  *embeddedPacket;        /**< This pipeline's embedded packet */

    RwUInt32                   numInputRequirements;  /**< Input requirements count */
    RxPipelineRequiresCluster *inputRequirements;     /**< Input requirements array */

    void                      *superBlock;            /**< Internally used block of memory */
    RwUInt32                   superBlockSize;        /**< Internally used block of memory */

    RwUInt32                   entryPoint;            /**< The index of the node which is the entry point of this pipeline */
    RwUInt32                   pluginId;              /**< If required, the Id of the plugin owning this pipeline, or 0 */
    RwUInt32                   pluginData;            /**< Rights callback extra data */
};

/****************************************************************************
 * Global Prototypes
 */

/**
 * \ingroup rwcoregeneric
 * \ref RxPipelineNodeOutputCallBack 
 * is the callback function supplied 
 * to \ref RxPipelineNodeForAllConnectedOutputs.
 *
 * The callback will be passed a pointer to the \ref RxPipelineNode whose
 * outputs are being traversed and a pointer to the current output
 * \ref RxPipelineNode, as well as a pointer to an optional user-defined
 * data structure (callbackdata). If no such structure was specified, this
 * will be NULL.
 *
 * \param  node         A pointer to the pipeline node whose outputs
 *                      are being traversed
 * \param  outputnode   A pointer to the current output
 *                      pipeline node
 * \param  callbackdata A pointer to optional user-supplied data
 *
 * \return Returns a pointer to the \ref RxPipelineNode whose outputs are being
 * traversed, or NULL to terminate traversal
 */
typedef RxPipelineNode * (*RxPipelineNodeOutputCallBack) (RxPipelineNode * node,
                                                  RxPipelineNode * outputnode,
                                                  void *callbackdata);

#ifdef RWDEBUG
#define RXCHECKFORUSERTRAMPLING(_pipeline)                       \
    ( _rwPipelineCheckForTramplingOfNodePrivateSpace(_pipeline) )
#endif /* RWDEBUG */

#if (!defined(RXCHECKFORUSERTRAMPLING))
#define RXCHECKFORUSERTRAMPLING(_pipeline) /* No op */
#endif /* (!defined(RXCHECKFORUSERTRAMPLING)) */


#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

extern void
RxPipelineSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwBool
_rxPipelineOpen(void);

extern RwBool
_rxPipelineClose(void);

extern RwBool
rxPipelinePluginsAttach(void);

extern RxPipeline *
RxPipelineCreate(void);


extern void
_rxPipelineDestroy(RxPipeline * Pipeline);

#define _RxPipelineDestroy(_ppln)  _rxPipelineDestroy(_ppln)
#define RxPipelineDestroy(_ppln) (_rxPipelineDestroy(_ppln), TRUE)

extern RxHeap      *
RxHeapGetGlobalHeap(void);

extern RxPipeline *
RxPipelineExecute(RxPipeline  * pipeline,
                  void        * data,
                  RwBool       heapReset);

extern RxPacket *
RxPacketCreate(RxPipelineNode * node);

extern RxCluster   *
RxClusterSetStride(RxCluster * cluster,
                   RwInt32 stride);

extern RxCluster   *
RxClusterSetExternalData(RxCluster * cluster,
                         void *data,
                         RwInt32 stride,
                         RwInt32 numElements);

extern RxCluster   *
RxClusterSetData(RxCluster * cluster,
                 void *data,
                 RwInt32 stride,
                 RwInt32 numElements);

/* underlying PacketDestroy function */
extern void
_rxPacketDestroy(RxPacket * Packet);

/* more convenient parameterization */
#define RxPacketDestroy(pk, self) \
    ( _rxPacketDestroy(pk) )

#if (defined(RWDEBUG))
extern RxPacket *RxPacketFetch(RxPipelineNode * Node);
extern void      RxPacketDispatch(RxPacket * packet,
                                  RwUInt32 output,
                                  RxPipelineNode * self);
extern void      RxPacketDispatchToPipeline(RxPacket * packet,
                                            RxPipeline * dest,
                                            RxPipelineNode * self);
#else /* (defined(RWDEBUG)) */
#define RxPacketFetch(_self) \
    rxPacketFetchMacro(_self)
#define RxPacketDispatch(     _packet, _output, _self) \
    rxPacketDispatchMacro(_packet, _output, _self)
#define RxPacketDispatchToPipeline(     _packet, _pipeline, _self) \
    rxPacketDispatchToPipelineMacro(_packet, _pipeline, _self)
#endif /* (defined(RWDEBUG)) */

#define RxClusterInitialiseData(_clstr, _nmlmnts, _strd) \
    ( RxClusterInitializeData((_clstr), (_nmlmnts), (_strd)) )
extern RxCluster   *
RxClusterInitializeData(RxCluster *cluster, RwUInt32 numElements, RwUInt16 stride);

extern RxCluster   *
RxClusterResizeData(RxCluster *CurrentCluster, RwUInt32 NumElements);

extern RxCluster   *
RxClusterDestroyData(RxCluster *CurrentCluster);

#if (defined(RWDEBUG))

extern RxCluster *RxClusterLockRead(RxPacket * packet, RwUInt32 clusterIndex);

#else  /* !RWDEBUG */

#define RXCLSLOT(PKT, CLIND)             \
    ((PKT)->inputToClusterSlot[(CLIND)])

#define RxClusterLockRead(PKT, CLIND)                               \
    ( (((RwInt32)RXCLSLOT(PKT, CLIND)) == -1) ?                     \
      ((RxCluster *)NULL) :                                         \
      (RxClusterResetCursor(&PKT->clusters[RXCLSLOT(PKT, CLIND)]),  \
       &PKT->clusters[RXCLSLOT(PKT, CLIND)]) )

#endif /* !RWDEBUG */

extern RxCluster   *
RxClusterLockWrite(RxPacket * packet,
                   RwUInt32 clusterIndex,
                   RxPipelineNode * node);

extern void
RxClusterUnlock(RxCluster * cluster);

extern RwUInt32
RxPipelineNodeSendConfigMsg(RxPipelineNode * dest,
                            RwUInt32 msg,
                            RwUInt32 intparam,
                            void *ptrparam);

extern RxPipelineNode *
RxPipelineNodeForAllConnectedOutputs(RxPipelineNode * node,
                                     RxPipeline * pipeline,
                                     RxPipelineNodeOutputCallBack callbackfn,
                                     void *callbackdata);

/* Cluster attributes api [pipeline construction time] */

extern RxPipelineCluster *
RxPipelineNodeGetPipelineCluster(RxPipelineNode *node,
                                   RwUInt32 clustersOfInterestIndex);

extern RwUInt32
RxPipelineClusterGetCreationAttributes(RxPipelineCluster *cluster);

extern RxPipelineCluster *
RxPipelineClusterSetCreationAttributes(RxPipelineCluster *cluster,
                                         RwUInt32 creationAttributes);

/* Cluster attributes api [pipeline execution time] */

extern RwUInt32
RxClusterGetAttributes(RxCluster *cluster);

extern RxCluster *
RxClusterSetAttributes(RxCluster *cluster, RwUInt32 attributes);


extern void
_rxEmbeddedPacketBetweenPipelines(RxPipeline * fromPipeline,
                                 RxPipeline * toPipeline);

extern RxPipelineNode *
_rxEmbeddedPacketBetweenNodes(RxPipeline     *pipeline,
                             RxPipelineNode *nodeFrom,
                             RwUInt32        whichOutput);

extern RxExecutionContext _rxExecCtxGlobal;

/* Summary of dispatch rules:
 * o nodes that never fetch are safe to dispatch NULL, whether
 *   nodes above pass them a packet or not
 * o if you destroy the packet you can dispatch(NULL,,)
 * o if you fetch/create and dispatch(NULL), it doesn't really
 *   matter - the packet'll get passed on anyway */

/* TODO: there's currently no way to prematurely terminate the pipeline
 *      without doing so as an error condition. You should create an
 *      enum for the exit code, either RXNODEEXITCONTINUE, RXNODEEXITTERMINATE
 *      or RXNODEEXTTERMINATEERROR and then test for RXNODEEXITCONTINUE in
 *      the below macros rather than FALSE. */

/* TODO: _packet redundant here... create a new macro and legacy wrapper */
#define rxPacketDispatchMacro(_packet, _output, _self)                      \
MACRO_START                                                                 \
{                                                                           \
    RxPipeline *curPipeline = _rxExecCtxGlobal.pipeline;                    \
                                                                            \
    /* _packet is now an obsolete parameter */                              \
                                                                            \
    if ( FALSE != _rxExecCtxGlobal.exitCode )                               \
    {                                                                       \
        RxPipelineNode *nextNode =                                          \
            _rxEmbeddedPacketBetweenNodes(curPipeline,                      \
                                         _self,                             \
                                         (_output));                        \
        if ( nextNode != NULL )                                             \
        {                                                                   \
            RwUInt32 exitCode =                                             \
                nextNode->nodeDef->nodeMethods.nodeBody(                    \
                    nextNode, &(_rxExecCtxGlobal.params));                  \
            /* Don't overwrite 'error' with 'success' */                    \
            if (FALSE == exitCode) _rxExecCtxGlobal.exitCode = exitCode;    \
        }                                                                   \
    }                                                                       \
    if ( curPipeline->embeddedPacketState > rxPKST_UNUSED                   \
         /* !UNUSED and !PACKETLESS */ )                                    \
    {                                                                       \
        curPipeline->embeddedPacketState = rxPKST_INUSE;                    \
        _rxPacketDestroy(curPipeline->embeddedPacket);                      \
    }                                                                       \
}                                                                           \
MACRO_STOP

/* TODO: _self redundant here... create a new macro and legacy wrapper */
#define rxPacketDispatchToPipelineMacro(_packet, _pipeline, _self)          \
MACRO_START                                                                 \
{                                                                           \
    RxPipeline *toPipeline = (_pipeline);                                   \
                                                                            \
    /* _packet is now an obsolete parameter */                              \
                                                                            \
    if ( FALSE != _rxExecCtxGlobal.exitCode )                               \
    {                                                                       \
        RwUInt32 exitCode;                                                  \
        RxPipeline *fromPipeline = _rxExecCtxGlobal.pipeline; /* save */    \
        _rxEmbeddedPacketBetweenPipelines(fromPipeline,                     \
                                         toPipeline);                       \
        _rxExecCtxGlobal.pipeline = toPipeline; /* modify */                \
        exitCode =                                                          \
            toPipeline->nodes[0].nodeDef->nodeMethods.nodeBody(             \
                &toPipeline->nodes[0], &(_rxExecCtxGlobal.params));         \
        if ( FALSE == exitCode ) _rxExecCtxGlobal.exitCode = exitCode;      \
        _rxExecCtxGlobal.pipeline = fromPipeline; /* restore */             \
    }                                                                       \
    if ( toPipeline->embeddedPacketState > rxPKST_UNUSED                    \
         /* !UNUSED and !PACKETLESS */ )                                    \
    {                                                                       \
        toPipeline->embeddedPacketState = rxPKST_INUSE;                     \
        _rxPacketDestroy(toPipeline->embeddedPacket);                       \
    }                                                                       \
}                                                                           \
MACRO_STOP

#define rxPacketFetchMacro(_node)                                           \
    ( ((_rxExecCtxGlobal.pipeline)->embeddedPacketState == rxPKST_PENDING) ?\
      ((_rxExecCtxGlobal.pipeline)->embeddedPacketState = rxPKST_INUSE,     \
       (_rxExecCtxGlobal.pipeline)->embeddedPacket) :                       \
      (NULL) )

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/opengl/nodeOpenGLSubmitNoLight.h ---*/

#if defined( __cplusplus )
extern "C"
{
#endif /* defined( __cplusplus ) */


extern RxNodeDefinition *
RxNodeDefinitionGetOpenGLImmInstance( void );

extern RxNodeDefinition *
RxNodeDefinitionGetOpenGLSubmitNoLight( void );

#if defined( __cplusplus )
}
#endif /* defined( __cplusplus ) */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2define.h ---*/

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeOutput 
 * typedef for a reference to an output of a pipeline node */
typedef RwUInt32       *RxNodeOutput;

/**
 * \ingroup rwcoregeneric
 * \ref RxNodeInput 
 *  typedef for a reference to the input of a pipeline node */
typedef RxPipelineNode *RxNodeInput;

/**
 * \ingroup rwcoregeneric
 * \ref RxLockedPipe
 * typedef for a reference to a locked pipeline 
 */
typedef RxPipeline      RxLockedPipe;


#ifdef    __cplusplus
extern "C"
{
#endif /* __cplusplus */


/* PIPELINENODE API */

extern RxNodeOutput
RxPipelineNodeFindOutputByName(RxPipelineNode *node,
                               const RwChar *outputname);

extern RxNodeOutput
RxPipelineNodeFindOutputByIndex(RxPipelineNode *node,
                                RwUInt32 outputindex);

extern RxNodeInput
RxPipelineNodeFindInput(RxPipelineNode *node);

extern RxNodeDefinition *
RxPipelineNodeCloneDefinition(RxPipelineNode *node,
                              RxClusterDefinition *cluster2add);

extern RxPipeline *
RxPipelineNodeRequestCluster(RxPipeline *pipeline,
                             RxPipelineNode *node,
                             RxClusterDefinition *clusterDef);

extern RxPipeline *
RxPipelineNodeReplaceCluster(RxPipeline *pipeline,
                             RxPipelineNode *node,
                             RxClusterDefinition *oldClusterDef,
                             RxClusterDefinition *newClusterDef);

extern void *
RxPipelineNodeGetInitData(RxPipelineNode *node);

extern void *
RxPipelineNodeCreateInitData(RxPipelineNode *node,
                             RwUInt32 size);

/* PIPELINE MANIPULATION API */

extern RxPipeline *
RxPipelineClone(RxPipeline *pipeline);

extern RxPipelineNode *
RxPipelineFindNodeByName(RxPipeline *pipeline,
                         const RwChar *name,
                         RxPipelineNode *start,
                         RwInt32 *nodeIndex);

extern RxPipelineNode *
RxPipelineFindNodeByIndex(RxPipeline *pipeline,
                          RwUInt32 nodeindex);

extern RxLockedPipe *
RxPipelineLock(RxPipeline *pipeline);

extern RxPipeline *
RxLockedPipeUnlock(RxLockedPipe *pipeline);


extern RxLockedPipe *
RxLockedPipeAddFragment(RxLockedPipe *pipeline,
                        RwUInt32 *firstIndex,
                        RxNodeDefinition *nodeDef0,
                        ...);


extern RxPipeline *
RxLockedPipeReplaceNode(RxLockedPipe *pipeline,
                        RxPipelineNode *node,
                        RxNodeDefinition *nodeDef);

extern RxPipeline *
RxLockedPipeDeleteNode(RxLockedPipe *pipeline,
                       RxPipelineNode *node);


extern RxPipeline *
RxLockedPipeSetEntryPoint(RxLockedPipe *pipeline,
                          RxNodeInput in);


extern RxPipelineNode *
RxLockedPipeGetEntryPoint(RxLockedPipe *pipeline);


extern RxPipeline *
RxLockedPipeAddPath(RxLockedPipe *pipeline,
                    RxNodeOutput out,
                    RxNodeInput in);

extern RxPipeline *
RxLockedPipeDeletePath(RxLockedPipe *pipeline,
                       RxNodeOutput out,
                       RxNodeInput in);


extern RxPipeline *
RxPipelineInsertDebugNode(RxPipeline *pipeline,
                          RxPipelineNode *before,
                          RxPipelineNode *after,
                          RxNodeDefinition *debugNode);

#ifdef    __cplusplus
}
#endif /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2altmdl.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/bavagl.h ---*/

/* Macros for GL_VERTEX_ARRAY */
#define RwOpenGLVASetPositionMacro(_numComponents,_baseType,            \
                                   _stride,_memAddr)                    \
MACRO_START                                                             \
{                                                                       \
    if ( FALSE == _rwOpenGLVAPositionEnabled )                          \
    {                                                                   \
        glEnableClientState( GL_VERTEX_ARRAY );                         \
        _rwOpenGLVAPositionEnabled = TRUE;                              \
    }                                                                   \
    glVertexPointer((_numComponents),(_baseType),(_stride),_memAddr);   \
}                                                                       \
MACRO_STOP

#define RwOpenGLVASetPositionATIMacro(_numComponents,_baseType,         \
                                      _stride,_vaoName,_offset)         \
MACRO_START                                                             \
{                                                                       \
    if ( FALSE == _rwOpenGLVAPositionEnabled )                          \
    {                                                                   \
        glEnableClientState( GL_VERTEX_ARRAY );                         \
        _rwOpenGLVAPositionEnabled = TRUE;                              \
    }                                                                   \
    _rwOpenGLExt.ArrayObjectATI( GL_VERTEX_ARRAY,                       \
                                 (_numComponents),                      \
                                 (_baseType),                           \
                                 (_stride),                             \
                                 (_vaoName),                            \
                                 (RwUInt32)(_offset) );                 \
}                                                                       \
MACRO_STOP

/* Macros for GL_NORMAL_ARRAY */
#define RwOpenGLVASetNormalMacro(_enableTest,_baseType,                     \
                                 _stride,_memAddr)                          \
MACRO_START                                                                 \
{                                                                           \
    if ( FALSE != (_enableTest) )                                           \
    {                                                                       \
        if ( FALSE == _rwOpenGLVANormalEnabled )                            \
        {                                                                   \
            glEnableClientState( GL_NORMAL_ARRAY );                         \
            _rwOpenGLVANormalEnabled = TRUE;                                \
        }                                                                   \
        glNormalPointer((_baseType),(_stride),(const GLvoid *)_memAddr);    \
    }                                                                       \
    else if ( FALSE != _rwOpenGLVANormalEnabled )                           \
    {                                                                       \
        glDisableClientState( GL_NORMAL_ARRAY );                            \
        _rwOpenGLVANormalEnabled = FALSE;                                   \
    }                                                                       \
}                                                                           \
MACRO_STOP

    
#define RwOpenGLVASetNormalATIMacro(_enableTest,_baseType,      \
                                    _stride,_vaoName,_offset)   \
MACRO_START                                                     \
{                                                               \
    if ( FALSE != (_enableTest) )                               \
    {                                                           \
        if ( FALSE == _rwOpenGLVANormalEnabled )                \
        {                                                       \
            glEnableClientState( GL_NORMAL_ARRAY );             \
            _rwOpenGLVANormalEnabled = TRUE;                    \
        }                                                       \
        _rwOpenGLExt.ArrayObjectATI( GL_NORMAL_ARRAY,           \
                                     3,                         \
                                     (_baseType),               \
                                     (_stride),                 \
                                     (_vaoName),                \
                                     (RwUInt32)(_offset) );     \
    }                                                           \
    else if ( FALSE != _rwOpenGLVANormalEnabled )               \
    {                                                           \
        glDisableClientState( GL_NORMAL_ARRAY );                \
        _rwOpenGLVANormalEnabled = FALSE;                       \
    }                                                           \
}                                                               \
MACRO_STOP

/* Macros for GL_COLOR_ARRAY */
#define RwOpenGLVASetColorMacro(_enableTest,_numComponents,_baseType,   \
                                _stride,_memAddr)                       \
MACRO_START                                                             \
{                                                                       \
    if ( FALSE != (_enableTest) )                                       \
    {                                                                   \
        if ( FALSE == _rwOpenGLVAColorEnabled )                         \
        {                                                               \
            glEnableClientState( GL_COLOR_ARRAY );                      \
            _rwOpenGLVAColorEnabled = TRUE;                             \
        }                                                               \
        glColorPointer((_numComponents),(_baseType),                    \
                       (_stride),(const GLvoid *)_memAddr);             \
    }                                                                   \
    else if ( FALSE != _rwOpenGLVAColorEnabled )                        \
    {                                                                   \
        glDisableClientState( GL_COLOR_ARRAY );                         \
        _rwOpenGLVAColorEnabled = FALSE;                                \
    }                                                                   \
}                                                                       \
MACRO_STOP

#define RwOpenGLVASetColorATIMacro(_enableTest,_numComponents,  \
                                   _baseType,_stride,_vaoName,  \
                                   _offset)                     \
MACRO_START                                                     \
{                                                               \
    if ( FALSE != (_enableTest) )                               \
    {                                                           \
        if ( FALSE == _rwOpenGLVAColorEnabled )                 \
        {                                                       \
            glEnableClientState( GL_COLOR_ARRAY );              \
            _rwOpenGLVAColorEnabled = TRUE;                     \
        }                                                       \
        _rwOpenGLExt.ArrayObjectATI( GL_COLOR_ARRAY,            \
                                     (_numComponents),          \
                                     (_baseType),               \
                                     (_stride),                 \
                                     (_vaoName),                \
                                     (RwUInt32)(_offset) );     \
    }                                                           \
    else if ( FALSE != _rwOpenGLVAColorEnabled )                \
    {                                                           \
        glDisableClientState( GL_COLOR_ARRAY );                 \
        _rwOpenGLVAColorEnabled = FALSE;                        \
    }                                                           \
}                                                               \
MACRO_STOP

/* Macros for GL_TEXTURE_COORD_ARRAY */
#define RwOpenGLVASetTexUnitMacro(_texUnit)                                     \
MACRO_START                                                                     \
{                                                                               \
    if ( (RwUInt32)(_texUnit) != _rwOpenGLVATexUnit )                           \
    {                                                                           \
        if ( NULL != _rwOpenGLExt.ClientActiveTextureARB )                      \
        {                                                                       \
            _rwOpenGLExt.ClientActiveTextureARB( GL_TEXTURE0_ARB + (_texUnit) );\
            _rwOpenGLVATexUnit = (_texUnit);                                    \
        }                                                                       \
    }                                                                           \
}                                                                               \
MACRO_STOP

#define RwOpenGLVASetTexCoordMacro(_enableTest,_numComponents,      \
                                   _baseType,_stride,_memAddr)      \
MACRO_START                                                         \
{                                                                   \
    RwOpenGLVASetTexUnitMacro(0);                                   \
    if ( FALSE != (_enableTest) )                                   \
    {                                                               \
        if ( FALSE == _rwOpenGLVATexCoordEnabled[0] )               \
        {                                                           \
            glEnableClientState( GL_TEXTURE_COORD_ARRAY );          \
            _rwOpenGLVATexCoordEnabled[0] = TRUE;                   \
        }                                                           \
        glTexCoordPointer((_numComponents),(_baseType),(_stride),   \
                          (const GLvoid *)_memAddr);                \
    }                                                               \
    else if ( FALSE != _rwOpenGLVATexCoordEnabled[0] )              \
    {                                                               \
        glDisableClientState( GL_TEXTURE_COORD_ARRAY );             \
        _rwOpenGLVATexCoordEnabled[0] = FALSE;                      \
    }                                                               \
}                                                                   \
MACRO_STOP


#define RwOpenGLVASetTexCoordATIMacro(_enableTest,_numComponents,   \
                                      _baseType,_stride,_vaoName,   \
                                      _offset)                      \
MACRO_START                                                         \
{                                                                   \
    RwOpenGLVASetTexUnitMacro(0);                                   \
    if ( FALSE != (_enableTest) )                                   \
    {                                                               \
        if ( FALSE == _rwOpenGLVATexCoordEnabled[0] )               \
        {                                                           \
            glEnableClientState( GL_TEXTURE_COORD_ARRAY );          \
            _rwOpenGLVATexCoordEnabled[0] = TRUE;                   \
        }                                                           \
        _rwOpenGLExt.ArrayObjectATI( GL_TEXTURE_COORD_ARRAY,        \
                                     (_numComponents),              \
                                     (_baseType),                   \
                                     (_stride),                     \
                                     (_vaoName),                    \
                                     (RwUInt32)(_offset) );         \
    }                                                               \
    else if ( FALSE != _rwOpenGLVATexCoordEnabled[0] )              \
    {                                                               \
        glDisableClientState( GL_TEXTURE_COORD_ARRAY );             \
        _rwOpenGLVATexCoordEnabled[0] = FALSE;                      \
    }                                                               \
}                                                                   \
MACRO_STOP


/* Macros for multitexture GL_TEXTURE_COORD_ARRAY */
#define RwOpenGLVASetMultiTexCoordMacro(_enableTest,_texUnit,         \
                                        _numComponents,_baseType,     \
                                        _stride,_memAddr)             \
MACRO_START                                                           \
{                                                                     \
    RwOpenGLVASetTexUnitMacro(_texUnit);                              \
    if ( FALSE != (_enableTest) )                                     \
    {                                                                 \
        if ( FALSE == _rwOpenGLVATexCoordEnabled[(_texUnit)])         \
        {                                                             \
            glEnableClientState( GL_TEXTURE_COORD_ARRAY );            \
            _rwOpenGLVATexCoordEnabled[(_texUnit)] = TRUE;            \
        }                                                             \
        glTexCoordPointer((_numComponents),(_baseType),(_stride),     \
                          (const GLvoid *)_memAddr);                  \
    }                                                                 \
    else if ( FALSE != _rwOpenGLVATexCoordEnabled[(_texUnit)] )       \
    {                                                                 \
        glDisableClientState( GL_TEXTURE_COORD_ARRAY );               \
        _rwOpenGLVATexCoordEnabled[(_texUnit)] = FALSE;               \
    }                                                                 \
}                                                                     \
MACRO_STOP

#define RwOpenGLVASetMultiTexCoordATIMacro(_enableTest,_texUnit,      \
                                           _numComponents,_baseType,  \
                                           _stride,_vaoName,          \
                                           _offset)                   \
MACRO_START                                                           \
{                                                                     \
    RwOpenGLVASetTexUnitMacro(_texUnit);                              \
    if ( FALSE != (_enableTest) )                                     \
    {                                                                 \
        if ( FALSE == _rwOpenGLVATexCoordEnabled[(_texUnit)])         \
        {                                                             \
            glEnableClientState( GL_TEXTURE_COORD_ARRAY );            \
            _rwOpenGLVATexCoordEnabled[(_texUnit)] = TRUE;            \
        }                                                             \
        _rwOpenGLExt.ArrayObjectATI( GL_TEXTURE_COORD_ARRAY,          \
                                     (_numComponents),                \
                                     (_baseType),                     \
                                     (_stride),                       \
                                     (_vaoName),                      \
                                     (RwUInt32)(_offset) );           \
    }                                                                 \
    else if ( FALSE != _rwOpenGLVATexCoordEnabled[(_texUnit)] )       \
    {                                                                 \
        glDisableClientState( GL_TEXTURE_COORD_ARRAY );               \
        _rwOpenGLVATexCoordEnabled[(_texUnit)] = FALSE;               \
    }                                                                 \
}                                                                     \
MACRO_STOP


#define RwOpenGLVADisablePositionMacro()            \
MACRO_START                                         \
    if ( FALSE != _rwOpenGLVAPositionEnabled )      \
    {                                               \
        glDisableClientState( GL_VERTEX_ARRAY );    \
        _rwOpenGLVAPositionEnabled = FALSE;         \
    }                                               \
MACRO_STOP      

#define RwOpenGLVADisableNormalMacro()              \
MACRO_START                                         \
    if ( FALSE != _rwOpenGLVANormalEnabled )        \
    {                                               \
        glDisableClientState( GL_NORMAL_ARRAY );    \
        _rwOpenGLVANormalEnabled = FALSE;           \
    }                                               \
MACRO_STOP

#define RwOpenGLVADisableColorMacro()           \
MACRO_START                                     \
    if ( FALSE != _rwOpenGLVAColorEnabled )     \
    {                                           \
        glDisableClientState( GL_COLOR_ARRAY ); \
        _rwOpenGLVAColorEnabled = FALSE;        \
    }                                           \
MACRO_STOP

#define RwOpenGLVADisableTexCoordMacro(_texUnit)                \
MACRO_START                                                     \
{                                                               \
    RwOpenGLVASetTexUnitMacro(_texUnit);                        \
    if ( FALSE != _rwOpenGLVATexCoordEnabled[(_texUnit)] )      \
    {                                                           \
        glDisableClientState( GL_TEXTURE_COORD_ARRAY );         \
        _rwOpenGLVATexCoordEnabled[(_texUnit)] = FALSE;         \
    }                                                           \
}                                                               \
MACRO_STOP

#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwOpenGLVASetPosition   \
    RwOpenGLVASetPositionMacro

#define RwOpenGLVASetPositionATI    \
    RwOpenGLVASetPositionATIMacro

#define RwOpenGLVASetNormal  \
    RwOpenGLVASetNormalMacro

#define RwOpenGLVASetNormalATI  \
    RwOpenGLVASetNormalATIMacro

#define RwOpenGLVASetColor  \
    RwOpenGLVASetColorMacro

#define RwOpenGLVASetColorATI   \
    RwOpenGLVASetColorATIMacro

#define RwOpenGLVASetTexCoord   \
    RwOpenGLVASetTexCoordMacro

#define RwOpenGLVASetTexCoordATI    \
    RwOpenGLVASetTexCoordATIMacro

#define RwOpenGLVASetMultiTexCoord  \
    RwOpenGLVASetMultiTexCoordMacro

#define RwOpenGLVASetMultiTexCoordATI   \
    RwOpenGLVASetMultiTexCoordATIMacro

#define RwOpenGLVADisablePosition   \
    RwOpenGLVADisablePositionMacro

#define RwOpenGLVADisableNormal \
    RwOpenGLVADisableNormalMacro

#define RwOpenGLVADisableColor  \
    RwOpenGLVADisableColorMacro

#define RwOpenGLVADisableTexCoord   \
    RwOpenGLVADisableTexCoordMacro

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


#if defined( __cplusplus )
extern "C"
{
#endif /* defined( __cplusplus ) */

extern RwBool   _rwOpenGLVAPositionEnabled;
extern RwBool   _rwOpenGLVANormalEnabled;
extern RwBool   _rwOpenGLVAColorEnabled;
extern RwBool   *_rwOpenGLVATexCoordEnabled;
extern RwUInt32 _rwOpenGLVATexUnit;


#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

extern void
RwOpenGLVASetPosition( const RwUInt32 numComponents,
                       const RwInt32 baseType,
                       const RwUInt32 stride,
                       const void *memAddr );
extern void
RwOpenGLVASetPositionATI( const RwUInt32 numComponents,
                          const RwInt32 baseType,
                          const RwUInt32 stride,
                          const RwUInt32 vaoName,
                          const void *offset );

extern void
RwOpenGLVASetNormal( const RwBool enableTest,
                     const RwInt32 baseType,
                     const RwUInt32 stride,
                     const void *memAddr );
extern void
RwOpenGLVASetNormalATI( const RwBool enableTest,
                        const RwInt32 baseType,
                        const RwUInt32 stride,
                        const RwUInt32 vaoName,
                        const void *offset );

extern void
RwOpenGLVASetColor( const RwBool enableTest,
                    const RwUInt32 numComponents,
                    const RwInt32 baseType,
                    const RwUInt32 stride,
                    const void *memAddr );
extern void
RwOpenGLVASetColorATI( const RwBool enableTest,
                       const RwUInt32 numComponents,
                       const RwInt32 baseType,
                       const RwUInt32 stride,
                       const RwUInt32 vaoName,
                       const void *offset );

extern void
RwOpenGLVASetTexCoord( const RwBool enableTest,
                       const RwUInt32 numComponents,
                       const RwInt32 baseType,
                       const RwUInt32 stride,
                       const void *memAddr );
extern void
RwOpenGLVASetTexCoordATI( const RwBool enableTest,
                          const RwUInt32 numComponents,
                          const RwInt32 baseType,
                          const RwUInt32 stride,
                          const RwUInt32 vaoName,
                          const void *offset );

extern void
RwOpenGLVASetMultiTexCoord( const RwBool enableTest,
                            const RwInt32 texUnit,
                            const RwUInt32 numComponents,
                            const RwInt32 baseType,
                            const RwUInt32 stride,
                            const void *memAddr );
extern void
RwOpenGLVASetMultiTexCoordATI( const RwBool enableTest,
                               const RwInt32 texUnit,
                               const RwUInt32 numComponents,
                               const RwInt32 baseType,
                               const RwUInt32 stride,
                               const RwUInt32 vaoName,
                               const void *offset );

extern void
RwOpenGLVADisablePosition( void );

extern void
RwOpenGLVADisableNormal( void );

extern void
RwOpenGLVADisableColor( void );

extern void
RwOpenGLVADisableTexCoord( const RwInt32 texUnit );

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

#if defined( __cplusplus )
}
#endif /* defined( __cplusplus ) */


/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/bastdogl.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/badxtgl.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/barastgl.h ---*/

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */


extern void *
RwOpenGLRasterStreamReadDDS( RwStream *stream );

extern void *
RwOpenGLDDSTextureRead( const RwChar *name,
                        const RwChar *maskname );

extern void
RwOpenGLRasterSetGenericTextureCompression( const RwBool enable );

extern RwBool
RwOpenGLRasterGetGenericTextureCompression( void );

extern RwBool
RwOpenGLRasterIsCubeMap( void *rasterVoid );

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */


/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/barstate.h ---*/

#define RwOpenGLEnableMacro(_token)                 \
MACRO_START                                         \
if ( FALSE == RwOpenGLStateCache[_token].enabled )  \
{                                                   \
    glEnable( RwOpenGLStateCache[_token].glToken ); \
    RwOpenGLStateCache[_token].enabled = TRUE;      \
}                                                   \
MACRO_STOP

#define RwOpenGLDisableMacro(_token)                    \
MACRO_START                                             \
if ( FALSE != RwOpenGLStateCache[_token].enabled )      \
{                                                       \
    glDisable( RwOpenGLStateCache[_token].glToken );    \
    RwOpenGLStateCache[_token].enabled = FALSE;         \
}                                                       \
MACRO_STOP

#define RwOpenGLIsEnabledMacro(_token)                  \
    RwOpenGLStateCache[_token].enabled

#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwOpenGLEnable      RwOpenGLEnableMacro
#define RwOpenGLDisable     RwOpenGLDisableMacro
#define RwOpenGLIsEnabled   RwOpenGLIsEnabledMacro

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


/**
 * \ingroup rwengineopengl
 *  RwOpenGLStateToken 
 *  This type represents the RenderWare Graphics' tokens corresponding to
 *  some of OpenGL's state tokens.
 */
enum RwOpenGLStateToken
{
    rwGL_STATENA = 0,           /**< Internal use only */
                            
    rwGL_ALPHA_TEST,            /**< Equivalent to \c GL_ALPHA_TEST */
    rwGL_BLEND,                 /**< Equivalent to \c GL_BLEND */
    rwGL_COLOR_MATERIAL,        /**< Equivalent to \c GL_COLOR_MATERIAL */
    rwGL_CULL_FACE,             /**< Equivalent to \c GL_CULL_FACE */
    rwGL_DEPTH_TEST,            /**< Equivalent to \c GL_DEPTH_TEST */
    rwGL_FOG,                   /**< Equivalent to \c GL_FOG */
    rwGL_LIGHT0,                /**< Equivalent to \c GL_LIGHT0 */
    rwGL_LIGHT1,                /**< Equivalent to \c GL_LIGHT1 */
    rwGL_LIGHT2,                /**< Equivalent to \c GL_LIGHT2 */
    rwGL_LIGHT3,                /**< Equivalent to \c GL_LIGHT3 */
    rwGL_LIGHT4,                /**< Equivalent to \c GL_LIGHT4 */
    rwGL_LIGHT5,                /**< Equivalent to \c GL_LIGHT5 */
    rwGL_LIGHT6,                /**< Equivalent to \c GL_LIGHT6 */
    rwGL_LIGHT7,                /**< Equivalent to \c GL_LIGHT7 */
    rwGL_LIGHTING,              /**< Equivalent to \c GL_LIGHTING */
    rwGL_NORMALIZE,             /**< Equivalent to \c GL_NORMALIZE */
    rwGL_SCISSOR_TEST,          /**< Equivalent to \c GL_SCISSOR_TEST */
    rwGL_STENCIL_TEST,          /**< Equivalent to \c GL_STENCIL_TEST */
    rwGL_TEXTURE0_2D,           /**< Equivalent to \c GL_TEXTURE_2D for texture unit 0 */
    rwGL_TEXTURE1_2D,           /**< Equivalent to \c GL_TEXTURE_2D for texture unit 1 */
    rwGL_TEXTURE2_2D,           /**< Equivalent to \c GL_TEXTURE_2D for texture unit 2 */
    rwGL_TEXTURE3_2D,           /**< Equivalent to \c GL_TEXTURE_2D for texture unit 3 */
    rwGL_TEXTURE4_2D,           /**< Equivalent to \c GL_TEXTURE_2D for texture unit 4 */
    rwGL_TEXTURE5_2D,           /**< Equivalent to \c GL_TEXTURE_2D for texture unit 5 */
    rwGL_TEXTURE6_2D,           /**< Equivalent to \c GL_TEXTURE_2D for texture unit 6 */
    rwGL_TEXTURE7_2D,           /**< Equivalent to \c GL_TEXTURE_2D for texture unit 7 */
    rwGL_TEXTURE0_GEN_S,        /**< Equivalent to \c GL_TEXTURE_GEN_S for texture unit 0 */
    rwGL_TEXTURE1_GEN_S,        /**< Equivalent to \c GL_TEXTURE_GEN_S for texture unit 1 */
    rwGL_TEXTURE2_GEN_S,        /**< Equivalent to \c GL_TEXTURE_GEN_S for texture unit 2 */
    rwGL_TEXTURE3_GEN_S,        /**< Equivalent to \c GL_TEXTURE_GEN_S for texture unit 3 */
    rwGL_TEXTURE4_GEN_S,        /**< Equivalent to \c GL_TEXTURE_GEN_S for texture unit 4 */
    rwGL_TEXTURE5_GEN_S,        /**< Equivalent to \c GL_TEXTURE_GEN_S for texture unit 5 */
    rwGL_TEXTURE6_GEN_S,        /**< Equivalent to \c GL_TEXTURE_GEN_S for texture unit 6 */
    rwGL_TEXTURE7_GEN_S,        /**< Equivalent to \c GL_TEXTURE_GEN_S for texture unit 7 */
    rwGL_TEXTURE0_GEN_T,        /**< Equivalent to \c GL_TEXTURE_GEN_T for texture unit 0 */
    rwGL_TEXTURE1_GEN_T,        /**< Equivalent to \c GL_TEXTURE_GEN_T for texture unit 1 */
    rwGL_TEXTURE2_GEN_T,        /**< Equivalent to \c GL_TEXTURE_GEN_T for texture unit 2 */
    rwGL_TEXTURE3_GEN_T,        /**< Equivalent to \c GL_TEXTURE_GEN_T for texture unit 3 */
    rwGL_TEXTURE4_GEN_T,        /**< Equivalent to \c GL_TEXTURE_GEN_T for texture unit 4 */
    rwGL_TEXTURE5_GEN_T,        /**< Equivalent to \c GL_TEXTURE_GEN_T for texture unit 5 */
    rwGL_TEXTURE6_GEN_T,        /**< Equivalent to \c GL_TEXTURE_GEN_T for texture unit 6 */
    rwGL_TEXTURE7_GEN_T,        /**< Equivalent to \c GL_TEXTURE_GEN_T for texture unit 7 */
    rwGL_TEXTURE0_GEN_R,        /**< Equivalent to \c GL_TEXTURE_GEN_R for texture unit 0 */
    rwGL_TEXTURE1_GEN_R,        /**< Equivalent to \c GL_TEXTURE_GEN_R for texture unit 1 */
    rwGL_TEXTURE2_GEN_R,        /**< Equivalent to \c GL_TEXTURE_GEN_R for texture unit 2 */
    rwGL_TEXTURE3_GEN_R,        /**< Equivalent to \c GL_TEXTURE_GEN_R for texture unit 3 */
    rwGL_TEXTURE4_GEN_R,        /**< Equivalent to \c GL_TEXTURE_GEN_R for texture unit 4 */
    rwGL_TEXTURE5_GEN_R,        /**< Equivalent to \c GL_TEXTURE_GEN_R for texture unit 5 */
    rwGL_TEXTURE6_GEN_R,        /**< Equivalent to \c GL_TEXTURE_GEN_R for texture unit 6 */
    rwGL_TEXTURE7_GEN_R,        /**< Equivalent to \c GL_TEXTURE_GEN_R for texture unit 7 */
    rwGL_TEXTURE0_GEN_Q,        /**< Equivalent to \c GL_TEXTURE_GEN_Q for texture unit 0 */
    rwGL_TEXTURE1_GEN_Q,        /**< Equivalent to \c GL_TEXTURE_GEN_Q for texture unit 1 */
    rwGL_TEXTURE2_GEN_Q,        /**< Equivalent to \c GL_TEXTURE_GEN_Q for texture unit 2 */
    rwGL_TEXTURE3_GEN_Q,        /**< Equivalent to \c GL_TEXTURE_GEN_Q for texture unit 3 */
    rwGL_TEXTURE4_GEN_Q,        /**< Equivalent to \c GL_TEXTURE_GEN_Q for texture unit 4 */
    rwGL_TEXTURE5_GEN_Q,        /**< Equivalent to \c GL_TEXTURE_GEN_Q for texture unit 5 */
    rwGL_TEXTURE6_GEN_Q,        /**< Equivalent to \c GL_TEXTURE_GEN_Q for texture unit 6 */
    rwGL_TEXTURE7_GEN_Q,        /**< Equivalent to \c GL_TEXTURE_GEN_Q for texture unit 7 */
    rwGL_TEXTURE_CUBE_MAP_ARB,  /**< Equivalent to \c GL_TEXTURE_CUBE_MAP_ARB */

    rwGL_NUMSTATES,             /**< Internal use only */

    rwGL_STATEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT /**< Internal use only */
};
typedef enum RwOpenGLStateToken RwOpenGLStateToken;

typedef struct RwOpenGLStateData RwOpenGLStateData;
/** 
 * \ingroup rwengineopengl
 * \struct RwOpenGLStateData
 *
 * This type contains RenderWare Graphics' state cache data.
 *
 */
struct RwOpenGLStateData
{
    RwUInt32    glToken;    /**< Internal use only */

    RwBool      enabled;    /**< Internal use only */
};


#if defined( __cplusplus )
extern "C"
{
#endif /* defined( __cplusplus ) */

extern RwOpenGLStateData   RwOpenGLStateCache[rwGL_NUMSTATES];


extern void
RwOpenGLSetStencilClear( RwUInt32 stencilValue );

extern RwUInt32
RwOpenGLGetStencilClear( void );

extern void
RwOpenGLSetTexture( void *textureVoid );

extern RwUInt32
RwOpenGLSetActiveTextureUnit( const RwUInt32 textureUnit );

extern RwUInt32
RwOpenGLGetActiveTextureUnit( void );

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
extern void
RwOpenGLEnable( const RwOpenGLStateToken token );

extern void
RwOpenGLDisable( const RwOpenGLStateToken token );

extern RwBool
RwOpenGLIsEnabled( const RwOpenGLStateToken token );
#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

#if defined( __cplusplus )
}
#endif /* defined( __cplusplus ) */


/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/baim2dgl.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/common/ssematml.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/common/cpuext.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/driver/common/datblkcb.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/baraster.h ---*/

/****************************************************************************
 Defines
 */

/**
 * \ingroup rwraster
 * \ref RwRasterLockMode represents the options available for locking 
 * a raster so that it may be modified (see API function \ref RwRasterLock). An 
 * application may wish to write to the raster, read from the raster or
 * simultaneously write and read a raster (rwRASTERLOCKWRITE | rwRASTERLOCKREAD).
 */
enum RwRasterLockMode
{
    rwRASTERLOCKWRITE = 0x01,   /**<Lock for writing */
    rwRASTERLOCKREAD = 0x02,    /**<Lock for reading */
    rwRASTERLOCKNOFETCH = 0x04, /**<When used in combination with
                                 *  rwRASTERLOCKWRITE, asks the driver not to
                                 *  fetch the pixel data. This is only useful
                                 *  if it is known that ALL the raster data is
                                 *  going to be overwritten before the raster
                                 *  is unlocked, i.e. from an 
                                 *  \ref RwRasterSetFromImage call. This flag
                                 *  is not supported by all drivers. */
    rwRASTERLOCKRAW = 0x08,    /**<When used in combination with
                                   rwRASTERLOCKWRITE or rwRASTERLOCKREAD
                                   allows access to the raw platform specific
                                   pixel format */
    rwRASTERLOCKMODEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};

#define rwRASTERLOCKREADWRITE   (rwRASTERLOCKREAD|rwRASTERLOCKWRITE)

typedef enum RwRasterLockMode RwRasterLockMode;

/**
 * \ingroup rwraster
 *  \ref RwRasterFlipMode represents
 *  raster flip modes */
enum RwRasterFlipMode
{
    rwRASTERFLIPDONTWAIT = 0,   /**<Don't wait for VSync */
    rwRASTERFLIPWAITVSYNC = 1,  /**<Flip on VSync */
    rwRASTERFLIPMODEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwRasterFlipMode RwRasterFlipMode;

/**
 * \ingroup rwraster
 *  RwRasterType 
 *  This type represents the options available for creating a new 
 * raster (se API function \ref RwRasterCreate)*/
enum RwRasterType
{
    rwRASTERTYPENORMAL = 0x00,          /**<Normal */
    rwRASTERTYPEZBUFFER = 0x01,         /**<Z Buffer */
    rwRASTERTYPECAMERA = 0x02,          /**<Camera */
    rwRASTERTYPETEXTURE = 0x04,         /**<Texture */
    rwRASTERTYPECAMERATEXTURE = 0x05,   /**<Camera texture */
    rwRASTERTYPEMASK = 0x07,            /**<Mask for finding type */

    rwRASTERPALETTEVOLATILE = 0x40,        /**<If set, hints that the palette will change often */
    rwRASTERDONTALLOCATE = 0x80,        /**<If set the raster is not allocated */
    rwRASTERTYPEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwRasterType RwRasterType;

/**
 * \ingroup rwraster
 * \ref RwRasterFormat is a set of values and flags which may be combined to
 * specify a raster format. The format chosen for a particular raster depends
 * on the hardware device and the raster type specified at creation time
 * (see API function \ref RwRasterCreate). The format may be retrieved using
 * API function \ref RwRasterGetFormat.
 *
 * The raster format is a packed set of bits which contains the following
 * four pieces of information (these may be combined with bitwise OR):
 *
 * <ol>
 * <li> The pixel color format corresponding to one of the following values:
 *      <ul>
 *      <li> rwRASTERFORMAT1555
 *      <li> rwRASTERFORMAT565
 *      <li> rwRASTERFORMAT4444
 *      <li> rwRASTERFORMATLUM8
 *      <li> rwRASTERFORMAT8888
 *      <li> rwRASTERFORMAT888
 *      <li> rwRASTERFORMAT16
 *      <li> rwRASTERFORMAT24
 *      <li> rwRASTERFORMAT32
 *      <li> rwRASTERFORMAT555
 *      </ul>
 *      This value may be masked out of the raster format using
 *      rwRASTERFORMATPIXELFORMATMASK.
 * <li> The palette depth if the raster is palettized:
 *      <ul> 
 *      <li> rwRASTERFORMATPAL4
 *      <li> rwRASTERFORMATPAL8
 *      </ul>
 *      In these cases, the color format refers to that of the palette.
 * <li> Flag rwRASTERFORMATMIPMAP. Set if the raster contains mipmap levels.
 * <li> Flag rwRASTERFORMATAUTOMIPMAP. Set if the mipmap levels were generated
 *      automatically by RenderWare.
 * </ol>
 */
enum RwRasterFormat
{
    rwRASTERFORMATDEFAULT = 0x0000, /* Whatever the hardware likes best */

    rwRASTERFORMAT1555 = 0x0100,    /**<16 bits - 1 bit alpha, 5 bits red, green and blue */
    rwRASTERFORMAT565 = 0x0200,     /**<16 bits - 5 bits red and blue, 6 bits green */
    rwRASTERFORMAT4444 = 0x0300,    /**<16 bits - 4 bits per component */
    rwRASTERFORMATLUM8 = 0x0400,    /**<Gray scale */
    rwRASTERFORMAT8888 = 0x0500,    /**<32 bits - 8 bits per component */
    rwRASTERFORMAT888 = 0x0600,     /**<24 bits - 8 bits per component */
    rwRASTERFORMAT16 = 0x0700,      /**<16 bits - undefined: useful for things like Z buffers */
    rwRASTERFORMAT24 = 0x0800,      /**<24 bits - undefined: useful for things like Z buffers */
    rwRASTERFORMAT32 = 0x0900,      /**<32 bits - undefined: useful for things like Z buffers */
    rwRASTERFORMAT555 = 0x0a00,     /**<16 bits - 5 bits red, green and blue */

    rwRASTERFORMATAUTOMIPMAP = 0x1000, /**<RenderWare generated the mip levels */

    rwRASTERFORMATPAL8 = 0x2000,    /**<8 bit palettised */
    rwRASTERFORMATPAL4 = 0x4000,    /**<4 bit palettised */

    rwRASTERFORMATMIPMAP = 0x8000,  /**<Mip mapping on */

    rwRASTERFORMATPIXELFORMATMASK = 0x0f00, /**<The pixel color format 
                                             *  (excluding palettised bits) */
    rwRASTERFORMATMASK = 0xff00     /**<The whole format */ ,
    rwRASTERFORMATFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwRasterFormat RwRasterFormat;

enum RwRasterPrivateFlag
{
    rwRASTERGAMMACORRECTED = 0x01,
    rwRASTERPIXELLOCKEDREAD = 0x02, /* pixels are locked for reading */
    rwRASTERPIXELLOCKEDWRITE = 0x04, /* pixels are locked for writing */
    rwRASTERPALETTELOCKEDREAD = 0x08, /* palette is locked for reading */
    rwRASTERPALETTELOCKEDWRITE = 0x10, /* palette is locked for writing */
    rwRASTERPIXELLOCKEDRAW = 0x20, /* the pixels are in platform specific
                                      format, used in combination with
                                      rwRASTERPIXELLOCKEDREAD &
                                      rwRASTERPIXELLOCKEDWRITE */
    rwRASTERPRIVATEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwRasterPrivateFlag RwRasterPrivateFlag;

#define rwRASTERPIXELLOCKED     (rwRASTERPIXELLOCKEDREAD | rwRASTERPIXELLOCKEDWRITE)
#define rwRASTERPALETTELOCKED   (rwRASTERPALETTELOCKEDREAD | rwRASTERPALETTELOCKEDWRITE)
#define rwRASTERLOCKED          (rwRASTERPIXELLOCKED|rwRASTERPALETTELOCKED)

/* How big is my stack!!! */
#define rwRASTERCONTEXTSTACKSIZE 10

/****************************************************************************
 Global Types
 */

/**
 * \ingroup rwraster
 * \struct RwRaster 
 * Raster containing device-dependent pixels. 
 * This should be considered an opaque type.
 * Use the RwRaster API functions to access.
 */
typedef struct RwRaster RwRaster;

#if (!defined(DOXYGEN))
struct RwRaster
{
    RwRaster           *parent; /* Top level raster if a sub raster */
    RwUInt8            *cpPixels; /* Pixel pointer when locked */
    RwUInt8            *palette; /* Raster palette */
    RwInt32             width, height, depth; /* Dimensions of raster */
    RwInt32             stride; /* Lines bytes of raster */
    RwInt16             nOffsetX, nOffsetY; /* Sub raster offset */
    RwUInt8             cType;  /* Type of raster */
    RwUInt8             cFlags; /* Raster flags */
    RwUInt8             privateFlags; /* Raster private flags */
    RwUInt8             cFormat; /* Raster format */

    RwUInt8            *originalPixels;
    RwInt32             originalWidth;
    RwInt32             originalHeight;
    RwInt32             originalStride;
};
#endif /* (!defined(DOXYGEN)) */


/****************************************************************************
 <macro/inline functionality
 */

#define RwRasterGetWidthMacro(_raster) \
    ((_raster)->width)

#define RwRasterGetHeightMacro(_raster) \
    ((_raster)->height)

#define RwRasterGetStrideMacro(_raster) \
    ((_raster)->stride)

#define RwRasterGetDepthMacro(_raster) \
    ((_raster)->depth)

#define RwRasterGetFormatMacro(_raster) \
    ((((_raster)->cFormat) & (rwRASTERFORMATMASK >> 8)) << 8)

#define RwRasterGetTypeMacro(_raster) \
    (((_raster)->cType) & rwRASTERTYPEMASK)

#define RwRasterGetParentMacro(_raster) \
    ((_raster)->parent)


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwRasterGetWidth(_raster)                   \
    RwRasterGetWidthMacro(_raster)

#define RwRasterGetHeight(_raster)                  \
    RwRasterGetHeightMacro(_raster)

#define RwRasterGetStride(_raster)                  \
    RwRasterGetStrideMacro(_raster)

#define RwRasterGetDepth(_raster)                   \
    RwRasterGetDepthMacro(_raster)

#define RwRasterGetFormat(_raster)                  \
    RwRasterGetFormatMacro(_raster)

#define RwRasterGetType(_raster)                  \
    RwRasterGetTypeMacro(_raster)

#define RwRasterGetParent(_raster)                  \
    RwRasterGetParentMacro(_raster)

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

/* Creating destroying rasters */
extern void RwRasterSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwRaster    *RwRasterCreate(RwInt32 width, RwInt32 height,
                                   RwInt32 depth, RwInt32 flags);
extern RwBool       RwRasterDestroy(RwRaster * raster);

/* Pulling info out of raster structure */

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
extern RwInt32      RwRasterGetWidth(const RwRaster *raster);
extern RwInt32      RwRasterGetHeight(const RwRaster *raster);
extern RwInt32      RwRasterGetStride(const RwRaster *raster);
extern RwInt32      RwRasterGetDepth(const RwRaster *raster);
extern RwInt32      RwRasterGetFormat(const RwRaster *raster);
extern RwInt32      RwRasterGetType(const RwRaster *raster);
extern RwRaster    *RwRasterGetParent(const RwRaster *raster);
#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

extern RwRaster    *RwRasterGetOffset(RwRaster *raster, 
                                      RwInt16 *xOffset, RwInt16 *yOffset);

extern RwInt32      RwRasterGetNumLevels(RwRaster * raster);

extern RwRaster    *RwRasterSubRaster(RwRaster * subRaster,
                                      RwRaster * raster, RwRect * rect);

extern RwRaster    *RwRasterRenderFast(RwRaster * raster, RwInt32 x,
                                       RwInt32 y);
extern RwRaster    *RwRasterRender(RwRaster * raster, RwInt32 x,
                                       RwInt32 y);
extern RwRaster    *RwRasterRenderScaled(RwRaster * raster,
                                         RwRect * rect);

/* Raster rendering context */
extern RwRaster    *RwRasterPushContext(RwRaster * raster);
extern RwRaster    *RwRasterPopContext(void);
extern RwRaster    *RwRasterGetCurrentContext(void);

/* Clearing rasters */
extern RwBool       RwRasterClear(RwInt32 pixelValue);
extern RwBool       RwRasterClearRect(RwRect * rpRect,
                                          RwInt32 pixelValue);

/* Displaying rasters */
extern RwRaster    *RwRasterShowRaster(RwRaster * raster, void *dev,
                                       RwUInt32 flags);

/* Locking and releasing */
extern RwUInt8     *RwRasterLock(RwRaster * raster, RwUInt8 level,
                                 RwInt32 lockMode);
extern RwRaster    *RwRasterUnlock(RwRaster * raster);
extern RwUInt8     *RwRasterLockPalette(RwRaster * raster,
                                        RwInt32 lockMode);
extern RwRaster    *RwRasterUnlockPalette(RwRaster * raster);

/* Attaching toolkits */
extern RwInt32      RwRasterRegisterPlugin(RwInt32 size,
                                           RwUInt32 pluginID,
                                           RwPluginObjectConstructor
                                           constructCB,
                                           RwPluginObjectDestructor
                                           destructCB,
                                           RwPluginObjectCopy copyCB);
extern RwInt32      RwRasterGetPluginOffset(RwUInt32 pluginID);
extern RwBool       RwRasterValidatePlugins(const RwRaster * raster);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2renderstate.h ---*/

/**
 * \ingroup rwcoregeneric
 *  RxRenderStateFlag 
 *  Flags used in the \ref RxRenderStateVector structure */
enum RxRenderStateFlag
{
    rxRENDERSTATEFLAG_TEXTUREPERSPECTIVE   = 0x00000001, /**<Perspective texturing is to be enabled */
    rxRENDERSTATEFLAG_ZTESTENABLE          = 0x00000002, /**<Z-Buffer testing is to be performed */
    rxRENDERSTATEFLAG_ZWRITEENABLE         = 0x00000004, /**<Z-Buffer writing is to be enabled */
    rxRENDERSTATEFLAG_VERTEXALPHAENABLE    = 0x00000008, /**<Vertex alpha is to be enabled */
    rxRENDERSTATEFLAG_FOGENABLE            = 0x00000010, /**<Fog is to be enabled */
    rxRENDERSTATEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RxRenderStateFlag RxRenderStateFlag;

typedef struct RxRenderStateVector RxRenderStateVector;
/**
 * \ingroup rwcoregeneric
 * \struct RxRenderStateVector
 * Structure describing a render-state vector,
 * used by the RxClRenderState cluster */
struct RxRenderStateVector
{
    RwUInt32             Flags;         /**< A load of the boolean renderstate options */
    RwShadeMode          ShadeMode;     /**< Flat or Gouraud currently */
    RwBlendFunction      SrcBlend;      /**< Src  alpha, 1-src  alpha, etc */
    RwBlendFunction      DestBlend;     /**< Dest alpha, 1-dest alpha, etc */
    RwRaster            *TextureRaster; /**< texture raster */
    RwTextureAddressMode AddressModeU;  /**< U addressing mode - WRAP, MIRROR, CLAMP, BORDER */
    RwTextureAddressMode AddressModeV;  /**< V addressing mode - WRAP, MIRROR, CLAMP, BORDER */
    RwTextureFilterMode  FilterMode;    /**< filtering mode - combos of NEAREST LINEAR MIP */
    RwRGBA               BorderColor;   /**< Border color for texturing address mode border */
    RwFogType            FogType;       /**< Select the type of fogging to use */
    RwRGBA               FogColor;      /**< Color used for fogging */
};

#if (!defined(RxRenderStateVectorAssign))
#define RxRenderStateVectorAssign(_target, _source)            \
    ( *(_target) = *(_source) )
#endif /* (!defined(RxRenderStateVectorAssign)) */



#ifdef    __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern       RxRenderStateVector *RxRenderStateVectorSetDefaultRenderStateVector(RxRenderStateVector *rsvp);
extern const RxRenderStateVector *RxRenderStateVectorGetDefaultRenderStateVector(void);
extern       RxRenderStateVector *RxRenderStateVectorCreate(RwBool current);
extern       void                 RxRenderStateVectorDestroy(RxRenderStateVector *rsvp);
extern       RxRenderStateVector *RxRenderStateVectorLoadDriverState(RxRenderStateVector *rsvp);

#ifdef    __cplusplus
}
#endif /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/baimage.h ---*/

/****************************************************************************
 Defines
 */

/* If this bit is set then the image has been allocated by the user */

enum RwImageFlag
{
    rwNAIMAGEFLAG = 0x00,
    rwIMAGEALLOCATED = 0x1,
    rwIMAGEGAMMACORRECTED = 0x2,
    rwIMAGEFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwImageFlag RwImageFlag;

/****************************************************************************
 Global Types
 */

/**
 * \ingroup rwimage
 * \struct RwImage 
 * Image containing device-independent pixels. 
 * This should be considered an opaque type.
 * Use the RwImage API functions to access.
 */
typedef struct RwImage RwImage;

#if (!defined(DOXYGEN))
struct RwImage
{
        RwInt32             flags;

        RwInt32             width;  /* Device may have different ideas */
        RwInt32             height; /* internally !! */

        RwInt32             depth;  /* Of referenced image */
        RwInt32             stride;

        RwUInt8            *cpPixels;
        RwRGBA             *palette;
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwimage
 * \ref RwImageCallBackRead 
 * is the function registered with \ref RwImageRegisterImageFormat that is used,
 * for example by \ref RwImageRead and \ref RwImageReadMaskedImage,
 * to read images of a specific format from a disk file.
 * 
 * \param  imageName   Pointer to a string containing the file name of the image.
 *
 * \return Returns a pointer to the image read.
 *
 * \see RwImageRegisterImageFormat
 *
 */
typedef RwImage *(*RwImageCallBackRead)(const RwChar * imageName);

/**
 * \ingroup rwimage
 * \ref RwImageCallBackWrite 
 * is the function registered with \ref RwImageRegisterImageFormat that is used,
 * for example by \ref RwImageWrite, 
 * to write images of a specific format to a disk file.
 * 
 * \param  image   Pointer to the image.
 *
 * \param  imageName   Pointer to a string containing the file name
 * of the image.
 *
 *
 * \return Pointer to the written image.
 *
 * \see RwImageRegisterImageFormat
 *
 */
typedef RwImage *(*RwImageCallBackWrite)(RwImage *image, const RwChar *imageName);


/****************************************************************************
 <macro/inline functionality
 */

#define RwImageSetStrideMacro(_image, _stride)      \
    (((_image)->stride = (_stride)), (_image))

#define RwImageSetPixelsMacro(_image, _pixels)      \
    (((_image)->cpPixels = (_pixels)), (_image))

#define RwImageSetPaletteMacro(_image, _palette)    \
    (((_image)->palette = (_palette)), (_image))

#define RwImageGetWidthMacro(_image)                \
    ((_image)->width)

#define RwImageGetHeightMacro(_image)               \
    ((_image)->height)

#define RwImageGetDepthMacro(_image)                \
    ((_image)->depth)

#define RwImageGetStrideMacro(_image)               \
    ((_image)->stride)

#define RwImageGetPixelsMacro(_image)               \
    ((_image)->cpPixels)

#define RwImageGetPaletteMacro(_image)              \
    ((_image)->palette)


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwImageSetStride(_image, _stride)           \
    RwImageSetStrideMacro(_image, _stride)

#define RwImageSetPixels(_image, _pixels)           \
    RwImageSetPixelsMacro(_image, _pixels)

#define RwImageSetPalette(_image, _palette)         \
    RwImageSetPaletteMacro(_image, _palette)

#define RwImageGetWidth(_image)                     \
    RwImageGetWidthMacro(_image)

#define RwImageGetHeight(_image)                    \
    RwImageGetHeightMacro(_image)

#define RwImageGetDepth(_image)                     \
    RwImageGetDepthMacro(_image)

#define RwImageGetStride(_image)                    \
    RwImageGetStrideMacro(_image)

#define RwImageGetPixels(_image)                    \
    RwImageGetPixelsMacro(_image)

#define RwImageGetPalette(_image)                   \
    RwImageGetPaletteMacro(_image)

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

    /* Creating and destroying */

extern void RwImageSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern void RwImageFormatSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwImage     *RwImageCreate(RwInt32 width, RwInt32 height,
                                  RwInt32 depth);
extern RwBool       RwImageDestroy(RwImage * image);

    /* Allocating */
extern RwImage     *RwImageAllocatePixels(RwImage * image);
extern RwImage     *RwImageFreePixels(RwImage * image);

    /* Converting images */
extern RwImage     *RwImageCopy(RwImage * destImage,
                                const RwImage * sourceImage);

    /* Resizing images */
extern RwImage     *RwImageResize(RwImage * image, RwInt32 width,
                                  RwInt32 height);

    /* Producing masks ! */
extern RwImage     *RwImageApplyMask(RwImage * image,
                                     const RwImage * mask);
extern RwImage     *RwImageMakeMask(RwImage * image);

    /* Helper functions */
extern RwImage     *RwImageReadMaskedImage(const RwChar * imageName,
                                           const RwChar * maskname);
extern RwImage     *RwImageRead(const RwChar * imageName);
extern RwImage     *RwImageWrite(RwImage * image,
                                 const RwChar * imageName);

    /* Setting and getting the default path for images */
extern RwChar      *RwImageGetPath(void);
extern const RwChar *RwImageSetPath(const RwChar * path);
    /* Fast image path change */
extern void        _rwImageSwapPath(RwChar **path, RwInt32 *size);

    /* Setting */
#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
extern RwImage     *RwImageSetStride(RwImage * image, RwInt32 stride);
extern RwImage     *RwImageSetPixels(RwImage * image, RwUInt8 * pixels);
extern RwImage     *RwImageSetPalette(RwImage * image, RwRGBA * palette);

    /* Getting */
extern RwInt32      RwImageGetWidth(const RwImage * image);
extern RwInt32      RwImageGetHeight(const RwImage * image);
extern RwInt32      RwImageGetDepth(const RwImage * image);
extern RwInt32      RwImageGetStride(const RwImage * image);
extern RwUInt8     *RwImageGetPixels(const RwImage * image);
extern RwRGBA      *RwImageGetPalette(const RwImage * image);
#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

    /* Get device dependent pixel value */
extern RwUInt32     RwRGBAToPixel(RwRGBA * rgbIn, RwInt32 rasterFormat);
extern RwRGBA      *RwRGBASetFromPixel(RwRGBA * rgbOut,
                                       RwUInt32 pixelValue,
                                       RwInt32 rasterFormat);

    /* Gamma correction */
extern RwBool       RwImageSetGamma(RwReal gammaValue);
extern RwReal       RwImageGetGamma(void);
extern RwImage     *RwImageGammaCorrect(RwImage * image);

    /* Adding and removing gamma correction */
extern RwRGBA      *RwRGBAGammaCorrect(RwRGBA * rgb);

    /* Attaching toolkits */
extern RwInt32      RwImageRegisterPlugin(RwInt32 size, RwUInt32 pluginID,
                                          RwPluginObjectConstructor
                                          constructCB,
                                          RwPluginObjectDestructor
                                          destructCB,
                                          RwPluginObjectCopy copyCB);
extern RwInt32      RwImageGetPluginOffset(RwUInt32 pluginID);
extern RwBool       RwImageValidatePlugins(const RwImage * image);

extern RwBool       RwImageRegisterImageFormat(const RwChar * extension,
                                               RwImageCallBackRead
                                               imageRead,
                                               RwImageCallBackWrite
                                               imageWrite);

    /* Finding an extension for an image to load */
extern const RwChar *RwImageFindFileType(const RwChar * imageName);

    /* Reading and writing images to streams */
extern RwInt32      RwImageStreamGetSize(const RwImage * image);
extern RwImage     *RwImageStreamRead(RwStream * stream);
extern const RwImage *RwImageStreamWrite(const RwImage * image,
                                         RwStream * stream);


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/*--- Automatically derived from: C:/daily/rwsdk/driver/common/palquant.h ---*/

/****************************************************************************
 Defines
 */

#define RWPALQUANT_MAXDEPTH 8
#define RWPALQUANT_MAXCOLOR (1<<RWPALQUANT_MAXDEPTH)

/****************************************************************************
 Global Types
 */

/**
 * \ingroup rwpalquant
 * \struct RwPalQuant
 * This opaque type is a structure that stores working data for the palette
 * quantization functions. This contains the color quantization tree, which
 * has a maximum depth set globally by \ref RwPalQuantSetMaxDepth.
 *
 * \see RwPalQuantInit
 * \see RwPalQuantAddImage
 * \see RwPalQuantResolvePalette
 * \see RwPalQuantMatchImage
 * \see RwPalQuantTerm
 */
typedef struct RwPalQuant RwPalQuant;

#if (!defined(DOXYGEN))

typedef struct _rwPalQuantRGBABox _rwPalQuantRGBABox;
typedef struct _rwPalQuantOctNode _rwPalQuantOctNode;
typedef struct _rwPalQuantLeafNode _rwPalQuantLeafNode;
typedef struct _rwPalQuantBranchNode _rwPalQuantBranchNode;

struct _rwPalQuantRGBABox
{
    RwInt32 col0[4];    /* min value, inclusive */
    RwInt32 col1[4];    /* max value, exclusive */
};

struct _rwPalQuantLeafNode
{
    /* Represents stats for both true leaf nodes and also branch nodes */
    RwReal      weight;     /* Accumulated weight */
    RwRGBAReal  ac;         /* Accumulated (weight * color) */
    RwReal      var;        /* Weight * variance */
    RwUInt8     palIndex;
};

struct _rwPalQuantBranchNode
{
    _rwPalQuantOctNode *dir[16];
};

struct _rwPalQuantOctNode
{
    _rwPalQuantLeafNode   Leaf;
    _rwPalQuantBranchNode Branch;
};

struct RwPalQuant
{
    _rwPalQuantRGBABox  Mcube[RWPALQUANT_MAXCOLOR];
    RwReal              Mvv[RWPALQUANT_MAXCOLOR];
    _rwPalQuantLeafNode Mvol[RWPALQUANT_MAXCOLOR];
    _rwPalQuantOctNode  *root;                    
    RwFreeList          *cubefreelist;            
};

#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Function prototypes
 */


#ifdef    __cplusplus
extern          "C"
{
#endif         /* __cplusplus */

extern void
RwPalQuantSetMaxDepth(RwUInt32 depth);

extern RwUInt32
RwPalQuantGetMaxDepth(void);

extern RwBool
RwPalQuantInit(RwPalQuant *pq);

extern void
RwPalQuantTerm(RwPalQuant *pq);


extern void
RwPalQuantAddImage(RwPalQuant *pq, RwImage *img, RwReal weight);


extern RwInt32
RwPalQuantResolvePalette(RwRGBA *palette, RwInt32 maxcols, RwPalQuant *pq);


extern void
RwPalQuantMatchImage(RwUInt8 *dstpixels, RwInt32 dststride, RwInt32 dstdepth,
                      RwBool dstPacked, RwPalQuant *pq, RwImage *img);

#ifdef    __cplusplus
}
#endif         /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/batextur.h ---*/

/****************************************************************************
 Defines
 */

/* Type ID */
#define rwTEXDICTIONARY 6

/* Mipmap Name generation - maximum number of RwChar characters which can
 * be appended to the root name.
 */
#define rwTEXTUREMIPMAPNAMECHARS    16

/* We define texture names to be a maximum of 16 ISO chars */
#define rwTEXTUREBASENAMELENGTH     32

#define rwTEXTUREFILTERMODEMASK     0x000000FF
#define rwTEXTUREADDRESSINGUMASK    0x00000F00
#define rwTEXTUREADDRESSINGVMASK    0x0000F000
#define rwTEXTUREADDRESSINGMASK     (rwTEXTUREADDRESSINGUMASK |  \
                                     rwTEXTUREADDRESSINGVMASK)

/****************************************************************************
 Global Types
 */

/**
 * \ingroup rwtexdict
 * \struct RwTexDictionary 
 * is a texture dictionary containing textures. 
 * This should be considered an opaque type.
 * Use the RwTexDictionary API functions to access.
 */
typedef struct RwTexDictionary RwTexDictionary;

#if (!defined(DOXYGEN))
struct RwTexDictionary
{
    RwObject            object; /* Homogeneous type */
    RwLinkList          texturesInDict; /* List of textures in dictionary */
    RwLLLink            lInInstance; /* Link list of all dicts in system */
};
/* Information is entirely device dependent */
#endif /* (!defined(DOXYGEN)) */


/* Parent is the dictionary */

/**
 * \ingroup rwtexture
 * \struct  RwTexture 
 * is a texture object. 
 * This should be considered an opaque type.
 * Use the RwTexture API functions to access.
 */
typedef struct RwTexture RwTexture;

#if (!defined(DOXYGEN))
struct RwTexture
{
    RwRaster           *raster; /** pointer to RwRaster with data */
    RwTexDictionary    *dict;   /* Dictionary this texture is in */
    RwLLLink            lInDictionary; /* List of textures in this dictionary */

    RwChar              name[rwTEXTUREBASENAMELENGTH];  /* Name of the texture */
    RwChar              mask[rwTEXTUREBASENAMELENGTH];  /* Name of the textures mask */

    /* 31 [xxxxxxxx xxxxxxxx vvvvuuuu ffffffff] 0 */
    RwUInt32            filterAddressing; /* Filtering & addressing mode flags */

    RwInt32             refCount; /* Reference count, surprisingly enough */
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwtexture
 * \ref RwTextureCallBackRead 
 * represents the function used by \ref RwTextureRead to read the specified
 * texture from a disk file. This function should return a pointer to the
 * texture to indicate success.
 * 
 * \param  name   Pointer to a string containing the name of
 * the texture to read.
 *
 * \param  maskName   Pointer to a string containing the name
 * of the mask to read and apply to the texture.
 *
 * \return Pointer to the texture
 *
 * \see RwTextureSetReadCallBack
 * \see RwTextureGetReadCallBack
 */
typedef RwTexture *(*RwTextureCallBackRead)(const RwChar *name,
                                            const RwChar *maskName);

/**
 * \ingroup rwtexture
 * \ref RwTextureCallBackFind
 * represents the function used by \ref RwTextureRead to search for a 
 * texture in memory before attempting to read one from disk. This
 * may involve searching previously loaded texture dictionaries.
 *
 * \param  name   Pointer to a string containing the name of
 * the texture to find.
 *
 * \return Pointer to the texture, or NULL if not found.
 *
 * \see RwTextureSetFindCallBack
 * \see RwTextureGetFindCallBack
 */
typedef RwTexture *(*RwTextureCallBackFind)(const RwChar *name);

/**
 * \ingroup rwtexture
 * \ref RwTextureCallBack
 * represents the function called from \ref RwTexDictionaryForAllTextures
 * for all textures in a given texture dictionary. This function should
 * return the current texture to indicate success. The callback may return
 * NULL to terminate further callbacks on the texture dictionary.
 * 
 * \param  texture   Pointer to the current texture.
 *
 * \param  pData   User-defined data pointer.
 *
 * \return Pointer to the current texture
 *
 * \see RwTexDictionaryForAllTextures
 */
typedef RwTexture *(*RwTextureCallBack)(RwTexture *texture, void *pData);


/**
 * \ingroup rwtexdict
 * \ref RwTexDictionaryCallBack
 * represents the function called from \ref RwTexDictionaryForAllTexDictionaries
 * for all texture dictionaries that currently exist. This function should
 * return the current texture dictionary to indicate success. The callback may
 * return NULL to terminate further callbacks on the texture dictionary. It may
 * safely destroy the current texture dictionary without adversely affecting
 * the iteration process.
 * 
 * \param  dict   Pointer to the current texture dictionary.
 *
 * \param  pData   User-defined data pointer.
 *
 * \return Pointer to the current texture dictionary
 *
 * \see RwTexDictionaryForAllTexDictionaries
 */
typedef RwTexDictionary *(*RwTexDictionaryCallBack)(RwTexDictionary *dict, void *data);


/**
 * \ingroup rwtexture
 * \ref RwTextureCallBackMipmapGeneration 
 * is the callback function supplied to \ref RwTextureSetMipmapGenerationCallBack 
 * and returned from \ref RwTextureGetMipmapGenerationCallBack.
 *
 * The supplied function will be passed a pointer to a raster and an image.
 * The raster is the target for the generated mipmap levels and the image 
 * provides the base for their generation.
 * 
 * \param  raster   Pointer to raster, the target for generated mipmap levels
 * \param  image    Pointer to image, used to generate mipmap levels.
 * 
 * \return
 * Returns a pointer to the raster if successful or NULL if an error occurred.
 * 
 * \see RwTextureSetMipmapGenerationCallBack
 * \see RwTextureGetMipmapGenerationCallBack
 * \see RwTextureSetAutoMipmapping
 * \see RwTextureGetAutoMipmapping
 */
typedef RwRaster *(*RwTextureCallBackMipmapGeneration)(RwRaster * raster,
                                                       RwImage * image);

/**
 * \ingroup rwtexture
 * \ref RwTextureCallBackMipmapName
 * is the callback function supplied to \ref RwTextureSetMipmapNameCallBack and
 * returned from \ref RwTextureGetMipmapNameCallBack.
 *
 * The supplied function will be passed a pointer to a root name, a maskName, a mipmap
 * level and a format. The function returns TRUE if successful and the root name will have been 
 * modified to equal the mipmap name.
 * 
 * \param  name       Pointer to a string containing the root name of the texture. The 
 * mipmap level name is put here.
 * \param  maskName   Pointer to a string containing the root mask name of the texture or
 * NULL if no mask name is required.
 * \param  mipLevel   A value equal to the mipmap level for which the name is required.
 * \param  format     A value describing the mipmapping mode. A combination of the bit
 * flags rwRASTERFORMATMIPMAP and rwRASTERFORMATAUTOMIPMAP.
 * 
 * \return
 * Returns TRUE if the name is generated successfully or FALSE if an error occurred.
 * 
 * \see RwTextureGenerateMipmapName
 * \see RwTextureSetMipmapNameCallBack
 * \see RwTextureGetMipmapNameCallBack
 * \see RwTextureSetAutoMipmapping
 * \see RwTextureGetAutoMipmapping
 */
typedef RwBool (*RwTextureCallBackMipmapName)(RwChar *name,
                                              RwChar *maskName,
                                              RwUInt8 mipLevel,
                                              RwInt32 format);

/****************************************************************************
 <macro/inline functionality
 */

#define RwTextureGetRasterMacro(_tex)                       \
    ((_tex)->raster)

#define RwTextureAddRefMacro(_tex)                          \
    (((_tex)->refCount++), (_tex))

#define RwTextureAddRefVoidMacro(_tex)                      \
MACRO_START                                                 \
{                                                           \
    (_tex)->refCount++;                                     \
}                                                           \
MACRO_STOP

#define RwTextureGetNameMacro(_tex)                         \
    ((_tex)->name)

#define RwTextureGetMaskNameMacro(_tex)                     \
    ((_tex)->mask)

#define RwTextureGetDictionaryMacro(_tex)                   \
    ((_tex)->dict)

#define RwTextureSetFilterModeMacro(_tex, _filtering)                       \
    (((_tex)->filterAddressing =                                            \
      ((_tex)->filterAddressing & ~rwTEXTUREFILTERMODEMASK) |               \
      (((RwUInt32)(_filtering)) &  rwTEXTUREFILTERMODEMASK)),               \
     (_tex))

#define RwTextureGetFilterModeMacro(_tex)                                   \
    ((RwTextureFilterMode)((_tex)->filterAddressing &                       \
                           rwTEXTUREFILTERMODEMASK))

#define RwTextureSetAddressingMacro(_tex, _addressing)                      \
    (((_tex)->filterAddressing =                                            \
      ((_tex)->filterAddressing & ~rwTEXTUREADDRESSINGMASK) |               \
      (((((RwUInt32)(_addressing)) <<  8) & rwTEXTUREADDRESSINGUMASK) |     \
       ((((RwUInt32)(_addressing)) << 12) & rwTEXTUREADDRESSINGVMASK))),    \
     (_tex))

#define RwTextureSetAddressingUMacro(_tex, _addressing)                     \
    (((_tex)->filterAddressing =                                            \
      ((_tex)->filterAddressing & ~rwTEXTUREADDRESSINGUMASK) |              \
      (((RwUInt32)(_addressing) << 8) & rwTEXTUREADDRESSINGUMASK)),         \
     (_tex))

#define RwTextureSetAddressingVMacro(_tex, _addressing)                     \
    (((_tex)->filterAddressing =                                            \
      ((_tex)->filterAddressing & ~rwTEXTUREADDRESSINGVMASK) |              \
      (((RwUInt32)(_addressing) << 12) & rwTEXTUREADDRESSINGVMASK)),        \
     (_tex))

#define RwTextureGetAddressingMacro(_tex)                                   \
    (((((_tex)->filterAddressing & rwTEXTUREADDRESSINGUMASK) >>  8) ==      \
      (((_tex)->filterAddressing & rwTEXTUREADDRESSINGVMASK) >> 12)) ?      \
     ((RwTextureAddressMode)(((_tex)->filterAddressing &                    \
                              rwTEXTUREADDRESSINGVMASK) >> 12)) :           \
     rwTEXTUREADDRESSNATEXTUREADDRESS)

#define RwTextureGetAddressingUMacro(_tex)                                  \
    ((RwTextureAddressMode)(((_tex)->filterAddressing &                     \
                             rwTEXTUREADDRESSINGUMASK) >> 8))

#define RwTextureGetAddressingVMacro(_tex)                                  \
    ((RwTextureAddressMode)(((_tex)->filterAddressing &                     \
                             rwTEXTUREADDRESSINGVMASK) >> 12))


#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwTextureGetRaster(_tex)                            \
    RwTextureGetRasterMacro(_tex)

#define RwTextureAddRef(_tex)                               \
    RwTextureAddRefMacro(_tex)

#define RwTextureGetName(_tex)                              \
    RwTextureGetNameMacro(_tex)

#define RwTextureGetMaskName(_tex)                          \
    RwTextureGetMaskNameMacro(_tex)

#define RwTextureGetDictionary(_tex)                        \
    RwTextureGetDictionaryMacro(_tex)

#define RwTextureSetFilterMode(_tex, _filtering)            \
    RwTextureSetFilterModeMacro(_tex, _filtering)

#define RwTextureGetFilterMode(_tex)                        \
    RwTextureGetFilterModeMacro(_tex)

#define RwTextureSetAddressing(_tex, _addressing)           \
    RwTextureSetAddressingMacro(_tex, _addressing)

#define RwTextureSetAddressingU(_tex, _addressing)          \
    RwTextureSetAddressingUMacro(_tex, _addressing)

#define RwTextureSetAddressingV(_tex, _addressing)          \
    RwTextureSetAddressingVMacro(_tex, _addressing)

#define RwTextureGetAddressing(_tex)                        \
    RwTextureGetAddressingMacro(_tex)

#define RwTextureGetAddressingU(_tex)                       \
    RwTextureGetAddressingUMacro(_tex)

#define RwTextureGetAddressingV(_tex)                       \
    RwTextureGetAddressingVMacro(_tex)

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */



/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

    /* Reading mip maps */

    /* Setting mip mapping states */
extern RwBool       RwTextureSetMipmapping(RwBool enable);
extern RwBool       RwTextureGetMipmapping(void);
extern RwBool       RwTextureSetAutoMipmapping(RwBool enable);
extern RwBool       RwTextureGetAutoMipmapping(void);

    /* Setting and getting the mipmap generation function */
extern              RwBool
RwTextureSetMipmapGenerationCallBack(RwTextureCallBackMipmapGeneration
                                     callback);
extern              RwTextureCallBackMipmapGeneration
RwTextureGetMipmapGenerationCallBack(void);

    /* Setting and getting the mipmap file name generation function */
extern              RwBool
RwTextureSetMipmapNameCallBack(RwTextureCallBackMipmapName callback);
extern RwTextureCallBackMipmapName RwTextureGetMipmapNameCallBack(void);

    /* Generating mipmaps for a raster */
extern RwBool       RwTextureGenerateMipmapName(RwChar * name,
                                                RwChar * maskName,
                                                RwUInt8 mipLevel,
                                                RwInt32 format);
extern RwBool       RwTextureRasterGenerateMipmaps(RwRaster * raster,
                                                   RwImage * image);

    /* LEGACY-SUPPORT mip mapping */
extern RwBool       _rwTextureSetAutoMipMapState(RwBool enable);
extern RwBool       _rwTextureGetAutoMipMapState(void);

    /* Setting and getting the callback function */
extern RwTextureCallBackRead RwTextureGetReadCallBack(void);
extern RwBool       RwTextureSetReadCallBack(RwTextureCallBackRead callBack);

extern RwTextureCallBackFind RwTextureGetFindCallBack(void);
extern RwBool       RwTextureSetFindCallBack(RwTextureCallBackFind callBack);

    /* Texture and mask names */
extern RwTexture   *RwTextureSetName(RwTexture * texture,
                                     const RwChar * name);
extern RwTexture   *RwTextureSetMaskName(RwTexture * texture,
                                         const RwChar * maskName);

    /* Creating/destroying dictionaries */
extern void RwTexDictionarySetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwTexDictionary *RwTexDictionaryCreate(void);
extern RwBool       RwTexDictionaryDestroy(RwTexDictionary * dict);

    /* Textures */
void RwTextureSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwTexture   *RwTextureCreate(RwRaster * raster);
extern RwBool       RwTextureDestroy(RwTexture * texture);

    /* Setting and getting texture map rasters */
extern RwTexture   *RwTextureSetRaster(RwTexture * texture,
                                       RwRaster * raster);

    /* Dictionary access */
extern RwTexture   *RwTexDictionaryAddTexture(RwTexDictionary * dict,
                                              RwTexture * texture);
extern RwTexture   *RwTexDictionaryRemoveTexture(RwTexture * texture);
extern RwTexture   *RwTexDictionaryFindNamedTexture(RwTexDictionary *
                                                    dict,
                                                    const RwChar * name);

    /* Reading a texture */
extern RwTexture   *RwTextureRead(const RwChar * name,
                                  const RwChar * maskName);

    /* Setting the current dictionary */
extern RwTexDictionary *RwTexDictionaryGetCurrent(void);
extern RwTexDictionary *RwTexDictionarySetCurrent(RwTexDictionary * dict);

    /* Enumerating textures */
extern const RwTexDictionary *RwTexDictionaryForAllTextures(const
                                                            RwTexDictionary
                                                            * dict,
                                                            RwTextureCallBack
                                                            fpCallBack,
                                                            void *pData);

    /* Enumerating the texture dictionaries currently in the system */
extern RwBool RwTexDictionaryForAllTexDictionaries(
    RwTexDictionaryCallBack fpCallBack, void *pData);


    /* Attaching toolkits */
extern RwInt32      RwTextureRegisterPlugin(RwInt32 size,
                                            RwUInt32 pluginID,
                                            RwPluginObjectConstructor
                                            constructCB,
                                            RwPluginObjectDestructor
                                            destructCB,
                                            RwPluginObjectCopy copyCB);
extern RwInt32      RwTexDictionaryRegisterPlugin(RwInt32 size,
                                                  RwUInt32 pluginID,
                                                  RwPluginObjectConstructor
                                                  constructCB,
                                                  RwPluginObjectDestructor
                                                  destructCB,
                                                  RwPluginObjectCopy
                                                  copyCB);
extern RwInt32      RwTextureGetPluginOffset(RwUInt32 pluginID);
extern RwInt32      RwTexDictionaryGetPluginOffset(RwUInt32 pluginID);
extern RwBool       RwTextureValidatePlugins(const RwTexture * texture);
extern RwBool       RwTexDictionaryValidatePlugins(const RwTexDictionary *
                                                   dict);

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))
/* Textures */
extern RwRaster *RwTextureGetRaster(const RwTexture *texture);
extern RwTexture *RwTextureAddRef(RwTexture *texture);

/* Texture and mask names */
extern RwChar *RwTextureGetName(RwTexture *texture);
extern RwChar *RwTextureGetMaskName(RwTexture *texture);

/* Get owner dictionary */
extern RwTexDictionary *RwTextureGetDictionary(RwTexture *texture);

/* Filtering */
extern RwTexture *RwTextureSetFilterMode(RwTexture *texture,
                                         RwTextureFilterMode filtering);

extern RwTextureFilterMode RwTextureGetFilterMode(const RwTexture *texture);

/* Addressing */
extern RwTexture *RwTextureSetAddressing(RwTexture *texture,
                                         RwTextureAddressMode addressing);
extern RwTexture *RwTextureSetAddressingU(RwTexture *texture,
                                          RwTextureAddressMode addressing);
extern RwTexture *RwTextureSetAddressingV(RwTexture *texture,
                                          RwTextureAddressMode addressing);

extern RwTextureAddressMode RwTextureGetAddressing(const RwTexture *texture);
extern RwTextureAddressMode RwTextureGetAddressingU(const RwTexture *texture);
extern RwTextureAddressMode RwTextureGetAddressingV(const RwTexture *texture);

#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#define RwTextureSetAutoMipMapState(_enable) \
    _rwTextureSetAutoMipMapState(_enable)

#define RwTextureGetAutoMipMapState() \
    _rwTextureGetAutoMipMapState()


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/p2stdcls.h ---*/

/*
 * Current:
 *
 * wait on Simon for instructions to do cluster renaming thing,
 * or go thru and  change all cluster type names and cluster
 * names (add CSL?)
 *
 */

/* CamVerts.csl */

/* clip flags */

/**
 * \ingroup rwcoregeneric
 * \ref RwClipFlag
 * Flags specifying the clipping status of a vertex
 */
enum RwClipFlag
{
    rwXLOCLIP   = 0x01, /**<The vertex is outside the low X clip-plane */
    rwXHICLIP   = 0x02, /**<The vertex is outside the high X clip-plane */
    rwXCLIP     = 0x03, /**<The vertex is outside an X clip-plane */

    rwYLOCLIP   = 0x04, /**<The vertex is outside the low Y clip-plane */
    rwYHICLIP   = 0x08, /**<The vertex is outside the high Z clip-plane */
    rwYCLIP     = 0x0C, /**<The vertex is outside a Y clip-plane */

    rwZLOCLIP   = 0x10, /**<The vertex is outside the low Z clip-plane */
    rwZHICLIP   = 0x20, /**<The vertex is outside the high Z clip-plane */
    rwZCLIP     = 0x30, /**<The vertex is outside a Z clip-plane */

    rwCLIPMASK  = 0x3F, /**<Mask covering all used bits in the clip flags
                         * in case a plugin  wants free ones to use (e.g RpGloss) */

    rwCLIPFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
/*
 * Typedef for RwClipFlag enumeration specifying the clipping status of a vertex
 */
typedef enum RwClipFlag RwClipFlag;



typedef struct RxCamSpace3DVertex RxCamSpace3DVertex;

/**
 * \ingroup rwcoregeneric
 * \struct RxCamSpace3DVertex
 * Structure describing a camera-space 3D vertex.
 */
struct RxCamSpace3DVertex
{
    /* Position in sheared camera-space (pre-projection) */
    RwV3d           cameraVertex; /**< \ref RwV3d camera-space position of the vertex */
    /* Clip flags on this vertex */
    RwUInt8         clipFlags;    /**< Clip flags for the vertex generated during transformation into camera-space, see \ref RwClipFlag */
    RwUInt8         pad[3];       /**< Alignment padding */
    /* Lit color */
    RwRGBAReal      col;          /**< Accumulated \ref RwReal light values (initialized to zero or prelight colors) */
    /* Only used by the clipper */
    RwReal          u;            /**< Texture U coordinate */
    RwReal          v;            /**< Texture V coordinate */
};

/* Supports pipeline1 apps: */
/**
 * \ingroup rwcoregeneric
 * \ref RwCameraVertex
 * typedef for a structure describing a camera-space 3D vertex.
 */
typedef RxCamSpace3DVertex RwCameraVertex;

/* (used during lighting) Doesn't use alpha yet, but it will */
#define RxCamSpace3DVertexSetRGBA(camvert, r, g, b, a)  \
MACRO_START                                             \
{                                                       \
    ((camvert)->col.red = (r));                         \
    ((camvert)->col.green = (g));                       \
    ((camvert)->col.blue = (b));                        \
    ((camvert)->col.alpha = (a));                       \
}                                                       \
MACRO_STOP

#define RxCamSpace3DVertexAddRGBA(camvert, r, g, b, a)  \
MACRO_START                                             \
{                                                       \
    ((camvert)->col.red += (r));                        \
    ((camvert)->col.green += (g));                      \
    ((camvert)->col.blue += (b));                       \
    ((camvert)->col.alpha += (a));                      \
}                                                       \
MACRO_STOP

/* LEGACY-SUPPORT macros */
#define RXCAMSPACE3DVERTEXSetRGBA(camvert, r, g, b, a)  \
    RxCamSpace3DVertexSetRGBA(camvert, r, g, b, a)
#define RXCAMSPACE3DVERTEXAddRGBA(camvert, r, g, b, a)  \
    RxCamSpace3DVertexAddRGBA(camvert, r, g, b, a)

/* MeshState.csl */


/**
 * \ingroup rwcoregeneric
 * \ref RxGeometryFlag
 * Flags describing geometry properties
 */
enum RxGeometryFlag
{
    rxGEOMETRY_TRISTRIP      = 0x01,  /**<This geometry's meshes can be rendered as tri-strips */
    rxGEOMETRY_POSITIONS     = 0x02,  /**<This geometry has positions */
    rxGEOMETRY_TEXTURED      = 0x04,  /**<This geometry has textures applied */
    rxGEOMETRY_PRELIT        = 0x08,  /**<This geometry has luminance values */
    rxGEOMETRY_NORMALS       = 0x10,  /**<This geometry has normals */
    rxGEOMETRY_LIGHT         = 0x20,  /**<This geometry will be lit */
    rxGEOMETRY_MODULATE      = 0x40,  /**<This geometry will modulate the material color with the vertex colors (prelit + lit) */
    rxGEOMETRY_TEXTURED2     = 0x80,  /**<This geometry has 2 set of texture coordinates */

    rxGEOMETRY_COLORED       = 0x100, /**<This mesh specifies per-vertex colors. NB: ONLY USED IN IM3D */

    rxGEOMETRYFLAGFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
/*
 * Typedef for RxGeometryFlag enumeration describing geometry properties
 */
typedef enum RxGeometryFlag RxGeometryFlag;

typedef struct RxMeshStateVector RxMeshStateVector;

/**
 * \ingroup rwcoregeneric
 * \struct RxMeshStateVector
 * Structure describing a mesh-state vector,
 * used by the RxClMeshState cluster
 */
struct RxMeshStateVector
{
    RwInt32             Flags;              /**< \ref RxGeometryFlag Flags from the source geometry */
    void               *SourceObject;       /**< A void pointer. In immediate mode it points to an
                                             * internal structure and in atomic/world-sector object
                                             * or material pipelines it points to an \ref RpMaterial. */
    RwMatrix            Obj2World;          /**< \ref RwMatrix to transform from object-space to world-space */
    RwMatrix            Obj2Cam;            /**< \ref RwMatrix to transform from object-space to camera-space */
    RwSurfaceProperties SurfaceProperties;  /**< \ref RwSurfaceProperties */
    /* We can't necessarily reference an RpMaterial in here (i.e with Im3D),
     * because RpMaterials are defined in RpWorld not RwCore */
    RwTexture          *Texture;            /**< A pointer to a \ref RwTexture */
    RwRGBA              MatCol;             /**< \ref RwRGBA material color */
    RxPipeline         *Pipeline;           /**< A pointer to the material pipeline where appropriate */
    /* rwPRIMTYPETRILIST/TRIFAN/TRISTRIP/LINELIST/POLYLINE */
    RwPrimitiveType     PrimType;           /**< \ref RwPrimitiveType primitive type */
    /* Interpretation based on PrimType */
    RwUInt32            NumElements;        /**< \ref RwUInt32 number of elements (triangles, lines...) */
    RwUInt32            NumVertices;        /**< \ref RwUInt32 number of vertices */
    RwInt32             ClipFlagsOr;        /**< Boolean OR of the \ref RwClipFlag clip flags of all vertices in the mesh */
    RwInt32             ClipFlagsAnd;       /**< Boolean AND of the \ref RwClipFlag clip flags of all vertices in the mesh */
    void               *SourceMesh;         /**< A void pointer to the source \ref RpMesh */
    void               *DataObject;         /**< Mirrors the void data pointer of \ref RxPipelineExecute */
};

/* RxScatter.csl */
typedef struct RxScatter RxScatter;
/**
 * \ingroup rwcoregeneric
 * \struct RxScatter
 * Structure used by the RxClScatter cluster
 */
struct RxScatter
{
    RxPipeline    *pipeline; /**< \ref RxPipeline pointer, causes Scatter.csl
                              * to spit the packet out to the specified pipeline */
    RxPipelineNode *node;    /**< \ref RxPipelineNode pointer, causes Scatter.csl
                              * to send the packet to the specified PipelineNode
                              * (as long as it is actually one of its outputs!) */
};

/* RxInterpolants.csl */
typedef struct RxInterp RxInterp;
/**
 * \ingroup rwcoregeneric
 * \struct RxInterp
 * Structure used by the RxClInterp cluster
 */
struct RxInterp
{
    RxVertexIndex originalVert; /**< \ref RxVertexIndex index to the new vertex generated on the clipped edge */
    RxVertexIndex parentVert1;  /**< \ref RxVertexIndex index to the first vertex of the clipped edge */
    RxVertexIndex parentVert2;  /**< \ref RxVertexIndex index to the second vertex of the clipped edge */
    RwReal        interp;       /**< \ref RwReal interpolant along the clipped edge */
};

/* RxUVs.csl */
typedef struct RxUV RxUV;
/**
 * \ingroup rwcoregeneric
 * \struct RxUV
 * Structure used by the RxClUV cluster
 */
struct RxUV
{
    RwReal u; /**< \ref RwReal U texture coordinate */
    RwReal v; /**< \ref RwReal V texture coordinate */
};

/* RxTriPlanes.csl */
typedef struct RxTriPlane RxTriPlane;

/**
 * \ingroup rwcoregeneric
 * \struct RxTriPlane
 * for the packed plane structure used in RpWorlds and by the RxClTriPlane cluster
 * NOTE: this is currently not used in any nodes that ship with the SDK
 */
struct RxTriPlane
{
    /* Packed plane format used in RpWorlds */
    RwUInt32 N; /**< \ref RwUInt32 Packed normal */
    RwReal   w; /**< \ref RwReal distance from origin */
};

/* RxVSteps.csl */

#if (defined(_MSC_VER))
#  if (_MSC_VER>=1000)
#    pragma pack(push, 1)
#  endif /* (_MSC_VER>=1000) */
#endif /* (defined(_MSC_VER)) */

typedef struct RxVStep RxVStep;
/**
 * \ingroup rwcoregeneric
 * \struct RxVStep
 * Structure used by the RxClVStep cluster.
 * To use the step values in the RxClVStep cluster, start at the beginning
 * of the RxVStep and vertex arrays and proceed as follows: (a) Process one
 * vertex, (b) Skip 'step' vertices, (c) Increment the cursor of the RxClVStep
 * cluster. Repeat (a)-(c) until the entire vertex array has been processed.
 * If the RxVStep array contains valid data, you should not have to bounds-check
 * its cursor.
 */
struct RxVStep
{
    RwUInt8 step; /**< \ref RwUInt8 The number of vertices after the current one
                   * which can be skipped in lighting and other calculations because,
                   * for example, they belong only to back-facing triangles */
};

#if (defined(_MSC_VER))
#  if (_MSC_VER>=1000)
#    pragma pack(pop)
#  endif /* (_MSC_VER>=1000) */
#endif /* (defined(_MSC_VER)) */

/* CamNorms.csl */
/**
 * \ingroup rwcoregeneric
 * \ref RxCamNorm
 * typedef for \ref RwV3d used by the RxClVStep cluster */
typedef RwV3d RxCamNorm;


#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Uses the RxObjSpace3DVertex type (see pipmodel.h) */
extern RxClusterDefinition RxClObjSpace3DVertices;
/* Uses the RxCamSpace3DVertex type */
extern RxClusterDefinition RxClCamSpace3DVertices;
/* Uses the RxScrSpace2DVertex type (see pipmodel.h) */
extern RxClusterDefinition RxClScrSpace2DVertices;
/* Uses the RxInterp type */
extern RxClusterDefinition RxClInterpolants;
/* Uses the RxMeshStateVector type */
extern RxClusterDefinition RxClMeshState;
/* Uses the RxRenderStateVector type (p2renderstate.c/h) */
extern RxClusterDefinition RxClRenderState;
/* Uses the RxVertexIndex type */
extern RxClusterDefinition RxClIndices;
/* Uses the RxScatter type */
extern RxClusterDefinition RxClScatter;
/* Uses the RxUV type */
extern RxClusterDefinition RxClUVs;
/* Uses the RxVStep type */
extern RxClusterDefinition RxClVSteps;
/* Uses the RwRGBAReal type */
extern RxClusterDefinition RxClRGBAs;
/* Uses the RxCamNorm type */
extern RxClusterDefinition RxClCamNorms;

/* Uses the RxTriPlane type.
 * NOTE: this is currently not used in any nodes that ship with the SDK */
extern RxClusterDefinition RxClTriPlanes;

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/baim3d.h ---*/

/**
 * \ingroup rwim3d
 * RwIm3DTransformFlags
 *  The bit-field type  RwIm3DTransformFlags
 * specifies options available for controlling execution of the 3D immediate
 * mode pipeline (see API function \ref RwIm3DTransform):*/
enum RwIm3DTransformFlags
{
    rwIM3D_VERTEXUV      = 1,   /**<Texture coordinates in source vertices should be used */
    rwIM3D_ALLOPAQUE     = 2,   /**<All source vertices are opaque (alpha is 255) */
    rwIM3D_NOCLIP        = 4,   /**<No clipping should be performed on the geometry (the
                                 * app may know it is all onscreen or within the guard band clipping
                                 * region for the current hardware, so clipping can be skipped) */
    rwIM3D_VERTEXXYZ     = 8,   /**<Vertex positions */
    rwIM3D_VERTEXRGBA    = 16,  /**<Vertex color */

    rwIM3DTRANSFORMFLAGSFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwIm3DTransformFlags RwIm3DTransformFlags;



typedef struct rwIm3DPool            rwIm3DPool;
typedef struct rwImmediGlobals       rwImmediGlobals;
typedef struct rwIm3DRenderPipelines rwIm3DRenderPipelines;
typedef struct _rwIm3DPoolStash       _rwIm3DPoolStash;

#if (0 && defined(SKY2))
typedef struct rwIm3DVertexCache     RwIm3DVertexCache;
#endif /* (0&& defined(SKY2)) */

/* complete information to reconstruct post-transform Im3D "mesh" packet */

#if (!defined(DOXYGEN))
struct _rwIm3DPoolStash
{
    RwUInt32                 flags;    /* rwIM3D_VERTEXUV, rwIM3D_ALLOPAQUE, rwIM3D_NOCLIP etc */
    RwMatrix                *ltm;      /* world-space frame of the vertices, if they have one */
    RwUInt32                 numVerts;
    RxObjSpace3DVertex      *objVerts;
    RxCamSpace3DVertex      *camVerts;
    RxScrSpace2DVertex      *devVerts;
    RxMeshStateVector       *meshState;
    RxRenderStateVector     *renderState;
    RxPipeline              *pipeline;
    RwPrimitiveType          primType;
    RxVertexIndex           *indices;
    RwUInt32                 numIndices;
};

/* Used as a cache of transformed vertices */
struct rwIm3DPool
{
    RwUInt16         numElements; /* could become RwUInt32 nowadays */
    RwUInt16         pad;         /* alignment padding */
    void            *elements;    /* the original array of verts (or whatever...) - referenced not copied */
    RwInt32          stride;      /* the stride of the element */
    _rwIm3DPoolStash  stash;
};

struct rwIm3DRenderPipelines
{
    /* One Im3D render pipeline pointer per rwPRIMTYPE
     * (several pointers may point to the same pipeline though) */
    RxPipeline *triList;
    RxPipeline *triFan;
    RxPipeline *triStrip;
    RxPipeline *lineList;
    RxPipeline *polyLine;
    RxPipeline *pointList;
};

struct rwImmediGlobals
{
    RxPipeline           *im3DTransformPipeline;
    rwIm3DRenderPipelines im3DRenderPipelines;

    /* Platforms that have their own non-generic pipelines
     * (OPENGL, D3D8, SKY2, KAMUI2, DOLPHIN) put them here: */
    RxPipeline           *platformIm3DTransformPipeline;
    rwIm3DRenderPipelines platformIm3DRenderPipelines;

#if (defined(SKY2_DRVMODEL_H))
    /* The triangle PS2All render pipe automatically
     * calls this PS2AllMat pipeline: */
    RxPipeline           *ps2AllMatIm3DTrianglePipeline;
    /* The line PS2All render pipe automatically
     * calls this PS2AllMat pipeline: */
    RxPipeline           *ps2AllMatIm3DLinePipeline;
#endif /* (defined(SKY2_DRVMODEL_H)) */

    rwIm3DPool   curPool;              /* The current cache of transformed vertices */
};
#endif /* (!defined(DOXYGEN)) */


#ifdef    __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern rwIm3DPool *_rwIm3DGetPool( void );

extern void  *RwIm3DTransform(RwIm3DVertex *pVerts, RwUInt32 numVerts,
                              RwMatrix *ltm, RwUInt32 flags);
extern RwBool RwIm3DEnd(void);

extern RwBool RwIm3DRenderLine(RwInt32 vert1, RwInt32 vert2);
extern RwBool RwIm3DRenderTriangle(RwInt32 vert1, RwInt32 vert2,
                                   RwInt32 vert3);
extern RwBool RwIm3DRenderIndexedPrimitive(RwPrimitiveType primType,
                                           RwImVertexIndex *indices,
                                           RwInt32 numIndices);
extern RwBool RwIm3DRenderPrimitive(RwPrimitiveType primType);

extern RxPipeline *RwIm3DGetTransformPipeline(void);
extern RxPipeline *RwIm3DGetRenderPipeline(   RwPrimitiveType  primType);
extern RxPipeline *RwIm3DSetTransformPipeline(RxPipeline *pipeline);
extern RxPipeline *RwIm3DSetRenderPipeline(   RxPipeline *pipeline,
                                              RwPrimitiveType primType);

#ifdef    __cplusplus
}
#endif /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/opengl/im3dpipe.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/baresamp.h ---*/

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

extern RwImage *RwImageResample(RwImage *dstImage, const RwImage *srcImage);
extern RwImage *RwImageCreateResample(const RwImage *srcImage, RwInt32 width,
                                                               RwInt32 height);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/baimras.h ---*/
/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Images from rasters */
extern RwImage *RwImageSetFromRaster(RwImage *image, RwRaster *raster);

/* Rasters from images */
extern RwRaster *RwRasterSetFromImage(RwRaster *raster, RwImage *image);

/* Read a raster */
extern RwRaster *RwRasterRead(const RwChar *filename);
extern RwRaster *RwRasterReadMaskedRaster(const RwChar *filename, const RwChar *maskname);

/* Finding appropriate raster formats */
extern RwImage *RwImageFindRasterFormat(RwImage *ipImage,RwInt32 nRasterType,
                                        RwInt32 *npWidth,RwInt32 *npHeight,
                                        RwInt32 *npDepth,RwInt32 *npFormat);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/baframe.h ---*/

/****************************************************************************
 Defines
 */

#if (!defined(RWFRAMESTATICPLUGINSSIZE))
#define RWFRAMESTATICPLUGINSSIZE 0
#endif

#define RWFRAMEALIGNMENT(_frame) \
   (! (((rwFRAMEALIGNMENT)-1) & ((RwUInt32)(_frame))))

/* Type ID */
#define rwFRAME 0

/* dirty flag bits */
#define rwFRAMEPRIVATEHIERARCHYSYNCLTM  0x01
#define rwFRAMEPRIVATEHIERARCHYSYNCOBJ  0x02
#define rwFRAMEPRIVATESUBTREESYNCLTM    0x04
#define rwFRAMEPRIVATESUBTREESYNCOBJ    0x08
#define rwFRAMEPRIVATESTATIC            0x10

/****************************************************************************
 Global Types
 */

#if (!defined(DOXYGEN))
struct RwFrame
{
    RwObject            object;

    RwLLLink            inDirtyListLink;

    /* Put embedded matrices here to ensure they remain 16-byte aligned */
    RwMatrix            modelling;
    RwMatrix            ltm;

    RwLinkList          objectList; /* List of objects connected to a frame */

    struct RwFrame      *child;
    struct RwFrame      *next;
    struct RwFrame      *root;   /* Root of the tree */

#if (RWFRAMESTATICPLUGINSSIZE)
    RWALIGN(RwUInt8             pluginData[RWFRAMESTATICPLUGINSSIZE], rwFRAMEALIGNMENT);
#endif /* defined(RWFRAMESTATICPLUGINSIZE)) */
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwframe
 * \struct RwFrame 
 * Frame for defining object position and orientation. 
 * This should be considered an opaque type.
 * Use the RwFrame API functions to access.
 */
typedef struct RwFrame RWALIGN(RwFrame, rwFRAMEALIGNMENT);

/**
 * \ingroup rwframe
 * \ref RwFrameCallBack type represents the function 
 * called from \ref RwFrameForAllChildren for all child frames linked to a given frame.  
 * This function should return a pointer to the current frame to indicate success.  
 * The callback may return NULL to terminate further callbacks on the child frames.
 * 
 * \param  frame   Pointer to the current frame, supplied by
 * iterator.
 * \param  data  Pointer to developer-defined data structure.
 *
 * \return Pointer to the current frame, or NULL If not found.
 *
 * \see RwFrameForAllChildren
 *
 */
typedef RwFrame *(*RwFrameCallBack)(RwFrame *frame, void *data);


#define RwFrameGetParentMacro(_f)   ((RwFrame *)rwObjectGetParent(_f))
#if (! ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) ))
#define RwFrameGetParent(_f)    RwFrameGetParentMacro(_f)
#endif

#define RwFrameGetMatrixMacro(_f)   (&(_f)->modelling)
#if (! ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) ))
#define RwFrameGetMatrix(_f)    RwFrameGetMatrixMacro(_f)
#endif



/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */


/* Finding what is attached to a frame */
extern RwFrame *
RwFrameForAllObjects(RwFrame * frame,
                     RwObjectCallBack callBack,
                     void *data);

/* Matrix operations */
extern RwFrame *
RwFrameTranslate(RwFrame * frame,
                 const RwV3d * v,
                 RwOpCombineType combine);

extern RwFrame *
RwFrameRotate(RwFrame * frame,
              const RwV3d * axis,
              RwReal angle,
              RwOpCombineType combine);

extern RwFrame *
RwFrameScale(RwFrame * frame,
             const RwV3d * v,
             RwOpCombineType combine);

extern RwFrame *
RwFrameTransform(RwFrame * frame,
                 const RwMatrix * m,
                 RwOpCombineType combine);

extern RwFrame *
RwFrameOrthoNormalize(RwFrame * frame);

extern RwFrame *
RwFrameSetIdentity(RwFrame * frame);

/* Cloning */
extern RwFrame *
RwFrameCloneHierarchy(RwFrame * root);

/* Destruction */
extern RwBool
RwFrameDestroyHierarchy(RwFrame * frame);

/* Building a frame */
extern RwFrame *
RwFrameForAllChildren(RwFrame * frame,
                      RwFrameCallBack callBack,
                      void *data);

extern RwFrame *
RwFrameRemoveChild(RwFrame * child);

extern RwFrame *
RwFrameAddChild(RwFrame * parent, RwFrame * child);

extern RwFrame *
RwFrameAddChildNoUpdate(RwFrame *parent, RwFrame *child);

#if ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) )
extern RwFrame *
RwFrameGetParent(const RwFrame * frame);
#endif

/* Getting the root */
extern RwFrame *
RwFrameGetRoot(const RwFrame * frame);

/* Getting Matrices */
extern RwMatrix *
RwFrameGetLTM(RwFrame * frame);

#if ( defined(RWDEBUG) || defined(RWSUPPRESSINLINE) )
extern RwMatrix *
RwFrameGetMatrix(RwFrame * frame);
#endif

/* Elements */
extern RwFrame *
RwFrameUpdateObjects(RwFrame * frame);

/* Creating destroying frames */
extern void
RwFrameSetFreeListCreateParams( RwInt32 blockSize, RwInt32 numBlocksToPrealloc );

extern RwFrame *
RwFrameCreate(void);

extern RwBool
RwFrameDestroy(RwFrame * frame);

/* Finding a frames state */
extern RwBool
RwFrameDirty(const RwFrame * frame);

/* Find the amount of frames in a hierarchy */
extern RwInt32
RwFrameCount(RwFrame * frame);

/* static frame functions */
extern RwBool
_rwFrameSetStaticPluginsSize(RwInt32 size);

extern RwBool
_rwFrameInit(RwFrame *frame);

extern RwBool
_rwFrameDeInit(RwFrame *frame);

/* Plugins */
extern RwInt32
RwFrameRegisterPlugin(RwInt32 size,
                      RwUInt32 pluginID,
                      RwPluginObjectConstructor constructCB,
                      RwPluginObjectDestructor destructCB,
                      RwPluginObjectCopy copyCB);

extern RwInt32
RwFrameGetPluginOffset(RwUInt32 pluginID);

extern RwBool
RwFrameValidatePlugins(const RwFrame * frame);

/* Cloning */
extern RwFrame *
_rwFrameCloneAndLinkClones(RwFrame * root);

extern
RwFrame *
_rwFramePurgeClone(RwFrame *root);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/batypehf.h ---*/

typedef struct RwObjectHasFrame RwObjectHasFrame;
typedef RwObjectHasFrame * (*RwObjectHasFrameSyncFunction)(RwObjectHasFrame *object);

#if (!defined(DOXYGEN))
struct RwObjectHasFrame
{
    RwObject                     object;
    RwLLLink                     lFrame;
    RwObjectHasFrameSyncFunction sync;
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Frames */
extern void _rwObjectHasFrameSetFrame(void *object, RwFrame *frame);
extern void _rwObjectHasFrameReleaseFrame(void *object);

/* ObjectHASFRAME METHODS */
#define rwObjectHasFrameInitialize(o, type, subtype, syncFunc)  \
MACRO_START                                                     \
{                                                               \
    rwObjectInitialize(o, type, subtype);                       \
    ((RwObjectHasFrame *)o)->sync = syncFunc;                   \
}                                                               \
MACRO_STOP

#define rwObjectHasFrameSync(o) \
    ((RwObjectHasFrame *)(o))->sync(o)

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/* Compatibility macros */

#define rwObjectHasFrameSetFrame(object, frame) \
        _rwObjectHasFrameSetFrame(object, frame)
#define rwObjectHasFrameReleaseFrame(object) \
        _rwObjectHasFrameReleaseFrame(object)



/*--- Automatically derived from: C:/daily/rwsdk/src/basync.h ---*/

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */
    
/* Sync all the dirty frames */
extern RwBool _rwFrameSyncDirty(void);

/* Syncing the LTMs in a hierarchy */
extern void _rwFrameSyncHierarchyLTM(RwFrame *frame);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/babintex.h ---*/
/****************************************************************************
 Global types
 */
typedef struct rpTextureChunkInfo RwTextureChunkInfo;

#if (!defined(DOXYGEN))
struct rpTextureChunkInfo
{
    RwTextureFilterMode filtering;
    RwTextureAddressMode addressingU;
    RwTextureAddressMode addressingV;
};
#endif /* (!defined(DOXYGEN)) */

/* Bit flags defining properties of textures when stream */
enum RwTextureStreamFlags
{
    rwNATEXTURESTREAMFLAG = 0x00,
    rwTEXTURESTREAMFLAGSUSERMIPMAPS = 0x01,
    rwTEXTURESTREAMFLAGSFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwTextureStreamFlags RwTextureStreamFlags;
/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Texture binary format */
extern RwInt32
RwTextureRegisterPluginStream(RwUInt32 pluginID,
                              RwPluginDataChunkReadCallBack readCB,
                              RwPluginDataChunkWriteCallBack writeCB,
                              RwPluginDataChunkGetSizeCallBack getSizeCB);

extern RwInt32
RwTextureSetStreamAlwaysCallBack(RwUInt32 pluginID,
                                 RwPluginDataChunkAlwaysCallBack alwaysCB);

extern RwUInt32
RwTextureStreamGetSize(const RwTexture *texture);

extern RwTexture *
RwTextureStreamRead(RwStream *stream);

extern const RwTexture *
RwTextureStreamWrite(const RwTexture *texture,
                     RwStream *stream);

/* Texture dictionary binary format */
extern RwInt32
RwTexDictionaryRegisterPluginStream(RwUInt32 pluginID,
                                    RwPluginDataChunkReadCallBack readCB,
                                    RwPluginDataChunkWriteCallBack writeCB,
                                    RwPluginDataChunkGetSizeCallBack getSizeCB);

extern RwInt32
RwTexDictionarySetStreamAlwaysCallBack(RwUInt32 pluginID,
                                       RwPluginDataChunkAlwaysCallBack alwaysCB);

extern RwUInt32
RwTexDictionaryStreamGetSize(const RwTexDictionary *texDict);

extern RwTexDictionary
*RwTexDictionaryStreamRead(RwStream *stream);

extern const RwTexDictionary *
RwTexDictionaryStreamWrite(const RwTexDictionary *texDict,
                           RwStream *stream);

extern RwTextureChunkInfo *
_rwTextureChunkInfoRead(RwStream *stream,
                        RwTextureChunkInfo *textureChunkInfo,
                        RwInt32 *bytesRead);

/* Compatibility macro */

#define  RwTextureChunkInfoRead(_stream, _textureChunkInfo, _bytesRead) \
        _rwTextureChunkInfoRead(_stream, _textureChunkInfo, _bytesRead) 

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/babinfrm.h ---*/
/****************************************************************************
 Global types
 */

typedef struct rwFrameList rwFrameList;

#if (!defined(DOXYGEN))
struct rwFrameList
{
    RwFrame **frames;
    RwInt32 numFrames;
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Global Variables 
 */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Frame binary format */

extern void
RwFrameListSetAutoUpdate(RwBool flag);


extern RwInt32 
RwFrameRegisterPluginStream(RwUInt32 pluginID,
                            RwPluginDataChunkReadCallBack readCB,
                            RwPluginDataChunkWriteCallBack writeCB,
                            RwPluginDataChunkGetSizeCallBack getSizeCB);

extern RwInt32 
RwFrameSetStreamAlwaysCallBack(RwUInt32 pluginID,
                               RwPluginDataChunkAlwaysCallBack alwaysCB);


extern rwFrameList *
_rwFrameListInitialize(rwFrameList *frameList,
                      RwFrame *frame);

extern RwBool 
_rwFrameListFindFrame(const rwFrameList *frameList,
                     const RwFrame *frame,
                     RwInt32 *npIndex);

extern rwFrameList *
_rwFrameListDeinitialize(rwFrameList *frameList);

extern RwUInt32 
_rwFrameListStreamGetSize(const rwFrameList *frameList);

extern rwFrameList *
_rwFrameListStreamRead(RwStream *stream,
                      rwFrameList *fl);

extern const rwFrameList *
_rwFrameListStreamWrite(const rwFrameList *frameList,
                       RwStream *stream);


#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/* Comparibility macros */

#define rwFrameListInitialize(frameList,frame) \
       _rwFrameListInitialize(frameList,frame)

#define rwFrameListFindFrame(frameList, frame, index) \
       _rwFrameListFindFrame(frameList, frame, index)

#define rwFrameListDeinitialize(frameList) \
       _rwFrameListDeinitialize(frameList)

#define rwFrameListStreamGetSize(frameList) \
       _rwFrameListStreamGetSize(frameList)

#define rwFrameListStreamRead(stream, fl) \
       _rwFrameListStreamRead(stream, fl)

#define rwFrameListStreamWrite(frameList, stream) \
       _rwFrameListStreamWrite(frameList, stream)


/*--- Automatically derived from: C:/daily/rwsdk/src/babbox.h ---*/
/****************************************************************************
 Global types
 */

typedef struct RwBBox RwBBox;
/**
 * \ingroup rwbbox
 * \struct RwBBox
 * This type represents a 3D axis-aligned bounding-box
 * specified by the positions of two corners which lie on a diagonal.
 * Typically used to specify a world bounding-box when the world is created
 * 
 * \param sup Supremum vertex (contains largest values)
 * \param inf Infimum vertex (contains smallest values)
 * 
 * \see RpWorldCreate
 */
struct RwBBox
{
    /* Must be in this order */
    RwV3d sup;   /**< Supremum vertex. */
    RwV3d inf;   /**< Infimum vertex. */
};

#if (!defined(RwBBoxAssign))
#define RwBBoxAssign(_target, _source)            \
    ( *(_target) = *(_source) )
#endif /* (!defined(RwBBoxAssign)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */


extern RwBBox *RwBBoxCalculate(RwBBox *boundBox,
                               const RwV3d *verts,
                               RwInt32 numVerts);
extern RwBBox *RwBBoxInitialize(RwBBox *boundBox,
                                const RwV3d *vertex);
extern RwBBox *RwBBoxAddPoint(RwBBox *boundBox,
                              const RwV3d *vertex);
extern RwBool RwBBoxContainsPoint(const RwBBox *boundBox,
                                  const RwV3d *vertex);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/src/bacamera.h ---*/

/****************************************************************************
 Defines
 */

/* Type ID */
#define rwCAMERA 4



/****************************************************************************
 <macro/inline functionality
 */

#define RwCameraGetViewOffsetMacro(_camera)                     \
    (&((_camera)->viewOffset))

#define RwCameraSetRasterMacro(_camera, _raster)                \
    (((_camera)->frameBuffer = (_raster)), (_camera))

#define RwCameraSetRasterVoidMacro(_camera, _raster)            \
MACRO_START                                                     \
{                                                               \
    (_camera)->frameBuffer = (_raster);                         \
}                                                               \
MACRO_STOP

#define RwCameraGetRasterMacro(_camera)                         \
    ((_camera)->frameBuffer)

#define RwCameraSetZRasterMacro(_camera, _raster)               \
    (((_camera)->zBuffer = (_raster)), (_camera))

#define RwCameraSetZRasterVoidMacro(_camera, _raster)           \
MACRO_START                                                     \
{                                                               \
    (_camera)->zBuffer = (_raster);                             \
}                                                               \
MACRO_STOP

#define RwCameraGetZRasterMacro(_camera)                        \
    ((_camera)->zBuffer)

#define RwCameraGetNearClipPlaneMacro(_camera)                  \
    ((_camera)->nearPlane)

#define RwCameraGetFarClipPlaneMacro(_camera)                   \
    ((_camera)->farPlane)

#define RwCameraSetFogDistanceMacro(_camera, _distance)         \
    (((_camera)->fogPlane = (_distance)), (_camera))

#define RwCameraGetFogDistanceMacro(_camera)                    \
    ((_camera)->fogPlane)

#define RwCameraGetCurrentCameraMacro()                         \
    ((RwCamera *)RWSRCGLOBAL(curCamera))

#define RwCameraGetProjectionMacro(_camera)                     \
    ((_camera)->projectionType)

#define RwCameraGetViewWindowMacro(_camera)                     \
    (&((_camera)->viewWindow))

#define RwCameraGetViewMatrixMacro(_camera)                     \
    (&((_camera)->viewMatrix))

#define RwCameraSetFrameMacro(_camera, _frame)                  \
    (_rwObjectHasFrameSetFrame((_camera), (_frame)), (_camera))

#define RwCameraSetFrameVoidMacro(_camera, _frame)      \
MACRO_START                                             \
{                                                       \
    _rwObjectHasFrameSetFrame((_camera), (_frame));     \
}                                                       \
MACRO_STOP


#define RwCameraGetFrameMacro(_camera)                          \
    ((RwFrame *)rwObjectGetParent((_camera)))

#if !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

#define RwCameraGetViewOffset(_camera)                          \
    RwCameraGetViewOffsetMacro(_camera)

#define RwCameraSetRaster(_camera, _raster)                     \
    RwCameraSetRasterMacro(_camera, _raster)

#define RwCameraGetRaster(_camera)                              \
    RwCameraGetRasterMacro(_camera)

#define RwCameraSetZRaster(_camera, _raster)                    \
    RwCameraSetZRasterMacro(_camera, _raster)

#define RwCameraGetZRaster(_camera)                             \
    RwCameraGetZRasterMacro(_camera)

#define RwCameraGetNearClipPlane(_camera)                       \
    RwCameraGetNearClipPlaneMacro(_camera)

#define RwCameraGetFarClipPlane(_camera)                        \
    RwCameraGetFarClipPlaneMacro(_camera)

#define RwCameraSetFogDistance(_camera, _distance)              \
    RwCameraSetFogDistanceMacro(_camera, _distance)

#define RwCameraGetFogDistance(_camera)                         \
    RwCameraGetFogDistanceMacro(_camera)

#define RwCameraGetCurrentCamera()                              \
    RwCameraGetCurrentCameraMacro()

#define RwCameraGetProjection(_camera)                          \
    RwCameraGetProjectionMacro(_camera)

#define RwCameraGetViewWindow(_camera)                          \
    RwCameraGetViewWindowMacro(_camera)

#define RwCameraGetViewMatrix(_camera)                          \
    RwCameraGetViewMatrixMacro(_camera)

#define RwCameraSetFrame(_camera, _frame)                       \
    RwCameraSetFrameMacro(_camera, _frame)

#define RwCameraGetFrame(_camera)                               \
    RwCameraGetFrameMacro(_camera)

#endif /* !(defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */


/****************************************************************************
 Global Types
 */

/**
 * \ingroup rwcamera
 * RwCameraClearMode 
 * Camera clear flags */
enum RwCameraClearMode
{
    rwCAMERACLEARIMAGE = 0x1,   /**<Clear the frame buffer */
    rwCAMERACLEARZ = 0x2,       /**<Clear the Z buffer */
    rwCAMERACLEARSTENCIL = 0x4, /**<\if xbox   Clear the stencil buffer \endif
                                  * \if d3d8   Clear the stencil buffer \endif
                                  * \if d3d9   Clear the stencil buffer \endif
                                  * \if opengl Clear the stencil buffer \endif
                                  */
    rwCAMERACLEARMODEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwCameraClearMode RwCameraClearMode;

/**
 * \ingroup rwcamera
 * RwCameraProjection 
 * This type represents the options available for 
 * setting the camera projection model, either perspective projection or 
* parallel projection (see API function \ref RwCameraSetProjection)*/
enum RwCameraProjection
{
    rwNACAMERAPROJECTION = 0,   /**<Invalid projection */
    rwPERSPECTIVE = 1,          /**<Perspective projection */
    rwPARALLEL = 2,             /**<Parallel projection */
    rwCAMERAPROJECTIONFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwCameraProjection RwCameraProjection;

/**
 * \ingroup rwcamera
 * RwFrustumTestResult 
 * This type represents the results from a 
 * camera frustum test on a given sphere (see API function 
 * \ref RwCameraFrustumTestSphere)*/
enum RwFrustumTestResult
{
    rwSPHEREOUTSIDE = 0,    /**<Outside the frustum */
    rwSPHEREBOUNDARY = 1,   /**<On the boundary of the frustum */
    rwSPHEREINSIDE = 2,     /**<Inside the frustum */
    rwFRUSTUMTESTRESULTFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RwFrustumTestResult RwFrustumTestResult;


/**
 * \ingroup rwcamera
 * \struct RwCamera
 * Camera object for rendering a view. 
 * This should be considered an opaque type.
 * Use the RwCamera API functions to access.
 */
typedef struct RwCamera RWALIGN(RwCamera, rwMATRIXALIGNMENT);

/* This allows a world to overload functionality */
typedef RwCamera   *(*RwCameraBeginUpdateFunc) (RwCamera * camera);
typedef RwCamera   *(*RwCameraEndUpdateFunc) (RwCamera * camera);

typedef struct RwFrustumPlane RwFrustumPlane;

#if (!defined(DOXYGEN))
/*
 * Structure describing a frustrum plane.
 */
struct RwFrustumPlane
{
        RwPlane             plane;
        RwUInt8             closestX;
        RwUInt8             closestY;
        RwUInt8             closestZ;
        RwUInt8             pad;
};


struct RwCamera
{
        RwObjectHasFrame    object;

        /* Parallel or perspective projection */
        RwCameraProjection  projectionType;

        /* Start/end update functions */
        RwCameraBeginUpdateFunc beginUpdate;
        RwCameraEndUpdateFunc endUpdate;

        /* The view matrix */
        RwMatrix            viewMatrix;

        /* The cameras image buffer */
        RwRaster           *frameBuffer;

        /* The Z buffer */
        RwRaster           *zBuffer;

        /* Cameras mathmatical characteristics */
        RwV2d               viewWindow;
        RwV2d               recipViewWindow;
        RwV2d               viewOffset;
        RwReal              nearPlane;
        RwReal              farPlane;
        RwReal              fogPlane;

        /* Transformation to turn camera z or 1/z into a Z buffer z */
        RwReal              zScale, zShift;

        /* The clip-planes making up the viewing frustum */
        RwFrustumPlane      frustumPlanes[6];
        RwBBox              frustumBoundBox;

        /* Points on the tips of the view frustum */
        RwV3d               frustumCorners[8];
};
#endif /* (!defined(DOXYGEN)) */

/**
 * \ingroup rwcamera
 * \ref RwCameraCallBack type represents a function called from any camera
 * iterator that may be implemented in plugins. This function should return a
 * pointer to the current camera to indicate success. The callback may return
 * NULL to terminate further callbacks on other cameras.
 * 
 * \param  camera   Pointer to the current camera, supplied by iterator.
 * \param  data  Pointer to developer-defined data structure.
 *
 * \return Pointer to the current camera, or NULL If not found.
 */
typedef RwCamera *(*RwCameraCallBack)(RwCamera *camera, void *data);


/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern              "C"
{
#endif                          /* __cplusplus */

    /* Rendering */
extern RwCamera    *RwCameraBeginUpdate(RwCamera * camera);
extern RwCamera    *RwCameraEndUpdate(RwCamera * camera);

extern RwCamera    *RwCameraClear(RwCamera * camera, RwRGBA * colour,
                                  RwInt32 clearMode);

/* Displaying results */
extern RwCamera    *RwCameraShowRaster(RwCamera * camera, void *pDev,
                                       RwUInt32 flags);

/* Creation and destruction */
extern void RwCameraSetFreeListCreateParams( RwInt32 blockSize,
                                            RwInt32 numBlocksToPrealloc );
extern RwBool       RwCameraDestroy(RwCamera * camera);
extern RwCamera    *RwCameraCreate(void);
extern RwCamera    *RwCameraClone(RwCamera * camera);

/* Offset */
extern RwCamera    *RwCameraSetViewOffset(RwCamera *camera,
                                          const RwV2d *offset);

/* View window */
extern RwCamera    *RwCameraSetViewWindow(RwCamera *camera,
                                          const RwV2d *viewWindow);

/* Projection */
extern RwCamera    *RwCameraSetProjection(RwCamera *camera,
                                          RwCameraProjection projection);

/* Clip planes */
extern RwCamera    *RwCameraSetNearClipPlane(RwCamera *camera, RwReal nearClip);
extern RwCamera    *RwCameraSetFarClipPlane(RwCamera *camera, RwReal farClip);

/* Attaching toolkits */
extern RwInt32      RwCameraRegisterPlugin(RwInt32 size,
                                           RwUInt32 pluginID,
                                           RwPluginObjectConstructor
                                           constructCB,
                                           RwPluginObjectDestructor
                                           destructCB,
                                           RwPluginObjectCopy copyCB);
extern RwInt32      RwCameraGetPluginOffset(RwUInt32 pluginID);
extern RwBool       RwCameraValidatePlugins(const RwCamera * camera);

/* Frustum testing */
extern RwFrustumTestResult RwCameraFrustumTestSphere(const RwCamera *
                                                     camera,
                                                     const RwSphere *
                                                     sphere);

#if (defined(RWDEBUG) || defined(RWSUPPRESSINLINE))

/* Offset */
extern const RwV2d *RwCameraGetViewOffset(const RwCamera *camera);

/* Rasters */
extern RwCamera    *RwCameraSetRaster(RwCamera *camera, RwRaster *raster);
extern RwRaster    *RwCameraGetRaster(const RwCamera *camera);
extern RwCamera    *RwCameraSetZRaster(RwCamera *camera, RwRaster *zRaster);
extern RwRaster    *RwCameraGetZRaster(const RwCamera *camera);

/* Clip planes */
extern RwReal       RwCameraGetNearClipPlane(const RwCamera *camera);
extern RwReal       RwCameraGetFarClipPlane(const RwCamera *camera);
extern RwCamera    *RwCameraSetFogDistance(RwCamera *camera, RwReal fogDistance);
extern RwReal       RwCameraGetFogDistance(const RwCamera *camera);

extern RwCamera    *RwCameraGetCurrentCamera(void);

/* Projection */
extern RwCameraProjection RwCameraGetProjection(const RwCamera *camera);

/* View window */
extern const RwV2d *RwCameraGetViewWindow(const RwCamera *camera);

extern RwMatrix    *RwCameraGetViewMatrix(RwCamera *camera);

/* Frames */
extern RwCamera    *RwCameraSetFrame(RwCamera *camera, RwFrame *frame);
extern RwFrame     *RwCameraGetFrame(const RwCamera *camera);
#endif /* (defined(RWDEBUG) || defined(RWSUPPRESSINLINE)) */

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

/*--- Automatically derived from: C:/daily/rwsdk/driver/common/barwtyp.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/bacamval.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/pipe/p2/bapipe.h ---*/

#if (!defined(DOXYGEN))
struct rwPipeGlobals
{
    RwFreeList          *pipesFreeList;   /* Save mallocs, use a freelist */
    RxRenderStateVector  defaultRenderState;
    RwLinkList           allPipelines;    /* Unused as of yet, meant to be used to keep track of all
                                           * created pipelines (for CBs and maybe cleanup) */
    RwUInt32             maxNodesPerPipe; /* Initialised from _rxPipelineMaxNodes at startup. Used to
                                           * allow conservative, single allocations during pipelock */

    /* NOTE: Rw and RpWorld PowerPipe globals kept together for simplicity */

    /* The current default pipelines (used if pipe == NULL for an object) */
    RxPipeline          *currentAtomicPipeline;
    RxPipeline          *currentWorldSectorPipeline;
    RxPipeline          *currentMaterialPipeline;
    /* Generic C-based pipes that run on all platforms
     * - these are set as the current pipes at startup unless
     *   platform-specific pipes (below) are created */
    RxPipeline          *genericAtomicPipeline;
    RxPipeline          *genericWorldSectorPipeline;
    RxPipeline          *genericMaterialPipeline;
    /* Platforms that have their own non-generic pipelines
     * (OPENGL, D3D8, SKY2, KAMUI2, DOLPHIN) put them here: */
    RxPipeline          *platformAtomicPipeline;
    RxPipeline          *platformWorldSectorPipeline;
    RxPipeline          *platformMaterialPipeline;
};
#endif /* (!defined(DOXYGEN)) */

typedef struct rwPipeGlobals rwPipeGlobals;

#define RXPIPELINEGLOBAL(var) (RWPLUGINOFFSET(rwPipeGlobals, RwEngineInstance, _rxPipelineGlobalsOffset)->var)

#ifdef    __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern RwInt32      _rxPipelineGlobalsOffset;

#ifdef    __cplusplus
}
#endif /* __cplusplus */


/*--- Automatically derived from: C:/daily/rwsdk/driver/opengl/baintogl.h ---*/

/*--- Automatically derived from: C:/daily/rwsdk/src/babincam.h ---*/
/****************************************************************************
 Global types
 */

/* Camera stream format */

/**
 * \ingroup rwcamera
 * \ref RwCameraChunkInfo is typedef'd to a structure that holds camera
 * data. This should be considered an opaque type. Use the RwCamera
 * API functions to access it.
 */

typedef struct rwStreamCamera RwCameraChunkInfo;
typedef struct rwStreamCamera rwStreamCamera;

#if (!defined(DOXYGEN))
struct rwStreamCamera
{
    RwV2d viewWindow;
    RwV2d viewOffset;
    RwReal nearPlane, farPlane;
    RwReal fogPlane;
    RwUInt32 projection;
};
#endif /* (!defined(DOXYGEN)) */

/****************************************************************************
 Function prototypes
 */

#ifdef    __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/* Camera binary format */
extern RwInt32 RwCameraRegisterPluginStream(RwUInt32 pluginID,
                                            RwPluginDataChunkReadCallBack readCB,
                                            RwPluginDataChunkWriteCallBack writeCB,
                                            RwPluginDataChunkGetSizeCallBack getSizeCB);
extern RwInt32 RwCameraSetStreamAlwaysCallBack(
                   RwUInt32 pluginID,
                   RwPluginDataChunkAlwaysCallBack alwaysCB);
extern RwUInt32 RwCameraStreamGetSize(const RwCamera *camera);
extern RwCamera *RwCameraStreamRead(RwStream *stream);
extern const RwCamera *RwCameraStreamWrite(const RwCamera *camera,
                                           RwStream *stream);
extern RwCameraChunkInfo * RwCameraChunkInfoRead(RwStream *stream,
                                                 RwCameraChunkInfo *cameraChunkInfo,
                                                 RwInt32 *bytesRead);

#ifdef    __cplusplus
}
#endif                          /* __cplusplus */

#endif /* RWCORE_H */
