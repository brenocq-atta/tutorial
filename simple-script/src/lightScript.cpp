//--------------------------------------------------
// Simple Script
// lightScript.cpp
// Date: 2021-11-06
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "lightScript.h"
#include <atta/componentSystem/components/transformComponent.h>

void LightScript::update(atta::Entity entity, float dt)
{
    // Update time
    static float time = 0;
    time += dt*0.001;
    if(time > 2*M_PI) time -= 2*M_PI;

    // Get the entity transform component
    atta::TransformComponent* t = entity.getComponent<atta::TransformComponent>();

    // Rotate the point lights using the entityId as offset
    t->position.x = 1.5f*cos(time+(float)entity.getId()*2);
    t->position.y = 1.5f*sin(time+(float)entity.getId()*2);
    t->position.z = 1.5f;
}
