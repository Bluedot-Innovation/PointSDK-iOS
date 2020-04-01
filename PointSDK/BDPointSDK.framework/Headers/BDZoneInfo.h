//
//  Created by Bluedot Innovation
//  Copyright © 2016 Bluedot Innovation. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BDFenceInfo;
@class BDBeaconInfo;

/**

  @brief Contains information about a Zone, including the set of @ref BDFenceInfo "fences" that comprise it.

  A set of @ref BDZoneInfo objects will be delivered to your application's BDPLocationDelegate#locationDelegate at
  the time of their download from the Bluedot Point web-service.

  This usually occurs immediately after the authentication process is complete.

  @copyright Bluedot Innovation

*/
@interface BDZoneInfo : NSObject

/** The name of this Zone that was entered into Point Access */
@property (copy,readonly) NSString *name;

/** The description of this Zone that was entered into Point Access */
@property (copy,readonly) NSString *description;

/**
  A unique <a href="http://en.wikipedia.org/wiki/Globally_unique_identifier">GUID</a> to identify this Zone by.
  This is permanent and may be used to identify specific Zones created in the Point Access web-interface,
  from your client application.
 */
@property (copy,readonly) NSString  *ID;

/**
 * The set of BDFenceInfo fences included in this Zone.
 */
@property (copy,readonly) NSSet<BDFenceInfo *>  *fences;

/**
* The set of BDBeaconInfo beacons included in this Zone.
*/
@property (copy,readonly) NSSet<BDBeaconInfo *>  *beacons;

/**
 * Whether CheckOuts should be generated for any CheckIns to this Zone.
 */
@property (readonly) BOOL checkOut;

- (BOOL)isEqual:(id)other;

- (BOOL)isEqualToInfo:(BDZoneInfo *)info;

- (NSUInteger)hash;


@end
