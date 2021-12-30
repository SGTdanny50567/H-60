/*
 * vtx_uh60_anvishud_fnc_changeBrightness
 *
 * Adjusts brightness of the HMD
 *
 * params (array)[(object) vehicle, (boolean) isDriver, (integer) polarity (1 or -1)]
 *
 */

params ["_vehicle", "_isDriver", "_polarity"];

//Determine correct pylon index based on L or R seat
private _index = if(_isDriver) then [{15}, {11}];

_ammoCount = (_vehicle) ammoOnPylon _index;

//Adjust change amount based on current brightness and polarity passed to the function
private _change = (if(_ammocount >= 300) then [{100}, {50}]) * _polarity;

//Adjust ammo at pylon index to manipulate HMD brightness (alpha)
_vehicle setAmmoOnPylon [_index, (_ammoCount + _change) max 0 min 1000];

if(vtx_uh60_ui_showDebugMessages) then {systemChat Format["HMD Brightness: %1%2", (_vehicle ammoOnPylon _index)/10, "%"]};