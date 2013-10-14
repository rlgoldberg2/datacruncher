//
//  NSNotificationCenter+Ext.m
//  WeMo_Universal
//
//  Created by Mrigank Gupta on 29/05/12.
//  Copyright (c) 2012 Agnity Inc. All rights reserved.
//

#import "NSNotificationCenter+Ext.h"

@implementation NSNotificationCenter (Ext)

- (void)postOnMainThreadWithNotification:(NSNotification *)notification{
    [self performSelectorOnMainThread:@selector(performPostNotification:) withObject:notification waitUntilDone:YES];
}
- (void)postOnMainThreadWithNotificationName:(NSString *)aName object:(id)anObject{
    NSNotification* notification = [NSNotification notificationWithName:aName object:anObject];
    [self performSelectorOnMainThread:@selector(performPostNotification:) withObject:notification waitUntilDone:YES];
}
- (void)postOnMainThreadWithNotificationName:(NSString *)aName object:(id)anObject userInfo:(NSDictionary *)aUserInfo{
    NSNotification* notification = [NSNotification notificationWithName:aName object:anObject userInfo:aUserInfo];
    [self performSelectorOnMainThread:@selector(performPostNotification:) withObject:notification waitUntilDone:YES];
}
- (void) performPostNotification:(NSNotification *)notification
{
    [[NSNotificationCenter defaultCenter] postNotification:notification];
}

@end
