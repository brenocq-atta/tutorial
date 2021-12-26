//--------------------------------------------------
// Simple Script
// cubeScript.cpp
// Date: 2021-11-06
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "cubeScript.h"
#include <atta/componentSystem/components/transformComponent.h>

void CubeScript::update(atta::Entity entity, float dt)
{
    // Update time
    static float time = 0;
    time += dt*1.2f;
    if(time > 2*M_PI) time -= 2*M_PI;

    // Get the entity transform component
    atta::TransformComponent* t = entity.getComponent<atta::TransformComponent>();

    t->scale.x = 0.1f*sin(time)+0.9f;
    t->scale.y = 0.1f*sin(time)+0.9f;
    t->scale.z = 0.1f*sin(time)+0.9f;
}
