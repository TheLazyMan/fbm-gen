#include "Renderer.h"

#include "../Core/fbmgen_gl.h"

namespace fbmgen {

    bool Renderer::Create() {
        return m_Texture.Load("test.jpg");
    }

    void Renderer::Draw() {
        GLCall(glClear(GL_COLOR_BUFFER_BIT);)
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f);)
    }

}