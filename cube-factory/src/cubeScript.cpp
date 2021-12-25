//--------------------------------------------------
// Simple Script
// cubeScript.cpp
// Date: 2021-11-06
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "cubeScript.h"
#include <atta/componentSystem/components/transformComponent.h>
#include <atta/componentSystem/components/materialComponent.h>
#include <atta/componentSystem/components/nameComponent.h>

#define QTY_CLONES 100

void CubeScript::update(atta::Entity entity, float dt)
{
    // Update time
    static float time = 0;
    int cloneId = entity.getCloneId();
    
    // This static variable is shared among all clones, we are using the clone 0 to update the time
    if(cloneId == 0)
    {
        time += dt*0.1;
        if(time > 2*M_PI) time -= 2*M_PI;
    }

    //----- Transform Component -----//
    atta::TransformComponent* t = entity.getComponent<atta::TransformComponent>();
    // Using cloneId to calculate clone specific transform
    unsigned row = cloneId % (unsigned)sqrt(QTY_CLONES);
    unsigned col = cloneId / (unsigned)sqrt(QTY_CLONES);
    float offset = 8*M_PI/QTY_CLONES * (col+row)+time;

    // Update clone transform
    t->position.x = row;
    t->position.y = col;
    t->position.z = sin(offset);

    //----- Material Component -----//
    atta::MaterialComponent* m = entity.getComponent<atta::MaterialComponent>();
    m->albedo.x = (t->position.z+1.0f)*0.5f;
    m->albedo.y = 1.0f-m->albedo.x;
    m->albedo.z = 1.0f;

    //----- Name Component -----//
    atta::NameComponent* n = entity.getComponent<atta::NameComponent>();
    strcpy(n->name, ("Cube clone "+std::to_string(cloneId)).c_str());
}
