//--------------------------------------------------
// Simple Script
// lightScript.cpp
// Date: 2021-11-06
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "lightScript.h"
#include <atta/componentSystem/components/transformComponent.h>

void LightScript::update(atta::EntityId entityId, uint64_t cloneId, std::vector<atta::Component*> components, float dt)
{
    // Update time
    static float time = 0;
    time += dt*0.001;
    if(time > 2*M_PI) time -= 2*M_PI;

    // Get transform component. Note that the transform component is the third that appear 
    // on the UI for the light entity, so we get the third component in the vector
    atta::TransformComponent* t = reinterpret_cast<atta::TransformComponent*>(components[2]);

    // Rotate the point lights using the entityId as offset
    t->position.x = 1.5f*cos(time+(float)entityId*2);
    t->position.y = 1.5f*sin(time+(float)entityId*2);
    t->position.z = 1.5f;
}
