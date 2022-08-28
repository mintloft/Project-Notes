#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "primitive_m2.h"
#include "primitive_move_m2.h"
#include "mode_m2l.h"
#include "light_m2.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

class FTestLightControlSubobject : public FComponentSubobject
{
public:
    std::weak_ptr<FDirectionalLightComponent> dirRef;
    virtual void Init() override
    {
        dirRef = std::dynamic_pointer_cast<FDirectionalLightComponent>(owner.lock());

        FInputReceiver::FObjectInputKey key;
        key.priority = 0;
        key.objId = dirRef.lock()->GetObjectId();

        auto&& inputHandle = FInputReceiver::GetInputReceiver().keyHandles[key];
        std::weak_ptr<FTestLightControlSubobject> weakThis = std::static_pointer_cast<FTestLightControlSubobject>(this->shared_from_this());

        inputHandle.repeatCallback = [weakThis](int key)->void
        {
            std::shared_ptr<FTestLightControlSubobject> safeThis = weakThis.lock();
            if (safeThis)
            {
                std::shared_ptr<FDirectionalLightComponent> dirOwner = safeThis->dirRef.lock();
                if (key == GLFW_KEY_N)
                {
                    auto trans = dirOwner->GetWorldTransform();
                    glm::vec3 scale;
                    glm::quat rotation;
                    glm::vec3 location;
                    glm::vec3 skew;
                    glm::vec4 persp;
                    glm::decompose(trans,scale,rotation, location, skew, persp);

                    rotation = glm::angleAxis(glm::radians(20 * FInputReceiver::GetInputReceiver().deltaTime), glm::vec3(0, 1, 0)) * rotation;

                    dirOwner->SetWorldTransform(glm::translate(glm::mat4_cast(rotation), location));
                    
                }
                else if (key == GLFW_KEY_M)
                {
                    auto trans = dirOwner->GetWorldTransform();
                    glm::vec3 scale;
                    glm::quat rotation;
                    glm::vec3 location;
                    glm::vec3 skew;
                    glm::vec4 persp;
                    glm::decompose(trans, scale, rotation, location, skew, persp);

                    rotation = glm::angleAxis(glm::radians(-20 * FInputReceiver::GetInputReceiver().deltaTime), glm::vec3(0, 1, 0)) * rotation;

                    dirOwner->SetWorldTransform(glm::translate(glm::mat4_cast(rotation), location));
                }
            }
        };
    }

};

