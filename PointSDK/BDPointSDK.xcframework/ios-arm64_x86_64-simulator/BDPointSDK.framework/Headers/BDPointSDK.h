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
#import "BDLocationInfo.h"
#import "BDPointSessionException.h"

// Bluedot protocols
#import "BDPDeepCopy.h"
#import "BDPGeometry.h"
#import "BDPValidatable.h"
#import "BDPSpatialObjectInfo.h"
#import "BDPSpatialObject.h"
#import "BDPNamedDescribed.h"
#import "BDPTempoTrackingDelegate.h"
#import "BDPBluedotServiceDelegate.h"
#import "BDPGeoTriggeringEventDelegate.h"
#import "BDPJSONSerializable.h"
