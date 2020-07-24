#pragma once

#include <glm/glm.hpp>

#include "../Core/types.h"
#include "Texture.h"
#include "Shader.h"
#include "Camera.h"
#include "ImageExtension.h"

namespace fbmgen {

    class Application;

    class Renderer {
    public:
        inline const Texture* GetTexture() const { return m_Texture; }

        bool Create(Application* app);
        void Draw();

        inline void SetCamera(Camera* camera) { m_Camera = camera; }

        // Move to Controller
        inline void SetSunDirection(const glm::vec3& dir) { m_SunDirection = dir; }
        void SetSunPosition(const glm::vec2& imageCoord, const glm::vec2& resolution);
        //

        void RenderImage(const char* path, s32 width, s32 height, ImageExtension extension, s32 quality = 100);
        ~Renderer();
    private:
        Application* m_App = nullptr;
        Shader* m_Shader = nullptr;
        Texture* m_Texture = nullptr;
        Camera* m_Camera = nullptr;

        /* Parameters */
        glm::vec3 m_SunDirection = glm::normalize(glm::vec3(0.0f, 1.0f, -1.0f));
        glm::vec3 m_SunColor = glm::vec3(1.0f, 1.0f, 0.35f);
        f32 m_SunIntensity = 2.0f;
        
        /* Screen Quad */ 
        u32 m_FrameBuffer = 0;
        u32 m_VertexBuffer = 0;
        u32 m_IndexBuffer = 0;
        u32 m_VertexArray = 0;
    };
}