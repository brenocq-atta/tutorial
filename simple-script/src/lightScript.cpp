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
    if(entity.getId() == 1)
        time += dt*0.3f;
    if(time > 2*M_PI) time -= 2*M_PI;

    // Get the entity transform component
    atta::TransformComponent* t = entity.getComponent<atta::TransformComponent>();

    // Rotate the point lights using the entityId as offset
    t->position.x = 1.2f*cos(time+(float)entity.getId()*2);
    t->position.y = 1.2f*sin(time+(float)entity.getId()*2);
    t->position.z = 1.2f;
}
