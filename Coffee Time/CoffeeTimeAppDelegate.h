//
//  CoffeeTimeAppDelegate.h
//  Coffee Time
//
//  Created by Richard Goldberg on 10/14/13.
//  Copyright (c) 2013 Michael Manning and Richard Goldberg. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CoffeeTimeAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;

@end
