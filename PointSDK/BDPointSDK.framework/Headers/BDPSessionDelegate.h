//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
  @brief Defines a delegate for handling <b>Point SDK</b>'s session related callbacks

  <p><b>Point SDK</b> needs to authenticate with <b>Point Access</b> to function.
  Applications must observe the correct authentication lifecycle when using <b>Point SDK</b> features, as documented.</p>

  <p>Authentication state changes are most simply observed via the
  <a href="https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/KeyValueObserving/Articles/KVOCompliance.html">KVO-compliant</a>
  BDLocationManager.sessionDelegate.authenticationState property.</p>

  <p>For richer information about the authentication lifecycle, applications may optionally assign an implementation of this
  protocol to the sessionDelegate property of the shared BDLocationManager instance.</p>

  @copyright Bluedot Innovation
 */
@protocol BDPSessionDelegate <NSObject>

/**
 *  This method is called when an authentication request has been made to initiate a Point session.
 */
- (void)willAuthenticateWithApiKey: (NSString *)apiKey;

/**
 *  This method indicates that authentication was successful and a Point session has started.
 */
- (void)authenticationWasSuccessful;

/**
 *  Indicates that connection was successful with the server but the session was denied for the reason provided.
 */
- (void)authenticationWasDeniedWithReason: (NSString *)reason;

/**
 *  Indicates a communication error with the server.
 */
- (void)authenticationFailedWithError: (NSError *)error;

/**
 *  This method is called after an authenticated Point session has ended.
 */
- (void)didEndSession;

/**
 *  This method is called if an authenticated Point session ends unexpectedly.
 *  Details from NSError objects delivered here are intended for development logging purposes
 *  and are not intended to be seen by your application's users.
 */
- (void)didEndSessionWithError: (NSError *)error;

@end
