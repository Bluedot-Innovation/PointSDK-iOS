//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BDLocationManager.h"
#import "BDInitializationState.h"
#import "BDPBluedotServiceDelegate.h"
#import "BDPGeoTriggeringEventDelegate.h"
#import "BDPTempoTrackingDelegate.h"
#import "BDZoneInfo.h"

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
    BDTempoErrorCannotStartWhileApplicationInBackground = -1004,
    /**
     * Tempo Tracking stopped due to SDK has been reset
     */
    BDTempoErrorSDKHasBeenReset = -1005,
    /**
     * Tempo Tracking stopped due to an unexpected error
     */
    BDTempoErrorUnexpectedError = -1006,
    /**
     * Tempo is not enabled. Contact Bluedot Support team to have it enabled.
     */
    BDTempoErrorTempoNotEnabled = -1007
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

/**
  Provides <b>Point SDK</b> specific initialization methods and delegate properties to `BDLocationManager`.

  @see details in `BDLocationManager` for unified documentation of the class, including this Category.
*/
@interface BDLocationManager (BDPointSDK)

/**
 * Initialize Bluedot Point SDK with projectId.
 *
 * @note Bluedot SDK will not start triggering Geofeatures immediately after initialization as per previous API. You will have to make the call explicitly to start/stop Geo-triggering.
 *
 * @note Bluedot Point SDK doesn not request for OS location permission on initialization. We encourage you to request OS location permission that you requires (Always or When in Use), at an opportune moment from within your app, to get the best conversion rate.
 * For example, when customer places an order within the mobile app, at this point you can start Geo-triggering, as well as requesting for location permission. To request for OS location permission, you can make the calls via our *BDLocationManager* Singleton, for example:
 * ````
 * [BDLocationManager.instance requestAlwaysAuthorization];
 * [BDLocationManager.instance requestWhenInUseAuthorization];
 * ````
 *
 * @param projectId The projectId to be initialized. You can find your projectId on Bluedot Canvas
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

/**
 * A collection of `BDZoneInfo` objects, corresponding to the Zones you created for this project, in the
 * <b>Canvas</b> web-interface.
 */
@property (nonatomic, readonly) NSSet<BDZoneInfo *> *zoneInfos;

/**
  Disabled or re-enable a specific `BDZoneInfo` "zone".  Information about valid `BDZoneInfo` "zones", including
  their respective <i>zoneId</i>'s for use in this method, is delivered to `-[BDPGeoTriggeringEventDelegate didUpdateZoneInfo]`.
 */
- (void)setZone:(NSString *)zoneId disableByApplication:(BOOL)disable;

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

@end

#pragma clang diagnostic pop
