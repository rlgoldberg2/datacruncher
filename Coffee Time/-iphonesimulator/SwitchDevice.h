//
//  SwitchDevice.h
//  WeMo_Universal
//
//  Created by Brent Murata on 4/26/12.
//  Copyright (c) 2012 Ikona Medical Corporation. All rights reserved.
//

#define SWITCHSTATE_ON          @"ON"
#define SWITCHSTATE_OFF         @"OFF"
#define SWITCHSTATE_UPGRADE     @"UPGRADE"

#import "BaseDevice.h"

@interface SwitchDevice : BaseDevice
{
    int     countOnToOff;
    int     countOffToOn;
}

@property int countOnToOff;
@property int countOffToOn;

- (void)setPluginStatus:(NSString *)newState;

@end
