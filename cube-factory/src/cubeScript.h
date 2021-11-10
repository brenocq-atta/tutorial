//--------------------------------------------------
// Simple Script
// cubeScript.h
// Date: 2021-11-06
// By Breno Cunha Queiroz
//--------------------------------------------------
#ifndef CUBE_SCRIPT_H
#define CUBE_SCRIPT_H
#include <atta/pch.h>
#include <atta/scriptSystem/script.h>

class CubeScript : public atta::Script
{
public:
    void update(atta::Entity entity, float dt) override;
};

ATTA_REGISTER_SCRIPT(CubeScript)

#endif// CUBE_SCRIPT_H
