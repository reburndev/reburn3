#include "cb3graphicsmanager.h"

#include <rwcore.h>

#include "../define.h"

void CB3GraphicsManager::Construct()
{
    OpenRenderWare();
}

__declspec(naked) void CB3GraphicsManager::ConstructLTCG()
{
    _asm {
        mov ecx, eax
        call Construct
        ret
    }
}

void CB3GraphicsManager::OpenRenderWare()
{
    if (RwEngineInit(nullptr, rwENGINEINITNOFREELISTS, 0x4000)) {
        //if (RwFrameSetStaticPluginsSize(0)) {
            //if (CGtTexture::AttachPlugins()) {
                RwEngineOpenParams openParams;
                
                openParams.displayID = g_windowHandle;

                if (RwEngineOpen(&openParams)) {
                    if (RwEngineStart()) {
                        /*LPDIRECT3DDEVICE8 d3dDevice = (LPDIRECT3DDEVICE8) RwD3D8GetCurrentD3DDevice();

                        LPDIRECT3DSURFACE8 depthSurface;
                        d3dDevice->GetDepthStencilSurface(&depthSurface);
                        m_defaultZStencil = depthSurface;*/

                        /*d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0, 0.0, 0);
                        d3dDevice->Swap(0);
                        d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0 , 0.0, 0);
                        d3dDevice->Swap(0);*/
                        RwMemoryFunctions *xboxMemFuncs = (RwMemoryFunctions *) 0x007593d4;
                        *xboxMemFuncs = RWSRCGLOBAL(memoryFuncs);
                    } else {
                        RwEngineClose();
                        RwEngineTerm();
                    }
                } else {
                    RwEngineTerm();
                }
            //}
        //}
    }
}