//
//  CloudPrintAPIClient.h
//  GoogleCloudPrint
//
//  Created by Conrad Kramer on 10/21/12.
//  Copyright (c) 2012 Kramer Software Productions, LLC. All rights reserved.
//

#import "AFRESTClient.h"

@class CPPrinter, AFOAuthCredential;

@interface CloudPrintAPIClient : AFRESTClient <AFIncrementalStoreHTTPClient>

+ (CloudPrintAPIClient *)sharedClient;

- (void)verifyCredentialWithSuccess:(void (^)(AFOAuthCredential *))success
                            failure:(void (^)(NSError *))failure;

- (void)authenticateWithCode:(NSString *)code
                 redirectURI:(NSString *)uri
                     success:(void (^)(AFOAuthCredential *))success
                     failure:(void (^)(NSError *))failure;

@end