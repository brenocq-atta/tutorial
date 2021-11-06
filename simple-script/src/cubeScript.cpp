//--------------------------------------------------
// Simple Script
// cubeScript.cpp
// Date: 2021-11-06
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "cubeScript.h"
#include <atta/componentSystem/components/transformComponent.h>

void CubeScript::update(atta::EntityId entityId, uint64_t cloneId, std::vector<atta::Component*> components, float dt)
{
    // Update time
    static float time = 0;
    time += dt*0.005;
    if(time > 2*M_PI) time -= 2*M_PI;

    // Get transform component. Note that the transform component is the third that appear 
    // on the UI for the cube entity, so we get the third component in the vector
    atta::TransformComponent* t = reinterpret_cast<atta::TransformComponent*>(components[2]);

    t->scale.x = 0.1f*sin(time)+0.9f;
    t->scale.y = 0.1f*sin(time)+0.9f;
    t->scale.z = 0.1f*sin(time)+0.9f;
}
