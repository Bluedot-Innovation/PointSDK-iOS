//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
Entry-point for your Application's interaction with <b>Point SDK</b>. This is a subclass of <a hef="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/">CLLocationManager</a> and is intended as a drop-in replacement while providing additional features.

<b>Point SDK</b> carries out location specific, conditional actions that you define in the <b>Point Access</b> web-interface.
To start these behaviours with your Application, it is necessary only to call the authentication method
on the shared singleton instance `BDLocationManager.+instance`

Calling the authentication method will start a session with <b>Point Access</b>.
Upon success, `BDZoneInfo` "Zones" will be downloaded and associated actions will be executed by the library,
without any further intervention.

In general, the `BDLocationManager.+instance` shared, singleton instance  should be used wherever the standard Core Location
<a hef="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/">CLLocationManager</a>
class would have been used.</p>

This class exposes <b>three new delegate properties</b>, in addition to the usual <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/#//apple_ref/occ/instp/CLLocationManager/delegate"><b>delegate</b></a> property
inherited from <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/">CLLocationManager</a>:

- `BDLocationManager.sessionDelegate` - to which you should assign your own implementation of the `BDPSessionDelegate` protocol. The  property provides callbacks that inform the application of <b>Point SDK</b>'s authentication state with it's supporting web-service. The rules defined in <b>Point Access</b> will only be observed while authenticated.
- `BDLocationManager.locationDelegate` - to which you should assign your own implementation of the `BDPLocationDelegate` protocol. The property provides callbacks to notify your application when Zone information is received. This typically occurs immediately after the authentication process completes. Any <b>Custom Action</b>s defined in the <b>Point Access</b> are also triggered, in real-time.
- `BDLocationManager.tempoTrackingDelegate` - to which you should assign your own implementation of the `BDPTempoTrackingDelegate` protocol. This  property provides callbacks to notify your application
of Tempo related events.

In addition, some methods of <b>Point SDK</b> classes may only be called while authenticated
and will otherwise cause an exception to be thrown. Individual restrictions are documented clearly in this API
reference. It is only necessary to authenticate once during the runtime of the application.

@copyright Bluedot Innovation
*/
@interface BDLocationManager : CLLocationManager

/**
 *  @return The singleton instance of @ref BDLocationManager
 */
+ (BDLocationManager *)instance;

/**
 *  Key-Value Observable representation of the current, underlying CoreLocation authorization status for this Application.
 */
@property (nonatomic, readonly) CLAuthorizationStatus authorizationStatus;

@end
