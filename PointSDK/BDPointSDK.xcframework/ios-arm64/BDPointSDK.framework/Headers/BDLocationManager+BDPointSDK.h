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
#import "BDPBluedotServiceDelegate.h"
#import "BDPGeoTriggeringEventDelegate.h"
#import "BDPTempoTrackingDelegate.h"

@protocol BDPAuthenticationDelegate;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

/**
 * Bluedot Service Related Errors
*/
static NSString * const _Nonnull BDServiceErrorDomain = @"com.bluedot.service";
typedef NS_ENUM(NSInteger, BDServiceError) {
    /**
     * SDK not initialized
     */
    BDServiceErrorSDKNotInitialized = -1000,
    /**
     * Invalid Project Id
     */
    BDServiceErrorInvalidProjectId = -1001,
    /**
     * Access Denied
     */
    BDServiceErrorAccessDenied = -1002,
    /**
     * Storage full on device
     */
    BDServiceErrorStorageFull = -1003,
    /**
     * Notification Permission Not Granted
     */
    BDServiceErrorNotificationPermissionNotGranted = -1004,
    /**
     * SDK already initialized
     */
    BDServiceErrorSDKAlreadyInitialized = -1005,
    /**
     * Missing Location (when requesting RuleSet)
     */
    BDServiceErrorMissingLocation = -1006,
    /**
     * Failed to connect to Point API
     */
    BDServiceErrorFailedToConnect = -2000,
    /**
     * Failed to retrieve remote configuration
     */
    BDServiceErrorFailedToRetrieveRemoteConfiguration = -2001,
    /**
     * Failed to retrieve global config
     */
    BDServiceErrorFailedToRetrieveGlobalConfig = -2002,
    /**
     * Failed to retrieve ruleset
     */
    BDServiceErrorFailedToRetrieveRuleSet = -2003,
};

/**
 * Bluedot Tempo Related Errors
*/
static NSString * const _Nonnull BDTempoErrorDomain = @"com.bluedot.tempo";
typedef NS_ENUM(NSInteger, BDTempoError) {
    /**
     * Tempo Tracking cannot start while already in progress
     */
    BDTempoErrorCannotStartWhileAlreadyInProgress = -1000,
    /**
     * Tempo Tracking cannot stop while Tempo is not in progress
     */
    BDTempoErrorCannotStopWhileNotInProgress = -1001,
    /**
     * Invalid Destination ID
     */
    BDTempoErrorInvalidDestinationId = -1002,
    /**
     * Couldn't start Tempo due to insufficient Location Permision. <b>Always</b> permission is required
     */
    BDTempoErrorInsufficientLocationPermission = -1003,
    /**
     * Couldn't start Tempo when application is in the background
     */
    BDTempoErrorCannotStartWhileApplicationInBackground = -1004
};

/**
 * Bluedot Geo-triggering Related Errors
*/

static NSString * const _Nonnull BDGeoTriggeringErrorDomain = @"com.bluedot.geoTriggering";
typedef NS_ENUM(NSInteger, BDGeoTriggeringError) {
    /**
     * Couldn't start Geo-triggering service when Geo-triggering  already in progress
     */
    BDGeoTriggeringErrorCannotStartWhileAlreadyInProgress = -1000,
    /**
     * Trying to stop Geo-Triggering when it is not in progress
     */
    BDGeoTriggeringErrorCannotStopWhileNotInProgress = -1001,
    /**
     * Couldn't start Geo-triggering service due to insufficient Location Permision. <b>Always</b> or <b>When in use</b> permission is required
     */
    BDGeoTriggeringErrorInsufficientLocationPermission = -1002,
    /**
     * Couldn't start Geo-triggering service when application is in the background
     */
    BDGeoTriggeringErrorCannotStartWhileApplicationInBackground = -1003,
    /**
     * Fail to download zone info from Canvas
     */
    BDGeoTriggeringErrorZoneDownloadFailed = -1004,
    /**
     * Couldn't start Geo-Trigggering with restart notification service, due to insufficient notifications permission
     */
    BDGeoTriggeringInsufficientNotificationPermission = -1005
};


