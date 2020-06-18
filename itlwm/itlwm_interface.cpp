/*
* Copyright (C) 2020  钟先耀
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

#include "itlwm_interface.hpp"

#define super IOEthernetInterface
OSDefineMetaClassAndStructors( itlwm_interface, IOEthernetInterface )

bool itlwm_interface::init(IONetworkController *controller)
{
    if (!super::init(controller))
        return false;
    IOLog("itlwm setting MTU to %d\n", ETHERNET_MTU);
    setMaxTransferUnit(ETHERNET_MTU);
    return true;
}

bool itlwm_interface::setMaxTransferUnit(UInt32 mtu) {
    if (mtu > 1500) {
        return false;
    }
    super::setMaxTransferUnit(mtu);
    return true;
}

void itlwm_interface::free()
{
    super::free();
}
