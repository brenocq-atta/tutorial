//--------------------------------------------------
// Logging
// projectScript.h
// Date: 2021-11-14
// By Breno Cunha Queiroz
//--------------------------------------------------
#ifndef PROJECT_SCRIPT_H
#define PROJECT_SCRIPT_H
#include <atta/pch.h>
#include <atta/scriptSystem/projectScript.h>

class Project : public atta::ProjectScript
{
public:
	void onLoad() override;
};

ATTA_REGISTER_PROJECT_SCRIPT(Project)

#endif// PROJECT_SCRIPT_H