typedef NS_ENUM(NSInteger, BDAuthorizationLevel)
{
    authorizedAlways,
    authorizedWhenInUse
} __attribute__((deprecated("First deprecated in 15.4.0 - This will be removed in future version")));

/**
  Provides <b>Point SDK</b> specific authentication methods and delegate properties to `BDLocationManager`.

  @see details in `BDLocationManager` for unified documentation of the class, including this Category.
*/
@interface BDLocationManager (BDPointSDK)

/**
 * Initialize Bluedot Point SDK with projectId.
 *
 * @note Bluedot SDK will not start triggering Geofeatures immediately after initialization as per previous API. You will have to make the call explicitly to start/stop Geo-triggering.
 *
 * @note Bluedot Point SDK no longer requests for OS location permission on authentication/initialization as per previous API.
 *
 * We encourage you to request OS location permission that you requires (Always or When in Use), at an opportune moment from within your app, to get the best conversion rate. For example, when customer places an order within the mobile app, at this point you can start geotriggering, as well as requesting for location permission. To request for OS location permission, you can make the calls via our *BDLocationManager* Singleton, for example:
 * ````
 * [BDLocationManager.instance requestAlwaysAuthorization];
 * [BDLocationManager.instance requestWhenInUseAuthorization];
 * ````
 *
 * @param projectId The projectId to be initialised. You can find your projectId on Bluedot Canvas
 * @param completion A mandatory completion handler called once processing completed. If the initialization is successful, error will be returned as nil. However, if the initilialization fails, an error will be provided.
*/
- (void)initializeWithProjectId:(NSString *_Nonnull)projectId completion:(void (^_Nonnull)(NSError * _Nullable error))completion;


/**
 * Method to determine if Point SDK is initialized.
 *
 * @return Returns whether Bluedot Point SDK is initialized or not
 */
- (BOOL)isInitialized;

/**
 *
 * Reset Bluedot Point SDK (only if you wish to switch to a different projectId)
 *
 * Call this method only if you need to switch to a different projectId, this will reset the Bluedot Point SDK to its original state. Upon completion callback, you can make the call `-initializeWithProjectId:completion:`  to initialize with a different projectId.
 *
 * @param completion A mandatory completion handler called once processing completed. If the initialization is successful, error will be returned as nil. However, if the initilialization fails, an error will be provided.
*/
- (void)resetWithCompletion:(void (^_Nonnull)(NSError * _Nullable error))completion;



/// This method has been deprecated as of version 1.14.0; it will be removed in a future version.
- (void)authenticateWithApiKey:(NSString *)apiKey
__attribute__((deprecated("First deprecated in 1.14.0 - use method `-[BDLocationManager initializeWithProjectId:completion:]` instead")));

/**
 Authenticate, and start a session with <b>Canvas</b>.
 This behaviour is asynchronous and this method will return immediately. Progress of the authentication process can be
 monitored by callbacks provided via the <b>sessionDelegate</b> property, or the KVO-enabled <b>authenticationState</b> property.
 
 Location Services are required immediately after successful authentication.
 
 It is the responsibility of the Application to respect the authentication life-cycle and ensure that `BDLocationManager`
 is not already Authenticated, or in the process of Authenticating, while calling this method.
 
 @param apiKey API Key
 @param authorizationLevel It is mandatory to request authorization level during SDK authentication. Requesting with
 "authorizedAlways" option will show iOS location permission prompt with three options, "Always", "When in use" and "Never".
 Requesting with "authorizedWhenInUse" option will show iOS location permission prompt with two options, "When in use" and "Never".
 @note `BDPointSessionException` Calling this method while in an invalid state will result in a `BDPointSessionException` being thrown.
 */
