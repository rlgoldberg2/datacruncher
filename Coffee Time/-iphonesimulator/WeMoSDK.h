//
//  WeMoSDK.h
//  WeMoSDK
//
//  Created by Niraj on 27/08/12.
//  Copyright (c) 2012 Belkin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WeMoSDK : NSObject

+ (void) refreshListOfWeMoDevicesOnLAN;
+ (NSArray*)getListOfWeMoDevicesOnLAN;
+ (NSString *)getDeviceState:(NSString *)deviceID;
+ (void)setDeviceState:(NSString *)state withDeviceID:(NSString *)deviceID;

@end
