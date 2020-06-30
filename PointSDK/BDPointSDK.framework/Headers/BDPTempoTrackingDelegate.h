//
//  BDPTempoTrackingDelegate.h
//  BDPointSDK
//
//  Created by Duncan Lau on 4/5/20.
//  Copyright © 2020 BlueDot. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
  Defines the call-backs which Point SDK makes to inform the Application of Tempo events.

  Assign your own implementation of this protocol to the `BDLocationManager.tempoTrackingDelegate`  property of the
  shared `BDLocationManager` instance, to handle Tempo related callbacks.
*/
@protocol BDPTempoTrackingDelegate <NSObject>

/**
*  This method indicates that Tempo Tracking has started
*/
- (void)didStartTracking;

/**
*   This method indicates that Tempo Tracking has stopped
*/
- (void)didStopTracking;

/**
*  This method is called if Tempo Tracking is stopped due to an error (for e.g. invalid destination Id)
* @param error Details from NSError objects delivered here are intended for development logging purposes
*  and are not intended to be seen by your application's users.
*/
- (void)didStopTrackingWithError: (NSError *)error;

@end
