//
//  SensorDevice.h
//  WeMo_Universal
//
//  Created by Brent Murata on 4/26/12.
//  Copyright (c) 2012 Ikona Medical Corporation. All rights reserved.
//

#define SENSORSTATE_MOTION          @"Motion Sensed"
#define SENSORSTATE_NOMOTION        @"No Motion Sensed"
#define SENSORSTATE_INITIALMOTION   @"Initial Motion"
#define SENSORSTATE_UPGRADE         @"UPGRADE"

#import "BaseDevice.h"

@interface SensorDevice : BaseDevice

- (void)updateMotionState:(NSString *)pushState;

@end
