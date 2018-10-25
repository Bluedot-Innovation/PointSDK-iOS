//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@class BDBeaconInfo;
@class BDFenceInfo;
@class BDZoneInfo;

@protocol BDPSpatialObjectInfo;

@interface MKMapView (BDPointSDK)


// Adding Point features to the map
//__attribute__((deprecated("MKMapView (BDPointSDK) has beein deprecated since version 1.13. Please implement map overlays in your project.")))
- (void)addOverlaysForBeacon:(BDBeaconInfo *)beaconInfo
                   iconImage:(UIImage *)icon
                   iconScale:(CGFloat)scale
     DEPRECATED_MSG_ATTRIBUTE("First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.");

- (void)addOverlaysForFence:(BDFenceInfo *)fenceInfo;

- (void)addOverlaysForZone:(BDZoneInfo *)zoneInfo
       withBeaconIconImage:(UIImage *)beaconIconImage
           beaconIconScale:(CGFloat)beaconIconScale
   DEPRECATED_MSG_ATTRIBUTE("First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.");

- (void)addOverlaysForZones:(NSSet *)zoneInfos
        withBeaconIconImage:(UIImage *)beaconIconImage
            beaconIconScale:(CGFloat)beaconIconScale
    DEPRECATED_MSG_ATTRIBUTE("First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.");


// Removing Point features from the map

- (void)removeAllSpatialObjectOverlays DEPRECATED_MSG_ATTRIBUTE("First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.");

- (void)removeOverlaysForSpatialObjectInfo:(id <BDPSpatialObjectInfo>)spatialObject
                   DEPRECATED_MSG_ATTRIBUTE("First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.");


// Setting the tint colour for Beacons and Fences

- (void)setTintColor:(UIColor *)tintColor
    forSpatialObject:(id<BDPSpatialObjectInfo>)spatialObjectInfo
DEPRECATED_MSG_ATTRIBUTE("First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.");


// Getting map regions for Point features

- (MKMapRect)mapRectForSpatialObject:(id<BDPSpatialObjectInfo>)spatialObjectInfo
             DEPRECATED_MSG_ATTRIBUTE("First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.");

- (MKMapRect)mapRectForZone:(BDZoneInfo *)zone
    DEPRECATED_MSG_ATTRIBUTE("First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.");

- (MKMapRect)mapRectForZones:(NSSet *)zones
     DEPRECATED_MSG_ATTRIBUTE("First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.");

@end
