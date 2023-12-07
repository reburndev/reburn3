
#ifndef RPMATFX_H
#define RPMATFX_H

/*===========================================================================*
 *--- Include files ---------------------------------------------------------*
 *===========================================================================*/

#include "rwcore.h"
#include "rpworld.h"

/*---- start: ./matfx.h----*/

#ifndef RPMATFX_MATFX_H
#define RPMATFX_MATFX_H


/**
 * \defgroup rpmatfx RpMatFX
 * \ingroup materials
 *
 * Material Effects Plugin for RenderWare Graphics.
 */

/*===========================================================================*
 *--- Global Types ----------------------------------------------------------*
 *===========================================================================*/

/**
 * \ingroup rpmatfx
 * RpMatFXMaterialFlags, this type represents the different types of
 * material effects that can be used on a material. The effects are
 * initialized with \ref RpMatFXMaterialSetEffects:
 */
enum RpMatFXMaterialFlags
{
    rpMATFXEFFECTNULL            = 0, /**<No material effect.           */
    rpMATFXEFFECTBUMPMAP         = 1, /**<Bump mapping                  */
    rpMATFXEFFECTENVMAP          = 2, /**<Environment mapping           */
    rpMATFXEFFECTBUMPENVMAP      = 3, /**<Bump and environment mapping  */
    rpMATFXEFFECTDUAL            = 4, /**<Dual pass                     */
    rpMATFXEFFECTUVTRANSFORM     = 5, /**<Base UV transform             */
    rpMATFXEFFECTDUALUVTRANSFORM = 6, /**<Dual UV transform (2 pass)    */

    rpMATFXEFFECTMAX,
    rpMATFXNUMEFFECTS       = rpMATFXEFFECTMAX - 1,

    rpMATFXFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpMatFXMaterialFlags  RpMatFXMaterialFlags;


/*===========================================================================*
 *--- Plugin API Functions --------------------------------------------------*
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*--- Plugin functions ------------------------------------------------------*/
extern void
RpMatFXMaterialDataSetFreeListCreateParams( RwInt32 blockSize,
                                            RwInt32 numBlocksToPrealloc );

extern RwBool
RpMatFXPluginAttach( void );

/*--- Setup functions -------------------------------------------------------*/
extern RpAtomic *
RpMatFXAtomicEnableEffects( RpAtomic *atomic );

extern RwBool
RpMatFXAtomicQueryEffects( RpAtomic *atomic );

extern RpWorldSector *
RpMatFXWorldSectorEnableEffects( RpWorldSector *worldSector );

extern RwBool
RpMatFXWorldSectorQueryEffects( RpWorldSector *worldSector );

extern RpMaterial *
RpMatFXMaterialSetEffects( RpMaterial *material,
                           RpMatFXMaterialFlags flags );


/*--- Setup Effects ---------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetupBumpMap( RpMaterial *material,
                             RwTexture *texture,
                             RwFrame *frame,
                             RwReal coef );

extern RpMaterial *
RpMatFXMaterialSetupEnvMap( RpMaterial *material,
                            RwTexture *texture,
                            RwFrame *frame,
                            RwBool useFrameBufferAlpha,
                            RwReal coef );

extern RpMaterial *
RpMatFXMaterialSetupDualTexture( RpMaterial *material,
                                 RwTexture *texture,
                                 RwBlendFunction srcBlendMode,
                                 RwBlendFunction dstBlendMode );

/*--- Tinker with effects ---------------------------------------------------*/
extern RpMatFXMaterialFlags
RpMatFXMaterialGetEffects( const RpMaterial *material );

/*--- Bump Map --------------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetBumpMapTexture( RpMaterial *material,
                                  RwTexture *texture );

extern RpMaterial *
RpMatFXMaterialSetBumpMapFrame( RpMaterial *material,
                                RwFrame *frame );

extern RpMaterial *
RpMatFXMaterialSetBumpMapCoefficient( RpMaterial *material,
                                      RwReal coef );
extern RwTexture *
RpMatFXMaterialGetBumpMapTexture( const RpMaterial *material );

extern RwTexture *
RpMatFXMaterialGetBumpMapBumpedTexture( const RpMaterial *material );

extern RwFrame *
RpMatFXMaterialGetBumpMapFrame( const RpMaterial *material );

extern RwReal
RpMatFXMaterialGetBumpMapCoefficient( const RpMaterial *material );

/*--- Env Map ---------------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetEnvMapTexture( RpMaterial *material,
                                 RwTexture *texture );

extern RpMaterial *
RpMatFXMaterialSetEnvMapFrame( RpMaterial *material,
                               RwFrame *frame );

extern RpMaterial *
RpMatFXMaterialSetEnvMapFrameBufferAlpha( RpMaterial *material,
                                          RwBool useFrameBufferAlpha );

extern RpMaterial *
RpMatFXMaterialSetEnvMapCoefficient( RpMaterial *material,
                                     RwReal coef );

extern RwTexture *
RpMatFXMaterialGetEnvMapTexture( const RpMaterial *material );

extern RwFrame *
RpMatFXMaterialGetEnvMapFrame( const RpMaterial *material );

extern RwBool
RpMatFXMaterialGetEnvMapFrameBufferAlpha( const RpMaterial *material );

extern RwReal
RpMatFXMaterialGetEnvMapCoefficient( const RpMaterial *material );

/*--- Dual Pass -------------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetDualTexture( RpMaterial *material,
                               RwTexture *texture );

extern RpMaterial *
RpMatFXMaterialSetDualBlendModes( RpMaterial *material,
                                  RwBlendFunction srcBlendMode,
                                  RwBlendFunction dstBlendMode );

extern RwTexture *
RpMatFXMaterialGetDualTexture( const RpMaterial *material );

extern const RpMaterial *
RpMatFXMaterialGetDualBlendModes( const RpMaterial *material,
                                  RwBlendFunction *srcBlendMode,
                                  RwBlendFunction *dstBlendMode );

/*--- UV Transform + Dual UV Transform---------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetUVTransformMatrices( RpMaterial *material,
                                       RwMatrix *baseTransform,
                                       RwMatrix *dualTransform );

extern const RpMaterial *
RpMatFXMaterialGetUVTransformMatrices( const RpMaterial *material,
                                       RwMatrix **baseTransform,
                                       RwMatrix **dualTransform );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* RPMATFX_MATFX_H */

/*---- end: ./matfx.h----*/

/*---- start: c:/daily/rwsdk/plugin/matfx/opengl/matfxplatform.h----*/

/**
 * \defgroup rpmatfxopengl OpenGL
 * \ingroup rpmatfx
 *
 * OpenGL specific documentation.
 */


/**
 * \ingroup rpmatfxopengl
 * \ref RpMatFXOpenGLPipeline
 */
enum RpMatFXOpenGLPipeline
{
    rpNAMATFXOPENGLPIPELINE          = 0,
    rpMATFXOPENGLATOMICPIPELINE      = 1, /**<OpenGL atomic material effect rendering pipeline. */
    rpMATFXOPENGLWORLDSECTORPIPELINE = 2, /**<OpenGL world sector material effect rendering pipeline. */
    rpMATFXOPENGLPIPELINEMAX,
    rpMATFXOPENGLPIPELINEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpMatFXOpenGLPipeline RpMatFXOpenGLPipeline;


#if defined( __cplusplus )
extern "C"
{
#endif /* defined( __cplusplus ) */

extern RxPipeline *
RpMatFXGetOpenGLPipeline( RpMatFXOpenGLPipeline openglPipeline );

#if defined( __cplusplus )
}
#endif /* defined( __cplusplus ) */

/*---- end: c:/daily/rwsdk/plugin/matfx/opengl/matfxplatform.h----*/

#endif /* RPMATFX_H */


