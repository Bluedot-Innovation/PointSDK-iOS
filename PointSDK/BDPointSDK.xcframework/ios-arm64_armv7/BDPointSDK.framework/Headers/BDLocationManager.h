//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
@brief Entry-point for your Application's interaction with <b>Point SDK</b>.

<b>Point SDK</b> carries out location specific, conditional actions that you define in the <b>Canvas</b> web-interface.
To start these behaviours with your Application, it is necessary only to call the authentication method
on the @ref BDLocationManager#instance "shared singleton instance" of @ref BDLocationManager.<p/>

Calling the authentication method will start a session with <b>Canvas</b>.
Upon success, `BDZoneInfo` "Zones" will be downloaded and associated actions will be executed by the library,
without any further intervention.

<p>In general, the @ref BDLocationManager#instance "shared, singleton instance" of @ref BDLocationManager should be used wherever the standard Core Location
<a hef="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/">CLLocationManager</a>
class would have been used.

@ref BDLocationManager is a subclass of <a hef="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/">CLLocationManager</a>
and is intended as a drop-in replacement while providing additional features.

@ref BDLocationManager exposes <b>two new delegate properties</b>, in addition to the usual <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/#//apple_ref/occ/instp/CLLocationManager/delegate"><b>delegate</b></a> property
inherited from <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/">CLLocationManager</a>:

- `BDLocationManager.sessionDelegate` - to which you should assign your own implementation of the `BDPSessionDelegate` protocol. The  property provides callbacks that inform the application of <b>Point SDK</b>'s authentication state with it's supporting web-service. The rules defined in <b>Canvas</b> will only be observed while authenticated.
- `BDLocationManager.locationDelegate` - to which you should assign your own implementation of the `BDPLocationDelegate` protocol. The property provides callbacks to notify your application when Zone information is received. This typically occurs immediately after the authentication process completes. Any <b>Custom Action</b>s defined in the <b>Canvas</b> are also triggered, in real-time.
- `BDLocationManager.etaTrackingDelegate` - to which you should assign your own implementation of the `BDPEtaTrackingDelegate` protocol. This  property provides callbacks to notify your application
of Eta (Estimated time of arrival) related events.

<h3>Session Delegate</h3>
<p>The @ref BDPSessionDelegate protocol provides callbacks that inform the application
of <b>Point SDK</b>'s authentication state with it's supporting web-service. The rules defined in <b>Point Access</b> will only be
observed while authenticated.</p>
<p>In addition, some methods of <b>Point SDK</b> classes may only be called while authenticated
and will otherwise cause an exception to be thrown. Individual restrictions are documented clearly in this API
reference. It is only necessary to authenticate once during the runtime of the application.
*/
@interface BDLocationManager : CLLocationManager


/// @return The singleton instance of `BDLocationManager`
+ (BDLocationManager *)instance;


/// Key-Value Observable representation of the current, underlying [CoreLocation authorization status](https://developer.apple.com/documentation/corelocation/clauthorizationstatus) for this Application.
@property (nonatomic, readonly) CLAuthorizationStatus authorizationStatus;

@end
