//--------------------------------------------------
// Simple Script
// cubeScript.cpp
// Date: 2021-11-06
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "cubeScript.h"
#include <atta/component/components/material.h>
#include <atta/component/components/name.h>
#include <atta/component/components/transform.h>
#include <atta/resource/interface.h>
#include <atta/resource/resources/material.h>

namespace scr = atta::script;
namespace cmp = atta::component;
namespace rsc = atta::resource;

void CubeScript::update(cmp::Entity entity, float dt) {
    // The static variables are shared among all CubeScripts
    static const cmp::Entity prototype(1);
    static unsigned numClones = 0;
    static float time = 0;

    int cloneId = entity.getCloneId();

    //----- Get number of clones -----//
    if (numClones == 0)
        numClones = cmp::getFactory(prototype)->getNumClones();

    //----- Advance time -----//
    // Use clone 0 to advance the time
    if (cloneId == 0) {
        time += dt * 0.1;
        if (time > 2 * M_PI)
            time -= 2 * M_PI;
    }

    //----- Transform Component -----//
    unsigned row = cloneId % (unsigned)sqrt(numClones);
    unsigned col = cloneId / (unsigned)sqrt(numClones);
    float offset = 8 * M_PI / numClones * (col + row) + time;

    // Update clone transform
    cmp::Transform* t = entity.get<cmp::Transform>();
    t->position.x = row;
    t->position.y = col;
    t->position.z = sin(offset);

    //----- Material Component -----//
    // Set material resource
    std::string materialName = "Material " + std::to_string(cloneId);
    rsc::Material* m = rsc::get<rsc::Material>(materialName);
    entity.get<cmp::Material>()->set(m);

    // Update material color
    m->color.x = (t->position.z + 1.0f) * 0.5f;
    m->color.y = 1.0f - m->color.x;
    m->color.z = 1.0f;

    //----- Name Component -----//
    cmp::Name* n = entity.get<cmp::Name>();
    strcpy(n->name, ("Cube clone " + std::to_string(cloneId)).c_str());
}
