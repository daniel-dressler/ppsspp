// Copyright (c) 2012- PPSSPP Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official git repository and contact information can be found at
// https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.

#pragma once

#include <string>
#include <list>

#include "ui/screen.h"

class EmuScreen : public Screen
{
public:
	EmuScreen(const std::string &filename);
	~EmuScreen();

	virtual void update(InputState &input);
	virtual void render();
	virtual void deviceLost();
	virtual void dialogFinished(const Screen *dialog, DialogResult result);
	virtual void sendMessage(const char *msg, const char *value);

private:
	// Something invalid was loaded, don't try to emulate
	bool invalid_;
	std::string errorMessage_;
	int32_t pressedLastUpdate;
	bool unthrottle_last_update;
	bool cycle_throttles_last_update;
};