int main()
{
#if 1 //假装是从文件加载进来的数据
    float vertices[] = {
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,


        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    float groundVertex[] =
    {
        -44.5f, -4.5f, -44.5f,  0.0f, 1.0f,
        44.5f, -4.5f, -44.5f,  1.0f, 1.0f,
         44.5f, -4.5f,  44.5f,  1.0f, 0.0f,
        -44.5f, -4.5f,  44.5f,  0.0f, 0.0f,
    };

    unsigned int groundIndices[] =
    {
        0,2,1,0,3,2
    };

    // world space positions of our cubes
    glm::vec3 cubePositions[] = {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  0.0f, -15.0f),
        glm::vec3(-1.5f, -0.0f, -2.5f),
        glm::vec3(-3.8f, -0.0f, -12.3f),
        glm::vec3(2.4f, -0.0f, -3.5f),
        glm::vec3(-1.7f,  0.0f, -7.5f),
        glm::vec3(1.3f, -0.0f, -2.5f),
        glm::vec3(1.5f,  0.0f, -2.5f),
        glm::vec3(1.5f,  0.0f, -1.5f),
        glm::vec3(-1.3f,  0.0f, -1.5f)
    };


#endif

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl; 
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetKeyCallback(window, key_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    FShaderRef ourShader2 = std::make_shared<FShader>("shaders/simple_model_deferred.vs", "shaders/simple_model_deferred.fs");

    FModel model("./objects/backpack/backpack.obj");

    glEnable(GL_DEPTH_TEST);


    FSceneRef scene = std::make_shared<FScene>();

    std::vector<char> vertexData;
    vertexData.resize(sizeof(vertices));
    memcpy(vertexData.data(), vertices, vertexData.size());
    FPrimitiveVertexDesc vertexDesc;
    vertexDesc.structSize = 5 * sizeof(int);
    vertexDesc.props.emplace_back(0, reinterpret_cast<void*>(0), GL_FLOAT, 3);
    vertexDesc.props.emplace_back(2, reinterpret_cast<void*>(3 * sizeof(float)), GL_FLOAT, 2);

    //创建一个立方体模型
    FPrimitiveRef cube = std::make_shared<FPrimitive>();
    cube->SetData(vertexData, std::vector<unsigned int>(), vertexDesc);

    //创建一个平面模型
    FPrimitiveRef plane = std::make_shared<FPrimitive>();
    vertexData.resize(30 * sizeof(float));
    plane->SetData(vertexData, std::vector<unsigned int>(), vertexDesc);

    //再创建一个大一点的平面模型
    FPrimitiveRef ground = std::make_shared<FPrimitive>();
    vertexData.resize(sizeof(groundVertex));
    memcpy(vertexData.data(), groundVertex, vertexData.size());
    std::vector<unsigned int> indices;
    indices.resize(sizeof(groundIndices));
    memcpy(indices.data(), groundIndices, indices.size());
    ground->SetData(vertexData, indices, vertexDesc);

    //创建一个Shader作为模板
    FShaderRef ourShader = std::make_shared<FShader>("shaders/simple_model_deferred.vs", "shaders/simple_model_deferred.fs");

    //加载俩贴图
    FTextureRef tex[3];
    tex[0] = std::make_shared<FTexture>(("./container.jpg"), ETextureWarpMethod::TWM_Repeat, ETextureFilterMethod::TFM_TriLinear);
    tex[1] = std::make_shared<FTexture>(("./awesomeface.png"), ETextureWarpMethod::TWM_Clamp, ETextureFilterMethod::TFM_TriLinear);

    //给场景添加一个相机
    auto cameraComp = scene->CreateComponentWithArg<FCameraComponent>(glm::vec3(0.0f, 0.0f, 3.0f));
    cameraComp->AddSubobjectWithArgs<FSimpleImputMoveComponentSubobject>(0);//给相机添加个输入移动组件
    cameraComp->bDeferredPipeline = true;
    //方便起见将刚才的framebuffer的color贴图也放到这个数组里
    tex[2] = tex[0];//frameBuffer->Color[0];

     
    //创建一个渲染组件，作为场景的一个地面
    auto groundComponent = scene->CreateComponent<FPrimitiveComponent>();
    groundComponent->AddPrimitiveUnit(ground, std::make_shared<FShader>(*ourShader));//地面用那个大一点的平面模型，方便起见用ourShader作为模板复制一份出来

    groundComponent->GetShader(0)->SetTexture("Emissive", tex[1]);
    groundComponent->GetShader(0)->SetTexture("Albedo", tex[0]);
    groundComponent->GetShader(0)->SetTexture("Specular", FTexture::GetWhite());
    groundComponent->GetShader(0)->SetTexture("Roughness", FTexture::GetWhite());
    groundComponent->GetShader(0)->SetTexture("Metallic", FTexture::GetWhite());
    groundComponent->GetShader(0)->SetTexture("AO", FTexture::GetWhite());
     
    //创建一个场景组件，并作为相机的子物体
    auto cameraFollower = scene->CreateComponent<FPrimitiveComponent>();
    cameraFollower->AddPrimitiveUnit(cube, std::make_shared<FShader>(*ourShader));//用立方体模型，方便起见用ourShader作为模板复制一份出来
    cameraFollower->GetShader(0)->SetTexture("Emissive", tex[1]);
    cameraFollower->GetShader(0)->SetTexture("Albedo", tex[0]);
    cameraFollower->GetShader(0)->SetTexture("Specular", FTexture::GetWhite());
    cameraFollower->GetShader(0)->SetTexture("Roughness", FTexture::GetWhite());
    cameraFollower->GetShader(0)->SetTexture("Metallic", FTexture::GetWhite());
    cameraFollower->GetShader(0)->SetTexture("AO", FTexture::GetWhite());
	//cameraFollower->AttachTo(cameraComp, EAttachRule::AR_KeepRelative);
    cameraFollower->SetLocalLocation(glm::vec3(1, 1, -3));  


    FTextureRef pbrtex[5];
    pbrtex[0] = std::make_shared<FTexture>("./objects/backpack/diffuse.jpg", ETextureWarpMethod::TWM_Clamp, ETextureFilterMethod::TFM_TriLinear);
    pbrtex[1] = std::make_shared<FTexture>("./objects/backpack/normal.png", ETextureWarpMethod::TWM_Clamp, ETextureFilterMethod::TFM_TriLinear);
    pbrtex[2] = std::make_shared<FTexture>("./objects/backpack/roughness.jpg", ETextureWarpMethod::TWM_Clamp, ETextureFilterMethod::TFM_TriLinear);
    pbrtex[3] = std::make_shared<FTexture>("./objects/backpack/specular.jpg", ETextureWarpMethod::TWM_Clamp, ETextureFilterMethod::TFM_TriLinear);
    pbrtex[4] = std::make_shared<FTexture>("./objects/backpack/ao.jpg", ETextureWarpMethod::TWM_Clamp, ETextureFilterMethod::TFM_TriLinear);


    scene->CreateComponentWithArg<FEnvLightComponent>(glm::vec3(0.02f, 0.02f, 0.02f));
    glm::quat dirLightDir = glm::angleAxis(glm::radians(60.0f), glm::vec3(0, 1, 0)) * glm::angleAxis(glm::radians(-30.0f), glm::vec3(1, 0, 0));
    scene->CreateComponentWithArg<FDirectionalLightComponent>(glm::vec3(10.f, 10.0f, 10.0f), dirLightDir)->AddSubobject<FTestLightControlSubobject>();



    auto&& guitaComponent = scene->CreateComponent<FPrimitiveComponent>();
    guitaComponent->SetWorldTransform(glm::mat4(1));
    for(auto&& mod : model.meshes)
    {  
        auto tempShader = std::make_shared<FShader>(*ourShader2); 
        guitaComponent->AddPrimitiveUnit(mod.primitive, tempShader);
        tempShader->SetTexture("Emissive", FTexture::GetBlack());
        tempShader->SetTexture("Albedo", pbrtex[0]);
        tempShader->SetTexture("Specular", pbrtex[3]);
        tempShader->SetTexture("Roughness", pbrtex[2]);
        tempShader->SetTexture("Metallic", FTexture::GetWhite());
        tempShader->SetTexture("AO", pbrtex[4]);
    }

    //再随便给场景添加10个渲染组件
    for (unsigned int i = 0; i < 10; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

        auto primitive = scene->CreateComponent<FPrimitiveComponent>();
        
        primitive->SetWorldTransform(model);

        //为了方便展示，不同的渲染组件交替使用两个模型    
        if (i % 2)
        {
            primitive->AddPrimitiveUnit(cube, std::make_shared<FShader>(*ourShader));
        }
        else
        {
            primitive->AddPrimitiveUnit(plane, std::make_shared<FShader>(*ourShader));
            primitive->GetShader(0)->SetCullMethod(ECullMethod::CM_None);//平面模型不剔除，渲染双面
        }
        primitive->GetShader(0)->SetTexture("Emissive", tex[1]);
        primitive->GetShader(0)->SetTexture("Albedo", tex[0]);
        primitive->GetShader(0)->SetTexture("Specular", FTexture::GetWhite());
        primitive->GetShader(0)->SetTexture("Roughness", FTexture::GetWhite());
        primitive->GetShader(0)->SetTexture("Metallic", FTexture::GetWhite());
        primitive->GetShader(0)->SetTexture("AO", FTexture::GetWhite());
        

    }


    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        glfwPollEvents();
    	FInputReceiver::GetInputReceiver().deltaTime = deltaTime;
        FInputReceiver::GetInputReceiver().Execute();


        // game logic
        // ----------
        scene->Tick(deltaTime);

        FInputReceiver::GetInputReceiver().FinalExecute();
        FInputReceiver::GetInputReceiver().frameIndex++;
        // render
        // ------
        FCameraComponent::GetDeferredCmds().Execute();

        glfwSwapBuffers(window);
        
    }

    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow* window)
{

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
    {
        glfwSetWindowShouldClose(window, true);
    }

    if(action == GLFW_PRESS || action == GLFW_RELEASE)
    {
        std::get<1>(FInputReceiver::GetInputReceiver().keyStatus[key]) = (action == GLFW_PRESS);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    FInputReceiver::GetInputReceiver().mousePos[2] = xposIn;
    FInputReceiver::GetInputReceiver().mousePos[3] = yposIn;
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    //cameraComp.lock()->ProcessMouseScroll(static_cast<float>(yoffset));
}
