//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Defines a delegate for handling <b>Point SDK</b>'s session related callbacks

 <b>Point SDK</b> needs to authenticate with <b>Canvas</b> to function.
 Applications must observe the correct authentication lifecycle when using <b>Point SDK</b> features, as documented.

 For richer information about the authentication lifecycle, applications may optionally assign an implementation of this
 protocol to the sessionDelegate property of the shared `BDLocationManager instance.
 */
__attribute__((deprecated("First deprecated in 15.4.0 - initialization related delagate callbacks are now returned in completion callbacks. Please refer to `BDLocationManager.-initializeWithProjectId:completion:`")))
@protocol BDPSessionDelegate <NSObject>

/// This method is called when an authentication request has been made to initiate a Point session.
- (void)willAuthenticateWithApiKey: (NSString *)apiKey
__attribute__((deprecated("First deprecated in 15.4.0 - initialization related delegate callbacks are now returned in completion callbacks. Please refer to `BDLocationManager.-initializeWithProjectId:completion:`")));

/// This method indicates that authentication was successful and a Point session has started.
- (void)authenticationWasSuccessful
__attribute__((deprecated("First deprecated in 15.4.0 - initialization related delegate callbacks are now returned in completion callbacks. Please refer to `BDLocationManager.-initializeWithProjectId:completion:`")));

/// Indicates that connection was successful with the server but the session was denied for the reason provided.
- (void)authenticationWasDeniedWithReason: (NSString *)reason
__attribute__((deprecated("First deprecated in 15.4.0 - initialization related delegate callbacks are now returned in completion callbacks. Please refer to `BDLocationManager.-initializeWithProjectId:completion:`")));

/// Indicates a communication error with the server.
- (void)authenticationFailedWithError: (NSError *)error
__attribute__((deprecated("First deprecated in 15.4.0 - initialization related delegate callbacks are now returned in completion callbacks. Please refer to `BDLocationManager.-initializeWithProjectId:completion:`")));

/// This method is called after an authenticated Point session has ended.
- (void)didEndSession
__attribute__((deprecated("First deprecated in 15.4.0 - session ending delegate callbacks are now returned in reset's completion callbacks. Please refer to `BDLocationManager.-resetWithCompletion:`")));

/**
 *  This method is called if an authenticated Point session ends unexpectedly.
 *  @param error object delivered here is intended for development logging purposes
 *  and is not intended to be seen by your application's users.
 */
- (void)didEndSessionWithError: (NSError *)error
__attribute__((deprecated("First deprecated in 15.4.0 - session ending delegate callbacks are now returned in reset's completion callbacks. Please refer to `BDLocationManager.-resetWithCompletion:`")));

@end
