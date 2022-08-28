#pragma once
#include "core_m2.h"

enum class ETextureWarpMethod
{
    TWM_Unknow = 0,
    TWM_Clamp = GL_CLAMP_TO_EDGE,
    TWM_Repeat = GL_REPEAT,
};

enum class ETextureFilterMethod
{
    TFM_Unknow = 0,
    TFM_Nearest = GL_NEAREST,
    TFM_Linear = GL_LINEAR,
    TFM_TriNearest = GL_LINEAR_MIPMAP_NEAREST,
    TFM_TriLinear = GL_LINEAR_MIPMAP_LINEAR,
};

enum class ETexturePixelFormat : int
{
    TPF_Unknow = GL_NONE,
    TPF_R = GL_RED,
    TPF_RGB = GL_RGB,
    TPF_RGBA = GL_RGBA,
    TPF_RGBA16F = GL_RGBA16F,
    TPF_D24S8 = GL_DEPTH24_STENCIL8,
};

class FTexture
{
public:
    FTexture(glm::vec3 inColor) : TextureFormat(ETexturePixelFormat::TPF_RGB)
    {

        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        int format = GL_NONE;
        int elementType = GL_NONE;
        switch (TextureFormat)
        {
        case ETexturePixelFormat::TPF_Unknow: break;
        case ETexturePixelFormat::TPF_RGB:
            format = GL_RGB;
            elementType = GL_UNSIGNED_BYTE;
            break;
        case ETexturePixelFormat::TPF_RGBA:
            format = GL_RGBA;
            elementType = GL_UNSIGNED_BYTE;
            break;
        case ETexturePixelFormat::TPF_RGBA16F:
            format = GL_RGBA;
            elementType = GL_FLOAT;
            break;
        case ETexturePixelFormat::TPF_D24S8:
            format = GL_DEPTH_STENCIL;
            elementType = GL_UNSIGNED_INT_24_8;
            break;
        }
        auto clampedColor = glm::clamp(inColor, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));

        unsigned char colorData[] = { (unsigned char)(clampedColor.r * 255), (unsigned char)(clampedColor.g * 255), (unsigned char)(clampedColor.b * 255) };
        glTexImage2D(GL_TEXTURE_2D, 0, static_cast<GLint>(TextureFormat), 1, 1, 0, format, elementType, colorData);


        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    glm::vec2 GetSize() const
    {
	    if(ID == GL_NONE)
	    {
            return {0, 0};
	    }
        else
        {
            int w, h;
            glBindTexture(GL_TEXTURE_2D, ID);
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);
        	glBindTexture(GL_TEXTURE_2D, 0);
            return {w, h};
        }
    }

    unsigned int ID;

    std::string path;
    std::string name;

    ETexturePixelFormat TextureFormat;

    static std::shared_ptr<FTexture>& GetBlack();
    static std::shared_ptr<FTexture>& GetWhite();

    FTexture(int width, int height, ETexturePixelFormat inTextureFormat, bool bGenMipmap = false) : ID(GL_NONE), TextureFormat(ETexturePixelFormat::TPF_Unknow)
    {
        if (inTextureFormat == ETexturePixelFormat::TPF_Unknow)
        {
            return;
        }

        TextureFormat = inTextureFormat;

        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        int format = GL_NONE;
        int elementType = GL_NONE;
        switch (inTextureFormat)
        {
        case ETexturePixelFormat::TPF_Unknow: break;
        case ETexturePixelFormat::TPF_RGB:
            format = GL_RGB;
            elementType = GL_UNSIGNED_BYTE;
            break;
        case ETexturePixelFormat::TPF_RGBA:
            format = GL_RGBA;
            elementType = GL_UNSIGNED_BYTE;
            break;
        case ETexturePixelFormat::TPF_RGBA16F:
            format = GL_RGBA;
            elementType = GL_FLOAT;
            break;
        case ETexturePixelFormat::TPF_D24S8:
            format = GL_DEPTH_STENCIL;
            elementType = GL_UNSIGNED_INT_24_8;
            break;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, static_cast<GLint>(inTextureFormat), width, height, 0, format, elementType, nullptr);

        if (bGenMipmap)
        {
            glGenerateMipmap(GL_TEXTURE_2D);
        }

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, bGenMipmap ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, bGenMipmap ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    FTexture(const std::string& texturePath, ETextureWarpMethod warpMethod, ETextureFilterMethod filterMethod) : ID(GL_NONE), TextureFormat(ETexturePixelFormat::TPF_Unknow)
    {
        stbi_set_flip_vertically_on_load(true);
        path = texturePath;
        int width, height, nrChannels;
        auto data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            int format;
            switch (nrChannels)
            {
            case 1:
                format = GL_RED;
                TextureFormat = ETexturePixelFormat::TPF_R;
                break;
            case 3:
                format = GL_RGB;
                TextureFormat = ETexturePixelFormat::TPF_RGB;
                break;
            case 4:
                format = GL_RGBA;
                TextureFormat = ETexturePixelFormat::TPF_RGBA;
                break;
            default:
                format = GL_NONE;
                break;
            }

            if (format == GL_NONE)
            {
                std::cout << "unsupported texture format" << std::endl;
                return;
            }

            glGenTextures(1, &ID);
            glBindTexture(GL_TEXTURE_2D, ID);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, static_cast<GLint>(warpMethod));
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, static_cast<GLint>(warpMethod));

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(filterMethod));
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(filterMethod));



            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

        }
        else
        {
            return;
        }

        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);
    }

    bool IsValid() const
    {
        return ID != GL_NONE;
    }

    virtual ~FTexture()
    {
        if (ID != GL_NONE)
        {
            glDeleteTextures(1, &ID);
        }
    }
};

