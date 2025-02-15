//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
Entry-point for your Application's interaction with <b>Point SDK</b>.

<b>Point SDK</b> carries out location specific, conditional actions that you define in the <b>Canvas</b> web-interface.
To start these behaviours with your Application, it is necessary only to call the initialize method
on the ``BDLocationManager.instance`` "shared singleton instance" of ``BDLocationManager``.<p/>

Calling the initialization method will start a session with <b>Canvas</b>..

<p>In general, the ``BDLocationManager.instance`` "shared, singleton instance" of ``BDLocationManager`` should be used wherever the standard Core Location
<a hef="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/">CLLocationManager</a>
class would have been used.

``BDLocationManager`` is a subclass of <a hef="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/">CLLocationManager</a>
and is intended as a drop-in replacement while providing additional features.

``BDLocationManager`` exposes <b>a few new delegate properties</b>, in addition to the usual <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/#//apple_ref/occ/instp/CLLocationManager/delegate"><b>delegate</b></a> property
inherited from <a href="https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/">CLLocationManager</a>:

 - `BDLocationManager.geoTriggeringEventDelegate` - to which you should assign your own implementation of the `BDPGeoTriggeringEventDelegate` protocol. The property provides callbacks to notify your application when Zone information is received and any zone enter/ zone exit events as they occur, in real-time.
 - `BDLocationManager.tempoTrackingDelegate` - to which you should assign your own implementation of the `BDPTempoTrackingDelegate` protocol. This  property provides callbacks to notify your application
 of Tempo related events.
 - `BDLocationManager.bluedotServiceDelegate` - to which you should assign your own implementation of the `BDPBluedotServiceDelegate` protocol to receive Bluedot service related callbacks (for e.g. location permission changed, accuracy authorization changed, etc.).

By default, ``BDLocationManager`` disables background location updates for While Using location permission, which will not display the visual blue bar in the StatusBar area at the top of the screen and the Point SDK will not process location updates when app is in the background and permission is While Using.
If you prefer to enable that behavior when app is in the background and permission is While Using, set ``BDLocationManager.backgroundLocationAccessForWhileUsing`` to `true`.
 
<p>In addition, some methods of <b>Point SDK</b> classes may only be called while initialized
and will otherwise cause an exception to be thrown. Individual restrictions are documented clearly in this API
reference. It is only necessary to initialize once during the runtime of the application.
*/
@interface BDLocationManager : CLLocationManager


/// @return The singleton instance of `BDLocationManager`
+ (BDLocationManager *)instance;


/// Key-Value Observable representation of the current, underlying [CoreLocation authorization status](https://developer.apple.com/documentation/corelocation/clauthorizationstatus) for this Application.
@property (nonatomic, readonly) CLAuthorizationStatus authorizationStatus;

@end
