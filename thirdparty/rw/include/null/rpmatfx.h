
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

/*---- start: c:/daily/rwsdk/plugin/matfx/null/matfxplatform.h----*/

/**
 * \defgroup rpmatfxnull Null
 * \ingroup rpmatfx
 *
 * Null specific documentation.
 */

/*---- start: ./multiTexEffect.h----*/

#ifndef RPMATFX_MULTITEXEFFECT_H
#define RPMATFX_MULTITEXEFFECT_H


/******************************************************************************
 *  Includes
 */
#include "rwcore.h"
#include "rpworld.h"

/******************************************************************************
 *  Defines
 */
#define rpMTEFFECTNAMELENGTH      32

/******************************************************************************
 *  Types
 */


/**
 * \ingroup rpmultitex
 * \struct RpMTEffect
 * RpMTEffect is an opaque type. See the RpMTEffect API.
 */
typedef struct RpMTEffect RpMTEffect;

/**
 * \ingroup rpmultitex
 * \struct RpMTEffectDict
 * RpMTEffectDict is an opaque type.
 *
 * \see RpMTEffectDictCreate
 * \see RpMTEffectDictDestroy
 * \see RpMTEffectDictGetCurrent
 * \see RpMTEffectDictSetCurrent
 * \see RpMTEffectDictAddEffect
 * \see RpMTEffectDictFindNamedEffect
 * \see RpMTEffectDictStreamRead
 */
typedef struct RpMTEffectDict RpMTEffectDict;

/**
 * \ingroup rpmultitex
 *  RpMTEffectCallBack is the callback type used with
 * \ref RpMTEffectDictForAllEffects.
 *
 * \param effect    Pointer to the multi-texture effect.
 * \param data      Pointer to used data.
 *
 * \return Pointer to the effect, or NULL for early out.
 */
typedef RpMTEffect *(*RpMTEffectCallBack)(RpMTEffect *effect, void *data);

/**
 * \ingroup rpmultitex
 * \ref RpMTEffectDictCallBack
 * RpMTEffectDictCallBack is the callback type used with
 * \ref RpMTEffectDictForAllDictionaries.
 *
 * \param dict      Pointer to the multi-texture effect dictionary.
 * \param data      Pointer to used data.
 *
 * \return Pointer to the effect dictionary, or NULL for early out.
 */
typedef RpMTEffectDict *(*RpMTEffectDictCallBack)(
                            RpMTEffectDict *dict, void *data);


#if(!defined(DOXYGEN))
struct RpMTEffect
{
    RwPlatformID    platformID;
    RwUInt32        refCount;
    RwChar          name[rpMTEFFECTNAMELENGTH];
    RwLLLink        dictLink;
};
#endif /* (!defined(DOXYGEN)) */

typedef void        (*rpMTEffectDestroyCallBack)(RpMTEffect *effect);
typedef RwInt32     (*rpMTEffectStreamGetSizeCallBack)(const RpMTEffect *effect);
typedef RpMTEffect *(*rpMTEffectStreamReadCallBack)(RwStream *stream,
                                                    RwPlatformID platformID,
                                                    RwUInt32 version,
                                                    RwUInt32 length);
typedef const RpMTEffect *(*rpMTEffectStreamWriteCallBack)(
                        const RpMTEffect *effect, RwStream *stream);

/******************************************************************************
 *  Functions
 */


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*--- MultiTexture Effect Dictionary Functions ------------------------------*/

extern RpMTEffectDict *
RpMTEffectDictCreate(void);

extern void
RpMTEffectDictDestroy(RpMTEffectDict *dict);

extern RpMTEffectDict *
RpMTEffectDictAddEffect(RpMTEffectDict *dict, RpMTEffect *effect);

extern RpMTEffect *
RpMTEffectDictRemoveEffect(RpMTEffect *effect);

extern RpMTEffect *
RpMTEffectDictFindNamedEffect(const RpMTEffectDict *dict,
                              const RwChar *name);

extern RpMTEffectDict *
RpMTEffectDictSetCurrent(RpMTEffectDict *dict);

extern RpMTEffectDict *
RpMTEffectDictGetCurrent(void);

extern RwUInt32
RpMTEffectDictStreamGetSize(const RpMTEffectDict *dict);

extern const RpMTEffectDict *
RpMTEffectDictStreamWrite(const RpMTEffectDict *dict, RwStream *stream);

extern RpMTEffectDict *
RpMTEffectDictStreamRead(RwStream *stream);

extern RwBool
RpMTEffectDictForAllDictionaries(RpMTEffectDictCallBack callBack, void *data);

extern const RpMTEffectDict *
RpMTEffectDictForAllEffects(const RpMTEffectDict *dict,
                            RpMTEffectCallBack    callBack,
                            void                 *data);

/*--- Multi-Texture Effect Functions ----------------------------------------*/

extern const RwChar *
RpMTEffectSetPath(const RwChar *path);

