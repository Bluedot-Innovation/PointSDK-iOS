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

- (void)addOverlaysForBeacon:(BDBeaconInfo *)beaconInfo
                   iconImage:(UIImage *)icon
                   iconScale:(CGFloat)scale;

- (void)addOverlaysForFence:(BDFenceInfo *)fenceInfo;

- (void)addOverlaysForZone:(BDZoneInfo *)zoneInfo
       withBeaconIconImage:(UIImage *)beaconIconImage
           beaconIconScale:(CGFloat)beaconIconScale;

- (void)addOverlaysForZones:(NSSet *)zoneInfos
        withBeaconIconImage:(UIImage *)beaconIconImage
            beaconIconScale:(CGFloat)beaconIconScale;


// Removing Point features from the map

- (void)removeAllSpatialObjectOverlays;

- (void)removeOverlaysForSpatialObjectInfo:(id <BDPSpatialObjectInfo>)spatialObject;


// Setting the tint colour for Beacons and Fences

- (void)setTintColor:(UIColor *)tintColor
    forSpatialObject:(id<BDPSpatialObjectInfo>)spatialObjectInfo;


// Getting map regions for Point features

- (MKMapRect)mapRectForSpatialObject:(id<BDPSpatialObjectInfo>)spatialObjectInfo;

- (MKMapRect)mapRectForZone:(BDZoneInfo *)zone;

- (MKMapRect)mapRectForZones:(NSSet *)zones;

@end