- (void)authenticateWithApiKey:(NSString *)apiKey
          requestAuthorization:(BDAuthorizationLevel)authorizationLevel
__attribute__((deprecated("First deprecated in 15.4.0 - use method `-[BDLocationManager initializeWithProjectId:completion:]` instead")));

/**
  Immediately ends a currently active session with <b>Canvas</b>.
  According to the authentication lifecycle, this method should only be called when <b>authenticationState</b> is
  `BDAuthenticationStateAuthenticated`. Otherwise, a `BDPointSessionException` will be thrown.
  
 @note `BDPointSessionException` Thrown if `BDLocationManager` is already logged out.
 */
- (void)logOut
__attribute__((deprecated("First deprecated in 15.4.0 - use method `-[BDLocationManager resetWithCompletion:]` instead")));

/**
  Equivalent to setting <b>locationDelegate</b> and <b>sessionDelegate</b>.
 
  @param pointDelegate Object implementing `BDPointDelegate`, equivalent to both `BDPSessionDelegate` and `BDPLocationDelegate`
 */
- (void)setPointDelegate:(id<BDPointDelegate>)pointDelegate
__attribute__((deprecated("First deprecated in 15.4.0 - Please implement individual delegates separately")));

@property id<BDPLocationDelegate> locationDelegate
__attribute__((deprecated("First deprecated in 15.4.0 - Features migrated to `bluedotServiceDelegate` or `geoTriggeringEventDelegate`")));

/**
 Applications using <b>Point SDK</b> must authenticate before using its features.
  
 Which classes and methods require authentication is set out clearly in the API documentation. Authentication is performed simply
 by calling `-[BDLocationManager authenticateWithApiKey:requestAuthorization:]` with the API credentials provided in your
 <a href="https://www.pointaccess.bluedot.com.au/pointaccess-v1/login.html"><b>Canvas</b> management portal</a>.
 
 Implement the callbacks in your own implementation of `BDPSessionDelegate`, and assign it to this property to
 receive feedback on the outcome of authentication, and to tell your application when it can start
 fully using <b>Point SDK</b>.  Attempting to call protected features when not authenticated will case a
 `BDPointSessionException` to be thrown.
 */
@property id<BDPSessionDelegate> sessionDelegate
__attribute__((deprecated("First deprecated in 15.4.0 - initialization related delegate callbacks are now returned in completion callbacks. Please refer to `-[BDLocationManager initialize:completion:]`")));

/**
 * Implement the callbacks in your own implementation of `BDPTempoTrackingDelegate`, and assign it to this property to
     receive Tempo related events
 *
 * Applications using Point SDK must initialize before using its features. Attempting to call protected features when not initialized will case a `BDPointSessionException` to be thrown.
 */
@property id<BDPTempoTrackingDelegate> tempoTrackingDelegate;

/**
 * Implement the callbacks in your own implementation of `BDPBluedotServiceDelegate`, and assign it to this property to receive bluedot service related callbacks (for e.g. location permission changed, accuracy authorization changed, e.t.c.
 *
 * Applications using Point SDK must initialize before using its features. Attempting to call protected features when not initialized will case a `BDPointSessionException` to be thrown.
 */
@property id<BDPBluedotServiceDelegate> _Nullable bluedotServiceDelegate;


/**
 * Implement the callbacks in your own implementation of `BDPGeoTriggeringEventDelegate`, and assign it to this property to receive Geotriggering e related callbacks (for e.g. zone updates, fence checkin e.t.c.)
 *
 * Applications using Point SDK must initialize before using its features. Attempting to call protected features when not initialized will case a `BDPointSessionException` to be thrown.
 */
@property id<BDPGeoTriggeringEventDelegate> _Nullable geoTriggeringEventDelegate;

/// This method has been deprecated as of version 1.14.0; it will be removed in a future version.
@property id<BDPAuthenticationDelegate> authenticationDelegate __attribute__((deprecated("First deprecated in 1.14.0 - initialization related delegate callbacks are now returned in completion callbacks. Please refer to `-[BDLocationManager initialize:completion:]`")));


