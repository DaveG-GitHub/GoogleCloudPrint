//
//  CloudPrintXPCBridge.h
//  GoogleCloudPrint
//
//  Created by Conrad Kramer on 10/21/12.
//  Copyright (c) 2012 Kramer Software Productions, LLC. All rights reserved.
//

#import <CoreData/CoreData.h>

@protocol NSXPCListenerDelegate;

@protocol CPPrinterService <NSObject>
@required
- (void)fetchPrintersWithReply:(void (^)(NSSet *))returnBlock;
@end

@protocol CPAuthenticationService <NSObject>
@required
- (void)authenticateWithCode:(NSString *)code redirectURI:(NSString *)redirectURI reply:(void (^)(BOOL success, NSError *error))replyBlock;
- (void)validateCredentialWithReply:(void (^)(BOOL success, NSError *error))replyBlock;
- (void)deleteCredential;
- (void)authorizationURLWithRedirectURI:(NSString *)uri reply:(void (^)(NSURL *))replyBlock;
@end

@interface CloudPrintXPCBridge : NSObject <NSXPCListenerDelegate, CPPrinterService, CPAuthenticationService>

@property (strong, readonly, nonatomic) NSManagedObjectContext *context;

- (id)initWithManagedObjectContext:(NSManagedObjectContext *)context;

- (void)runWithPrinterListener:(NSXPCListener *)printerListener authorizationListener:(NSXPCListener *)authListener;

@end