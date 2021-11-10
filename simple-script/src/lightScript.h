//--------------------------------------------------
// Simple Script
// lightScript.h
// Date: 2021-11-06
// By Breno Cunha Queiroz
//--------------------------------------------------
#ifndef LIGHT_SCRIPT_H
#define LIGHT_SCRIPT_H
#include <atta/pch.h>
#include <atta/scriptSystem/script.h>

class LightScript : public atta::Script
{
public:
    void update(atta::Entity entity, float dt) override;
};

ATTA_REGISTER_SCRIPT(LightScript)

#endif// LIGHT_SCRIPT_H
