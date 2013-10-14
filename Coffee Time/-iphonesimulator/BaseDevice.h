//
//  BaseDevice.h
//  WeMo_Universal
//
//  Created by Brent Murata on 4/18/12.
//  Copyright (c) 2012 Belkin Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

#define DEVICETYPE_SWITCH @"urn:Belkin:device:controllee:1"
#define DEVICETYPE_SENSOR @"urn:Belkin:device:sensor:1"
#define DEVICETYPE_SOCKET @"urn:Belkin:device:socket:1"
#define DEVICETYPE_CROCKPOT @"urn:Belkin:device:crockpot:1"
#define DEVICETYPE_NETCAM @"urn:Belkin:device:NetCamSensor:1"

#define DEVICEMODELCODE_SWITCH      @"Socket"
#define DEVICEMODELCODE_SENSOR      @"Sensor"
#define DEVICEMODELCODE_CROCKPOT    @"CrockPot"
#define DEVICEMODELCODE_NETCAM      @"NetCam"

#define FM_STATUS_DOWNLOADING             @"0"
#define FM_STATUS_DOWNLOAD_SUCCESS        @"1"
#define FM_STATUS_DOWNLOAD_UNSUCCESS      @"2"
#define FM_STATUS_UPDATE_STARTING         @"3"

#define kDeviceInfoDescription              @"smartDeviceDescription"
#define kDeviceInfoFriendlyName             @"friendlyName"
#define kDeviceInfoSerialNumber             @"serialNumber"
#define kDeviceInfoStatus                   @"status"
#define kDeviceInfoTimeStamp                @"statusTS"
#define kDeviceInfoMacAddress               @"macAddress"
#define kDeviceInfoPrivateKey               @"privateKey"
#define kDeviceInfoPluginID                 @"pluginId"
#define kDeviceInfoModelCode                @"modelCode"
#define kDeviceInfoUniqueID                 @"uniqueId"
#define kSignalStrength                     @"signalStrength" 
#define KRemoteFirmwareUpgradeStatus        @"fwUpgradeStatus"
#define kRemoteFirmwareVersion              @"firmwareVersion"

#define PLUG_STATUS_NO_PEER_ADDRESS         @"No Peer Address Found"                    //2
#define PLUG_STATUS_NO_RESPONSE             @"Unable to remotely reach the WeMo device" //3
#define PLUG_STATUS_ERROR                   @"Status Error"                             //4
#define PLUG_STATUS_VALIDATION_ERROR        @"Validation Error"                         //5
#define PLUG_STATUS_VALIDATION_DB_ERROR     @"Validation Data base Error"               //6
#define PLUG_STATUS_NO_PLUGIN_IN_DB_ERROR   @"Plugin Database Error"                    //7

#define ICON_SIZE 160

enum {
    REQUEST_STATUS_IDLE=0,
    REQUEST_STATUS_RUNNING=1,
    REQUEST_STATUS_TRANSITION_TO_ON=2,
    REQUEST_STATUS_TRANSITION_TO_OFF=3,
    REQUEST_TRANSITION_NOTDETECTED_TO_OFF=4,
    REQUEST_TRANSITION_NOTDETECTED_TO_ON=5
};

@class CGUpnpDevice;

@interface BaseDevice : NSObject <NSURLConnectionDelegate>
{
    NSString *friendlyName;
    NSString *udn;
    NSString *deviceType;
    NSString *state;
    NSString *firmwareVersion;
    NSString *privateKey;
    NSString *modelCode;
    NSString *macAddr;
    NSString *uniqueId;
    NSString *serialNumber;
    NSString *plugID;
    NSString *pluginSSID;
    NSString *iconURL;
    NSString *iconVersion;
    NSString *ruleDBPath;
    NSString *signalStrength;
    
    NSData          *iconData;
    CGUpnpDevice    *deviceInstance;
    NSDate          *statusTimestamp;
    
    int requestStatus;    
    int firmwareUpgradeStatus;
    
    // We are using this alive variable to notify any observers to remove themselves before we dealloc the object
    NSNumber *alive;
    BOOL upgradeFirmware;
}

@property (nonatomic,copy) NSString *friendlyName;
@property (nonatomic,copy) NSString *udn;
@property (nonatomic,copy) NSString *deviceType;
@property (nonatomic,copy) NSString *state;
@property (nonatomic,copy) NSString *firmwareVersion;
@property (nonatomic,copy) NSString *privateKey;
@property (nonatomic,copy) NSString *modelCode;
@property (nonatomic,copy) NSString *macAddr;
@property (nonatomic,copy) NSString *uniqueId;
@property (nonatomic,copy) NSString *serialNumber;
@property (nonatomic,copy) NSString *plugID;
@property (nonatomic,copy) NSString *pluginSSID;
@property (nonatomic,copy) NSString *iconURL;
@property (nonatomic,copy) NSString *iconVersion;
@property (nonatomic,copy) NSString *ruleDBPath;
@property (nonatomic,copy) NSString *signalStrength;
@property (nonatomic,copy) NSData *iconData;
@property (nonatomic,retain) id deviceInstance;
@property (nonatomic,retain) NSDate *statusTimestamp;

@property int requestStatus;
@property int firmwareUpgradeStatus;
@property BOOL upgradeFirmware;

@property (nonatomic,retain) NSNumber *alive;

- (id)initWithDevice:(CGUpnpDevice *)upnpDevice withUDN:(NSString *)udnStr;
- (id)initWithDictionary:(NSMutableDictionary *)deviceInformation;

// Abstraction for local UPnP vs Remote HTTP interfaces
// These methods will choose CGUpnpDevice for local request or HTTP operation for remote request
- (void)getPluginStatus;
- (void)setPluginStatus:(NSString *)state;
#if CROCK_POT
- (void)getCrockPotStatus;
- (void)setCrockPotStatus:(NSDictionary *)newStateDict;
#endif
- (void)updateStatus:(NSString *)remoteStatus;
- (void)updateFirmwareStatus:(NSString *)firmwareStatus;
- (void)updateStatusTimestamp:(NSString *)timestamp;
- (void)updateFirmware:(NSDictionary *)firmwareDictionary;
- (BOOL)resetToFactoryDefault;
- (NSInteger)resetSettings;

- (BOOL)postName:(NSString *)newName;
- (void)getIcon;
- (BOOL)postIcon:(NSData *)newIconData;
- (BOOL)isBadIcon:(NSData *)data;
- (BOOL)updateWeeklyCalendar:(NSMutableDictionary *)calendar;
- (NSString *)getRulesDbVersion;
- (NSString *)getRulesDbPath;
- (void)setRulesDbVersion:(NSString *)rulesDBVesrsion;
- (void)sendDB:(NSMutableDictionary *)dataWithVersion;

- (NSComparisonResult)compareDevices:(BaseDevice *)otherDevice;
@end
