//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MKShape;

/**
*  @brief Any object which can return a <a href="https://developer.apple.com/library/prerelease/ios/documentation/MapKit/Reference/MKShape_class/index.html">MapKit shape</a> representing its inherent geometry.
*
*  <p>This is implemented by the @ref BDBoundingBox "box", @ref BDCircle "circle", @ref BDPolygon "polygon" and
*  @ref BDLineString "line-string" geometries, to assist with their rendering in
*  <a href="https://developer.apple.com/library/ios/documentation/mapkit/reference/mkmapview_class/MKMapView/MKMapView.html">MapKit map views</a>.
*/
@protocol BDPMKShape <NSObject>

/**
 * @deprecated First deprecation in PointSDK v1.13. Please consider to implement map overlays renderrer in your project.
 */
-(MKShape*)shape __attribute__((deprecated("First deprecated in 1.13 - use method applicationContainsDisabledZone:completion: instead")));

@end