/**
  Read-only property, providing the current authentication authenticationState.
  This property is <a href="https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/KeyValueObserving/Articles/KVOCompliance.html#//apple_ref/doc/uid/20002178-BAJEAIEE">KVO compliant</a>,
  meaning that it can be observed for changes with <a href="https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/KeyValueObserving/KeyValueObserving.html">Key-Value Observing</a>.
 */
@property (readonly) BDAuthenticationState authenticationState
__attribute__((deprecated("First deprecated in 15.4.0 - This will be removed in future version. To check if Point SDK is initialized, please refer to `-[BDLocationManager isInitialized]`")));

/**
 * A collection of `BDZoneInfo` objects, corresponding to the Zones you created for this project, in the
 * <b>Canvas</b> web-interface.
 */
@property (nonatomic, readonly) NSSet *zoneInfos;

/**
  Disabled or re-enable a specific `BDZoneInfo` "zone".  Information about valid `BDZoneInfo` "zones", including
  their respective <i>zoneId</i>'s for use in this method, is delivered to `-[BDPGeoTriggeringEventDelegate onZoneInfoUpdate:]`.
 */
- (void)setZone:(NSString *)zoneId disableByApplication:(BOOL)disable;

/**
 *  Blocking method to determine if a user zone is in an enabled state.
 *
 *  @param zoneId zone UUID.
 *  @return Returns whenever zone is disabled or not
 */
- (BOOL)isZoneDisabledByApplication:(NSString *)zoneId
__attribute__((deprecated("First deprecated in 1.13 - use method `-[BDLocationManager applicationContainsDisabledZone:completion:]` instead")));

/**
 *  Non-blocking method to determine if a user zone is in an enabled state.
 *  @param zoneId zone UUID
 *  @param completion closure returns whenever zone is disabled or not
 */
- (void)applicationContainsDisabledZone:(NSString *)zoneId
                             completion:(void (^)(BOOL))completion;

/**
 * Returns the installation reference of this Point SDK enabled App.
 * This is the same as the Install Ref that appears in a Zone's Activity Log in Canvas, or queried via Open API.
 * This reference is randomly generated at the first run-time of the App and remains fixed for the duration of the App
 * installation.
 */
- (NSString *)installRef;

/**
 * Notifies <b>Point SDK</b> that the push notification has been received with given data.
 * @param data Push data passed through AppDelegate callback methods.
 */
- (void)notifyPushUpdateWithData:(NSDictionary *)data;

/**
 * Returns the version of the Point SDK as a NSString.
 */
- (NSString *)sdkVersion;

/**
 * Sets custom metadata for Notification events.
 * The custom metadata set through this API will be available on the backend in checkin activity log and via webhooks.
 * Only up to 20 custom meta data fields are allowed. Throws `BDCustomEventMetadataCountException` exception if the number of custom fields exceeded.
 * Only String Type is allowed. Throws `BDCustomEventMetadataDataFormatException` exception if data contains non-String type.
 */
- (void)setCustomEventMetaData:(NSDictionary *)data;

/**
 * Returns the custom metadata set by calling setCustomEventMetaData.
 */
- (NSDictionary *)customEventMetaData;

/**
 * Start GeoTriggering features of the Bluedot Point SDK. Please refer to `-[BDLocationManager startGeoTriggeringWithAppRestartNotificationTitle:notificationButtonText:completion:]` if you wish to implement App Restart Feature
 *
 * @note You can start Geo-triggering feature <b>only</b> while your App is in the Foreground.
 * @note An error will be returned if your App does not have either <b>Always</b> or <b>When In Use</b> location permission.
 * @param completion A mandatory completion handler called once Start GeoTriggering processing completed. If the  GeoTriggering feature is started successful, error will be returned as nil. However, if the Start GeoTriggering feature fails, an error will be provided.
*/
- (void)startGeoTriggeringWithCompletion:(void (^_Nonnull)(NSError * _Nullable error))completion;


