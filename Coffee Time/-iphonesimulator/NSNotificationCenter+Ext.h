//
//  NSNotificationCenter+Ext.h
//  WeMo_Universal
//
//  Created by Mrigank Gupta on 29/05/12.
//  Copyright (c) 2012 Agnity Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSNotificationCenter (Ext)

- (void)postOnMainThreadWithNotification:(NSNotification *)notification;
- (void)postOnMainThreadWithNotificationName:(NSString *)aName object:(id)anObject;
- (void)postOnMainThreadWithNotificationName:(NSString *)aName object:(id)anObject userInfo:(NSDictionary *)aUserInfo;
 
@end