using FTextureRef = std::shared_ptr<FTexture>;

enum class EFrameBufferColorFormat
{
    FCF_Unknow = (int)ETexturePixelFormat::TPF_Unknow,
    FCF_RGB = (int)ETexturePixelFormat::TPF_RGB,
    FCF_RGBA = (int)ETexturePixelFormat::TPF_RGBA,
    FCF_RGBA16F = (int)ETexturePixelFormat::TPF_RGBA16F,
};

class FFrameBuffer
{

private:

    const static std::shared_ptr<FFrameBuffer>& GetDefaultFrameBuffer();

    friend class FCameraComponent;

    GLuint FBO;

    static constexpr int MaxSupportColorAttachment = 4;

    std::vector<std::function<void(void)>> cmds;

    void Use()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    }

public:
    FTextureRef Color[MaxSupportColorAttachment];
    FTextureRef Depth;

    bool IsEmpty() const { return FBO == GL_NONE; }

    glm::vec4 clearColor;

    void Clear()
    {
        Use();
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    FFrameBuffer() : FBO(GL_NONE), clearColor(0, 0, 0, 0) {}

    FFrameBuffer(int width, int height, int n, EFrameBufferColorFormat inTextureFormat) : FBO(GL_NONE), clearColor(0, 0, 0, 0)
    {
        const int numOfColorAttachment = (n > MaxSupportColorAttachment) ? MaxSupportColorAttachment : n;
        for (int i = 0; i < numOfColorAttachment; ++i)
        {
            Color[i] = std::make_shared<FTexture>(width, height, static_cast<ETexturePixelFormat>(inTextureFormat));
        }
        Depth = std::make_shared<FTexture>(width, height, ETexturePixelFormat::TPF_D24S8);

        glGenFramebuffers(1, &FBO);
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);

        for (int i = 0; i < numOfColorAttachment; ++i)
        {
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, Color[i]->ID, 0);
        }

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, Depth->ID, 0);

        unsigned int attachments[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
        glDrawBuffers(numOfColorAttachment, attachments);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    ~FFrameBuffer()
    {
        if (FBO != GL_NONE)
        {
            glDeleteFramebuffers(1, &FBO);
        }
    }
};