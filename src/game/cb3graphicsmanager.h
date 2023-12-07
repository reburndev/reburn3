#ifndef B3GRAPHICSMANAGER_H
#define B3GRAPHICSMANAGER_H

#include <d3d8.h>

class CB3GraphicsManager
{
public:
    void Construct();
    void ConstructLTCG();

    void Update();

    void OpenRenderWare();
    
private:
    int m_width;
    int m_height;
    int m_bitDepth;

    // 0x868
    IDirect3DSurface8 *m_defaultZStencil;

};

#endif // B3GRAPHICSMANAGER_H