/**
 * Start GeoTriggering features of the Bluedot Point SDK with App Restart feature. Note that <b>Always</b> location permission is required for the App Restart feature.
 *
 * @note You can start Geo-triggering feature <b>only</b> while your App is in the Foreground.
 * @note An error will be returned if your App does not have <b>Always</b> location permission.
 * @note An error will be returned if notification permission is not granted.
 * @param notificationTitle the string to be used in the title of the banner or alert to be used in the local notification to restart the app.
 * @param notificationButtonText the string to be used in the text of the action button to be used in the local notification to restart the app.
 * @param completion A mandatory completion handler called once Start GeoTriggering processing completed. If the  GeoTriggering feature is started successful, error will be returned as nil. However, if the Start GeoTriggering feature fails, an error will be provided.
*/
- (void)startGeoTriggeringWithAppRestartNotificationTitle:(NSString *_Nonnull)notificationTitle
                                   notificationButtonText:(NSString *_Nonnull)notificationButtonText
                                               completion:(void (^_Nonnull)(NSError * _Nullable error))completion;


/**
 * Method to determine if GeoTriggering is running
 *
 * @return Returns whether GeoTriggering is running
 */
- (BOOL)isGeoTriggeringRunning;

/**
 * Stop GeoTriggering features of the Bluedot Point SDK
 *
 * @note Stopping Geo-triggering feature has the intended effect of stopping location services on the device, thereby conserving battery on your user’s device unless another feature such as Tempo, is active.
 * @param completion A mandatory completion handler called once Stop Geotriggering processing completed. If the Geotriggering feature is stopped successful, error will be returned as nil. However, if the Stop Geotriggering fails, an error will be provided.
*/
- (void)stopGeoTriggeringWithCompletion:(void (^_Nullable)(NSError * _Nullable error))completion;

/**
 * Start Tempo Tracking for destination id provided
 *
 * @note An error will be returned if your App does not have <b>Always</b>  location permission.
 * @param destinationId The destinationId to be tracked
 * @param completion A mandatory completion handler called once Start Tempo processing completed. If the Tempo is started successful, error will be returned as nil. However, if the Start Tempo fails, an error will be provided.
*/
- (void)startTempoTrackingWithDestinationId:(NSString *_Nonnull)destinationId
                                 completion:(void (^_Nonnull)(NSError * _Nullable error))completion;

/**
 * Start Tempo Tracking for destination id provided
 * @param destinationId The destinationId to be tracked
 * @note `BDPointSessionException` thrown if PointSDK is not logged in.
 * @note NSException with the name "BDTempoTrackingAlreadyStartedException" thrown if Tempo Tracking is currently already in progress
 * @note NSException with the name "BDTempoDestinationIdEmptyException" thrown if destinationId is empty
 */
- (void)startTempoTracking:(NSString *_Nonnull)destinationId
__attribute__((deprecated("First deprecated in 15.4.0 - use method `-[BDLocationManager startTempoTrackingWithDestinationId:completion:]` instead")));


/**
 * Stop Tempo Tracking
 *
 * @param completion A mandatory completion handler called once Stop Tempo processing completed. If the Tempo is stopped successful, error will be returned as nil. However, if the Start Tempo fails, an error will be provided.
*/
- (void)stopTempoTrackingWithCompletion:(void (^_Nonnull)(NSError * _Nullable error))completion;

/**
 * Method to determine if Tempo is running
 *
 * @return Returns whether Tempo is running
 */
- (BOOL)isTempoRunning;

/**
 * Stop Tempo Tracking
 * @note `BDPointSessionException` thrown if PointSDK is not logged in.
 */
- (void)stopTempoTracking
__attribute__((deprecated("First deprecated in 15.4.0 - use method `-[BDLocationManager stopTempoTrackingWithCompletion:]` instead")));

@end

#pragma clang diagnostic pop
