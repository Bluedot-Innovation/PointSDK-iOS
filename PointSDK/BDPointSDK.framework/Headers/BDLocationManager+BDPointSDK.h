//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BDLocationManager.h"
#import "BDAuthenticationState.h"
#import "BDPointDelegate.h"
#import "BDPLocationDelegate.h"
#import "BDPSessionDelegate.h"
#import "BDPAuthenticationStateProvider.h"

@protocol BDPAuthenticationDelegate;
typedef NS_ENUM(NSInteger, BDAuthorizationLevel)
{
    authorizedAlways,
    authorizedWhenInUse
};

/**
  @brief Provides <b>Point SDK</b> specific authentication methods and delegate properties to @ref BDLocationManager.

  @see details in @ref BDLocationManager for unified documentation of the class, including this Category.
*/
@interface BDLocationManager (BDPointSDK) <BDPAuthenticationStateProvider>

/**
 * This method has been deprecated as of version 1.14.0; it will be removed in a future version.
 *
 * @deprecated Use @ref authenticateWithApiKey:requestAuthorization:
 */
- (void)authenticateWithApiKey: (NSString *)apiKey
__attribute__((deprecated("First deprecated in 1.14.0 - use method authenticateWithApiKey:requestAuthorization: instead")));

/**
 * <p>Authenticate, and start a session with <b>Point Access</b>.
 * This behaviour is asynchronous and this method will return immediately. Progress of the authentication process can be
 * monitored by callbacks provided via the <b>sessionDelegate</b> property, or the KVO-enabled <b>authenticationState</b> property.</p>
 *
 * Location Services are required immediately after successful authentication.
 *
 * <p>It is the responsibility of the Application to respect the authentication life-cycle and ensure that @ref BDLocationManager
 * is not already Authenticated, or in the process of Authenticating, while calling this method.</p>
 *
 * @param apiKey API Key
 * @param authorizationLevel It is mandatory to request authorization level during SDK authentication. Requesting with
 * "authorizedAlways" option will show iOS location permission prompt with three options, "Always", "When in use" and "Never".
 * Requesting with "authorizedWhenInUse" option will show iOS location permission prompt with two options, "When in use" and "Never".
 * @exception BDPointSessionException Calling this method while in an invalid state will result in a @ref BDPointSessionException being thrown.
 */
- (void)authenticateWithApiKey: (NSString *)apiKey requestAuthorization: (BDAuthorizationLevel) authorizationLevel;

/**
  <p>Immediately ends a currently active session with <b>Point Access</b>.
  According to the authentication lifecycle, this method should only be called when <b>authenticationState</b> is
  BDAuthenticationStateAuthenticated. Otherwise, a BDPointSessionException will be thrown.</p>
  @exception BDPointSessionException Thrown if @ref BDLocationManager is already logged out.
 */
- (void)logOut;

/**
  <p>Equivalent to setting <b>locationDelegate</b> and <b>sessionDelegate</b></p>.
  @param pointDelegate Object implementing @ref BDPointDelegate, equivalent to both @ref BDPSessionDelegate and @ref BDPLocationDelegate
 */
- (void)setPointDelegate: (id<BDPointDelegate>)pointDelegate;

@property id<BDPLocationDelegate> locationDelegate;

/**
  <p>Applications using <b>Point SDK</b> must authenticate before using its features.</p>
  <p>Which classes and methods require authentication is set out clearly in the API documentation. Authentication is performed simply
  by calling BDLocationManager::authenticateWithApiKey: with the API credentials provided in your
  <a href="https://www.pointaccess.bluedot.com.au/pointaccess-v1/login.html"><b>Point Access</b> management portal</a>.</p>
  <p>Implement the callbacks in your own implementation of @ref BDPSessionDelegate, and assign it to this property to
  receive feedback on the outcome of authentication, and to tell your application when it can start
  fully using <b>Point SDK</b>.  Attempting to call protected features when not authenticated will case a
  @ref BDPointSessionException to be thrown.</p>
 */
@property id<BDPSessionDelegate> sessionDelegate;

/**
 * @deprecated This has been superceded by BDPSessionDelegate and will be removed in a future release.
 */
@property id<BDPAuthenticationDelegate> authenticationDelegate __attribute__((deprecated("This has been superceded by BDPSessionDelegate and will be removed in a future release.")));


/**
  Read-only property, providing the current authentication authenticationState.
  This property is <a href="https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/KeyValueObserving/Articles/KVOCompliance.html#//apple_ref/doc/uid/20002178-BAJEAIEE">KVO compliant</a>,
  meaning that it can be observed for changes with <a href="https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/KeyValueObserving/KeyValueObserving.html">Key-Value Observing</a>.
 */
@property (readonly) BDAuthenticationState authenticationState;

/**
 * A collection of @ref BDZoneInfo objects, corresponding to the Zones you created for this application, in the
 * <b>Point Access</b> web-interface.
 */
@property (nonatomic, readonly) NSSet* zoneInfos;

/**
  Disabled or re-enable a specific @ref BDZoneInfo "zone".  Information about valid @ref BDZoneInfo "zones", including
  their respective <i>zoneId</i>'s for use in this method, is delivered to BDPLocationDelegate::didUpdateZoneInfo:.
 */
- (void)setZone: (NSString *)zoneId disableByApplication: (BOOL)disable;

/**
 *  Blocking method to determine if a user zone is in an enabled state.
 *
 *  @param zoneId zone UUID.
 *  @return Returns whenever zone is disabled or not
 *  @deprecated Use @ref applicationContainsDisabledZone:completion:
 */
- (BOOL)isZoneDisabledByApplication: (NSString *)zoneId
__attribute__((deprecated("First deprecated in 1.13 - use method applicationContainsDisabledZone:completion: instead")));

/**
 *  Non-blocking method to determine if a user zone is in an enabled state.
 *  @param zoneId zone UUID
 *  @param completion closure returns whenever zone is disabled or not
 */
- (void)applicationContainsDisabledZone:(NSString *)zoneId completion:(void (^)(BOOL))completion;

/**
 * Returns the installation reference of this Point SDK enabled App.
 * This is the same as the Install Ref that appears in a Zone's Activity Log in Point Access, or queried via Open API.
 * This reference is randomly generated at the first run-time of the App and remains fixed for the duration of the App
 * installation.
 */
- (NSString *)installRef;

/**
 * Notifies <b>Point SDK</b> that the push notification has been received with given data.
 * @param data Push data passed through AppDelegate callback methods.
 */
- (void)notifyPushUpdateWithData: (NSDictionary *)data;

/**
 * Returns the version of the Point SDK as a NSString.
 */
- (NSString *)sdkVersion;

/**
 * Sets custom metadata for Notification events.
 * The custom metadata set through this API will be available on the backend in checkin activity log and via webhooks.
 * Only up to 5 custom meta data fields are allowed. Throws BDCustomEventMetadataCountException exception if the number of custom fields exceeded.
 * Only String Type is allowed. Throws BDCustomEventMetadataDataFormatException exception if data contains non-String type.
 */
- (void) setCustomEventMetaData: (NSDictionary *)data;

/**
 * Returns the custom metadata set by calling setCustomEventMetaData.
 */
- (NSDictionary *)customEventMetaData;

@end
