//
//  BDPBluedotServiceDelegate.h
//  BDPointSDK
//
//  Created by Duncan Lau on 31/7/20.
//  Copyright © 2020 BlueDot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
  Defines the call-backs which Point SDK makes to inform the Application of Bluedot service level events.

  Assign your own implementation of this protocol to the `BDLocationManager.bluedotServiceDelegate`  property of the
  shared `BDLocationManager` instance, to handle Bluedot service level related callbacks.
*/
@protocol BDPBluedotServiceDelegate <NSObject>

@optional

/**
 * This method can be implemented to keep track of changes in Location Manager's CLAuthorizationStatus.
 *
 * This method is called whenever location authorization status changes.
 *
 * You may wish to communicate to your user when location authorization status changes. For example, you may wish to ask for "Always" or "When in Use" authorization from within your app.
 *
 * @param previousAuthorizationStatus Previous authorization status
 * @param newAuthorizationStatus Current authorization status
*/
- (void)locationAuthorizationDidChangeFromPreviousStatus: (CLAuthorizationStatus) previousAuthorizationStatus toNewStatus: (CLAuthorizationStatus) newAuthorizationStatus;

/**
 * This method can be implemented to monitor whether the iOS 'Low Power Mode' has been enabled or disabled.
 *
 * This method is called whenever low power mode status changes in the device.
 *
 * The callback is required because Low Power mode negatively impacts the timeliness and precision of Point SDK, which your Application may need to communicate to the user.
 *
 * @param isLowPowerMode Indicates whether the device is in Low power mode
*/
- (void)lowPowerModeDidChange: (bool) isLowPowerMode;

/**
 * This method is called if Bluedot Error encouters an error.
 *
 * @param error Details from NSError objects delivered here are intended for development logging purposes and are not intended to be seen by your application's users.
*/
- (void)bluedotServiceDidReceiveError:(NSError *)error;

/**
 * Available from iOS 14. This method can be implemented to keep track of changes in Location Manager's CLAccuracyAuthorization .
 *
 * This method is called whenever accuracy authorization status changes.
 *
 * You may wish to communicate to your user when accuracy authorization changes. For example, you may wish to ask for Full Accuracy authorization from within your app.
 *
 * @param previousAccuracyAuthorization Previous accuracy authorization
 * @param newAccuracyAuthorization Current accuracy authorization
*/
- (void)accuracyAuthorizationDidChangeFromPreviousAuthorization: (CLAccuracyAuthorization) previousAccuracyAuthorization toNewAuthorization: (CLAccuracyAuthorization) newAccuracyAuthorization;

@end

