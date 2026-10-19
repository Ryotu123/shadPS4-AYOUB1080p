// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "SDL3/SDL.h"
#include "common/types.h"

namespace Input {

enum MouseMode {
    Off = 0,
    Joystick,
    Gyro,
    Touchpad,
};

bool ToggleMouseModeTo(MouseMode m);
void SetMouseToJoystick(int joystick);
void SetMouseParams(float mouse_deadzone_offset, float mouse_speed, float mouse_speed_offset);
void SetMouseGyroRollMode(bool mode);

void EmulateJoystick(GameController* controller, u32 interval);
void EmulateGyro(GameController* controller, u32 interval);

// Controller "sensor mode" (for pads without a gyro), modelled on the iss_pc native port:
//   L3+R3 together toggles it. While on, the pad is reported held sideways (spray can),
//   cross shakes, and the left stick aims. Those inputs are not sent to the game.
bool IsSensorModeOn();
void SensorModeStickButton(bool is_left, bool pressed);
void SetSensorShake(bool shake);
void SetSensorAim(bool is_x, float value); // value in -1..1
void EmulateSensorMode(GameController* controller, u32 interval);

void ApplyMouseInputBlockers();

// Polls the mouse for changes
Uint32 MousePolling(void* param, Uint32 id, Uint32 interval);

} // namespace Input
