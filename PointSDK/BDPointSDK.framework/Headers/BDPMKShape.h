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
 * @returns the <a href="https://developer.apple.com/library/ios/documentation/MapKit/Reference/MKShape_class/">MKShape</a> inherent to this object.
 */
-(MKShape*)shape;

@end