extern RwChar *
RpMTEffectGetPath(void);

extern RpMTEffect *
RpMTEffectCreateDummy(void);

extern void
RpMTEffectDestroy(RpMTEffect *effect);

extern RwUInt32
RpMTEffectStreamGetSize(const RpMTEffect *effect);

extern const RpMTEffect *
RpMTEffectStreamWrite(const RpMTEffect *effect, RwStream *stream);

extern RpMTEffect *
RpMTEffectStreamRead(RwStream *stream);

extern RpMTEffect *
RpMTEffectFind(RwChar *name);

extern const RpMTEffect *
RpMTEffectWrite(const RpMTEffect *effect);

extern RpMTEffect *
RpMTEffectSetName(RpMTEffect *effect, RwChar *name);

extern RwChar *
RpMTEffectGetName(RpMTEffect *effect);

extern RpMTEffect *
RpMTEffectAddRef(RpMTEffect *effect);

extern RwBool 
_rpMTEffectSystemInit(void);

extern RwBool 
_rpMTEffectRegisterPlatform(RwPlatformID                     platformID,
                            rpMTEffectStreamReadCallBack     streamRead,
                            rpMTEffectStreamWriteCallBack    streamWrite,
                            rpMTEffectStreamGetSizeCallBack  streamGetSize,
                            rpMTEffectDestroyCallBack        destroy);

extern RwBool 
_rpMTEffectOpen(void);

extern RwBool
_rpMTEffectClose(void);

extern RpMTEffect *
_rpMTEffectInit(RpMTEffect   *effect, 
                RwPlatformID  platformID);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* RPMATFX_MULTITEXEFFECT_H */

/*---- end: ./multiTexEffect.h----*/
/*---- start: ./multiTex.h----*/

#ifndef RPMATFX_MULTITEX_H
#define RPMATFX_MULTITEX_H

/**
 * \ingroup rpmultitex
 * \struct RpMultiTexture
 * RpMultiTexture is an opaque type.
 *
 * \see RpMaterialCreateMultiTexture
 * \see RpMaterialGetMultiTexture
 * \see RpMultiTextureSetTexture
 * \see RpMultiTextureGetTexture
 * \see RpMultiTextureSetCoords
 * \see RpMultiTextureGetCoords
 * \see RpMultiTextureSetEffect
 * \see RpMultiTextureGetEffect
 */
typedef struct RpMultiTexture RpMultiTexture;

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*--- MultiTexture Functions ------------------------------------------------*/

extern RwUInt32
RpMultiTextureGetNumTextures(const RpMultiTexture *multiTexture);

extern RpMultiTexture *
RpMultiTextureSetTexture(RpMultiTexture *multiTexture,
                         RwUInt32        index,
                         RwTexture      *texture);

extern RwTexture *
RpMultiTextureGetTexture(const RpMultiTexture *multiTexture,
                         RwUInt32        index);

extern RpMultiTexture *
RpMultiTextureSetCoords(RpMultiTexture *multiTexture,
                        RwUInt32        index,
                        RwUInt32        texCoordIndex);

extern RwUInt32
RpMultiTextureGetCoords(const RpMultiTexture *multiTexture,
                        RwUInt32        index);

extern RpMultiTexture *
RpMultiTextureSetEffect(RpMultiTexture *multiTexture,
                        RpMTEffect    *effect);

extern RpMTEffect *
RpMultiTextureGetEffect(const RpMultiTexture *multiTexture);


/*--- Material MultiTexture Functions ---------------------------------------*/

extern RpMaterial *
RpMaterialCreateMultiTexture(RpMaterial *material,
                             RwPlatformID platformID,
                             RwUInt32 numTextures);

extern RpMaterial *
RpMaterialDestroyMultiTexture(RpMaterial *material,
                              RwPlatformID platformID);

extern RpMultiTexture *
RpMaterialGetMultiTexture(const RpMaterial *material,
                          RwPlatformID platformID);

extern RwBool
RpMaterialQueryMultiTexturePlatform(RwPlatformID platformID);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* RPMATFX_MULTITEX_H */

/*---- end: ./multiTex.h----*/

/**
 * \ingroup rpmatfxnull
 * \ref RpMatFXNullPipeline
 */
enum RpMatFXNullPipeline
{
    rpNAMATFXNULLPIPELINE    = 0,
    rpMATFXNULLPIPELINEMATFX = 1, /**<Null material effect rendering pipeline. */
    rpMATFXNULLPIPELINEMAX,
    rpMATFXNULLPIPELINEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpMatFXNullPipeline RpMatFXNullPipeline;

/*===========================================================================*
 *--- Functions -------------------------------------------------------------*
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern RxPipeline *
RpMatFXGetNullPipeline( RpMatFXNullPipeline nullPipeline );

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*---- end: c:/daily/rwsdk/plugin/matfx/null/matfxplatform.h----*/

#endif /* RPMATFX_H */


