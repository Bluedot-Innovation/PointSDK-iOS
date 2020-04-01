//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

// Apple classes
#ifdef __APPLE__
#import <UIKit/UIKit.h>
#import "BDLocationManager.h"
#import "BDLocationManager+BDPointSDK.h"
#endif

#import "BDGeospatialUnits.h"

// Bluedot classes
#import "BDAuthenticationState.h"
#import "BDGeometry.h"
#import "BDBoundingBox.h"
#import "BDCircle.h"
#import "BDPoint.h"
#import "BDLineString.h"
#import "BDPolygon.h"
#import "BDPolygonal.h"
#import "BDLocation.h"
#import "BDZoneInfo.h"
#import "BDFenceInfo.h"
#import "BDBeaconInfo.h"
#import "BDLocationInfo.h"
#import "BDPointSessionException.h"
#import "BDPointOverlayRendererFactory.h"
#import "MKMapView+BDPointSDK.h"

// Bluedot protocols
#import "BDPointDelegate.h"
#import "BDPSessionDelegate.h"
#import "BDPDeepCopy.h"
#import "BDPGeometry.h"
#import "BDPLocationDelegate.h"
#import "BDPValidatable.h"
#import "BDPRestartAlertDelegate.h"
#import "BDPSpatialObjectInfo.h"
#import "BDPSpatialObject.h"
#import "BDPNamedDescribed.h"
#import "BDPAuthenticationStateProvider.h"
#import "BDPMKShape.h"

//! Project version number for BDPointSDK.
FOUNDATION_EXPORT double BDPointSDKVersionNumber;

//! Project version string for BDPointSDK.
FOUNDATION_EXPORT const unsigned char BDPointSDKVersionString[];
