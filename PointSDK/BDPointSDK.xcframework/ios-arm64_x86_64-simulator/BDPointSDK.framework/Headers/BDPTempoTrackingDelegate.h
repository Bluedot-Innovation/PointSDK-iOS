//
//  Created by Bluedot Innovation
//  Copyright © 2020 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TempoTrackingUpdate;

/**
  Defines the call-backs which Point SDK makes to inform the Application of Tempo events.

  Assign your own implementation of this protocol to the `BDLocationManager.tempoTrackingDelegate`  property of the
  shared `BDLocationManager` instance, to handle Tempo related callbacks.
*/
@protocol BDPTempoTrackingDelegate <NSObject>

@optional
/**
*   This method indicates that Tempo Tracking has expired
*/
- (void)tempoTrackingDidExpire;

@optional
/**
 * This method indicates that Tempo Tracking has been updated
 * @param tempoUpdate The Tempo tracking update details, including ETA and @ref Destination information
 */
- (void)tempoTrackingDidUpdate:(TempoTrackingUpdate *)tempoUpdate;

@required

/**
*  This method is called if Tempo Tracking is stopped due to an error (for e.g. invalid destination Id)
* @param error Details from NSError objects delivered here are intended for development logging purposes
*  and are not intended to be seen by your application's users.
*/
- (void)didStopTrackingWithError:(NSError *)error;

@end
